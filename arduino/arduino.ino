#include <SPI.h>
volatile char buf [20] = "Hello, world!";
volatile int pos;
volatile bool active;

void setup(void)
{
    Serial.begin(115200);                                     
    SPCR |= bit(SPE);                                         //ATMEGA328P/Arduino in slave mode
    pinMode(MISO, OUTPUT);                                    //Configure MISO as output, SlaveOut
    pinMode(9, OUTPUT);  //LED Test
    SPI.attachInterrupt();                                    //Enable interrupts for SPI-
}

// SPI interrupt routine
ISR (SPI_STC_vect)
{
byte c = SPDR;

  if (c == 2){
    digitalWrite(9,HIGH);
  }
  if (c == 1)  // starting new sequence?
    {
    digitalWrite(9,LOW);
    active = true;
    pos = 0;
    SPDR = buf [pos++];   // send first byte
    return;
    }

  if (!active)
    {
    SPDR = 0;
    return;
    }

  SPDR = buf [pos];
  if (buf [pos] == 0 || ++pos >= sizeof (buf)){
    active = false;}
}  // end of interrupt

void loop (void)
{

}  // end of loop
