#include "catalog.h"

using namespace std;

//This really should be like 6 files but I'm lazy

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
    float ppg = 0;
    //populate players
    for (int i = 0; i < teamarr[index].num_player; i++) {
        //note reader may need to be PBR again
        populate_player_data(teamarr[index].p, i, reader);
        ppg += teamarr[index].p[i].ppg;
    }

    teamarr[index].total_ppg = ppg;
    
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


void team_to_file(Team t){
    cout << "Placeholder, write ttf" << endl;
}

void player_to_cout(Player p) {
    cout << p.name << ": " << endl;
    cout << "Age: " << p.age << endl;
    cout << "Nation: " << p.nation << endl;
    cout << "Points per Game: " << p.ppg << endl;
    cout << "Field goal percentage: " << p.fg << endl << endl;
}

void team_to_cout(Team t){
    cout << "Team Name: " << t.name << endl;
    cout << "Team Owner: " << t.owner << endl;
    cout << "Team Market Value: " << t.market_value << endl;
    cout << "Team Player Count: " << t.num_player << endl;
    cout << "Players for: " << t.name << endl << endl;
    
    for (int i = 0; i < t.num_player; i++){
        player_to_cout(t.p[i]);
    }

    cout << "Total Points per game: " << t.total_ppg << endl;
}

void query_name_out(Team t) {
    string choice = "-1"; //dummy
    cout <<"Would you like the data as a file [a] or via the console [b]" << endl;
    do {
        cout << "(enter 1 or 2): ";
        cin >> choice;
        cout << endl; //newline for nicer formatting in term
    } while (choice != "a" && choice != "b");

    if (choice == "a") {
        team_to_file(t);
    }
    else if (choice == "b") {
        team_to_cout(t);
    }
    else {
        cout << "Error, was looking for a or b but got: " << choice << endl;
    }
}

void query_name(Team* teams, int num_teams) {
    string name;
    
    cout << "Submit valid name of team: ";
    cin >> name;

    bool index = -1;

    for (int i = 0; i < num_teams; i++) {
        cout << teams[i].name << endl;
        if (teams[i].name == name) {
            index = i;
        }
    }
    if (index == -1) {
        cout << "Invalid team name" <<  endl;
    }
    else {
        query_name_out(teams[index]);
    }
}

void top_score_to_cout(Team team, Player player, int score, bool tie) {
    // absurd one liner, probably should fix
    if (!tie) {
        cout << "Top score on team " << team.name << " is ";
        cout << score << " by player " << player.name << endl;
    }
    else {
        cout << "Top score on team " << team.name << " was a tie ";
        cout << " of " << score << " points" << endl;
    }
}

void top_score_to_file(Team team, Player player, int score, bool tie) {

}

bool query_top_scorers_out() {
    string choice = "-1"; //dummy
    cout <<"Would you like the data as a file [a] or via the console [b]" << endl;
    do {
        cout << "(enter 1 or 2): ";
        cin >> choice;
        cout << endl; //newline for nicer formatting in term
    } while (choice != "a" && choice != "b");

    if (choice == "a") {
        return true;
    }
    else if (choice == "b") {
        return false;
    }
    else {
        cout << "Error, was looking for a or b but got: " << choice << endl;
        return true;
    }
}

void query_top_scorers(Team* teams, int num_teams) {
    //this is so scuffed but we aren't being graded on efficiency

    //for each team
    bool out = query_top_scorers_out();
    for (int i = 0; i < num_teams; i++) {
        int top = 0, plr = -1;
        bool tie = 0;
        //for each player
        for (int j = 0; j < teams[i].num_player; j++) {
            if (top < teams[i].p[j].ppg) {
                top = teams[i].p[j].ppg;
                plr = j;
                tie = 0;
            }
            else if (top == teams[i].p[j].ppg) {
                tie = 1;
            }
        }
        if (!out) {
            top_score_to_cout(teams[i], teams[i].p[plr], top, tie);
        }
        else {
            top_score_to_file(teams[i], teams[i].p[plr], top, tie);
        }

    }
}

int sum_nationality_matches(Team* teams, int num_teams, string nationality) {
    int out = 0;
    for (int i = 0; i < num_teams; i++) {
        for (int j = 0; j < teams[i].num_player; j++) {
            if (teams[i].p[j].nationality == nationality) {
                out++;
            }
        }
    }

    return out;
}

void nationality_to_cout(Player* players, int size) {

}

void nationality_to_file(Player* players, int size) {

}

void query_nationality_out(Player* players, int size) {
    string choice = "-1"; //dummy
    cout <<"Would you like the data as a file [a] or via the console [b]" << endl;
    do {
        cout << "(enter 1 or 2): ";
        cin >> choice;
        cout << endl; //newline for nicer formatting in term
    } while (choice != "a" && choice != "b");

    if (choice == "a") {
        nationality_to_file(players, size);
    }
    else if (choice == "b") {
        nationality_to_cout(players, size);
    }
    else {
        cout << "Error, was looking for a or b but got: " << choice << endl;
    }
}

void query_nationality(Team* teams, int num_teams, string nationality) {
    //team
    Player* matches = new int[sum_nationality_matches(teams, num_teams, nationality)];
    index = 0;

    for (int i = 0; i < num_teams; i++) {
        for (int j = 0; j < teams[i].num_player; j++) {
            if (teams[i].p[j].nationality == nationality) {
                //set next index in array to player matching criteria
                matches[index] = teams[i].p[j];
                index++;
            }
        }
    }
}
