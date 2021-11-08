/*******************************************************************************
 * Copyright (c) 2014, 2015 IBM Corp.
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * and Eclipse Distribution License v1.0 which accompany this distribution.
 *
 * The Eclipse Public License is available at
 *    http://www.eclipse.org/legal/epl-v10.html
 * and the Eclipse Distribution License is available at
 *   http://www.eclipse.org/org/documents/edl-v10.php.
 *
 * Contributors:
 *    Ian Craggs - initial API and implementation and/or initial documentation
 *    Ian Craggs - make sure QoS2 processing works, and add device headers
 *******************************************************************************/
 
 /**
  This is a sample program to illustrate the use of the MQTT Client library
  on the mbed platform.  The Client class requires two classes which mediate
  access to system interfaces for networking and timing.  As long as these two
  classes provide the required public programming interfaces, it does not matter
  what facilities they use underneath. In this program, they use the mbed
  system libraries.
 
 */
 


#define logMessage printf
 
#include "MQTTmbed.h"
#include <MQTTClientMbedOs.h>
 
 
int main(int argc, char* argv[])
{
    logMessage("Starting HelloMQTT demo:\n");
 
    NetworkInterface *net = NetworkInterface::get_default_instance();
    if (!net) {
        printf("Error! No network inteface found.\n");
        return 0;
    }
    logMessage("Connecting to the network...\r\n");

    /* connect will perform the action to connect to the network */
    nsapi_size_or_error_t rc = net->connect();
    if (rc != 0) {
        printf("Error! _net->connect() returned: %d\r\n", rc);
        return -1;
    }

    /* opening the socket only allocates resources */
    TCPSocket socket;
    rc = socket.open(net);
    if (rc != 0) {
        printf("Error! _socket.open() returned: %d\r\n", rc);
        return -1;
    }

    /* now we have to find where to connect */
    SocketAddress address;
    net->gethostbyname("utrlr3.messaging.internetofthings.ibmcloud.com", &address);
    address.set_port(1883);

    /* we are connected to the network but since we're using a connection oriented
    * protocol we still need to open a connection on the socket */
    logMessage("Opening connection to remote %s port %d\r\n", address.get_ip_address(), address.get_port());
    rc = socket.connect(address);
    if (rc != 0) {
        printf("Error! _socket.connect() returned: %d\r\n", rc);
        return -1;
    }
    logMessage("Connected socket\n");

    /* MQTT connection */
    MQTTClient client(&socket);
    MQTTPacket_connectData data = MQTTPacket_connectData_initializer;
    data.MQTTVersion = 3;
    data.clientID.cstring = "d:orgid:STM32Board:my_test_board";
    data.username.cstring = "use-token-auth";
    data.password.cstring = "change-me";
    if ((rc = client.connect(data)) != 0)
        logMessage("rc from MQTT connect is %d\r\n", rc);

    MQTT::Message message;
    char* topic = "iot-2/evt/statusEvent/fmt/json"; 
    char buf[100];
    sprintf(buf, "{\"d\": \"Hello World!\"}");
    message.qos = MQTT::QOS0;
    message.retained = false;
    message.dup = false;
    message.payload = (void*)buf;
    message.payloadlen = strlen(buf);
    rc = client.publish(topic, message);
    logMessage("Message sent\n");
    logMessage("Demo concluded successfully \r\n");

    return 0;
}