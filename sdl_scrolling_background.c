#include <SDL/SDL.h>
#include <stdlib.h>
#include <assert.h>

SDL_Surface* screen, *image;
SDL_Rect area,dest;
SDL_Event event;
int quit = 0;



int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	atexit(SDL_Quit);
	screen = SDL_SetVideoMode(640,480,24,0);
	image = SDL_LoadBMP("wide.bmp");
	assert ( screen && image );

	dest.x = 0;
	dest.y = 0;
	dest.w = 640;
	dest.h = 480;
	area.x = 0;
	area.y = 0;
	area.w = 640;
	area.h = 480;

	while (!quit) {
		SDL_PollEvent(&event);

		switch(event.type) {
			case SDL_QUIT:
				quit = 1;
				break;
		}

		SDL_BlitSurface(image, &area, screen, &dest);

		SDL_UpdateRect(screen,0,0,0,0);

		area.x += 10;
		printf("Clip area: %d %d %d %d\n", area.x, area.y, area.w, area.h);
		if (area.x + screen->w > image->w) area.x = 0;
	}

	SDL_FreeSurface(image);
	return 0;
}

