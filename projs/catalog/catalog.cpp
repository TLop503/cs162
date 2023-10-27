/******************************************************
** Program: catalog.cpp
** Author: Troy Lopez
** Date: 10/30/2023
** Description: Functions for handling bulk of work for program.
    Users can search by nationality, team name, top score, or sort the players
** Input: called by run_catalog.cpp
** Output: varies wildly but ultimately gives the ok to quit
******************************************************/

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
    string filename;
    string count;

    cout << "specify file name: ";
    cin >> filename;
    reader.open(filename);
    if (!(reader.is_open())) {
        cout << "Invalid Filename, quitting" << endl;
        return 0;
    }
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
void delete_info(Team* team, int size){
    for (int i = 0; i < size; i++) {
        //cout << "deleting players on team" << i << endl;
        delete[] (team[i].p);
    }
}


/**************************************************
 * Name: player_to_file()
 * Description: prints data for each player to a file
 * Parameters: &writer - writer object, Player P - player struct to write about
 * Pre-conditions: player is populated and struct exists
 * Post-conditions: file will be written
 ***********************************************/
void player_to_file(ofstream &writer, Player p) {
    writer << p.name << ": " << endl;
    writer << "Age: " << p.age << endl;
    writer << "Nation: " << p.nation << endl;
    writer << "Points per Game: " << p.ppg << endl;
    writer << "Field goal percentage: " << p.fg << endl << endl;
}


/**************************************************
 * Name: team_to_file()
 * Description: given a team, call player_to_file for each player
 * Parameters: Team t - a team struct instance
 * Pre-conditions: struct is populated
 * Post-conditions: players will have been run through player_to_file
 ***********************************************/
void team_to_file(Team t){
    ofstream writer;
    string in;
    cout << "Please enter name for output file: ";
    cin >> in;
    writer << "Team Name: " << t.name << endl;
    writer << "Team Owner: " << t.owner << endl;
    writer << "Team Market Value: " << t.market_value << endl;
    writer << "Team Player Count: " << t.num_player << endl;
    writer << "Players for: " << t.name << endl << endl;
    writer.open(in + ".txt", ios::app);
    writer << t.name << ": " << endl;

    //write each player
    for (int i = 0; i < t.num_player; i++){
        player_to_file(writer, t.p[i]);
    }

    writer << "Total Points per game: " << t.total_ppg << endl;
}


/**************************************************
 * Name: player_to_cout()
 * Description: print data for player to stdio
 * Parameters: Player p - the player struct
 * Pre-conditions: struct is populated
 * Post-conditions: will be printed
 ***********************************************/
void player_to_cout(Player p) {
    cout << p.name << ": " << endl;
    cout << "Age: " << p.age << endl;
    cout << "Nation: " << p.nation << endl;
    cout << "Points per Game: " << p.ppg << endl;
    cout << "Field goal percentage: " << p.fg << endl << endl;
}


/**************************************************
 * Name: team_to_cout()
 * Description: given a team, call player_to_cout for each player
 * Parameters: Team t - a team struct instance
 * Pre-conditions: struct is populated
 * Post-conditions: players will have been run through player_to_cout
 ***********************************************/
void team_to_cout(Team t){
    cout << "Team Name: " << t.name << endl;
    cout << "Team Owner: " << t.owner << endl;
    cout << "Team Market Value: " << t.market_value << endl;
    cout << "Team Player Count: " << t.num_player << endl;
    cout << "Players for: " << t.name << endl << endl;

    //write each player
    for (int i = 0; i < t.num_player; i++){
        player_to_cout(t.p[i]);
    }

    cout << "Total Points per game: " << t.total_ppg << endl;
}


/**************************************************
 * Name: query_name_out()
 * Description: given a team, output each player. works as subproccess of query_name
 * Parameters: Team t - a team struct instance
 * Pre-conditions: struct is populated
 * Post-conditions: players will be outputted via cout or file
 ***********************************************/
