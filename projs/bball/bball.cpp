/*********************************************************************
** Program Filename: bball.cpp
** Author: Troy Lopez
** Date: 10/13/23
** Description: Simulates a simple, wii sports resort style basketball game
** Input: Ints for player number and moneyrack position, y/b for play again
** Output: Scores, prompts for input, winner
*********************************************************************/

#include <iostream>

using namespace std; 

int check_int(int low, int high) {
    /*********************************************************************
    ** Function: check_int
    ** Description: Checks if entered value is in range, and prompts for input if needed
    ** Parameters: upper and lower bounds
    ** Pre-Conditions: assumes user has been told what to input
    ** Post-Conditions: valid input is returned
    *********************************************************************/

    int in;
    cin >> in;

    if (in > high || in < low) {
        do {
            cout << "I'm sorry, that number is out of range. Please try again: ";
            cin >> in;
        } while (in > high || in < low);
    }

    return in;
}


int init(){
    /*********************************************************************
    ** Function: init
    ** Description: Asks for player count and verifys input
    ** Parameters: n/a
    ** Pre-Conditions: n/a
    ** Post-Conditions: returns total players
    *********************************************************************/
    int out;

    cout << "Welcome to lame basketball!" << endl;
    cout << "How many players are there?" << endl;
    out = check_int(0, 9999999);

    return out;
}


char score_ball(int ctr, int moneyball, int ball) {
    /*********************************************************************
    ** Function: score_ball
    ** Description: based on the current rack and type of ball return correct ball notation
    ** Parameters: ctr - current rack, moneyball - rack of moneyballs, ball - ball number in rack
    ** Pre-Conditions: ball generated was a successful shot
    ** Post-Conditions: returns ball in notation
    *********************************************************************/    
    if (ctr == 3 || ctr == 5) { //moneyball pedestals
        return 'w';
    }
    else if (ctr == moneyball || ball == 4) { //moneyball rack or ball is 5th on rack
        return 'm';
    }
    else { //regular ball
        return 'o';
    }
}


int score_rack(char rack[5], int ctr){
    /*********************************************************************
    ** Function: score rack
    ** Description: iterate through a rack of balls (may be starry) and generate each ball
    ** Parameters: the array of scored balls, the current rack number
    ** Pre-Conditions: rack array has been populated with scored balls [o x x o m]
    ** Post-Conditions: returns score to be added to running total
    *********************************************************************/
    int score = 0;

    //if the current rack is a starryball pedestal, only score the first ball
    if (ctr == 3 || ctr == 5) {
        cout << "Starryball shot: " << rack[0] << endl;

        //ternary operator to streamline score printing
        cout << (rack[0] == 'w' ? "3 pts" : "0 pts") << endl << endl;
        if (rack[0] == 'w') {score += 3;}
    }

    else {
        //note size is hardcoded here
        for (int i = 0; i < 5; i++) {
            cout << rack[i] << " ";
            if (rack[i] == 'o') {score++;}
            else if (rack[i] == 'm') {score += 2;}
        }
        cout << endl << "Rack Score is: " << score << endl << endl;
    }
    return score;
}


int generate_racks(int moneyball, int player) {
    /*********************************************************************
    ** Function: genereate_racks
    ** Description: populate each rack with made/missed shots
    ** Parameters: player number and moneyball location
    ** Pre-Conditions: user chooses moneyball rack
    ** Post-Conditions: returns total score
    *********************************************************************/

   //increment player number BEFORE printing it b/c index is 1 less than player number
    cout << "+--------------------+" << endl << "Player " << ++player << ": " << endl;
    
    int out = 0;
    char rack[5];
    for (int ctr = 1; ctr < 7; ctr++){
        int lim;
        (ctr == 3 || ctr == 5) ? lim = 1 : lim = 5;
        for (int i = 0; i < lim; i++) {
            if (rand() % 2) {
                rack[i] = score_ball(ctr, moneyball, i);
            }
            else {
                rack[i] = 'x';
            }
        }
        out += score_rack(rack, ctr);
    }

    // total score is stored in an array so the winner can be determined.
    cout << endl <<"Total Score: " << out << endl;
    cout << "+--------------------+" << endl;
    return out;
}


int ask_moneyball(){
    /*********************************************************************
    ** Function: ask_moneyball
    ** Description: prompts user to choose rack of moneyballs
    ** Parameters: n/a
    ** Pre-Conditions: player's turn has started
    ** Post-condtions: returns moneyball locaction
    *********************************************************************/
    int out;
    cout << "Which rack should be all moneyballs? (1-5)" << endl;
    out = check_int(1,5);

    switch (out) {
        case 3:
            out = 4;
            break;
        case 4:
            out = 6;
            break;
        case 5:
            out = 7;
            break;
        default:
            break;
    }
    return out;
}


void final_score(int* scores, int len) {
    /*********************************************************************
    ** Function: final score
    ** Description: find largest score and print winner
    ** Parameters: dynarray of scores, total players (len)
    ** Pre-Conditions: assumes score array is populated; otherwise returns tie with score 0
    ** Post-Conditions: game is complete
    *********************************************************************/
    int highscore = 0;
    int winner = 0;
    int tie = false;

    //find highest score in array, note it there is a tie
    for (int i = 0; i < len; i++) {
        if (scores[i] > highscore) {
            highscore = scores[i];
            winner = i;
            tie = false;
        }
        else if (scores[i] == highscore) {
            tie = true;
        }
    }

    //one-liners for brevity. winner is incremented b/c index is 1 less than player number
    if (!tie || len == 1) {cout << "Winner was player " << winner + 1 << " with score " << highscore << endl;}
    else {cout << "There was a tie, the highest score was " << highscore << endl;}
}


bool play_again() {
    /*********************************************************************
    ** Function: play_again
    ** Description: ask if player wants to play again, follows logic of int input validator
    ** Parameters: n/a
    ** Pre-Conditions: game has ended
    ** Post-Conditions: program may terminate
    *********************************************************************/
    string in;
    cout << "Would you like to play again? " << endl;
    do {
        cout << "Please enter y or n: ";
        cin >> in;
    } while (!(in == "y" || in == "n"));

    if (in == "y") {return true;}
    else {return false;}
}


int main () {
    //main function, see program header for details

    //seed rand based on time
    srand(time(nullptr));
    do {
        int players = init();
        //create dynarray with length equal to number of players
        int *scoreboard = new int[players];

        //for each player generate racks of balls based on moneyball location
        //and add score to corresponding spot on scoreboard
        for (int i = 0; i < players; i++) {
            scoreboard[i] = generate_racks(ask_moneyball(), i);
        }

        //calculate final score
        final_score(scoreboard, players);
        //free up memory
        delete[] scoreboard;

    //while player wants to play again
    } while (play_again());
}
