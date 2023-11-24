#include "game.h"
#include "gold.h"
#include "stalactites.h"
#include "bats.h"
#include "wumpus.h"
#include "player.h"
#include "room.h"
#include "rope.h"

#include <iostream>


using namespace std;

//Game Implementation
Game::Game(){
	//Game constructor
	//Your code here:
	//reassert, just in case
	p.is_alive = true;
	p.has_gold = false;
}


Game::~Game(){
	//Game destructor
	//Your code here:
	for (int i = 0; i < num_events + 1; i++) {
		if (events[i] != nullptr) {
			delete events[i];
		}
	}

}


//helper function for set_up()
/**************************************************
 * Name: unique_rands
 * Description: fill arrays with unique random numbers via very inefficient method
 * 	but it works and it's only 6 numbers
 * Parameters: arrays of ints x and y to fill, and ints xlim and ylim for max values
 * Pre-conditions: arrays exist and are empty
 * Post-conditions: arrays will be filled with unique random numbers. note unique refers to the pairs, not the numbers.
 ***********************************************/
void unique_rands(int (&x)[6], int (&y)[6], int xlim, int ylim) {
	srand(time(NULL));
	//setup initial index
	x[0] = rand() % xlim;
	y[0] = rand() % ylim;

	//cout << x[0] << ", " << y[0] << endl;

	//for remaining indexes
	for (int i = 1; i < 6; i++){
		bool valid = false;
		do {
			valid = true;

			//generate more coords
			x[i] = rand() % xlim;
			y[i] = rand() % ylim;

			//cout << x[i] << ", " << y[i] << endl;


			//and iterate through rest of array to make sure it isn't a dupe
			for (int j = (i - 1); j >=0; j--) {
				if (x[i] == x[j] && y[i] == y[j]) {
					valid = false;
				}
			}
		} while (!valid);
	}

	// cout << "DEBUG: " << endl;
	// for (int i = 0; i < 5; i++) {
	// 	cout << x[i] << ", " << y[i] << endl;
	// }
}


void Game::populate_events() {
	for (int i = 0; i < num_events; i++) {
		//ith event has coords xseed and yseed
		grid[xseed[i]][yseed[i]].set_event(events[i]);
	}
}


void Game::place_player(int xlim, int ylim) {
	do {
		p.x_location = rand() % xlim;
		p.y_location = rand() % ylim;
	} while (grid[p.x_location][p.y_location].get_event() != nullptr);

	events[6] = new Rope(p.x_location, p.y_location);
	grid[p.x_location][p.y_location].set_event(events[6]);
}


//slightly over line count b/c each event needs to be declared uniquely
void Game::set_up(int l, int w){
	//going a few lines over b/c each event needs to be declared,
	//but there aren't enough to justify iteration

	//set up the game
	this->length = l;
	this->width = w;

	//start with 3 arrows
	this->num_arrows = 3;

	// Populate the game board: 2D vector of Room objects
	for (int i = 0; i < l; i++) {
		vector<Room> row;
		for (int j = 0; j < w; j++) {
			Room temp(i, j);
			row.push_back(temp);
		}
		grid.push_back(row);
	}

	// randomly insert events (2 bats, 2 stalactites, 1 wumpus, 1 gold)
	// into the board
	// for (int i = 0; i < 5; i++){
	// 	xseed[i] = rand() % l;
	// 	yseed[i] = rand() % w;
	// }
	unique_rands(xseed, yseed, l, w);

	events[0] = new Bats(xseed[0], yseed[0]);
	//events[0]->assert_type();
	//cout << events[0]->get_symbol() << endl;
	events[1] = new Bats(xseed[1], yseed[1]);
	//events[1]->assert_type();
	events[2] = new Stalactites(xseed[2], yseed[2]);
	//events[2]->assert_type();
	events[3] = new Stalactites(xseed[3], yseed[3]);
	//events[3]->assert_type();
	events[4] = new Wumpus(xseed[4], yseed[4], l, w);
	//events[4]->assert_type();
	events[5] = new Gold(xseed[5], yseed[5]);

	populate_events();
	place_player(l,w);

	//cout << "DEBUG: set_up() complete" << endl;
}


//Note: you need to modify this function
void Game::display_game() {
	cout << endl << endl;
	cout << "Arrows remaining: " << this->num_arrows << endl;

	cout << "P x: " << p.x_location << " y: " << p.y_location << endl;

	string line = "";
	for (int i = 0; i < this->width; ++i)
		line += "-----";

	for (int i = 0; i < this->length; ++i)
	{
		cout << line << endl;
		for (int j = 0; j < this->width; ++j)
		{
			//The first char indicates whether there is a player in that room or not
			//if the room does not have the player, print space " "
			if (!(i == p.y_location && j == p.x_location)) {
				cout << " ";
			}
			//else, print "*"
			else {
				cout << "*";
			}
			//Fix the following
			//cout << " ";


			//The next two chars indicate the event in the room
			//if the room does not have an event, print "  ||" (2 spaces + ||)
			if (grid[j][i].get_event() == nullptr) {
				cout << "  ||";
			}
			else {
				if (debug_view) {
					//get symbol from event in grid at index j, i
					cout << grid[j][i].get_event()->get_symbol();
				}
				else {
					cout << " ";
				}
				cout << " ||";
			}
			//else,
				//if debug_view is true
					//print the corresponding char of the event
				//else
					//print " " (1 space)
				// print " ||" (1 space + ||)

			//Fix the following...
			//cout << "  ||";
		}
		cout << endl;
	}
	cout << line << endl;

	//example output (when finished):
	// --------------------
	//  B || G || B ||   ||
	// --------------------
	//    || W ||   || S ||
	// --------------------
	//    ||   ||   || S ||
	// --------------------
	// *  ||   ||   ||   ||
	// --------------------
}

