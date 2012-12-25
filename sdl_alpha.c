#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>

//the image to use
#define IMAGE "ball.bmp"

int main() {
	/* The structures */
	SDL_Surface* screen, *image;
	SDL_Rect dest;
	SDL_Event event;

	/* Initialization */
	SDL_Init(SDL_INIT_EVERYTHING);
	atexit(SDL_Quit);
	screen = SDL_SetVideoMode(640,480,0,0);
	image = SDL_LoadBMP( IMAGE );

	/* Set White as the colorkey (to get rid of the bg) */
	SDL_SetColorKey(image,SDL_SRCCOLORKEY,SDL_MapRGB(screen->format,255,255,255));

	/* Set transparency to 50% *
	 * The 3rd argument is at the range 0-256 *
	 * and sets the transparency */
	SDL_SetAlpha(image,SDL_SRCALPHA,128);
	for (;;) {
		if (SDL_PollEvent(&event)==0) {


			/* show the ball on screen and update it */
			dest.w = image->w;
			dest.h = image->h;

			dest.x = rand() % (640 - image->w);
			dest.y = rand() % (480 - image->h);

			SDL_BlitSurface(image,NULL,screen,&dest);

			SDL_UpdateRect(screen,0,0,0,0);
		/* handle the quit signal */
		} else if (event.type==SDL_QUIT) 
			break;
	
	}
	return 0;
}
	


