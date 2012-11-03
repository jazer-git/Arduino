#define p1 3
#define p2 4
#define p3 8
#define p4 9

#define LEDCOUNT 12
const int ledL[] = { p1, p2, p1, p3, p1, p4, p2, p3, p2, p4, p3, p4 };
const int ledH[] = { p2, p1, p3, p1, p4, p1, p3, p2, p4, p2, p4, p3 };

int mode = 3;

void setup()
{
  pinMode( p1, INPUT );
  pinMode( p2, INPUT );
  pinMode( p3, INPUT );
  pinMode( p4, INPUT );
}

void loop()
{
  switch ( mode )
  {
    case 0:
      scan();
      break;
    case 1:
      pong();
      break;
    case 2:
      picker();
      break;
    case 3:
      slider();
      break;
    default:
      break;
  }
}

void outputSingle( int led, int time )
{
    pinMode( ledH[ led ], OUTPUT );
    digitalWrite( ledH[ led ], HIGH );
    pinMode( ledL[ led ], OUTPUT );
    digitalWrite( ledL[ led ], LOW );
    delay(time);
    pinMode( ledH[ led ], INPUT );
    pinMode( ledL[ led ], INPUT );
}  
  
  
  
void scan()
{
    for ( int iLed = 0; iLed < LEDCOUNT; iLed++ )
  {
    outputSingle( iLed, 25 );
  }
}

void pong()
{
      for ( int iLed = 1; iLed < LEDCOUNT; iLed++ )
  {
    outputSingle( iLed, 30 );
  }
    for ( int iLed = LEDCOUNT-2; iLed >= 0; iLed-- )
  {
    outputSingle( iLed, 30 );
  }
}

void picker()
{
  int r = random( LEDCOUNT );
  outputSingle( r, 60 );
}

void slider()
{
  static int pos = 0;
  pos += random( 3 ) - 1;
  if ( pos < 0 )
    pos = LEDCOUNT + pos;
  else if ( pos >= LEDCOUNT )
    pos = pos - LEDCOUNT;
  outputSingle( pos, 80 );
}
