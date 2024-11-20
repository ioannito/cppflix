#include "graphics.h"

void App::draw() {

	graphics::Brush br;
	br.fill_color[0] = 0.2f;
	graphics::setWindowBackground(br);
	
	//BACKGROUND INFO

	br.outline_opacity = 0.0f;
	SETCOLOR(br.fill_color, 1.0f, 1.0f, 1.0f);
	graphics::drawRect(CANVAS_WIDTH / 3, CANVAS_HEIGHT, CANVAS_WIDTH, CANVAS_HEIGHT, br);
	graphics::drawRect((2*(CANVAS_WIDTH)/3), CANVAS_HEIGHT, CANVAS_WIDTH, CANVAS_HEIGHT, br);

	//MOVIES 

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			
			Movie* p = new Movie();
			m_movies.push_front(p); //CHECK IF YES OR NO

			p->setPosX();
			p->setPosY();
		}
	}
}

void App::update() {

	processEvent();

	graphics::MouseState mouse;
	graphics::getMouseState(mouse);

	float mousex = graphics::windowToCanvasX(mouse.cur_pos_x);
	float mousey = graphics::windowToCanvasY(mouse.cur_pos_y);

	//HIGHLIGHT MOVIE WHEN USER HOVERS OVER
	
	Movie* cur_movie = nullptr;
	for (auto movie : m_movies) {
		if (movie->contains(mousex, mousey)) {
			movie->setHighlight(true);
			cur_movie = movie;
		}
		else {
			movie->setHighlight(false);
		}
	}



}
