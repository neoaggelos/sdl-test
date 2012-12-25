#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	SDL_Surface *screen;

	// Initialize video system

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		printf("Unable to initialize SDL: %s\n",SDL_GetError());
		return 1;
	}

	atexit(SDL_Quit);
	
	screen = SDL_SetVideoMode(640,480,16,SDL_DOUBLEBUF);
	if (screen == NULL) {
		printf("Unable to set video mode: %s\n", SDL_GetError());
		return 1;
	}
	printf("Success!\n");
	return 0;
}
