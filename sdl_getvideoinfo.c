#include <SDL/SDL.h>
#include <stdlib.h>

const SDL_VideoInfo* info = NULL;

int main() {
	SDL_Init(SDL_INIT_VIDEO);
	atexit(SDL_Quit);
	info = SDL_GetVideoInfo();
	
	printf( "\nVideo Information:\n");
	printf( "hw_available? \t%d\n", info->hw_available);
	printf( "wm_available? \t%d\n", info->wm_available);
	printf( "blit_hw? \t%d\n", info->blit_hw);
	printf( "blit_hw_CC? \t%d\n", info->blit_hw_CC);
	printf( "blit_hw_A? \t%d\n", info->blit_hw_A);
	printf( "blit_sw? \t%d\n", info->blit_sw);
	printf( "blit_sw_CC? \t%d\n", info->blit_sw_CC);
	printf( "blit_sw_A? \t%d\n", info->blit_sw_A);
	printf( "blit_fill? \t%d\n", info->blit_fill);
	printf( "video memory(in K)? \t%d\n", info->video_mem);
	
	printf( "bits per pixel? \t%d\n",info->vfmt->BitsPerPixel);

	return 0;
}