bool Game::check_win() const{
	//check if game over/win
	//Your code here:

	//cout << "Game::check_win() is not implemented..." << endl;
	return (!p.is_alive || p.win);
}

void Game::move_up() {
	//move player up
	//Your code here:
	if (p.y_location == 0) {
		cout << "There is a wall blocking your path." << endl;
	}

	else p.y_location--;

	cout << "Game::move_up() is not tested" << endl;
	return;
}

void Game::move_down() {
	//move player up
	//Your code here:
	if (p.y_location == (width - 1)) {
		cout << "There is a wall blocking your path." << endl;
	}

	else p.y_location++;

	cout << "Game::move_down() is not tested" << endl;
	return;
}

void Game::move_left() {
	//move player left
	//Your code here:

	if (p.x_location == 0) {
		cout << "There is a wall blocking your path." << endl;
	}

	else p.x_location--;

	cout << "Game::move_left() is not tested" << endl;

}

void Game::move_right() {
	//move player right
	//Your code here:
	if (p.x_location == length - 1) {
		cout << "There is a wall blocking your path." << endl;
	}

	else p.x_location++;

	cout << "Game::move_right() is not tested" << endl;

	return;
}


char Game::get_dir(){
	//get direction of arrow:
	char dir;
	//Note: error checking is needed!!
	//Your code here:
	cout << "Fire an arrow...." << endl;
	cout << "W-up" << endl;
	cout << "A-left" << endl;
	cout << "S-down" << endl;
	cout << "D-right" << endl;


	cout << "Enter direction: " << endl;
	cin >> dir;
	cin.ignore(256, '\n');
	num_arrows--;
	return dir;
}

void Game::wumpus_move(){
	//after a missed arrow, 75% chance that the wumpus is moved to a different room

	//How to get 75%?
	//Hint: generate a random number from 0-3, if the number is not 0, then move

	//Your code here:
	cout << "Game::wumpus_move() is not implemented..." << endl;

	return;
}

void Game::fire_arrow(){
	// The player may fire arrow...
	char dir = get_dir();
	int x = p.x_location;
	int y = p.y_location;

	cout << "DEBUG: Firing arrow in direction " << dir << endl;

	//Your code here:
	for (int i = 0; i < 3; i++) {

		//move arrow
		if (dir == 'w' && y != 0) {
			y--;
		}
		else if (dir == 'a' && x != 0) {
			x--;
		}
		else if (dir == 's' && y != width - 1) {
			y++;
		}
		else if (dir == 'd' && x != length - 1) {
			x++;
		}
		else {
			cout << "You hit a wall!" << endl;
			return;
		}
		cout << "DEBUG: Player at " << p.x_location << ", " << p.y_location << endl;
		cout << "DEBUG: Arrow at " << x << ", " << y << endl;
		cout << "DEBUG: Wumpus at " << events[4]->get_x() << ", " << events[4]->get_y() << endl;

		//check if wumpus is hit
		if (events[4]->get_x() == x && events[4]->get_y() == y) {
			cout << "You killed the wumpus!" << endl;
			p.win = true;
			return;
		}
	}
	//only if arrow misses
	cout << "You missed!" << endl;
	cout << "Game::fire_arrow() is not implemented..." << endl;

	return;

}

void Game::move(char c) {
	// Handle player's action: move or fire an arrow
	if (c == 'f'){
		Game::fire_arrow();
		return;
	}
	if (p.bat_duration == 0) {
		switch(c){
			case 'w':
				Game::move_up();
				break;
			case 'a':
				Game::move_left();
				break;
			case 's':
				Game::move_down();
				break;
			case 'd':
				Game::move_right();
				break;
		}
	}
	else {
		switch(c){
			case 'w':
				Game::move_down();
				break;
			case 'a':
				Game::move_right();
				break;
			case 's':
				Game::move_up();
				break;
			case 'd':
				Game::move_left();
				break;
		}
		p.bat_duration--;
	}
}



void Game::move_wumpus(char move, int x, int y) {
		//move wumpus

	//set room to nullptr
	grid[events[4]->get_x()][events[4]->get_y()].set_event(nullptr);

	switch(move){
		case 'w':
			events[4]->set_y(y - 1);
			break;
		case 'a':
			events[4]->set_x(x - 1);
			break;
		case 's':
			events[4]->set_y(y + 1);
			break;
		case 'd':
			events[4]->set_x(x + 1);
			break;
	}

	//set new room to wumpus
	grid[events[4]->get_x()][events[4]->get_y()].set_event(events[4]);
}


