# nodemcu-arduino-spi-example
Ejemplo para los amigos del blog BorrowBits.com como complemento del siguiente artículo:
https://borrowbits.com/2017/11/como-comunicar-arduino-con-nodemcu-parte-i-conexion-serieuart/

En este ejemplo Arduino ejecuta una rutina de interrupción (ISR) a la espera de una orden del ESP8266 para empezar a enviar una cadena de texto. Es decir, NodeMCU actúa de máster (diciéndole a Arduino cuándo debe empezar a enviar datos de los sensores o ejecutar una orden como encender un LED).
