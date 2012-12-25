#include <SDL/SDL.h>
#include <assert.h>
#include <stdlib.h>

int main() {
	SDL_Surface *screen=NULL, *bmp = NULL;
	SDL_Event event;
	SDL_Rect src,dest;
	int i=0;
	SDL_Init(SDL_INIT_VIDEO);

	screen = SDL_SetVideoMode(640,480, 0, SDL_ANYFORMAT);
	bmp = SDL_LoadBMP("image.bmp");
	assert(bmp && screen);
	src.w = src.w = bmp->w;
	dest.h = dest.h = bmp->h;
	src.x = src.y = 0;
	for (;;) {
		if (SDL_PollEvent(&event)==0) {
			dest.x = rand() % (640-dest.w);
			dest.y = rand() % (480-dest.h);
			SDL_BlitSurface(bmp,&src,screen,&dest);
			SDL_UpdateRect(screen,0,0,0,0);
			printf("Time: %d\n, %d %d",++i,dest.x,dest.y);
			SDL_Delay(500);
		}
		else if (event.type==SDL_QUIT)
			break;
	}
	return 0;
}
			

