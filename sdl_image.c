#include <SDL/SDL.h>

#include <stdio.h>
#include <stdlib.h> //for atexit()
#include <assert.h> // for assert()

/*****************************************************

	display_image.c: 
	Show an image at a windowed view

*****************************************************/

int main(int argc,char ** argv) {
	// Declare the variables
	SDL_Surface *screen,*image;
	SDL_Rect src,dest;
	int ret;
	char* file;               // the filename of the image
 
	// If the file is specified as an argument, use it
	// The default name is "image.bmp"
	file = "image.bmp";
	if (argc>1) 
		file = argv[1];
	
	printf("Using the file %s\n",file);

	// Initialize SDL Video Mode
	ret = SDL_Init(SDL_INIT_VIDEO);
	assert(ret==0);

	//Assure that SDL_Quit() is called
	atexit(SDL_Quit);

	// Set up a 640x480 windowed video mode
	screen=SDL_SetVideoMode(640,480,16,0);

	// Load up the image
	image = SDL_LoadBMP(file);
	assert(image && screen);	

	//Calculate the data to be displayed
	src.x=src.y=dest.x=dest.y=0;
	src.h=dest.h=image->h;
	src.w=dest.w=image->w;

	// Reset the resolution depending on the image size
	// If it's impossible, reset to 640x480
	screen=SDL_SetVideoMode(image->w,image->h,16,0);
	if (screen==NULL) {
		screen=SDL_SetVideoMode(640,480,16,0);
	}

	// Copy the image on the screen buffer
	SDL_BlitSurface(image,&src,screen,&dest);

	//Update the screen
	SDL_UpdateRect(screen,0,0,0,0);
	
	//Wait for 3sec
	SDL_Delay(3000);

	//Free up the memory used by image
	SDL_FreeSurface(image);

	//Exit
	return 0;
}
