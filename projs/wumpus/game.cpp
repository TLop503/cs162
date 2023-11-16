#include "game.h"
#include "gold.h"
#include "stalactites.h"
#include "bats.h"
#include "wumpus.h"

#include <iostream>

using namespace std;

//Game Implementation

Game::Game(){
	//Game constructor
	//Your code here:
}

Game::~Game(){
	//Game destructor
	//Your code here:

}


void Game::set_up(int l, int w){
	//set up the game
	this->length = l;
	this->width = w;

	this->num_arrows = 3; 	//start with 3 arrows

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
	srand(time(NULL));
	for (int i = 0; i < 5; i++){
		xseed[i] = rand() % l;
		yseed[i] = rand() % w;
	}
	/*
	events[0] = Bat(xseed[0], yseed[0]);
	events[1] = Bat(xseed[1], yseed[1]);
	events[2] = Stalactite(xseed[2], yseed[2]);
	events[3] = Stalactite(xseed[3], yseed[3]);
	events[4] = Wumpus(xseed[4], yseed[4]);
	*/

}

//Note: you need to modify this function
void Game::display_game() const{
	cout << endl << endl;
	cout << "Arrows remaining: " << this->num_arrows << endl;
	
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

			//else, print "*"

			//Fix the following
			cout << " ";
			

			//The next two chars indicate the event in the room
			//if the room does not have an event, print "  ||" (2 spaces + ||)
			
			//else, 
				//if debug_view is true
					//print the corresponding char of the event
				//else
					//print " " (1 space)
				// print " ||" (1 space + ||)

			//Fix the following...
			cout << "  ||";
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

	cout << "Game::check_win() is not implemented..." << endl;
	return false;
}

void Game::move_up() {
	//move player up
	//Your code here:

	cout << "Game::move_up() is not implemented..." << endl;
	return;

}

void Game::move_down() {
	//move player down
	//Your code here:

	cout << "Game::move_down() is not implemented..." << endl;
	return;
}

void Game::move_left() {
	//move player left
	//Your code here:

	cout << "Game::move_left() is not implemented..." << endl;
	return;

}

void Game::move_right() {
	//move player right
	//Your code here:

	cout << "Game::move_right() is not implemented..." << endl;
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
	//Your code here:
	cout << "Game::fire_arrow() is not implemented..." << endl;

	return;

}

void Game::move(char c) {
	// Handle player's action: move or fire an arrow
	if (c == 'f'){
		Game::fire_arrow();
		return;
	}
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

char Game::get_input(){
	//get action, move direction or firing an arrow

	//Note: error checking is needed!!
	//Your code here:
	char c;

	cout << endl << endl << "Player move..." << endl << endl;
	cout << "W-up" << endl;
	cout << "A-left" << endl;
	cout << "S-down" << endl;
	cout << "D-right" << endl;
	cout << "f-fire an arrow" << endl;

	cout << "Enter input: " << endl;
	cin >> c;
	cin.ignore(256, '\n');

	
	return c;
}

//Note: you need to modify this function
void Game::play_game(int w, int l, bool d){


	Game::set_up(w, l);
	this->debug_view = d;

	char input, arrow_input;
	
	while (Game::check_win() == false){
		//print game board
		Game::display_game();

		//display percerts around player's location
		//Your code here:

		//Player move...
		//1. get input
		input = Game::get_input();

		//2. move player
		Game::move(input);

		//3. may or may not encounter events
		//Your code here:

	}
	
	
	return;

}

void Game::get_size(int& x, int& y, bool& debug) {
	bool valid = false;
	string temp = "no"; //middleman for debug check

	do {
	cout << "Width and length must be between 4 and 50 (inclusive)" << endl;
	cout << "Please enter width of gameboard" << endl;
	cin >> x;
	cout << "Please enter length of gameboard" << endl;
	cin >> y;

	cout << "would you like to play in debug mode? enter y for yes, anything else for no" << endl; 
	cin >> temp;
	debug = (temp == "y"); //if temp is y then use debug mode

	valid = (x < 51 && x > 3 && y < 51 && y > 3);
	} while (!valid);

	//TODO: remove before shipping
	//cout << "DEBUG MESSSAGE: Size from within get_size(): " << x << " " << y << endl;
}