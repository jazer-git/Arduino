/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;

int mode = 0;
int range = 10;
int current = 0;
int stepping = 1;
int looping = 10;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  switch ( mode )
  {
    case 0:
      if ( current >= range )
      {
        mode = 1;
        current-=stepping;
      }
      else
        current+=stepping;
      break;
    case 1:
      if ( current <= 0 )
      {
        mode = 0;
        current+=stepping;
      }
      else
        current-=stepping;
      break;
  }
  for ( int i = 0; i < looping; ++i )
  {
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(current);               // wait for a second
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
    delay(range-current);               // wait for a second
  }
}
