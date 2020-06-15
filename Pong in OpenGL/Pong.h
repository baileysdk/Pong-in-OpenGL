#ifndef Pong_hpp
#define Pong_hpp

#include "TexRect.h"
#include "Paddle.h"
#include "Ball.h"

#include <vector>

using namespace std;

class Pong {

	Paddle* Rpad;
	Paddle* Lpad;
	Ball* ball;
	TexRect* background;
	TexRect* pause;
	vector<TexRect*> Lscore;
	vector<TexRect*> Rscore;
	TexRect* left_victory;
	TexRect* right_victory;
	int left_score;
	int right_score;
	bool left_won;
	bool right_won;
	bool pause_state;
	
public:
	Pong();
	
	void incLscore();
	void incRscore();
	void handle_key(unsigned char);
	void draw();
	void draw_pause();
	void move_ball();
	void ai();
	void check_collision();
	void check_score();
	void reset_game();
	bool check_game_won();
	
	~Pong();
};

#endif
