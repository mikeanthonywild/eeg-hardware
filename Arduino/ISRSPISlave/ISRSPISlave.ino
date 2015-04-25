#include <SPI.h>

byte buf;
volatile byte pos;
volatile boolean process_it;

void setup (void)
{
  Serial.begin (115200);   // debugging

  // have to send on master in, *slave out*
  pinMode(MISO, OUTPUT);
  
  // turn on SPI in slave mode
  SPCR |= _BV(SPE);
  
  // now turn on interrupts
  SPI.attachInterrupt();

}  // end of setup


// SPI interrupt routine
ISR (SPI_STC_vect)
{
byte c = SPDR;  // grab byte from SPI Data Register
  
buf = c;
}  // end of interrupt routine SPI_STC_vect

// main loop - wait for flag set in interrupt routine
void loop (void)
{

    Serial.println (buf);
    pos = 0;

}
