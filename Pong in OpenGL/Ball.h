#ifndef Ball_hpp
#define Ball_hpp

#include "TexRect.h"

class Ball : public TexRect {

	float x_speed;
	float y_speed;
	bool last_score_left;
	bool last_score_right;
	
public: 

	Ball(const char*, int, int, float, float, float, float);
	
	void move();
	void reset();
	float get_left_side();
	float get_right_side();
	float get_top();
	float get_bottom();
	float get_center();
	void change_x_speed();
	void change_y_speed();
	void change_last_score_left();
	void change_last_score_right();

};

#endif
