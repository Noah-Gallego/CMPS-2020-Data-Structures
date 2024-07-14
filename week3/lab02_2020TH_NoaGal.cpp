#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Step {
    int type;
    int coins;
};

void clearSteps(Step steps[], int size) {
    for (int i = 0; i < size; i++) {
        steps[i].type = 0;
        steps[i].coins = 0;
    }
}

//TODO
void showPath(Step steps[], int size, int pos) {
    for (int i = 0; i < size; i++) {
        if (i == pos) {
            cout << 'X';
        } else {
            cout << '_';
        }
    }
    cout << endl;
}

void addCoins(Step steps[], int size) {
    int coinValues[10] = {0, 0, 5, 0, 0, 10, 0, 0, 20, 0};
    for (int i = 0; i < size; i++) {
        int r = (rand() % 10);
        steps[i].coins = coinValues[r];
    }
}

void setStepType(Step steps[], int size, const int type, int howMany) {
    for (int i = 0; i < howMany; i++) {
        int r = (rand() % size);
        steps[r].type = type;
    }
}

int main()
{
    const int TILE = 0;
    const int OIL = 1;
    const int GLUE = 2;
    const int BANDIT = 3;

    const int DISTANCE = 20;
    Step path[DISTANCE];
    int playerpos = 0;
    bool alive = true;
    char action;
    int coins = 0;

    srand(time(NULL));

    // set all steps in the path to TILE, and all coins to ZERO
    // TODO - Call clear_steps() function
    clearSteps(path, DISTANCE);

    // randomly distribute coins along the path
    // TODO - Call add_coins() function
    addCoins(path, DISTANCE);

    setStepType(path, DISTANCE, OIL, 3);      // set 3 steps to OIL
    setStepType(path, DISTANCE, GLUE, 2);     // set 2 steps to GLUE
    setStepType(path, DISTANCE, BANDIT, 1);   // set 1 step to BANDIT

    // TODO - Set the first step to be TILE
    path[0].type = TILE;

    for (int i = 0; i < DISTANCE; i++) {
        cout << path[i].type << endl;
    }

    while (alive && playerpos < DISTANCE)
    {
        showPath(path, 20, playerpos);
        cout << "s-step, h-hop > ";
        cin >> action;

        if (path[playerpos].type == OIL && action == 'h')
        {
            cout << "You're in oil. You can only step" << endl;
            action = 's';
        }
        if (path[playerpos].type == GLUE)
        {
            cout << "You stepped in glue. That makes you a glue-ser!" << endl;
            alive = false;
        }

        if (action == 's')
            playerpos++;
        if (action == 'h')
            playerpos += 2;

        // TODO Add the coins found on the current step to 
        // player's coins haul
        coins += path[playerpos].coins;

        if (path[playerpos].type == BANDIT)
        {
            cout << "Oh no! A bandit took all your coins!" << endl;
            coins = 0;
        }

        cout << "COINS: " << coins << endl << endl; } if (playerpos >= DISTANCE)
        cout << "You WON! You crossed the path unscathed!" << endl;
    else
        cout << "You lose. Womp womp." << endl;

    return 0;
}
