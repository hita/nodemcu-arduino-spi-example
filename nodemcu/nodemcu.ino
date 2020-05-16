#include <SPI.h>
#define CS 15 //define chip select line for manual control
void setup()
{
    pinMode(CS, OUTPUT);                                       //configure the line as output
    Serial.begin(115200);                                      //Set UART baud rate
    digitalWrite(CS, HIGH);                                    //Initialize the CS line to HIGH
    SPI.begin();                                               //Initialize the SPI module--> configures the MOSI, MISO and CLOCK lines
 
    /*Configure the SPI bus as follows
1. SPI bus speed = 1 MHz
2. Data Out = From MSB bit ---> To LSB bit
3. Data Mode = SPI MODE0*/
    SPI.beginTransaction(SPISettings(2000000, MSBFIRST, SPI_MODE0));
}
 
void loop()
{
    char buf [20];

  // enable Slave Select
  digitalWrite(CS, LOW);    
  SPI.transfer (1);   // initiate transmission
  for (int pos = 0; pos < sizeof (buf) - 1; pos++)
    {
    delayMicroseconds (15);
    buf [pos] = SPI.transfer (0);
    if (buf [pos] == 0)
      {
      break;
      }
    }

  buf [sizeof (buf) - 1] = 0;  // ensure terminating null

  // disable Slave Select
  digitalWrite(CS, HIGH);

  Serial.print ("We received: ");
  Serial.println (buf);

  delay (1000);  // 1 second delay 

   digitalWrite(CS, LOW);    
  SPI.transfer (2);   // initiate transmission
  digitalWrite(CS, HIGH);
  Serial.println("LED ON");
    delay (1000);  // 1 second delay 
}