void Game::wumpus_walker() {
	//neighboring rooms may not exist (i.e. on the edge of the board)
	//or may be occupied by the player or another event
	//check for open spaces, then move to one of them
	//otherwise don't move
	//movement is by changing which room has a pointer to event[4]
	//and then change the x and y values of event[4]

	int x = events[4]->get_x();
	int y = events[4]->get_y();

	vector<char> valid_moves;

	//check if each room exists, then if it is occupied. Add to vector if good
	if (x != 0) {
		if (grid[x - 1][y].get_event() == nullptr && x - 1 != p.x_location && y != p.y_location) {
			valid_moves.push_back('a');
		}
	}
	if (x != length - 1) {
		if (grid[x + 1][y].get_event() == nullptr && x + 1 != p.x_location && y != p.y_location) {
			valid_moves.push_back('d');
		}
	}
	if (y != 0) {
		if (grid[x][y - 1].get_event() == nullptr && x != p.x_location && y - 1 != p.y_location) {
			valid_moves.push_back('w');
		}
	}
	if (y != width - 1) {
		if (grid[x][y + 1].get_event() == nullptr && x != p.x_location && y + 1 != p.y_location) {
			valid_moves.push_back('s');
		}
	}

	//if there are valid moves, pick one at random
	if (valid_moves.size() > 0) {
		int move = rand() % valid_moves.size();	
		move_wumpus(valid_moves[move], x, y);
	}

}



char Game::get_input(){
	//get action, move direction or firing an arrow

	//Note: error checking is needed!!
	//Your code here:
	char c;
	bool valid = 0;

	do {

		cout << endl << endl << "Player move..." << endl << endl;
		cout << "W-up" << endl;
		cout << "A-left" << endl;
		cout << "S-down" << endl;
		cout << "D-right" << endl;
		cout << "f-fire an arrow" << endl;

		cout << "Enter input: " << endl;
		cin >> c;
		cin.ignore(256, '\n');

		valid = (c == 'w' || c == 'a' || c == 's' || c == 'd' || c == 'f');

	} while (!valid);

	return c;
}


//Note: you need to modify this function
void Game::play_game(int w, int l, bool d){


	Game::set_up(w, l);
	this->debug_view = d;

	char input, arrow_input;

	//for some reason these values get manged between init and now, so reset them to 0;
	// p.x_location = 0;
	// p.y_location = 0;

	while (Game::check_win() == false){
		//print game board
		Game::display_game();

		//display percerts around player's location
		//Your code here:
		display_events();

		//Player move...
		//1. get input
		input = Game::get_input();

		//2. move player
		Game::move(input);

		//3. may or may not encounter events
		//Your code here:
		if (grid[p.x_location][p.y_location].get_event() != nullptr) {
			grid[p.x_location][p.y_location].get_event()->do_event(p);
		}

		//move wumpus
		wumpus_walker();
	}

	if (p.win) {
		cout << "You win!" << endl << endl;
	}

	//future play again goes here

	return;

}

void Game::display_events() {
	//check if room exists
		//check for event
			//get event, print percept

	//on left
	if (p.x_location != 0) {
		if (grid[p.x_location - 1][p.y_location].get_event() != nullptr) {
			grid[p.x_location - 1][p.y_location].get_event()->print_percept();
		}
	}
	//on right
	if (p.x_location != length - 1) {
		if (grid[p.x_location + 1][p.y_location].get_event() != nullptr) {
			grid[p.x_location + 1][p.y_location].get_event()->print_percept();
		}
	}
	//on top
	if (p.y_location != 0) {
		if (grid[p.x_location][p.y_location - 1].get_event() != nullptr) {
			grid[p.x_location][p.y_location - 1].get_event()->print_percept();
		}
	}
	//on bottom
	if (p.y_location != width - 1) {
		if (grid[p.x_location][p.y_location + 1].get_event() != nullptr) {
			grid[p.x_location][p.y_location + 1].get_event()->print_percept();
		}
	}
}


void Game::get_size(int& x, int& y, bool& debug) {
	bool valid = false;
	string temp = "no"; //middleman for debug check

	do {
	cout << "Welcome to Hunt the Wumpus!" << endl;
	cout << "Please enter size of square gameboard" << endl;
	cout << "Gameboard is a square b/c I didn't want to debug on Thanksgiving." << endl;
	//cout << "Width and length must be between 4 and 50 (inclusive)" << endl;
	cout << "Please enter size of square gameboard, between 4 and 50 (inclusive)" << endl;
	cin >> x;
	//cout << "Please enter length of gameboard" << endl;
	//cin >> y;

	y = x; //square board

	cout << "would you like to play in debug mode? enter y for yes, anything else for no" << endl;
	cin >> temp;
	debug = (temp == "y"); //if temp is y then use debug mode

	valid = (x < 51 && x > 3 && y < 51 && y > 3);
	} while (!valid);

	//TODO: remove before shipping
	//cout << "DEBUG MESSSAGE: Size from within get_size(): " << x << " " << y << endl;
}