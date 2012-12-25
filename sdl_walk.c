#include <SDL/SDL.h>
#include <assert.h>
#include <stdlib.h>

SDL_Surface* screen,*sprite;
int quit = 0;
SDL_Rect frame,dest;

void render() {
	SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));
	SDL_BlitSurface(sprite,&frame,screen,&dest);
	SDL_Flip(screen);
	SDL_Delay(90);
}

int main() {
	SDL_Init(SDL_INIT_VIDEO);
	int i = 0;
	screen = SDL_SetVideoMode(640,480,0,0);
	sprite = SDL_LoadBMP("data.bmp");
	SDL_SetColorKey(sprite,SDL_SRCCOLORKEY,SDL_MapRGB(screen->format,0,0,255));
	atexit(SDL_Quit);
	dest.w = frame.w = sprite->w / 4;
	dest.h = frame.h = sprite->h;
	frame.y = 0;
	dest.y = screen->h - sprite->h;
	dest.x = screen->w - sprite->w / 4;
	for (;;i++) {
		frame.x = 64 * (i % 4);
		dest.x-= 10;
		if (dest.x <= 0) 
			goto end;
		render();	
	}
	end:
	SDL_FreeSurface (sprite);
	SDL_Delay(1000);

	return 0;
}
