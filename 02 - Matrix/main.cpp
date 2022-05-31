/* 2D TILE GAMES
POKEMON GAME
@ = Player  (Purple - Player location)
R = Road    (White  - Player can move on it)
P = Puddle  (Aqua   - can move on it)
B = Bush    (Green  - can move on it)
W = Wall    (Red    - Player can't move on it)
T = Tree    (Yellow - Player can't move on it)
S = Stone   (Grey   - Player can't move on it) */

#include <conio.h>
#include <iostream>
#include "include\color.hpp"
using namespace std;

struct pokemonStats {
    string name;
    int hp;
    int atk;
    int def;
    int spd;
};

int main() {
    int mapSize = 20;      // Size of the map
    int playerPosX = 10;   // Player's position X
    int playerPosY = 19;   // Player's position Y
    int pokemonCount = 0;  // Count of pokemon caught
    int pokemonChance;     // Chance of pokemon being caught
    pokemonStats pokemon[] = {
        // Pokemon list
        {"Bulbasaur",
         45,
         49,
         49,
         45},
        {"Ivysaur",
         60,
         62,
         63,
         60},
    };
    char map[mapSize][mapSize] = {
        // Map
        {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'R', 'R', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},  // 1
        {'S', 'S', 'P', 'B', 'B', 'B', 'S', 'P', 'B', 'R', 'R', 'S', 'S', 'P', 'P', 'P', 'P', 'B', 'B', 'B'},  // 2
        {'P', 'P', 'P', 'B', 'B', 'B', 'S', 'P', 'T', 'R', 'R', 'T', 'S', 'R', 'R', 'P', 'P', 'R', 'B', 'B'},  // 3
        {'P', 'R', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'B', 'B'},  // 4
        {'S', 'R', 'R', 'T', 'B', 'B', 'B', 'S', 'S', 'R', 'R', 'S', 'S', 'T', 'R', 'T', 'B', 'R', 'R', 'S'},  // 5
        {'R', 'R', 'R', 'B', 'B', 'B', 'B', 'S', 'T', 'R', 'R', 'T', 'S', 'S', 'R', 'B', 'B', 'R', 'T', 'S'},  // 6
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'R', 'R', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},  // 7
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'R', 'R', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},  // 8
        {'S', 'S', 'R', 'R', 'B', 'B', 'S', 'S', 'T', 'R', 'R', 'T', 'S', 'S', 'R', 'R', 'R', 'R', 'S', 'S'},  // 9
        {'S', 'S', 'B', 'B', 'B', 'B', 'B', 'S', 'S', 'R', 'R', 'S', 'S', 'B', 'B', 'B', 'B', 'P', 'B', 'B'},  // 10
        {'S', 'B', 'B', 'B', 'B', 'B', 'B', 'P', 'P', 'R', 'R', 'R', 'B', 'B', 'B', 'B', 'T', 'P', 'B', 'B'},  // 11
        {'S', 'B', 'B', 'B', 'B', 'B', 'B', 'P', 'T', 'R', 'R', 'T', 'B', 'B', 'B', 'B', 'P', 'P', 'R', 'B'},  // 12
        {'R', 'R', 'R', 'R', 'R', 'T', 'R', 'P', 'S', 'R', 'R', 'P', 'B', 'B', 'B', 'B', 'R', 'R', 'R', 'B'},  // 13
        {'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'P', 'B', 'B', 'B', 'R', 'B', 'B', 'T', 'B'},  // 14
        {'P', 'R', 'R', 'R', 'R', 'B', 'B', 'B', 'T', 'R', 'R', 'T', 'P', 'P', 'R', 'R', 'B', 'B', 'B', 'B'},  // 15
        {'P', 'P', 'T', 'R', 'B', 'B', 'B', 'B', 'B', 'R', 'R', 'R', 'P', 'T', 'R', 'R', 'R', 'P', 'B', 'B'},  // 16
        {'S', 'P', 'P', 'R', 'B', 'B', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'B', 'B', 'B', 'T', 'P', 'P', 'P'},  // 17
        {'S', 'S', 'B', 'B', 'T', 'R', 'R', 'R', 'T', 'R', 'R', 'T', 'R', 'R', 'B', 'B', 'S', 'P', 'P', 'P'},  // 18
        {'S', 'S', 'B', 'B', 'B', 'R', 'R', 'R', 'R', 'R', 'R', 'S', 'S', 'R', 'B', 'B', 'P', 'R', 'R', 'S'},  // 19
        {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'R', 'R', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},  // 20
        // 1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18   19   20
    };

    cout << "Player position, y:" << playerPosY + 1 << ", x:" << playerPosX + 1 << "\n";
    cout << "Game rules:\n";
    cout << "@ = Player (Player location)\n";
    cout << "R = Road   (Player can move on it)\n";
    cout << "P = Puddle (Player can move on it)\n";
    cout << "B = Bush   (Player can move on it)\n";
    cout << "S = Stone  (Player can't move on it)\n";
    cout << "T = Tree   (Player can't move on it)\n";
    cout << "W = Wall   (Player can't move on it)\n";
    int keyIn = 0;

    // GAME LOOP SECTION
    while (true) {
        // Chance of pokemon appearing (20% chance)
        pokemonChance = rand() % 10;

        /* Input keyboard
        ARROW_KEY_UP    = 72
        ARROW_KEY_LEFT  = 75
        ARROW_KEY_RIGHT = 77
        ARROW_KEY_DOWN  = 80
        ESC_KEY         = 27 */
    arrow_input:
        cout << "Press ARROW KEY to move or ESC to quit\n";
        cout << "Insert key: ";
        keyIn = getch();
        if (keyIn == 72) {
            cout << "Up\n";
        } else if (keyIn == 75) {
            cout << "Left\n";
        } else if (keyIn == 77) {
            cout << "Right\n";
        } else if (keyIn == 80) {
            cout << "Down\n";
        } else if (keyIn == 27) {
            cout << "Exit\n";
            break;
        } else {
            goto arrow_input;
        }

        // Clear screen
        system("cls");

        // MOVE PLAYER RULE SECTION
        if (keyIn == 72 && playerPosY > 0) {
            if (map[playerPosY - 1][playerPosX] == 'R' || map[playerPosY - 1][playerPosX] == 'P' || map[playerPosY - 1][playerPosX] == 'B') {
                playerPosY--;
            }
        } else if (keyIn == 75 && playerPosX > 0) {
            if (map[playerPosY][playerPosX - 1] == 'R' || map[playerPosY][playerPosX - 1] == 'P' || map[playerPosY][playerPosX - 1] == 'B') {
                playerPosX--;
            }
        } else if (keyIn == 77 && playerPosX < (mapSize - 1)) {
            if (map[playerPosY][playerPosX + 1] == 'R' || map[playerPosY][playerPosX + 1] == 'P' || map[playerPosY][playerPosX + 1] == 'B') {
                playerPosX++;
            }
        } else if (keyIn == 80 && playerPosY < (mapSize - 1)) {
            if (map[playerPosY + 1][playerPosX] == 'R' || map[playerPosY + 1][playerPosX] == 'P' || map[playerPosY + 1][playerPosX] == 'B') {
                playerPosY++;
            }
        }

        // DRAW MAP SECTION
        // Print map and player position
        for (int y = 0; y < mapSize; y++) {
            for (int x = 0; x < mapSize; x++) {
                if (y == playerPosY && x == playerPosX) {
                    cout << dye::purple("@") << " ";
                } else {
                    if (map[y][x] == 'P') {
                        cout << dye::aqua("P") << " ";
                    } else if (map[y][x] == 'B') {
                        cout << dye::light_green("B") << " ";
                    } else if (map[y][x] == 'T') {
                        cout << dye::yellow("T") << " ";
                    } else if (map[y][x] == 'W') {
                        cout << dye::red("W") << " ";
                    } else if (map[y][x] == 'S') {
                        cout << dye::grey("S") << " ";
                    } else {
                        cout << map[y][x] << " ";
                    }
                }
            }
            cout << endl;
        }

        // Alert message can't move on defined objects
        if (keyIn == 72 && playerPosY > 0) {
            if (map[playerPosY - 1][playerPosX] == 'W' || map[playerPosY - 1][playerPosX] == 'S' || map[playerPosY - 1][playerPosX] == 'T') {
                cout << "You can't go there!\n";
            }
        } else if (keyIn == 75 && playerPosX > 0) {
            if (map[playerPosY][playerPosX - 1] == 'W' || map[playerPosY][playerPosX - 1] == 'S' || map[playerPosY][playerPosX - 1] == 'T') {
                cout << "You can't go there!\n";
            }
        } else if (keyIn == 77 && playerPosX < (mapSize - 1)) {
            if (map[playerPosY][playerPosX + 1] == 'W' || map[playerPosY][playerPosX + 1] == 'S' || map[playerPosY][playerPosX + 1] == 'T') {
                cout << "You can't go there!\n";
            }
        } else if (keyIn == 80 && playerPosY < (mapSize - 1)) {
            if (map[playerPosY + 1][playerPosX] == 'W' || map[playerPosY + 1][playerPosX] == 'S' || map[playerPosY + 1][playerPosX] == 'T') {
                cout << "You can't go there!\n";
            }
        }

        // POKEMON APPEAR RULE SECTION
        if (map[playerPosY][playerPosX] == 'R') {
            cout << "You are on a road\n";
        } else if (map[playerPosY][playerPosX] == 'P') {
            cout << "You are on a puddle\n";
        } else if (map[playerPosY][playerPosX] == 'B') {
            cout << "You are on a bush\n";
            if (pokemonChance == 1) {
                cout << "You found a " << pokemon[0].name << endl;
                pokemonCount++;
            } else if (pokemonChance == 2) {
                cout << "You found a " << pokemon[1].name << endl;
                pokemonCount++;
            }
            pokemonChance = 0;
        }
    }

    cout << "Game exitted...";
    getch();
    return 0;
}