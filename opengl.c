#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>

SDL_Surface* screen;

int main() {
	SDL_Init(SDL_INIT_VIDEO);

	
	screen = SDL_SetVideoMode(640,480,0,SDL_OPENGL);
	glMatrixMode(GL_PROJECTION | GL_MODELVIEW);
	glLoadIdentity();
	glClearColor(0,0,0,1);
	glClear( GL_COLOR_BUFFER_BIT );
	glColor3f(1,0,0);
	glBegin ( GL_QUADS );
		glVertex2f(0.5, 0.5);
		glVertex2f(0.5, -0.5);
		glVertex2f(-0.5,-0.5);
		glVertex2f(-0.5,0.5);
	glEnd();
	glFlush();

	SDL_GL_SwapBuffers();

	SDL_Delay(3000);
	SDL_Quit();
}


	
