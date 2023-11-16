#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"

using namespace std;


int main()
{
	//set the random seed
	srand(time(NULL));
	
	int wid = 5, len = 5;
	bool debug = false;
	
	Game g;

	//get two inputs: size of the cave(wid and len)
	


	//get the 3rd input --> debug mode or not


	//Play game
	g.play_game(wid, len, debug);


	return 0;
}