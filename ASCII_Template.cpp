#include <SDL/SDL.h>        //Include SDL functions and datatypes
#include "def.h"        //Colors
#include "ASCII_Lib.h"  //Drawing functions

//***************************************
// SDL ASCII Template v101125
// Evan Eshelman - ejeshelman@gmail.com
// github.com/hovvit
// Use for anything!
//***************************************

SDL_Event event;
SDL_Surface* screen = NULL;
SDL_Surface* asciiBase = NULL;
SDL_Surface* ascii = NULL;

void loadAscii()
{
    //Load ascii characters
    asciiBase = SDL_LoadBMP( "ascii.bmp" );

    //Create an optimized image
    ascii = SDL_DisplayFormat( asciiBase );

    //Free the old image
    SDL_FreeSurface( asciiBase );

    //Map the color key
    Uint32 colorkey = SDL_MapRGB( ascii->format, 0xFF, 0, 0xFF );

    //Set all pixels of color R 0, G 0xFF, B 0xFF to be transparent
    SDL_SetColorKey( ascii, SDL_SRCCOLORKEY, colorkey );
}


int main( int argc, char* args[] )
{
    //Start SDL
    SDL_Init( SDL_INIT_EVERYTHING );

    //Set up screen
    screen = SDL_SetVideoMode( 800, 480, 32, SDL_SWSURFACE );

    //Load up all the ASCII chrs
    loadAscii();

    //Print a test character - X, Y, chr code, source, destination, color
    drawChr(2, 5, 2, ascii, screen, yellow);

    //Print a test number - X, Y, number, source, destination, color, number of digits (optional)
    int x = 6;
    drawInt(2, 7, x, ascii, screen, white, 3);

    //Print a test string - X, Y, string, source, destination, color
    char* testString = "Hey here is a string";
    drawStr(2, 9, testString, ascii, screen, red);

    bool quit = 0;
    /* Loop until an SDL_QUIT event is found */
    while( !quit )
    {
        /* Poll for events */
        while( SDL_PollEvent( &event ) )
        {
            switch ( event.type )
            {
                /* SDL_QUIT event (window close) */
                case SDL_QUIT:
                   quit = 1;
                   break;

                default:
                   break;
            }
        }

        //Update Screen
        SDL_Flip( screen );
        SDL_Delay( 50 );
    }

    SDL_FreeSurface( ascii );

    //Quit SDL
    SDL_Quit();

    return 0;
}

