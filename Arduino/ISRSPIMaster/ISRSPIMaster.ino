#include <SPI.h>

void setup (void)
{

  digitalWrite(SS, HIGH);  // ensure SS stays high for now
  randomSeed(analogRead(0));
  // Put SCK, MOSI, SS pins into output mode
  // also put SCK, MOSI into LOW state, and SS into HIGH state.
  // Then put SPI hardware into Master mode and turn SPI on
  SPI.begin ();

  // Slow down the master a bit
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  
}  // end of setup


void loop (void)
{

  int c = random(1024);

  // enable Slave Select
  digitalWrite(SS, LOW);    // SS is pin 10
  
  SPI.transfer (c);

  // disable Slave Select
  digitalWrite(SS, HIGH);

  delay (8);  // 1 seconds delay 
}
