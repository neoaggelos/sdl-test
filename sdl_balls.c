#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#define IMAGE "ball.bmp"

int main() {
	SDL_Surface* screen, *image;
	SDL_Rect dest;
	SDL_Event event;
	SDL_Init(SDL_INIT_EVERYTHING);
	atexit(SDL_Quit);
	screen = SDL_SetVideoMode(640,480,0,0);
	image = SDL_LoadBMP( IMAGE );

	SDL_SetColorKey(image,SDL_SRCCOLORKEY,SDL_MapRGB(screen->format,255,255,255));

	for (;;) {
		if (SDL_PollEvent(&event)==0) {

			dest.w = image->w;
			dest.h = image->h;

			dest.x = rand() % (640 - image->w);
			dest.y = rand() % (480 - image->h);

			SDL_BlitSurface(image,NULL,screen,&dest);

			SDL_UpdateRect(screen,0,0,0,0);
		} else if (event.type==SDL_QUIT) 
			break;
	
	}

	return 0;
}
	


