#include "graphics.h"

void draw() {
	
	App* myapp = App::getInstance();

	myapp->draw();
}

void update(float ms) {

	App* myapp = App::getInstance();

	myapp->update();
}

int main(int argc, char** argv) {
	
	graphics::createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "CppFlix");

	App* app = App::getInstance();

	graphics::setCanvasSize(CANVAS_WIDTH, CANVAS_HEIGHT);
	graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

	graphics::setDrawFunction(draw);
	graphics::setUpdateFunction(update);

	graphics::startMessageLoop();

	return 0;
}
