#include "Ball.h"

Ball::Ball(const char* file, int r, int c, float x, float y, float w, float h) : TexRect(file, r, c, x, y, w, h) {
	x_speed = -0.001;
	y_speed = 0.0005;
	while (!done()) {
		advance();
	}
	last_score_right = false;
	last_score_left = false;
}

void Ball::move() {
	x += x_speed;
	y += y_speed;
}

void Ball::reset() {
	x = -0.05;
	y = 0.2;
	x_speed = -x_speed;
	y_speed = 0.0005;
}

float Ball::get_left_side() {
	return x;
}
float Ball::get_right_side() {
	return x+w;
}
float Ball::get_top() {
	return y;
}
float Ball::get_bottom() {
	return y-h;
}
float Ball::get_center() {
	return y-(h/2);
}

void Ball::change_x_speed() {
	x_speed = -x_speed;
}
void Ball::change_y_speed() {
	y_speed = -y_speed;
}
void Ball::change_last_score_left() {
	last_score_left = !last_score_left;
}
void Ball::change_last_score_right() {
	last_score_right = !last_score_right;
}
