#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

struct Player {
    bool is_alive = true;
    bool has_gold = false;
    bool win = false;

    int bat_duration = 0;

    int x_location;
    int y_location;
};

#endif