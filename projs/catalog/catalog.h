#ifndef CAT_H
#define CAT_H

/******************************************************
** Program: catalog.h
** Author: Troy Lopez
** Date: 10/30/2023
*******************************************************/

#include <iostream>
#include <fstream>

using namespace std;

//a struct to hold info of a team
struct Team {
  string name;        //name of the team
  string owner;       //owner of the team
  int market_value;   //market value of the team
  int num_player;     //number of players in the team
  struct Player* p;   //an array that holds all players
  float total_ppg;    //total points per game
};

//a struct to hold info of a player
struct Player {
  string name;      //name of the player
  int age;          //age of the player
  string nation;    //nationality of the player
  float ppg;        //points per game of the player
  float fg;         //field goal percentage
};


/**************************************************
 * Name: init()
 * Description: This function will fetch the number of teams needed)
 * Parameters: reader - ifsteram
 * Pre-conditions: ifstream exists
 * Post-conditions: returns team count
 ***********************************************/
int init(ifstream&);


/**************************************************
 * Name: team_to_file()
 * Description: given a team, call player_to_file for each player
 * Parameters: Team t - a team struct instance
 * Pre-conditions: struct is populated
 * Post-conditions: players will have been run through player_to_file
 ***********************************************/
void team_to_file(Team);


/**************************************************
 * Name: team_to_cout()
 * Description: given a team, call player_to_cout for each player
 * Parameters: Team t - a team struct instance
 * Pre-conditions: struct is populated
 * Post-conditions: players will have been run through player_to_cout
 ***********************************************/
void team_to_cout(Team);


/**************************************************
 * Name: query_name_out()
 * Description: given a team, output each player. works as subproccess of query_name
 * Parameters: Team t - a team struct instance
 * Pre-conditions: struct is populated
 * Post-conditions: players will be outputted via cout or file
 ***********************************************/
void query_name_out(Team);


/**************************************************
 * Name: query_name()
 * Description: ask for a team and locate it's players
 * Parameters: Team* teams - arr of structs, num_teams - size of arr
 * Pre-conditions: struct is populated
 * Post-conditions: will run query_name_out if team is found
 ***********************************************/
void query_name(Team*, int);


/**************************************************
 * Name: top_score_to_cout()
 * Description: print top scoring player or tie
 * Parameters: Team team - team being analyzed, Player player - player that did best, score - hiscore, tie - yes or no
 * Pre-conditions: best player OR tie has been found. Note player is found IFF no tie
 * Post-conditions: prints out best scoring player or that there was a tie
 ***********************************************/
void top_score_to_cout(Team, Player, int, bool);


/**************************************************
 * Name: top_score_to_file()
 * Description: print top scoring player or tie
 * Parameters: Team team - team being analyzed, Player player - player that did best, score - hiscore, tie - yes or no, file - output file name
 * Pre-conditions: best player OR tie has been found. Note player is found IFF no tie
 * Post-conditions: prints out best scoring player or that there was a tie
 ***********************************************/
void top_score_to_file(Team, Player, int, bool);


/**************************************************
 * This is a mess but it works. Slightly over the line limit but only because I tried to add error messages incase something theoretically impossible occured.
 * Name: query_top_scorers_out()
 * Description: subproccess of query_top_scorers that determines output type and sets filename via pbr so that it only needs to be asked for once.
 * Parameters: string &filename - pbr to update filename if user wants to write to a file
 * Pre-conditions: query has been called
 * Post-conditions: returns bool corresponding to type of output
 ***********************************************/
bool query_top_scorers_out();


/**************************************************
 * Name: query_top_scorers()
 * Description: locate top scoring player for each team
 * Parameters: team* teams -- arr of teams, int num_teams -- size of arr
 * Pre-conditions: struct is full
 * Post-conditions: calls output subproccess
 ***********************************************/
void query_top_scorers(Team*, int);


/**************************************************
 * Name: sum_nationality_matches
 * Description: count how many players fit the requested nationality so a dynamic array can be created
 * Parameters: Team* teams - team arr, int num_teams - size of team arr, string nationality - nationality being searched for
 * Pre-conditions: structs are populated
 * Post-conditions: returns number of players matching criteria. It would be a lot more efficient to just find each player and
 *  print to file or cout but I didn't see a fast way to do that in 15 lines so now the whole nationality search takes 2 passes.
 ***********************************************/
int sum_nationality_matches(Team*, int, string);


