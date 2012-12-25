#include <SDL/SDL.h>
#include <assert.h>
#include <string.h>

SDL_Surface* screen;
SDL_Surface* line;
SDL_Surface* ball;
SDL_Event event;
SDL_Rect dest;
SDL_Rect des;
int row;
int column;
int quit = 0;


int main() {
	SDL_Init(SDL_INIT_VIDEO);
	atexit(SDL_Quit);

	system("clear");
	screen = SDL_SetVideoMode(640,480,0,0);
	ball = SDL_LoadBMP("ball.bmp");
	line = SDL_LoadBMP("line.bmp");
	assert(screen && ball && line);

	SDL_SetColorKey(ball,SDL_SRCCOLORKEY,SDL_MapRGB(screen->format,255,255,255));

	SDL_WM_SetCaption("Don't hit the wall","Don't hit the wall");

	des.x = 600;
	des.y =   0;
	des.w = line->w;
	des.h = line->h;

	SDL_BlitSurface(line,NULL,screen,&des);

	dest.x=20;
	dest.y=320;
	dest.w=ball->w;
	dest.h=ball->h;

	SDL_BlitSurface(ball,NULL,screen,&dest);
	SDL_Flip(screen);

	while(!quit) {
		SDL_PollEvent(&event);
		switch(event.type) {
			case SDL_KEYDOWN:
				if (!strcmp(SDL_GetKeyName(event.key.keysym.sym),"up")) {
					dest.y-=10;
				}
				if (!strcmp(SDL_GetKeyName(event.key.keysym.sym),"down")) {
					dest.y+=10;
				}
				if (!strcmp(SDL_GetKeyName(event.key.keysym.sym),"left")) {
					dest.x-=10;
				}
				if (!strcmp(SDL_GetKeyName(event.key.keysym.sym),"right")) {
					dest.x+=10;
				}
				break;

			case SDL_QUIT:
				quit=1;
			default:
				break;
		}
		dest.y+=rand() % 10;
		dest.y-=rand() % 10;
		dest.x+=rand() % 10;
		dest.x-=rand() % 10;

		if (dest.x>=540) {
			printf("Ouch, you hit the wall!!!\n");
			SDL_Delay(1000);
			quit=1;
		}
//		SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));
//		SDL_BlitSurface(line,NULL,screen,&des);
		SDL_BlitSurface(ball,NULL,screen,&dest);
		SDL_Flip(screen);
	}
	SDL_FreeSurface(ball);
		
	return 0;
}
