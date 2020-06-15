#ifndef Paddle_hpp
#define Paddle_hpp

#include "TexRect.h"

class Paddle : public TexRect {
	
	float inc_speed;
	float inc_speed_ai;
	bool player;
	
public:

	Paddle(const char*, int, int, float, float, float, float);
	
	void move(int);
	float get_left_side();
	float get_right_side();
	float get_top();
	float get_bottom();
	float get_center();
	void reset_left();
	void reset_right();
	void set_ai();
	
};

#endif
