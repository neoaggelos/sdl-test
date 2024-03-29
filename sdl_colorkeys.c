/* Example of blitting with colorkeys in SDL. */
#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
SDL_Surface *screen;
SDL_Surface *background;
SDL_Surface *image;
SDL_Rect src, dest;
Uint32 colorkey;
/* Initialize SDL’s video system and check for errors. */
if (SDL_Init(SDL_INIT_VIDEO) != 0) {
printf("Unable to initialize SDL: %s\n", SDL_GetError());
return 1;
}
/* Make sure SDL_Quit gets called when the program exits! */
atexit(SDL_Quit);
/* Attempt to set a 640x480 hicolor (16-bit) video mode. */
screen = SDL_SetVideoMode(640, 480, 16, 0);
if (screen == NULL) {
printf("Unable to set video mode: %s\n", SDL_GetError());
return 1;
}
/* Load the bitmap files. */
//background = SDL_LoadBMP("background.bmp");
//if (background == NULL) {
//printf("Unable to load bitmap.\n");
//return 1;
//}
image = SDL_LoadBMP("image.bmp");
if (image == NULL) {
printf("Unable to load bitmap.\n");
return 1;
}
/* Draw the background. 
src.x = 0;
src.y = 0;
src.w = background->w;
src.h = background->h;
dest.x = 0;
dest.y = 0;
dest.w = background->w;
dest.h = background->h;
SDL_BlitSurface(background, &src, screen, &dest);
/* Draw the penguin without a colorkey. */
src.x = 0;
src.y = 0;
src.w = image->w;
src.h = image->h;
dest.x = 30;
dest.y = 90;
dest.w = image->w;
dest.h = image->h;
SDL_BlitSurface(image, &src, screen, &dest);
/* The penguin is stored on a blue background. We
can use the SDL_MapRGB function to obtain the
correct pixel value for pure blue. */
colorkey = SDL_MapRGB(image->format, 0, 255, 0);
/* We’ll now enable this surface’s colorkey and draw
it again. To turn off the colorkey again, we would
replace the SDL_SRCCOLORKEY flag with zero. */
SDL_SetColorKey(image, SDL_SRCCOLORKEY, colorkey);
src.x = 0;
src.y = 0;
src.w = image->w;
src.h = image->h;
dest.x = screen->w - image->w ;
dest.y = 0;
dest.w = image->w;
dest.h = image->h;
SDL_BlitSurface(image, &src, screen, &dest);
/* Ask SDL to update the entire screen. */
SDL_UpdateRect(screen, 0, 0, 0, 0);
/* Pause for a few seconds as the viewer gasps in awe. */
SDL_Delay(10000);
/* Free the memory that was allocated to the bitmaps. */
SDL_FreeSurface(background);
SDL_FreeSurface(image);
return 0;
}
