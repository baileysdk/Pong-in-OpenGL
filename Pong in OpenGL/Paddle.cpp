#include "Paddle.h"

Paddle::Paddle(const char* file, int r, int c, float x, float y, float w, float h) : TexRect(file, r, c, x, y, w, h) {
	inc_speed = 0.03;
	inc_speed_ai = 0.005;
	player = true;
}

void Paddle::move(int up_down) {
	if (player == true) {
		if (up_down == 1) {
			y += inc_speed;
		}else if (up_down == -1) {
			y -= inc_speed;
		}
	} else {
		if (up_down == 1) {
			y += inc_speed_ai;
		}else if (up_down == -1) {
			y -= inc_speed_ai;
		}
	}
}

float Paddle::get_left_side() {
	return x;
}
float Paddle::get_right_side() {
	return x+w;
}
float Paddle::get_top() {
	return y;
}
float Paddle::get_bottom() {
	return y-h;
}
float Paddle::get_center() {
	return y-(h/2);
}

void Paddle::reset_left() {
	x = -1.0;
	y = 0.35;
}
void Paddle::reset_right() {
	x = 0.925;
	y = 0.35;
}

void Paddle::set_ai() {
	player = false;
}
