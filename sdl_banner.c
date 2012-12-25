#include <SDL/SDL.h>
#include <assert.h>
#include <stdlib.h>


SDL_Surface* screen, *ball;
SDL_Rect dest;
SDL_Event event;

int xvel, yvel, quit=0;

void draw_screen() {
	SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format, 80,80,80));

	SDL_BlitSurface(ball, NULL, screen, &dest);

	SDL_Flip(screen);
}



int main() {
	SDL_Init(SDL_INIT_VIDEO);
	atexit(SDL_Quit);
	screen = SDL_SetVideoMode(1000,600,0,0);
	ball = SDL_LoadBMP("ball.bmp");
	assert(screen && ball);
	xvel = yvel = 5;

	SDL_SetColorKey(ball, SDL_SRCCOLORKEY, SDL_MapRGB(screen->format,255,255,255));

	while(!quit) {
		if (SDL_PollEvent(&event) != 0) continue;
		if (event.type == SDL_QUIT) 
			quit = 1;
		else if (event.type == SDL_KEYDOWN)
			if (event.key.keysym.sym == SDLK_ESCAPE)
				quit = 1;
		if ( ( xvel == 5 ) && ( dest.x >= screen->w - dest.w ) )
			xvel = -5;
		if ( ( yvel == 5 ) && ( dest.y >= screen->h - dest.h ) )
			yvel = -5;
		if ( ( xvel == -5 ) && ( dest.x <= 0 ) ) 
			xvel = 5;
		if ( ( yvel == -5 ) && ( dest.y <= 0 ) ) 
			yvel = 5;

		dest.x += xvel;
		dest.y += yvel;
		draw_screen();
	}

	SDL_FreeSurface(ball);
	return 0;
}
