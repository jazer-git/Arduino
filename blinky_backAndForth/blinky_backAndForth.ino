const int ledPins[] = { 9, 10, 11, 3, 5, 6 };
#define LEDCOUNT 6
int ledVals[ LEDCOUNT ];

int sleepCount = 0;
int target = 0;
int dir = 1;

void setup()
{
  for ( int i = 0; i < LEDCOUNT; ++i )
    ledVals[ i ] = 0;
}

void loop()
{
  for ( int i = 0; i < LEDCOUNT; ++i )
  {
    if ( ledVals[i] != 0 )
    {
      ledVals[i] -= ledVals[i] / 8 + 1;
      if ( ledVals[i] < 0 )
         ledVals[i] = 0;
    } 
//    ledVals[i] = ledVals[i] < 11 ? 0 : ledVals[i] - 10;
  }


  if ( ++sleepCount > 10 )
  {
    sleepCount = 0;
    target += dir;
    if ( target < 0 || target >= LEDCOUNT )
    {
      dir = 0-dir;
      target += 2*dir;
    }
//    target = target == LEDCOUNT-1 ? 0 : target+1;
    
    ledVals[target] = 255;
  }
//  ledVals[target] = 25 * sleepCount;
  
    for ( int led = 0; led < LEDCOUNT; led++ )
      analogWrite(ledPins[led], ledVals[led] );         

    delay(10);                            
}

