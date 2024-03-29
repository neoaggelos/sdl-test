#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>

Uint16 CreateHicolorPixel(SDL_PixelFormat* fmt, Uint8 red, Uint8 green,
				Uint8 blue) {
	Uint16 value;

	value = ((red >> fmt->Rloss) << fmt->Rshift) +
		((green >> fmt->Gloss) << fmt->Gshift) +
		((blue >> fmt->Bloss) << fmt->Bshift);

	return value;
}

int main() {
	SDL_Surface* screen;
	Uint16 *raw_pixels,pixel_color;
	int x,y,offset;
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		printf("Unable to initialize SDL: %s\n",SDL_GetError());
		return 1;
	}

	screen = SDL_SetVideoMode(256,256,16,0);
	if (screen == NULL) {
		printf("Unable to set video mode: %s\n",SDL_GetError());
		return 1;
	}

	SDL_LockSurface(screen);

	raw_pixels = (Uint16*) screen->pixels;

	for (x=0;x<256;x++) {
		for (y=0;y<256;y++) {
			offset = (screen->pitch /2 * y + x);
			pixel_color = CreateHicolorPixel(screen->format,x,0,y);
			raw_pixels[offset] = pixel_color;	
		}
	}
	
	SDL_UnlockSurface(screen);
	
	SDL_UpdateRect(screen,0,0,0,0);
	SDL_Delay(3000);
	
	return 0;
}
	
