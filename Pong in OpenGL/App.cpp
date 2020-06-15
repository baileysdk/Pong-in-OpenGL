#include "App.h"

static App* activate;

void runtime(int value) {
	activate->game->check_collision();
	activate->game->ai();
	activate->game->move_ball();	
	activate->redraw();
	if (activate->game->check_game_won() != true) {
		glutTimerFunc(500, runtime, value);
	}
}

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
	activate = this;
    mx = 0.0;
    my = 0.0;
	
	game = new Pong();
}

void App::draw() {

    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Set background color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Set Color
    glColor3d(1.0, 1.0, 1.0);
    
    game->draw();
    runtime(0);
    
    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();
}

void App::mouseDown(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
    // Redraw the scene
    redraw();
}

void App::mouseDrag(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
    // Redraw the scene
    redraw();
}

void App::keyPress(unsigned char key) {
    if (key == 27){
        // Exit the app when Esc key is pressed
		delete game;
        exit(0);
    }else {
		game->handle_key(key);
		redraw();
	}
}
