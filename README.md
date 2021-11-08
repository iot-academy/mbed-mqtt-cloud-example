
# MQTT demo

Этот пример показывает, как использовать MQTT в mbed, а также как отправлять MQTT сообщения на Платформу интернета вещей IBM.

### Конфигурация приложения

Для работы примера вам необходимо предоставить SSID и пароль точки доступа Wi-Fi в файле `mbed_app.json`

Также в `main.cpp` в переменных `data.clientID.cstring`, `data.password.cstring`, `data.username.cstring` изменить значения в соответствии с параметрами вашего устройства, зарегистрированного в Платформе интернета вещей IBM.

### Ожидаемый результат

```
Starting HelloMQTT demo:
Connecting to the network...
Opening connection to remote 158.175.111.155 port 1883
Connected socket
Message sent
Demo concluded successfully
```
