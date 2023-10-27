/******************************************************
** Program: run_catalog.h
** Author: Troy Lopez
** Date: 10/30/2023
** Description: main entry point, creates dynarray and delegates functionality
*******************************************************/

#include "catalog.h"
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	//create file reader
	ifstream reader;
	//create teams based on the number of players from reader. 
	//returns 0 if file was bad
	int teams_count = init(reader);
	if (teams_count != 0){
		//create things
		Team* teams = create_teams(teams_count);
		for (int i = 0; i < teams_count; i++) {
			populate_team_data(teams, i, reader);
		}

		//presents menu, etc
		sort(teams, teams_count);
		handler(teams, teams_count);

		//cleanup
		delete_info(teams, teams_count);
		delete[] teams;
		reader.close();
	}
	return 0;
}