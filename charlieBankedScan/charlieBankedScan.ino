
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

void loop()
{
  static int p = 0;
  static int c = 5;
  if ( --c == 0 )
  {
    vidmem[p] = vidmem[p] ? 0 : 255;
    ++p;
    if ( p >= LEDCOUNT )
      p = 0;
    c = 50000;
  }

  static int bankSwitch = 1;
  if ( ++bankSwitch > 1000 )
  {
    bankSwitch = 0;
    
    static int iBank = 0;
    if ( ++iBank >= PINCOUNT )
      iBank = 0;

    for( int i=0; i< PINCOUNT; ++i )
      pinMode( pin[i], INPUT );

    pinMode( pin[ iBank ], OUTPUT );
    digitalWrite( pin[ iBank ], LOW );
    
    for( int iSub = 0; iSub < PINCOUNT-1; ++iSub )
    {
      pinMode( pin[ ledH[ banks[iBank][iSub]]], vidmem[ banks[iBank][iSub] ] == 0 ? INPUT : OUTPUT );
      digitalWrite( pin[ ledH[ banks[iBank][iSub]]], HIGH );
    }
  }
}
