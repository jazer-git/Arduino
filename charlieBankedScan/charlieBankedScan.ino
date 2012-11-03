
#define BANKPERIOD 5000

#define PINCOUNT 4
const int pin[] = { 3, 4, 8, 9 };

#define LEDCOUNT 12
int vidmem[ LEDCOUNT ];

const int banks[][PINCOUNT-1] = {
  { 0, 2, 4 },
  { 1, 6, 8 },
  { 3, 7,10 },
  { 5, 9,11 }
};
const int ledH[] = { 1, 0, 2, 0, 3, 0, 2, 1, 3, 1, 3, 2 };

void setup()
{
  for( int i = 0; i < PINCOUNT; ++i )
    pinMode( pin[i], INPUT );
    
  for( int i = 0; i < LEDCOUNT; ++i )
    vidmem[i] = 0;
}

void outputUpdate()
{
  static unsigned long nextBank = micros();
  if ( micros() > nextBank )
  {
    nextBank += BANKPERIOD;
    
    static int iBank = 0;
    if ( ++iBank >= PINCOUNT )
      iBank = 0;

    for( int i=0; i< PINCOUNT; ++i )
      pinMode( pin[i], INPUT );

    pinMode( pin[ iBank ], OUTPUT );
    digitalWrite( pin[ iBank ], LOW );
    
    for( int iSub = 0; iSub < PINCOUNT-1; ++iSub )
    {
      if ( vidmem[ banks[iBank][iSub] ] != 0 )
      {
        pinMode( pin[ ledH[ banks[iBank][iSub]]], OUTPUT );
        digitalWrite( pin[ ledH[ banks[iBank][iSub]]], HIGH );
      }
    }
  }
}

#define MODECOUNT 1;
void mode00( bool init )
{
  if ( init )
    for( int i = 0; i < LEDCOUNT; ++i )
      vidmem[i] = 0;
    
  static int p = 0;
  static unsigned long nextFrame = millis();
  if ( millis() > nextFrame )
  {
    nextFrame += 200; //   <<<<------   period

    vidmem[p] = vidmem[p] ? 0 : 255;
    ++p;
    if ( p >= LEDCOUNT )
      p = 0;
  }
}

void loop()
{
  outputUpdate();
  
  static int mode = 0;
  static unsigned long nextModeChange = millis();
  bool newMode = false;
  if ( millis() > nextModeChange )
  {
    nextModeChange += 5000;
    ++mode;
    if( MODECOUNT == mode )
      mode = 0;
    newMode = true;
  }
    
  switch( mode )
  {
    case 0:
      mode00( newMode );
      break;
  }  
}
