#include "catalog.h"

using namespace std;

int init(ifstream& reader){
    /*
    takes reader obj
    returns teamsize
    */

    string filename = "";
    string teamsize;
    
    cout << "specify file name: ";
    //TODO: error handling
    cin >> filename;
    reader.open(filename);
    reader >> teamsize;
    return stoi(teamsize);
}

/**************************************************
 * Name: create_teams()
 * Description: This function will dynamically allocate
                an array of teams (of the requested size)
 * Parameters: int - size of the array
 * Pre-conditions: none
 * Post-conditions: a Team array of requested size is created and return
 ***********************************************/
Team* create_teams(int teamsize) {
    Team* array = new Team[teamsize];
    return array;
}


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
void populate_team_data(Team* teamarr, int index, ifstream& reader) {
    //the easy stuff
    reader >> teamarr[index].name;
    reader >> teamarr[index].owner;
    reader >> teamarr[index].market_value;
    reader >> teamarr[index].num_player;
    
    //create player arr and assign to team struct
    teamarr.Player(create_players(teamarr[index].num_player));
    //populate players
    for (int i = 0; i < teamarr[index].num_player; i++) {
        //note reader may need to be PBR again
        populate_player_data(teamarr[index].Player, i, reader);
    }
} 


/**************************************************
 * Name: create_players()
 * Description: This function will dynamically allocate
                an array of players (of the requested size)
 * Parameters: int - size of the array
 * Pre-conditions: none
 * Post-conditions: a Player array of requested size is created and return
 ***********************************************/
Player* create_players(int size) {
    Player* players = new Player[size];
    return players;
}


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
 * Post-conditions: the Team struct, with all Players inside, is freed
 ***********************************************/
void delete_info(Team* team, int){
    delete[] team.Player;
    delete team;
}

