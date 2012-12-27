#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <assert.h>
#include <stdlib.h>

SDL_Surface* screen,*sprite, *text;
int quit = 0;
SDL_Rect frame,dest;
TTF_Font* font;
SDL_Color color = {255, 255, 255, 0};

void apply_surface(int x, int y, SDL_Surface* src, SDL_Surface* dest) {
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = text->w;
	rect.h = text->h;

	SDL_BlitSurface(src, NULL, dest, &rect);
}


void render() {
	SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));
	apply_surface((screen->w - text->w) /2 , 50, text, screen);
	SDL_BlitSurface(sprite,&frame,screen,&dest);
	SDL_Flip(screen);
	SDL_Delay(100);
}

int main() {
	SDL_Init(SDL_INIT_VIDEO);
	int i = 0;
	TTF_Init();
	screen = SDL_SetVideoMode(640,480,0,0);
	sprite = SDL_LoadBMP("data.bmp");
	SDL_SetColorKey(sprite,SDL_SRCCOLORKEY,SDL_MapRGB(screen->format,0,0,255));
	atexit(SDL_Quit);
	font = TTF_OpenFont("font.ttf",72);
	text = TTF_RenderText_Solid(font,"MOON WALK!!!",color); 
	assert(screen && sprite && font && text);
	SDL_Delay(1000);
	dest.w = frame.w = sprite->w / 4;
	dest.h = frame.h = sprite->h;
	frame.y = 0;
	dest.y = screen->h - sprite->h;
	dest.x = 0;
	for (;;i++) {
		frame.x = 64 * (i % 4);
		dest.x+= 10;
		if (dest.x > screen->w - sprite->w / 4 ) 
			goto end;
		render();	
	}
	end:
	TTF_CloseFont(font);
	SDL_FreeSurface(text);
	SDL_FreeSurface (sprite);
	SDL_Delay(1000);

	return 0;
}
