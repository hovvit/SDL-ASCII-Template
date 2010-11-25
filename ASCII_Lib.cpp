#include "SDL.h"
#include "def.h"
#include <math.h>

void drawChr(int x, int y, int smiley, SDL_Surface* source, SDL_Surface* destination, Uint32 color)
{
    //Holds offsets
    SDL_Rect offset;
    SDL_Rect clip[1];

    //Get offsets
    offset.x = x*8;
    offset.y = y*12;

    clip[0].x = x*8;
    clip[0].y = y*12;
    clip[0].w = 8;
    clip[0].h = 12;

    //Fill background
    SDL_FillRect( destination, clip, color );

    clip[0].x = ((smiley % 16)) * 8;
    clip[0].y = ((smiley - (clip[ 0 ].x / 8)) / 16 ) * 12;
    clip[0].w = 8;
    clip[0].h = 12;

    //Blit chr
    SDL_BlitSurface( source, clip, destination, &offset );
}



void drawStr(int x, int y, char stringy[], SDL_Surface* source, SDL_Surface* destination, Uint32 color)
{
    int i;
    for ( i = 0; i < strlen(stringy); i++)
    {
        drawChr( x+i, y, stringy[i], source, destination, color);
    }
}

void drawInt(int x, int y, int number, SDL_Surface* source, SDL_Surface* destination, Uint32 color, int size = 0)
{
    // Note that numbers do not erase before redrawing and are left-justified
    // For example, if you print '17', then in the same location print '5',
    // the result will be '57'. To work around this, set the size parameter
    // > 1 and the number will be represented with 'size' digits.

    char buf[size];
    if ( size > 1 )
    {
        int exp = 1;
        for ( int i = 0; i < (size-1); i++ ) { exp = exp*10; }
        number = number + exp;
    }
    itoa(number, buf, 10);
    if ( size > 1 )
    {
        buf[0] = 48;
    }
    drawStr(x, y, buf, source, destination, color);
}


