#ifndef ASCII_LIB_H
#define ASCII_LIB_H

// Print an ASCII character
void drawChr(int x, int y, int smiley, SDL_Surface* source, SDL_Surface* destination, Uint32 color);

// Print a string
void drawStr(int x, int y, char stringy[], SDL_Surface* source, SDL_Surface* destination, Uint32 color);

// Print a number
void drawInt(int x, int y, int number, SDL_Surface* source, SDL_Surface* destination, Uint32 color, int size = 0);

#endif
