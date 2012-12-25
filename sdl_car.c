#include <SDL/SDL.h>
#include <assert.h>
#include <stdlib.h>

int SDL_Clear(SDL_Surface *surface);


SDL_Event event;
SDL_Surface* screen;
SDL_Surface* car;
SDL_Rect rect,rect2;
int velocity = 1, quit = 0;
SDL_Rect r = {0,0,800,589};


int main() {
	int i = 10;
/* Initialization */
	SDL_Init(SDL_INIT_VIDEO);
	screen = SDL_SetVideoMode(800,600,0,0);
	car    = SDL_LoadBMP("car.bmp");
	assert (screen && car);
	atexit(SDL_Quit);
/* Draw the "road" */
	rect.y=590;
	rect.w=50;
	rect.h=1;
	for (i = 0 ; i < 800 ; i+=75) {
		rect.x = i;
		SDL_FillRect(screen,&rect,SDL_MapRGB(screen->format,255,255,255));
	}
	SDL_Flip(screen);
/* Draw the "car" */

	SDL_SetColorKey(car,SDL_SRCCOLORKEY,SDL_MapRGB(screen->format,255,255,255));
	rect.x = 20;
	rect2.y = rect.y = 590 - car->h;

	rect.w = car->w;
	rect2.h = rect.h = car->h;

	SDL_BlitSurface(car,NULL,screen,&rect);

	SDL_Flip(screen);

	printf("%d\n", car->w);
	
	while (!quit) {
		//if (SDL_PollEvent(&event) != 0) continue;
		SDL_PollEvent(&event);
		switch (event.type) {
			case SDL_QUIT:
				quit =1;
				break;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_RIGHT){
					velocity += 1;
				}
				if (event.key.keysym.sym == SDLK_LEFT) {
					velocity -= 1;
				}
				if (event.key.keysym.sym == SDLK_UP) {
					velocity += 10;
				}
				if (event.key.keysym.sym == SDLK_DOWN) {
					velocity -= 10;
				}
				SDL_Delay(10);
				break;
			default:
				break;
		}
		
		SDL_FillRect(screen,&r,SDL_MapRGB(screen->format,0,0,0));
		rect.x+=velocity;
		
		if (rect.x <= 0) {
			rect.x = 800; 
		}
		else if (rect.x >= 800) {
			rect.x = -rect.w;
		}

		SDL_BlitSurface(car,NULL,screen,&rect);
		SDL_Flip(screen);
	}

	SDL_FreeSurface(car);
	return 0;

}
