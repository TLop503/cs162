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


/**************************************************
 * Name: get_dir
 * Description: gets user input for dir of arrow
 * Parameters: none
 * Pre-conditions: user wants to use arrow
 * Post-conditions: returns cleaned input
 ***********************************************/
	char get_dir();


/**************************************************
 * Name: wumpus move
 * Description: skeleton code function
 * Parameters: none
 * Pre-conditions: since wumpus walks this isn't needed
 * Post-conditions: n/a
 ***********************************************/
	void wumpus_move();


/**************************************************
 * Name: fire_arrow
 * Description: initiates arrow math
 * Parameters: none
 * Pre-conditions: player wants to use arrow
 * Post-conditions: checks each room in arrow path for events, if wumpus, win game
 ***********************************************/
	void fire_arrow();

/**************************************************
 * Name: move_%dir%
 * Description: increments player position by 1 in given direction
 * Parameters: none
 * Pre-conditions: player has called move function with unput
 * Post-conditions: player will be moved, or wall message printed
 ***********************************************/
	void move_up();
	void move_down();
	void move_left();
	void move_right();
	

/**************************************************
 * Name: move
 * Description: calls corresponding move function based on input, and inverts if batted
 * Parameters: direction
 * Pre-conditions: player has input
 * Post-conditions: calls corresponding move function
 ***********************************************/
	void move(char);

/**************************************************
 * Name: get_input()
 * Description: gets user input and verifies it is valid
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: will return valid input wasdf
 ***********************************************/
	char get_input();


/**************************************************
 * Name: play_game
 * Description: main game loop, moves player, checjs for events, moves wumpus, checks for win
 * Parameters: ints for dimensions of board and bool for debug
 * Pre-conditions: player has entered inputs
 * Post-conditions: game ends, leading to destructors
 ***********************************************/
	void play_game(int, int, bool);


/**************************************************
 * Name: get_size
 * Description: asks user for dimensions and debug mode
 * Parameters: PBR ints for dimensions, bool for debug mode
 * Pre-conditions: setup has started
 * Post-conditions: will update vars to choices to be used by play_game
 ***********************************************/
	void get_size(int& x, int& y, bool& debug);


/**************************************************
 * Name: display_events
 * Description: print percepts for neighboring rooms
 * Parameters: none
 * Pre-conditions: grid exists and is of legitimate size
 * Post-conditions: prints percepts for each neighboring room that exists
 ***********************************************/
	void display_events();

/**************************************************
 * Name: populate_events
 * Description: assign each event to a random room
 * Parameters: none
 * Pre-conditions: internally generate randoms to fill seed array
 * Post-conditions: events will have unique non-overlapping positions
 ***********************************************/
	void populate_events();


/**************************************************
 * Name: place player
 * Description: uses BogoPlace (tm) to place player in a random room by
 *  picking ranomd rooms until one that is empty is found
 * Parameters: none
 * Pre-conditions: player exists
 * Post-conditions: player coords will be updated
 ***********************************************/
	void place_player(int xlim, int ylim);


/**************************************************
 * Name: wumpus_walker
 * Description: uses bogowump(tm) to move wumpus to a random room by picking a ranodm neighboring room
 * and checking if it is empty, if not, pick another
 * if wumpus doesn't find an empty room in 4 attempts it gets bored and stays put
 * Parameters: none
 * Pre-conditions: wumpus has a location
 * Post-conditions: wumpus will be moved
 ***********************************************/
	void wumpus_walker();

/**************************************************
 * Name: move_wumpus
 * Description: called by wumpus_walker to move wumpus to a given room by updating coords and event pointers
 * Parameters: char for direction, ints for coords
 * Pre-conditions: valid room is choosen
 * Post-conditions: pointers and coords will be updated
 ***********************************************/
	void move_wumpus(char dir, int x, int y);

};
#endif