/* GAME EVENT REQUIREMENTS
Requirements to join the event:
- Melee only
- Min. level requirements: lvl 30 */

#include <iostream>
using namespace std;

struct playerInfoS {
    string username;
    string heroRole;
    string heroType;
    int level;
};

int main() {
    playerInfoS playerInfo[] = {
    {
      "anti_marksman",
      "Fighter",
      "Melee",
      35
    },
    {
      "DemonSlayer",
      "Assasin",
      "Melee",
      10
    },
    {
      "TheProtector911",
      "Guardian",
      "Melee",
      9
    },
    {
      "GoblinSlayer",
      "Assasin",
      "Melee",
      31
    },
    {
      "TheAncestor",
      "Mage",
      "Ranged",
      41
    },
    {
      "RangeShooter",
      "Marksmen",
      "Ranged",
      21
    },
    {
      "OnlyFighter",
      "Fighter",
      "Melee",
      14
    },
    {
      "MaxHP+++",
      "Guardian",
      "Melee",
      39
    },
  };
  
    int playerInfoSize = sizeof(playerInfo) / sizeof(playerInfo[0]);
    int minLvlPlayer = 30;
    string typeReq = "Melee";

    cout << "Welcome to the event!" << endl;
    cout << "Here are the requirements:" << endl;
    cout << "Minimum level: " << minLvlPlayer << endl;
    cout << "Hero Type: " << typeReq << endl;
    cout << "\nPlayer who not meet the requirements :" << endl;

    for (int i = 0; i < playerInfoSize; i++)
    {
        while (playerInfo[i].level < minLvlPlayer || playerInfo[i].heroType != typeReq)
        {
            cout << "- Player " << playerInfo[i].username << " is not eligible to join the event." << endl;
            cout << "  The hero type is " << playerInfo[i].heroType << " and the level is " << playerInfo[i].level << endl;
            break;
        }
    }

    cout << "\nPlayer who eligible to join the event: " << endl;
    for (int i = 0; i < playerInfoSize; i++)
    {
        if (playerInfo[i].level < minLvlPlayer || playerInfo[i].heroType != typeReq)
        {
            continue;
        }
        cout << "- " << playerInfo[i].username 
        << ", Lvl(" << playerInfo[i].level << ") " << "Hero Type(" << playerInfo[i].heroType << ")" << endl;
    }
  
  return 0;
}