void query_name_out(Team t) {
    string choice = "-1"; //dummy
    cout <<"Would you like the data as a file [a] or via the console [b]" << endl;
    do {
        cout << "(enter a or b): ";
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


/**************************************************
 * Name: query_name()
 * Description: ask for a team and locate it's players
 * Parameters: Team* teams - arr of structs, num_teams - size of arr
 * Pre-conditions: struct is populated
 * Post-conditions: will run query_name_out if team is found
 ***********************************************/
void query_name(Team* teams, int num_teams) {
    string iname;

    cout << "Submit valid name of team: ";
    cin >> iname;

    int index = -1;

    for (int i = 0; i < num_teams; i++) {
        if (teams[i].name == iname) {
            index = i;
        }
    }
    //if team was not found
    if (index == -1) {
        cout << "Invalid team name. Please try again." <<  endl;
    }
    else {
        query_name_out(teams[index]);
    }
}


/**************************************************
 * Name: top_score_to_cout()
 * Description: print top scoring player or tie
 * Parameters: Team team - team being analyzed, Player player - player that did best, score - hiscore, tie - yes or no
 * Pre-conditions: best player OR tie has been found. Note player is found IFF no tie
 * Post-conditions: prints out best scoring player or that there was a tie
 ***********************************************/
void top_score_to_cout(Team team, Player player, int score, bool tie) {
    if (!tie) {
        cout << "Top score on team " << team.name << " is ";
        cout << score << " by player " << player.name << endl;
    }
    else {
        cout << "Top score on team " << team.name << " was a tie ";
        cout << " of " << score << " points" << endl;
    }
}


/**************************************************
 * Name: top_score_to_file()
 * Description: print top scoring player or tie
 * Parameters: Team team - team being analyzed, Player player - player that did best, score - hiscore, tie - yes or no, file - output file name
 * Pre-conditions: best player OR tie has been found. Note player is found IFF no tie
 * Post-conditions: prints out best scoring player or that there was a tie
 ***********************************************/
void top_score_to_file(Team team, Player player, int score, bool tie, string file) {
    ofstream writer;

    writer.open(file + ".txt", ios::app);
    if (!tie) {
        writer << "Top score on team " << team.name << " is ";
        writer << score << " by player " << player.name << endl;
    }
    else {
        writer << "Top score on team " << team.name << " was a tie ";
        writer << " of " << score << " points" << endl;
    }
}


/**************************************************
 * This is a mess but it works. Slightly over the line limit but only because I tried to add error messages incase something theoretically impossible occured.
 * Name: query_top_scorers_out()
 * Description: subproccess of query_top_scorers that determines output type and sets filename via pbr so that it only needs to be asked for once.
 * Parameters: string &filename - pbr to update filename if user wants to write to a file
 * Pre-conditions: query has been called
 * Post-conditions: returns bool corresponding to type of output
 ***********************************************/
bool query_top_scorers_out(string &filename) {
    string choice = "-1"; //dummy
    cout <<"Would you like the data as a file [a] or via the console [b]" << endl;
    do {
        cout << "(enter a or b): ";
        cin >> choice;
        cout << endl; //newline for nicer formatting in term
    } while (choice != "a" && choice != "b");

    if (choice == "a") {
        cout << "Please enter name for output file: ";
        cin >> filename;
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


/**************************************************
 * Name: query_top_scorers()
 * Description: locate top scoring player for each team
 * Parameters: team* teams -- arr of teams, int num_teams -- size of arr
 * Pre-conditions: struct is full
 * Post-conditions: calls output subproccess
 ***********************************************/
void query_top_scorers(Team* teams, int num_teams) {
    //this is so scuffed but we aren't being graded on efficiency

    //for each team
    string filename;
    bool out = query_top_scorers_out(filename);
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
        //16 lines b/c I didn't want to make this an absurdly long ternary operator
        if (!out) {
            top_score_to_cout(teams[i], teams[i].p[plr], top, tie);
        }
        else {
            top_score_to_file(teams[i], teams[i].p[plr], top, tie, filename);
        }

    }
}


/**************************************************
 * Name: sum_nationality_matches
 * Description: count how many players fit the requested nationality so a dynamic array can be created
 * Parameters: Team* teams - team arr, int num_teams - size of team arr, string nationality - nationality being searched for
 * Pre-conditions: structs are populated
 * Post-conditions: returns number of players matching criteria. It would be a lot more efficient to just find each player and
 *  print to file or cout but I didn't see a fast way to do that in 15 lines so now the whole nationality search takes 2 passes.
 ***********************************************/
int sum_nationality_matches(Team* teams, int num_teams, string nationality) {
    int out = 0;
    for (int i = 0; i < num_teams; i++) {
        for (int j = 0; j < teams[i].num_player; j++) {
            if (teams[i].p[j].nation == nationality) {
                out++;
            }
        }
    }
    if (out == 0) {
        cout << "Error: no playes with this nationality found." << endl;
    }
    return out;
}


/**************************************************
 * Name: nationality_to_cout()
 * Description: prints players in array
 * Parameters: player* players - list of players to be printed, int size (size)
 * Pre-conditions: array has been populated
 * Post-conditions: will be pritned to stdio
 ***********************************************/
void nationality_to_cout(Player* players, int size) {
    cout << "Players from " << players[0].nation << ": " << endl;
    for (int i = 0; i < size; i++) {
        cout << players[i].name << endl;
    }
}


/**************************************************
 * Name: nationality_to_file()
 * Description: Print all players in list to file
 * Parameters: player* players - list of players to be printed, int size (size)
 * Pre-conditions: array has been populated
 * Post-conditions: will be pritned to file
 ***********************************************/
void nationality_to_file(Player* players, int size) {
    ofstream writer;
    string in;
    cout << "Please enter name for output file: ";
    cin >> in;
    writer.open(in + ".txt", ios::app);
    writer << "Players from " << players[0].nation << ": " << endl;
    for (int i = 0; i < size; i++) {
        writer << players[i].name << endl;
    }
    writer.close();
}


/**************************************************
 * Name: query_nationality_out()
 * Description: asks where to print nationality data
 * Parameters: player* players - list of players to be printed, int size (size)
 * Pre-conditions: array has been populated
 * Post-conditions: calls subproccesses
 ***********************************************/
void query_nationality_out(Player* players, int size) {
    string choice = "-1"; //dummy
    cout <<"Would you like the data as a file [a] or via the console [b]" << endl;
    do {
        cout << "(enter a or b): ";
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


/**************************************************
 * Name: fetch_nationality()
 * Description: asks which nationality to look for
 * Parameters:
 * Pre-conditions:
 * Post-conditions: returns user string
 ***********************************************/
string fetch_nationality(){
    string out;
    cout << "Enter nationality: " << endl;
    cin >> out;
    return out;
}


/**************************************************
 * Name: query_nationality()
 * Description: searches data for nationalities matching request
 * Parameters: Team* teams - arr of teams, int num_teams - size
 * Pre-conditions: struct is populated
 * Post-conditions: calls subproccesses and eventually dumps data to file or stdio
 ***********************************************/
void query_nationality(Team* teams, int num_teams) {
    //team
    string nationality = fetch_nationality();
    int size = sum_nationality_matches(teams, num_teams, nationality);
    Player* matches = new Player[size];
    int index = 0;

    for (int i = 0; i < num_teams; i++) {
        for (int j = 0; j < teams[i].num_player; j++) {
            if (teams[i].p[j].nation == nationality) {
                //set next index in array to player matching criteria
                matches[index] = teams[i].p[j];
                index++;
            }
        }
    }
    query_nationality_out(matches, size);
    delete[] matches;
}


/**************************************************
 * Name: cout_ppg()
 * Description: prints sorted teams by ppg
 * Parameters: Team* teams - arr of teams, int num_teams - size
 * Pre-conditions: struct is populated, sorted
 * Post-conditions: dumps to cout
 ***********************************************/
void cout_ppg(Team* t, int size) {
    for (int i = 0; i < size; i++) {
        cout << t[i].name << " Points: " << t[i].total_ppg << endl;
    }
}


/**************************************************
 * Name: file_ppg()
 * Description: prints sorted teams by ppg
 * Parameters: Team* teams - arr of teams, int num_teams - size
 * Pre-conditions: struct is populated, sorted
 * Post-conditions: dumps to file
 ***********************************************/
void file_ppg(Team* t, int size) {
    ofstream writer;
    string in;
    cout << "Please enter name for output file: ";
    cin >> in;
    writer.open(in + ".txt", ios::app);
    for (int i = 0; i < size; i++) {
        writer << t[i].name << " Points: " << t[i].total_ppg << endl;
    }
}

/**************************************************
 * Name: sort()
 * Description: sorts teams by ppg
 * Parameters: Team* teams - arr of teams, int num_teams - size
 * Pre-conditions: struct is populated
 * Post-conditions: dumps to cout or file
 ***********************************************/
void sort(Team* t, int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (t[j].total_ppg > t[j + 1].total_ppg)
            swap(t[j], t[j+1]);
        }
    }
    cout <<"Would you like the data as a file [a] or via the console [b]" << endl;
    do {
        cout << "(enter a or b): ";
        cin >> choice;
        cout << endl; //newline for nicer formatting in term
    } while (choice != "a" && choice != "b");

    if (choice == "a") {
        file_ppg(t, size);
    }
    else if (choice == "b") {
        file_cout(t, size);
    }
}


/**************************************************
 * Name: runner()
 * Description: given user selection call subproccess
 * Parameters: string in - user choice, Team* teams - team arr, int size - size
 * Pre-conditions: struct has been populated
 * Post-conditions: will return to handler w/ whether or not to end program
 ***********************************************/
bool runner(string in, Team* teams, int size){
    if (in == "1") {
        query_name(teams, size);
    }
    else if (in == "2") {
        query_top_scorers(teams, size);
    }
    else if (in == "3") {
        query_nationality(teams, size);
    }
    else if (in == "4") {
        sort(teams, size);
    }
    else if (in == "5") {
        cout << "quitting..." << endl;
        return false;
    }
    else {
        cout << "Unknown selection slipped through checker in handler. fixme" << endl;
    }
    return true;
}


/**************************************************
 * Name: handler()
 * Description: asks for user selection
 * Parameters: Team* teams - team arr, int size - size
 * Pre-conditions: struct has been populated
 * Post-conditions: will end once user chooses 4.
 ***********************************************/
void handler(Team* teams, int size){
    string in;
    do {
        do {
            cout << "Please select a menu option (must be in range 1-5)" << endl;
            cout << "1. Search by team name" << endl << "2. List top scorers" << endl << "3. Search Players by nationality" << endl << "4. Sort by PPG" << endl << "5. Quit" << endl;
            cin >> in;
        } while (!(in == "1" || in == "2" || in == "3" || in == "4" || in == "5"));
    } while (runner(in, teams, size));
}