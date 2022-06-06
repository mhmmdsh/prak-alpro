#include <conio.h>
#include <iostream>
#include "include\color.hpp"
using std::cout, std::cin, std::endl, std::string;
using namespace dye;

/*
 * 2D RPG Game
 * @    = Player
 * ^    = Ground
 * D    = Door
 * W    = Wall
 * P    = Puddle
 * T    = Treasure
 * O    = Orc
 * G    = Goblin
 */

// DEFINE KEYBOARD INPUTS
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27
#define KEY_ENTER 13

// FILL MAP WITH CHARACTERS RANDOMLY
char map_randomizer() {
    char charReturn;
    int random = rand() % 10;
    if (random == 1 || random == 9 || random == 8) {
        charReturn = '^';
    } else if (random == 2 || random == 7 || random == 6) {
        charReturn = 'P';
    } else if (random == 3) {
        charReturn = 'T';
    } else if (random == 4) {
        charReturn = 'O';
    } else if (random == 5) {
        charReturn = 'G';
    }
    return charReturn;
}

// HERO STRUCT
struct hero {
    string username;
    string hero_name;
    int hp;
    int atk;
    int def;
    int gold;

    void basic_atk(int *hp_obj, int *def_obj) {
        int damage = (atk * 2) - *def_obj;
        cout << "You deal " << yellow(damage) << " damage to the monster with basic attack!\n";
        *hp_obj -= damage;
    }

    void special_atk(int *hp_obj, int *def_obj) {
        int damage = (atk * 5) - *def_obj;
        cout << "You deal " << red(damage) << " damage to the monster with special attack!\n";
        *hp_obj -= damage;
    }
};

// MONSTER STRUCT
struct monster {
    string monster_name;
    int hp;
    int atk;
    int def;

    void monster_atk(string name_obj ,int *hp_obj, int *def_obj) {
        int damage = (atk * 2) - *def_obj;
        cout << "\nThe " << name_obj << " deal " << yellow(damage) << " damage to you!\n";
        *hp_obj -= damage;
    }
};

