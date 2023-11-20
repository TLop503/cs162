#ifndef GAME_H
#define GAME_H 

#include <vector>
#include <iostream> 

#include "room.h"
#include "player.h"

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

	int xseed[6]; //array of ints used for rand
	int yseed[6];

	int num_events = 6;
	Event* events[7];// = {nullptr, nullptr, nullptr, nullptr, nullptr};

	Player p;

public:

	//suggested functions:
	Game();
	~Game();
	
	void set_up(int, int);

	void display_game();

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

	void display_events();
	void populate_events();
	void place_player(int xlim, int ylim);

	void wumpus_walker();

};
#endif