/**************************************************
 * Name: nationality_to_cout()
 * Description: prints players in array
 * Parameters: player* players - list of players to be printed, int size (size)
 * Pre-conditions: array has been populated
 * Post-conditions: will be pritned to stdio
 ***********************************************/
void nationality_to_cout(Player*, int);


/**************************************************
 * Name: nationality_to_file()
 * Description: Print all players in list to file
 * Parameters: player* players - list of players to be printed, int size (size)
 * Pre-conditions: array has been populated
 * Post-conditions: will be pritned to file
 ***********************************************/
void nationality_to_file(Player*, int);


/**************************************************
 * Name: query_nationality_out()
 * Description: asks where to print nationality data
 * Parameters: player* players - list of players to be printed, int size (size)
 * Pre-conditions: array has been populated
 * Post-conditions: calls subproccesses
 ***********************************************/
void query_nationlity_out(Player*, int);


/**************************************************
 * Name: query_nationality()
 * Description: searches data for nationalities matching request
 * Parameters: Team* teams - arr of teams, int num_teams - size
 * Pre-conditions: struct is populated
 * Post-conditions: calls subproccesses and eventually dumps data to file or stdio
 ***********************************************/
void query_nationality(Team*, int);


/**************************************************
 * Name: runner()
 * Description: given user selection call subproccess
 * Parameters: string in - user choice, Team* teams - team arr, int size - size
 * Pre-conditions: struct has been populated
 * Post-conditions: will return to handler w/ whether or not to end program
 ***********************************************/
bool runner (string, Team*, int);


/**************************************************
 * Name: handler()
 * Description: asks for user selection
 * Parameters: Team* teams - team arr, int size - size
 * Pre-conditions: struct has been populated
 * Post-conditions: will end once user chooses 4.
 ***********************************************/
void handler(Team*, int);


/**************************************************
 * Name: sort()
 * Description: sorts teams by ppg
 * Parameters: Team* teams - arr of teams, int num_teams - size
 * Pre-conditions: struct is populated
 * Post-conditions: dumps to cout or file
 ***********************************************/
void sort(Team*, int);


/**************************************************
 * Name: cout_ppg()
 * Description: prints sorted teams by ppg
 * Parameters: Team* teams - arr of teams, int num_teams - size
 * Pre-conditions: struct is populated, sorted
 * Post-conditions: dumps to cout
 ***********************************************/
void cout_ppg(Team*, int);


/**************************************************
 * Name: file_ppg()
 * Description: prints sorted teams by ppg
 * Parameters: Team* teams - arr of teams, int num_teams - size
 * Pre-conditions: struct is populated, sorted
 * Post-conditions: dumps to file
 ***********************************************/
void file_ppg(Team*, int);

/**************************************************
 * Name: create_teams()
 * Description: This function will dynamically allocate
                an array of teams (of the requested size)
 * Parameters: int - size of the array
 * Pre-conditions: none
 * Post-conditions: a Team array of requested size is created and return
 ***********************************************/
Team* create_teams(int);


/**************************************************
 * Name: populate_team_data()
 * Description: This function will fill a single team struct 
                with information that is read in from the file
 * Parameters:  Team* - pointer to the Team array
                int - index of the Team in the array to be filled 
                ifstream& - input file to get information from
 * Pre-conditions: Team array has been allocated; 
                   provided index is less than the array size
 * Post-conditions: a Team at provided index is populated
 ***********************************************/
void populate_team_data(Team*, int, ifstream &); 


/**************************************************
 * Name: create_players()
 * Description: This function will dynamically allocate
                an array of players (of the requested size)
 * Parameters: int - size of the array
 * Pre-conditions: none
 * Post-conditions: a Player array of requested size is created and return
 ***********************************************/
Player* create_players(int);


/**************************************************
 * Name: populate_player_data()
 * Description: This function will fill a single player struct 
                with information that is read in from the file
 * Parameters:  Player* - pointer to the Player array
                int - index of the Player in the array to be filled 
                ifstream& - input file to get information from
 * Pre-conditions: Player array has been allocated; 
                   provided index is less than the array size
 * Post-conditions: a Player at provided index is populated
 ***********************************************/
void populate_player_data(Player*, int, ifstream &); 


/**************************************************
 * Name: delete_info()
 * Description: This function will  delete all the memory that was dynamically allocated
 * Parameters: Team* - the Team array
 * Pre-conditions: the provided Team array hasn't been freed yet
 * Post-conditions: the Team array, with all Players inside, is freed
 ***********************************************/
void delete_info(Team*, int);


#endif