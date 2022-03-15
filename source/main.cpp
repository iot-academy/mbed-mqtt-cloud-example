#include "MQTTmbed.h"
#include <MQTTClientMbedOs.h>
#include <cstdio>
#include "BME280.h"

#define MQTT_BROKER "thingsboard.myitacademy.ru"
#define MQTT_TOPIC  "v1/devices/me/telemetry"
#define MQTT_PORT   1883
#define SIG_NEED_PUBLISH    0x01

DigitalOut led(LED1);
BME280 sensor_bme(I2C_SDA, I2C_SCL);

Thread mqtt_thread;
LowPowerTicker lpTicker;
Timeout led_timeout;

void led_off_cb(void)
{
    led = false;
}

void tickerIRQ (void)
{
    led = true;
    led_timeout.attach(callback(led_off_cb), 200ms);
    mqtt_thread.flags_set(SIG_NEED_PUBLISH);
}

void mqtt_thread_io()
{
    nsapi_size_or_error_t rc;
    printf("Starting ThingsBoard MQTT demo:\n");

    NetworkInterface *net = NetworkInterface::get_default_instance();
    if (!net)
    {
        printf("Error! No network inteface found.\n");
    }
    else
    {
        do
        {
            printf("Connecting to the network...\r\n");
            /* connect will perform the action to connect to the network */
            rc = net->connect();
            if (rc != 0)
            {
                printf("Error! _net->connect() returned: %d\r\n", rc);
                return;
            }

            TCPSocket socket;
            /* opening the socket only allocates resources */
            rc = socket.open(net);
            if (rc != 0)
            {
                printf("Error! _socket.open() returned: %d\r\n", rc);
                return;
            }

            /* now we have to find where to connect */
            SocketAddress address;
            net->gethostbyname(MQTT_BROKER, &address);
            address.set_port(MQTT_PORT);

            /* we are connected to the network but since we're using a connection oriented
            * protocol we still need to open a connection on the socket */
            printf("Opening connection to remote %s port %d\r\n",
                address.get_ip_address(), address.get_port());
            rc = socket.connect(address);
            if (rc != 0)
            {
                printf("Error! _socket.connect() returned: %d\r\n", rc);
                return;
            }
            printf("Connected socket\n");

            /* MQTT connection */
            MQTTClient client(&socket);
            MQTTPacket_connectData data = MQTTPacket_connectData_initializer;
            data.MQTTVersion = 3;
            data.clientID.cstring = (char*)"MyClientID";
            data.username.cstring = (char*)"A2_TEST_TOKEN";

            if ((rc = client.connect(data)) != 0)
                printf("rc from MQTT connect is %d\r\n", rc);

            MQTT::Message message;
            char buf[100];
            int temp = (int)sensor_bme.getTemperature();
            sprintf(buf, "{\"temperature\": %d}", temp);
            printf("Message sent. Temperature = %d\n", temp);
            message.qos = MQTT::QOS1;
            message.retained = false;
            message.dup = false;
            message.payload = (void *)buf;
            message.payloadlen = strlen(buf);
            rc = client.publish((const char*)MQTT_TOPIC, message);
            printf("Message sent, rc: %d\n", rc);

            while (true) {
                ThisThread::flags_wait_all(SIG_NEED_PUBLISH);
                temp = (int)sensor_bme.getTemperature();
                sprintf(buf, "{\"temperature\": %d}", temp);
                message.payload = (void *)buf;
                message.payloadlen = strlen(buf);

                rc = client.publish((const char*)MQTT_TOPIC, message);
                if (rc == 0)
                    printf("Message sent. Temperature = %d\n", temp);
                else
                    break;
            }
        } while (rc != 0);
    }
}

int main(int argc, char *argv[])
{
    mqtt_thread.start(callback(mqtt_thread_io));
    lpTicker.attach(tickerIRQ, 30s); // every 30 seconds
    while(1)
    {
    }
    return 0;
}
