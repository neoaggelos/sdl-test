#include <SDL/SDL.h>
#include <assert.h>
#include <stdlib.h>

int main() {
	const int SCREEN_WIDTH=640;
	const int SCREEN_HEIGHT=480;

	SDL_Surface* screen = NULL;
	SDL_Event event;
	SDL_Rect rect;

	Uint8 red,green,blue;
	Uint32 color;

	SDL_Init(SDL_INIT_VIDEO);
	atexit(SDL_Quit);

	screen = SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,0,SDL_ANYFORMAT);
	assert(screen!=NULL);
	for (;;) {
		if (SDL_PollEvent(&event)==0) {
		red = rand()%256;
		green = rand()%256;
		blue = rand()%256;
		color = SDL_MapRGB(screen->format, red,green,blue);
		rect.x=rand()%SCREEN_WIDTH;
		rect.y=rand()%SCREEN_HEIGHT;
		rect.w=rand()%(SCREEN_WIDTH-rect.x);
		rect.h=rand()%(SCREEN_HEIGHT-rect.y);
		SDL_FillRect(screen,&rect,color);
		SDL_UpdateRect(screen,0,0,0,0);
		}
		else {
			if (event.type==SDL_QUIT) break;
		}
	}	
	SDL_Delay(3000);
}
