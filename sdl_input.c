#include <SDL/SDL.h>

void PrintKeyInfo ( SDL_KeyboardEvent *key);
void PrintModifiers ( SDLMod mod);

int main() {
	SDL_Event event;
	int quit = 0;

	SDL_Init(SDL_INIT_VIDEO);
	
	SDL_SetVideoMode(320,240, 0 ,0);

	SDL_EnableUNICODE(1);

	while (!quit) {
		while (SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_KEYDOWN:
				case SDL_KEYUP:
					PrintKeyInfo( &event.key);
					break;
				case SDL_QUIT:
					quit = 1;
					
				default: 
					break;
			}
		}
	}
	SDL_Quit();
	return 0;
}

void PrintKeyInfo( SDL_KeyboardEvent *key) {
		if (key->type == SDL_KEYUP) 
			printf("Release:- ");
		else 
			printf("Press:- ");

		// hardware scancode

		printf(", Scancode: 0x%02X", key->keysym.sym);
		printf(", Name: %s", SDL_GetKeyName(key->keysym.sym));

		if (key->type == SDL_KEYDOWN) {
			printf(", Unicode: ");
			if (key->keysym.unicode < 0x80 && (char)key->keysym.unicode > 0) 
				printf("%c (0x04X)",(char)key->keysym.unicode, key->keysym.unicode);
			else 
				printf("? (0x%04X)", key->keysym.unicode);
		}
		printf("\n");
		PrintModifiers( key->keysym.mod);
}

void PrintModifiers( SDLMod mod ){
        printf( "Modifers: " );

        /* If there are none then say so and return */
        if( mod == KMOD_NONE ){
            printf( "None\n" );
            return;
        }

        /* Check for the presence of each SDLMod value */
        /* This looks messy, but there really isn't    */
        /* a clearer way.                              */
        if( mod & KMOD_NUM ) printf( "NUMLOCK " );
        if( mod & KMOD_CAPS ) printf( "CAPSLOCK " );
        if( mod & KMOD_LCTRL ) printf( "LCTRL " );
        if( mod & KMOD_RCTRL ) printf( "RCTRL " );
        if( mod & KMOD_RSHIFT ) printf( "RSHIFT " );
        if( mod & KMOD_LSHIFT ) printf( "LSHIFT " );
        if( mod & KMOD_RALT ) printf( "RALT " );
        if( mod & KMOD_LALT ) printf( "LALT " );
        if( mod & KMOD_CTRL ) printf( "CTRL " );
        if( mod & KMOD_SHIFT ) printf( "SHIFT " );
        if( mod & KMOD_ALT ) printf( "ALT " );
        printf( "\n" );
}
