#include <SDL/SDL_opengl.h>
#include <SDL/SDL.h>
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

float angle = 1;
float velocity = 1;
SDL_Surface* screen;
float x = 100;

bool renderState = true;

void handleKeys(SDL_Event *event) {

	SDL_Event temp;
	int t;

	if (event->type == SDL_KEYDOWN) {
		switch (event->key.keysym.sym) {
			case SDLK_DOWN:
				if (velocity < 0) {
					velocity = abs(velocity);
					cout << "Rotating Right" << endl;
				}
				break;
			case SDLK_UP:
				if (velocity > 0) {
					velocity = -abs(velocity);
					cout << "Rotating Left " << endl;
				}
				break;
			case SDLK_ESCAPE:
				if (renderState == true){ 
					renderState = false;
					cout << "Stop rendering" << endl;
				}
				else {
					renderState = true;
					cout << "Restart rendering" << endl; 
				}
				break;
		}
		event->type = SDL_KEYUP;
	}
}

void render() {
	if (renderState == false)
		return;

	angle+=velocity;
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(20,0,1,0);
	glRotatef(-angle,1,0,1);


	glBegin(GL_QUADS);
		glColor3f(1,0,0); glVertex2f(0.5,0.5);
		glColor3f(0,1,0); glVertex2f(-0.5,0.5);
		glColor3f(0,0,1); glVertex2f(-0.5,-0.5);
		glColor3f(1,0,1); glVertex2f(0.5,-0.5);
	glEnd();


	glBegin(GL_LINES);
		glColor3f(1,0,0); glVertex2f(-1,0);
		glColor3f(1,0,0); glVertex2f(1,0);
	glEnd();

	glBegin(GL_LINES);
		glColor3f(0,1,0); glVertex2f(0,-1);
		glColor3f(0,1,0); glVertex2f(0,1);
	glEnd();

	glBegin(GL_LINES);
		glColor3f(0,0,1); glVertex3f(0,0,-1);
		glColor3f(0,0,1); glVertex3f(0,0,1);
	glEnd();

	if ((int)angle%360 == 0) SDL_Delay(500);

	SDL_GL_SwapBuffers();
}


void initGL() {
	glMatrixMode(GL_PROJECTION | GL_MODELVIEW);
	glLoadIdentity();

	glClearColor(0,0,0,0.5);

}


void initSDL() {
	SDL_Init(SDL_INIT_VIDEO);
	screen = SDL_SetVideoMode(640,480,0,SDL_OPENGL|SDL_HWSURFACE);
	//screen = SDL_SetVideoMode(640,480,0,SDL_OPENGL);
	atexit(SDL_Quit);
}
	




SDL_Event event;
bool quit;


int main() {
	initSDL();

	initGL();

	while(!quit) {
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT)
			quit = true;
		handleKeys(&event);
		render();
			
	}

	return 0;

}
