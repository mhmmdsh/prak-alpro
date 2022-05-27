/* 2D TILE GAMES
POKEMON GAME
@ = Player  (Player location)
R = Road    (Player can move on it)
P = Puddle  (Player can move on it)
B = Bush    (Player can move on it)
W = Wall    (Player can't move on it)
T = Tree    (Player can't move on it)
S = Stone   (Player can't move on it) */

#include <conio.h>
#include <iostream>
using namespace std;

int main() {
    int mapSize = 20;     // Size of the map
    int playerPosX = 10;   // Player's position X
    int playerPosY = 19;  // Player's position Y

    cout << "Karakter ada di y:" << playerPosY << ", x:" << playerPosX << "\n";

    // Map
    char map[mapSize][mapSize] = {
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
        //1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18   19   20
    };

    /*
    ARROW_KEY_UP    = 72
    ARROW_KEY_LEFT  = 75
    ARROW_KEY_RIGHT = 77
    ARROW_KEY_DOWN  = 80
    */

    int arrowKey = 0;

    // GAME LOOP SECTION
    while (true) {
        // Input keyboard
    arrow_input:
        cout << "Masukkan arrow key: ";
        arrowKey = getch();
        if (arrowKey == 72) {
            cout << "Up\n";
        } else if (arrowKey == 75) {
            cout << "Left\n";
        } else if (arrowKey == 77) {
            cout << "Right\n";
        } else if (arrowKey == 80) {
            cout << "Down\n";
        } else {
            goto arrow_input;
        }

        // MOVE PLAYER RULE SECTION
        if (arrowKey == 72 && playerPosY > 0) {               // Upward rule
            if (map[playerPosY - 1][playerPosX] == 'R' || map[playerPosY - 1][playerPosX] == 'P' || map[playerPosY - 1][playerPosX] == 'B') {
                playerPosY--;
            }
        }
        
        if (arrowKey == 75 && playerPosX > 0) {        // Leftward rule
            if (map[playerPosY][playerPosX - 1] == 'R' || map[playerPosY][playerPosX - 1] == 'P' || map[playerPosY][playerPosX - 1] == 'B') {
                playerPosX--;
            }
        } 
        
        if (arrowKey == 77 && playerPosX < (mapSize - 1)) {  // Rightward rule
            if (map[playerPosY][playerPosX + 1] == 'R' || map[playerPosY][playerPosX + 1] == 'P' || map[playerPosY][playerPosX + 1] == 'B') {
                playerPosX++;
            }
        }
        
        if (arrowKey == 80 && playerPosY < (mapSize - 1)) {  // Downward rule
            if (map[playerPosY + 1][playerPosX] == 'R' || map[playerPosY + 1][playerPosX] == 'P' || map[playerPosY + 1][playerPosX] == 'B') {
                playerPosY++;
            }
        }

        // Print map and player position
        for (int y = 0; y < mapSize; y++) {
            for (int x = 0; x < mapSize; x++) {
                if (y == playerPosY && x == playerPosX) {
                    cout << "@" << " ";
                } else {
                    cout << map[y][x] << " ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}