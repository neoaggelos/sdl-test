#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <assert.h>
SDL_Surface* screen, *text;
TTF_Font* font;

void cleanup() {
	SDL_FreeSurface(text);
	TTF_CloseFont(font);
	TTF_Quit();
	SDL_Quit();
}

SDL_Color color = { 255 ,255,255,0};
SDL_Color bg = {213,42,142,0};

int main() {
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	screen = SDL_SetVideoMode(640,480,0,0);
	font = TTF_OpenFont("font/Verdana.ttf",15);
	text = TTF_RenderText_Shaded(font,"Sample Text",color,bg);
	assert(text && screen && font);
	atexit(cleanup);
	
	SDL_BlitSurface(text,NULL,screen,NULL);
	SDL_Flip(screen);
	SDL_Delay(3000);
	
	return 0;
}
