
# MQTT demo

Этот пример показывает, как использовать MQTT в mbed, а также как отправлять MQTT сообщения на Платформу интернета вещей ThingsBoard.

### Конфигурация приложения

Для работы примера вам необходимо предоставить SSID и пароль точки доступа Wi-Fi в файле `mbed_app.json`

Также в `main.cpp` в переменных `data.clientID.cstring`, `data.password.cstring`, `data.username.cstring` изменить значения в соответствии с параметрами вашего устройства, зарегистрированного в Платформе интернета вещей ThingsBoard.

### Ожидаемый результат

```
Starting ThingsBoard MQTT demo:
Connecting to the network...
Opening connection to remote 89.208.220.227 port 1883
Connected socket
Sending message: 
{"temperature":25}
Message sent, rc: 0
Demo concluded successfully
```
