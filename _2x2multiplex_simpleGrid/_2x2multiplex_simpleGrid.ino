const int pinRow[] = { 8, 9, -1 };
const int pinCol[] = { 3, 4, -1 };

const int ledRow[] = { 0, 1, 0, 1 };
const int ledCol[] = { 0, 0, 1, 1 };

in

void setup()
{
  for ( int i = 0; pinRow[i] >= 0; i++ )
    pinMode( pinRow[i], OUTPUT );
  for ( int i = 0; pinCol[i] >= 0; i++ )
    pinMode( pinCol[i], OUTPUT );
}

void loop()
{
  scan();
}

void scan()
{
  for ( int iLed = 0; iLed < 4; iLed++ )
  {
    digitalWrite( pinRow[ ledRow[ iLed ]], HIGH );
    digitalWrite( pinCol[ ledCol[ iLed ]], LOW );
    delay(500);
    digitalWrite( pinRow[ ledRow[ iLed ]], LOW );
    digitalWrite( pinCol[ ledCol[ iLed ]], HIGH );
  }
}

