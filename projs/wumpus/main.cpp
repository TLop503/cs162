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

	//ask user for basics
	g.get_size(wid, len, debug); //this is PBR so it should work
	//cout << "DEBUG MESSAGE: dimensions in main(): " << wid << " " << len << endl;

	//Play game
	g.play_game(wid, len, debug);


	return 0;
}