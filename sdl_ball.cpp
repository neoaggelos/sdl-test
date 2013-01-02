#include <SDL/SDL.h>
#include <cstdlib>
#include <cassert>

SDL_Rect dest;
SDL_Surface* screen;
SDL_Surface* ball;
SDL_Event event;
bool quit = false;
bool doRender = true;
int xvel, yvel;

void end() {
	SDL_FreeSurface(ball);
	SDL_Quit();
}

void render() {
	if (doRender == false)
		return;

	// clear screen
	SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));

	SDL_BlitSurface(ball,NULL,screen,&dest);
	SDL_Flip(screen);
}

void update() {
	static int i = 0;

	++i;


	dest.x += xvel;
	dest.y -= yvel;

	if (dest.x <= 0) {xvel=-xvel ;}
	if (dest.x + dest.w >= screen->w) {xvel=-xvel; }

	if (dest.y + dest.h >= screen->h) yvel=-yvel;
	if (i%3==0) yvel -= 1;

}


int main() {
	SDL_Init(SDL_INIT_VIDEO);


	screen = SDL_SetVideoMode(640,480,0,SDL_HWSURFACE | SDL_DOUBLEBUF);
	ball = SDL_LoadBMP("ball.bmp");
	
	assert(screen&&ball);	
	atexit(end);

	SDL_SetColorKey(ball,SDL_SRCCOLORKEY,SDL_MapRGB(screen->format,255,255,255));

	xvel = 4;
	yvel = 0;

	dest.x = 50;
	dest.y = 60;

	while(!quit) {
		if(SDL_PollEvent(&event) !=0) continue;

		switch(event.type) {
			case SDL_QUIT:
				quit = true;
				break;
		}

		update();
		render();
		SDL_Delay(15);
	}

	return 0;
		
}
		
		
