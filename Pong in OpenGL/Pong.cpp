#include "Pong.h"

#include <vector>

using namespace std;

Pong::Pong() {
	Rpad = new Paddle("Pad.bmp",1,1,0.925,0.35,0.075,0.3);
	Lpad = new Paddle("Pad.bmp",1,1,-1.0,0.35,0.075,0.3);
	ball = new Ball("Ball.bmp",3,3,-0.05,0.2,0.1,0.1);
	background = new TexRect("Back.bmp",1,1,-1.0,1.0,2.0,2.0);
	pause = new TexRect("Pause.bmp",1,1,-0.3,0.3,0.6,0.6);
	left_victory = new TexRect("Left.bmp",1,1,-0.3,0.3,0.6,0.6);
	right_victory = new TexRect("Right.bmp",1,1,-0.3,0.3,0.6,0.6);
	
	left_score = right_score = 0;
	
	left_won = false;
	right_won = false;
	pause_state = false;

	Rpad->set_ai();
}
	
void Pong::incLscore() {
	left_score++;
	Lscore.push_back(new TexRect("Ball.bmp",3,3,(-1.0 + 0.2*(left_score-1)),-0.85,0.2,0.2));
	if (left_score == 5) {
		left_won = true;
	}
}
void Pong::incRscore() {
	right_score++;
	Rscore.push_back(new TexRect("Ball.bmp",3,3,(0.8 - 0.2*(right_score-1)),-0.85,0.2,0.2));
	if (right_score == 5) {
		right_won = true;
	}
}

void Pong::handle_key(unsigned char key) {
	if (key == (unsigned char)(32)) { // " "
		pause_state = !pause_state;
	}else if (key == (unsigned char)(96)) { // "`"
		reset_game();
	}else if (key == (unsigned char)(119)) { // "w"
		if (Lpad->get_top() < 1.0) {
			Lpad->move(1);
		}
	}else if (key == (unsigned char)(115)) { // "s"
		if (Lpad->get_bottom() > -0.85) {
			Lpad->move(-1);
		}
	}
}

void Pong::draw() {
	if (pause_state == true) {
		pause->draw();
		background->draw();
	}else if (left_won == true) {
		left_victory->draw();
		background->draw();
	}else if (right_won == true) {
		right_victory->draw();
		background->draw();
	}else {
		Rpad->draw();
		Lpad->draw();
		ball->draw();
		
		for (int i = 0; i < Lscore.size(); i++) {
			int j = 0;
			while (j < i) {
				Lscore[i]->advance();
				j++;
			}
			Lscore[i]->draw();
		}
		for (int i = 0; i < Rscore.size(); i++) {
			int j = 0;
			while (j < i) {
				Rscore[i]->advance();
				j++;
			}
			Rscore[i]->draw();
		}
		
		background->draw();
	}
}

void Pong::move_ball() {
	check_score();
	check_collision();
	if (pause_state == false) {
		ball->move();
	}
	if (ball->get_top() >  1.0 || ball->get_bottom() < -0.85) {
		ball->change_y_speed();
	}
}

void Pong::ai() {
	check_collision();
	if (Rpad->get_top() < 1) {
		if (Rpad->get_center() < ball->get_center()) {
			Rpad->move(1);
		}
	}
	if (Rpad->get_bottom() > -0.85) {
		if (Rpad->get_center() > ball->get_center()) {
			Rpad->move(-1);
		}
	}
}

void Pong::check_collision() {
	if (ball->get_right_side() > 0.925) {
		if (ball->get_bottom() < Rpad->get_top() && ball->get_top() > Rpad->get_bottom()) {
			ball->change_x_speed();
		}

	}
	if (ball->get_left_side() < -0.925) {
		if (ball->get_bottom() < Lpad->get_top() && ball->get_top() > Lpad->get_bottom()) {
			ball->change_x_speed();
		}
	}
}
void Pong::check_score() {
	if (ball->get_left_side() < -1.0) {
		incRscore();
		ball->change_last_score_right();
		ball->reset();
		ball->change_last_score_right();
	}
	if (ball->get_right_side() > 1.0) {
		incLscore();
		ball->change_last_score_left();
		ball->reset();
		ball->change_last_score_left();
	}
}

bool Pong::check_game_won() {
	if (left_won || right_won) {
		return true;
	}else {
		return false;
	}
}

void Pong::reset_game() {
	ball->reset();
	Lpad->reset_left();
	Rpad->reset_right();
	Lscore.clear();
	left_score = 0;
	Rscore.clear();
	right_score = 0;
	left_won = false;
	right_won = false;
	draw();
}
	
Pong::~Pong() {
	delete Rpad;
	delete Lpad;
	delete ball;
	delete background;
	delete pause;
	
	for (vector<TexRect*>::iterator i = Lscore.begin(); i != Lscore.end(); i++) {
		delete *i;
	}
	for (vector<TexRect*>::iterator i = Rscore.begin(); i != Rscore.end(); i++) {
		delete *i;
	}
}
