#include "catalog.h"
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	//create file reader
	ifstream reader;
	//create teams based on the number of players from reader
	int teams_count = init(reader);
	Team* teams = create_teams(teams_count);
	for (int i = 0; i < teams_count; i++) {
		populate_team_data(teams, i, reader);
	}

	//TODO: delete before submitting
	//test_team(teams[0]);
	//team_to_cout(teams[0]);
	//query_name(teams, teams_count);
	query_top_scorers(teams, teams_count);

	return 0;
}