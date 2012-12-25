#include <SDL/SDL.h>

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main() {
	SDL_Surface* screen;
	SDL_Surface* image;
	SDL_Rect src,dest;

	assert (SDL_Init(SDL_INIT_VIDEO) == 0);
	atexit(SDL_Quit);
	
	screen=SDL_SetVideoMode(320,240,16,0);
	image = SDL_LoadBMP("image.bmp");
	assert(image!=NULL);
	src.x=dest.x=0;
	src.y=dest.y=0;
	src.w=dest.w=image->w;
	src.h=dest.h=image->h;

	SDL_BlitSurface(image,&src,screen,&src);

	SDL_UpdateRect(screen,0,0,0,0);

	SDL_Delay(3000);

	SDL_FreeSurface(image);

	return 0;
}
