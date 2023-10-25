#include "catalog.h"

using namespace std;

/**************************************************
 * Name: init()
 * Description: This function will fetch the number of teams needed)
 * Parameters: reader - ifsteram
 * Pre-conditions: ifstream exists
 * Post-conditions: returns team count
 ***********************************************/
int init(ifstream& reader){

    string filename = "";
    string count;

    cout << "specify file name: ";
    //TODO: error handling
    cin >> filename;
    reader.open(filename);
    reader >> count;
    return stoi(count);
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
    Team* t_array = new Team[teamsize];
    return t_array;
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
    teamarr[index].p = (create_players(teamarr[index].num_player));
    //populate players
    for (int i = 0; i < teamarr[index].num_player; i++) {
        //note reader may need to be PBR again
        populate_player_data(teamarr[index].p, i, reader);
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
void populate_player_data(Player* player, int index, ifstream& reader) {
    reader >> player[index].name;
    reader >> player[index].age;
    reader >> player[index].nation;
    reader >> player[index].ppg;
    reader >> player[index].fg;
}


/**************************************************
 * Name: delete_info()
 * Description: This function will  delete all the memory that was dynamically allocated
 * Parameters: Team* - the Team array
 * Pre-conditions: the provided Team array hasn't been freed yet
 * Post-conditions: the Team struct, with all Players inside, is freed
 ***********************************************/
void delete_info(Team* team, int index){
    delete[] team[index].p;
    delete team;
}

/**************************************************
 * Name: test_team()
 * Description: cout teams for troubleshooting
 * Parameters: Team - the Team
 * Pre-conditions: team arr exists
 * Post-conditions: simple couts
 ***********************************************/
void test_team(Team t){
    cout << t.p[0].name;
}

void team_to_file(team t){

}

void player_to_cout(player p) {
    cout << p.name << ": " << endl;
    cout << "Age: " << p.age << endl;
    cout << "Nation: " << p.nation << endl;
    cout << "Points per Game: " << p.ppg << endl;
    cout << "Field goal percentage" << p.fg << endl << endl;
}

void team_to_cout(team t){
    cout << "Team Name: " << t.name << endl;
    cout << "Team Owner: " << t.owner << endl;
    cout << "Team Market Value: " << t.market_value << endl;
    cout << "Team Player Count: " << t.num_player; << endl;
    cout << "Players for :" << t.name << endl;
    
    for (int i = 0; i < t.num_player; i++){
        player_to_cout(t.p[i]);
    }

    cout << "Total Points per game: " << t.total_ppg << endl;
}

void query_name_out(Team t) {
    string choice = "-1"; //dummy
    cout <<"Would you like the data as a file [1] or via the console [2]" << endl;
    do {
        cout << "(enter 1 or 2): ";
        cin >> choice;
    } while (choice != "1" || choice != "2");

    if (choice == "1") {
        team_to_file(t);
    }
    else if (choice == "2") {
        team_to_cout(t);
    }
    else {
        cout << "Error, was looking for 1 or 2 but got: " << choice << endl;
    }
}

void query_name(Team* teams, int num_teams) {
    string name;
    
    cout << "Submit valid name of team: ";
    cin >> name;

    bool index = -1;

    for (int i = 0; i < num_teams; i++) {
        if (teams[i].name == name) {
            index = i;
        }
    }
    if (index != -1) {
        cout << "Invalid team name" <<  endl;
    }
    else {
        query_name_out(teams[index])
    }
}
