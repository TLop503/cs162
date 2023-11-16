#ifndef GAME_H
#define GAME_H 

#include <vector>
#include <iostream> 
#include "room.h"

using namespace std;

//Game interface 
class Game
{
private:
	
	//declare a 2D vector of Room objects:

	//other member variables:
	int length; 			//length of the board
	int width;  			//width of the board
	int num_arrows; 		//keep track of number of errors remaining
	bool debug_view;		//debug mode or not
	vector<vector<Room>> grid;

	int xseed[5]; //array of ints used for rand
	int yseed[5];

	Event* events[5];// = {nullptr, nullptr, nullptr, nullptr, nullptr};

public:

	//suggested functions:
	Game();
	~Game();
	
	void set_up(int, int);

	void display_game() const;

	bool check_win() const;

	char get_dir();
	void wumpus_move();
	void fire_arrow();

	void move_up();
	void move_down();
	void move_left();
	void move_right();
	void move(char);

	char get_input();

	void play_game(int, int, bool);

	//feel free (and you will need) to add more functions...
	void get_size(int& x, int& y, bool& debug);



};
#endif