int main() {
    int input_key;
    int monster_atk_counter;
    int map_size = 10;
    int middle_map = map_size / 2;
    int player_x = middle_map;
    int player_y = map_size - 1;
    char map[map_size][map_size];

    hero player;
    monster orc;
    monster goblin;

    cout << "Welcome to 2D RPG Game!\n";
    cout << "Please enter your name: ";
    std::getline(cin, player.username);

    cout << "Select your hero: \n";
    cout << "1. Ashe\n";
    cout << "2. Lucian\n";
    cout << "3. Darius\n";
    cout << "4. Jhin\n";
    cout << "5. Ezreal\n";
select_hero:
    cout << "Input: ";
    cin >> input_key;

    if (input_key == 1) {
        player.hero_name = "Ashe";
        player.hp = 200;
        player.atk = 20;
        player.def = 5;
    } else if (input_key == 2) {
        player.hero_name = "Lucian";
        player.hp = 200;
        player.atk = 20;
        player.def = 5;
    } else if (input_key == 3) {
        player.hero_name = "Darius";
        player.hp = 400;
        player.atk = 15;
        player.def = 10;
    } else if (input_key == 4) {
        player.hero_name = "Jhin";
        player.hp = 200;
        player.atk = 20;
        player.def = 5;
    } else if (input_key == 5) {
        player.hero_name = "Jayce";
        player.hp = 250;
        player.atk = 15;
        player.def = 10;
    } else {
        cout << "Invalid input!\n";
        goto select_hero;
        return 0;
    }

    // PLAYER GOLD INIT
    player.gold = 0;

    // INIT MAP
    for (int y = 0; y < map_size; y++) {
        for (int x = 0; x < map_size; x++) {
            if (y == 0 && (x == middle_map - 1 || x == middle_map)) {
                map[y][x] = 'D';
            } else if (x == middle_map - 1 || x == middle_map) {
                map[y][x] = '^';
            } else if ((y == 0 || y == map_size - 1) || (x == 0 || x == map_size - 1)) {
                map[y][x] = 'W';
            } else {
                map[y][x] = map_randomizer();
            }
        }
    }

    while (true) {
        system("CLS");
    player_move:
        // PRINT MAP
        cout << "Player Position x: " << player_x << ", y: " << player_y << endl;
        for (int y = 0; y < map_size; y++) {
            for (int x = 0; x < map_size; x++) {
                if (y == player_y && x == player_x) {
                    cout << purple("@") << " ";
                } else if (map[y][x] == '^') {
                    cout << grey("^") << " ";
                } else if (map[y][x] == 'P') {
                    cout << aqua("P") << " ";
                } else if (map[y][x] == 'T') {
                    cout << yellow("T") << " ";
                } else if (map[y][x] == 'O') {
                    cout << green("O") << " ";
                } else if (map[y][x] == 'G') {
                    cout << green("G") << " ";
                } else if (map[y][x] == 'W') {
                    cout << red("W") << " ";
                } else {
                    cout << map[y][x] << " ";
                }
            }
            cout << endl;
        }

        cout << "Press Arrow Keys to move\n";
        cout << "Press Enter to show your stats\n";
        cout << "Press ESC to exit\n";
        cout << "Input: ";
        input_key = getch();

        // PLAYER MOVEMENT
        if (input_key == KEY_UP && player_y > 0) {
            if (map[player_y - 1][player_x] == 'W') {
                cout << "Cannot move up!\n";
            } else {
                player_y--;
            }
        } else if (input_key == KEY_DOWN && player_y < map_size - 1) {
            if (map[player_y + 1][player_x] == 'W') {
                cout << "Cannot move down!\n";
            } else {
                player_y++;
            }
        } else if (input_key == KEY_LEFT && player_x > 0) {
            if (map[player_y][player_x - 1] == 'W') {
                cout << "Cannot move left!\n";
            } else {
                player_x--;
            }
        } else if (input_key == KEY_RIGHT && player_x < map_size - 1) {
            if (map[player_y][player_x + 1] == 'W') {
                cout << "Cannot move right!\n";
            } else {
                player_x++;
            }
        } else if (input_key == KEY_ENTER) {
            if (map[player_y][player_x] == 'D') {
                cout << "\nYou found the door!\n";
                cout << "You will exit from this map!\n";
                getch();
                break;
            } else {
                cout << "\nYour stats:\n";
                cout << "Name   : " << player.username << endl;
                cout << "Hero   : " << player.hero_name << endl;
                cout << "HP     : " << player.hp << endl;
                cout << "ATK    : " << player.atk << endl;
                cout << "DEF    : " << player.def << endl;
                cout << "Gold   : " << player.gold << endl;
                getch();
            }
        } else if (input_key == KEY_ESC) {
            cout << "Exiting game..." << endl;
            break;
        }

        // MONSTER FIGHT
        if (map[player_y][player_x] == 'O') {
            orc.monster_name = "Orc";
            orc.hp = 150;
            orc.atk = 10;
            orc.def = 5;
            cout << "\nYou encountered an Orc!\n";
            while (true) {
                monster_atk_counter = rand() % 2;
                cout << red("\nOrc HP  : ") << red(orc.hp) << endl;
                cout << green("Your HP : ") << green(player.hp) << endl;
                cout << "\nPress UP to attack\n";
                cout << "Press DOWN to use special attack\n";
            orc_fight:
                cout << "Input: ";
                input_key = getch();

                system("CLS");

                if (input_key == KEY_UP && orc.hp > 0) {
                    player.basic_atk(&orc.hp, &orc.def);
                } else if (input_key == KEY_DOWN && orc.hp > 0) {
                    player.special_atk(&orc.hp, &orc.def);
                } else {
                    cout << "Invalid input!\n";
                    goto orc_fight;
                }

                if (monster_atk_counter == 0) {
                    orc.monster_atk(orc.monster_name, &player.hp, &player.def);
                } else {
                    cout << "\nYou dodged the Orc's attack!\n";
                }

                if (orc.hp <= 0) {
                    cout << "\nYou killed the Orc!\n";
                    map[player_y][player_x] = '^';
                    getch();
                    goto player_move;
                } else if (player.hp <= 0) {
                    cout << "\nYou died!\n";
                    getch();
                    return 0;
                }
            }
        } else if (map[player_y][player_x] == 'G') {
            goblin.monster_name = "Goblin";
            goblin.hp = 100;
            goblin.atk = 10;
            goblin.def = 5;
            cout << "\nYou encountered a Goblin!\n";
            while (true) {
                monster_atk_counter = rand() % 2;
                cout << red("\nGoblin HP : ") << red(goblin.hp) << endl;
                cout << green("Your HP   : ") << green(player.hp) << endl;
                cout << "\nPress UP to attack\n";
                cout << "Press DOWN to use special attack\n";
            goblin_fight:
                cout << "Input: ";
                input_key = getch();

                system("CLS");

                if (input_key == KEY_UP && goblin.hp > 0) {
                    player.basic_atk(&goblin.hp, &goblin.def);
                } else if (input_key == KEY_DOWN && goblin.hp > 0) {
                    player.special_atk(&goblin.hp, &goblin.def);
                } else {
                    cout << "Invalid input!\n";
                    goto goblin_fight;
                }

                if (monster_atk_counter == 0) {
                    goblin.monster_atk(goblin.monster_name, &player.hp, &player.def);
                } else {
                    cout << "\nYou dodged the Goblin's attack!\n";
                }

                if (goblin.hp <= 0) {
                    cout << "\nYou killed the Goblin!\n";
                    map[player_y][player_x] = '^';
                    getch();
                    break;
                } else if (player.hp <= 0) {
                    cout << "\nYou died!\n";
                    getch();
                    return 0;
                }
            }
        }

        // CHECK IF PLAYER IS ON A TREASURE
        if (map[player_y][player_x] == 'T') {
            cout << "You found a treasure!\n";
            player.gold = player.gold + rand() % 1000 + 1;
            map[player_y][player_x] = '^';
            getch();
            system("CLS");
            goto player_move;
        }
    }

    return 0;
}