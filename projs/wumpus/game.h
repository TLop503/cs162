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

/**************************************************
 * Name: default constructor
 * Description: sets player to alive and goldless
 * Parameters: none
 * Pre-conditions: game is initialized
 * Post-conditions: game will be craeted, but not set up yet
 ***********************************************/
	Game();

/**************************************************
 * Name: destructor
 * Description: checks each event in event grid, then deletes it if it exists
 * Parameters: none
 * Pre-conditions: technically none
 * Post-conditions: dynamic memory will be freed
 ***********************************************/
	~Game();
	
/**************************************************
 * Name: set_up
 * Description: given dimensions, set up game vector and populate it with events 
 * Parameters: ints l and w for length and width
 * Pre-conditions: player has entered dimensions
 * Post-conditions: game will be ready to play with events and player in place
 ***********************************************/
	void set_up(int, int);


/**************************************************
 * Name: display_game
 * Description: print the game board, w/ or w/o debug view
 * Parameters: none
 * Pre-conditions: grid is initialized, debug chosen or not
 * Post-conditions: grid will be printed with info to terminal
 ***********************************************/
	void display_game();

/**************************************************
 * Name: check_win
 * Description: just checks if p.win is true
 * Parameters: none
 * Pre-conditions: player exists
 * Post-conditions: game ends if true
 ***********************************************/
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
	void move_wumpus(char dir, int x, int y);

};
#endif