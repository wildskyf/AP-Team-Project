#define TESTMODE 1

#include <iostream>
#include <algorithm>
#include <vector>
#include "Player.h"
#include "Zombie.h"
#include "Map.h"

using namespace std;

#if TESTMODE

void StartMenu()
{
    cout << "-----------------------------" << endl
         << "|     Plants vs. Zombies    |" << endl
         << "-----------------------------" << endl ;
}

int main()
{
	/*
    StartMenu();

    cout << "Number of lands on the map (1-10, default:8)...>" << endl;
    */
    int land_num = 8;

    ///////////////////////////////////////////////////////////

	int zombie_num = 3;
    Zombie * zombies[zombie_num] = {};
    // Should set position
    zombies[0] = new Zombie(4);
    zombies[1] = new Zombie(5);
    zombies[2] = new Zombie(6);

    /*
    for(int i = 0 ; i < 3 ; ++i)
	{
		cout << "[" + to_string(i) + "] Damage: " + to_string(zombies[i]->attack()) + " HP:";
		for(int j = 0 ; j < zombies[i]->getFullHP(); ++j)
			cout << "*";
		cout << endl;
	}
	*/

    ///////////////////////////////////////////////////////////

	Map * game_map = new Map(land_num);
	Player player;
	vector<string> menu = player.store();

	/*
	cout << "Player has $" << player.currentMoney() << endl;
	cout << "There are " << game_map->size() <<  " planet(s) on the map:" << endl;

	for(int i = 0 ; i < game_map->size() ; ++i)
		cout << game_map->land(i) << endl;

	for(unsigned int i = 0 ; i < menu.size() ; ++i)
		cout << "[" + to_string(i) + "] " + menu[i] << endl;

	///////////////////////////////////////////////////////////

	int stand = 7;
	Plant first_plant = player.buy(1);
	Plant second_plant = player.buy(2);
	game_map->put(first_plant, stand);
	if(game_map->put(second_plant, stand))
	{
		// put plant success
	}
	else
	{
		// the place has been stood, choose another
		game_map->put(second_plant, 6);
	}

    for(int i = 0 ; i < game_map->size() ; ++i)
		cout << game_map->land(i) << endl;
	*/
	///////////////////////////////////////////////////////////

	// /*
	cout << "////// Zombie Position /////" << endl;
	for(int i = 0 ; i < zombie_num ; ++i)
		cout << "[" + to_string(i) +"] " << zombies[i]->position() << endl;

	cout << endl;

	zombies[0]->setPos(1);
	zombies[1]->setPos(2);
	zombies[2]->setPos(3);

	for(int i = 0 ; i < zombie_num ; ++i)
		cout << "[" + to_string(i) +"] " << zombies[i]->position() << endl;

	return 0;
}

#else
int main( int argc , char* argv[] )
{
	cout << "Hello, world." << endl ;
	return 0 ;
}
#endif // TESTMODE
