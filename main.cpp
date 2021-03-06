#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Game.h"

using namespace std;

void DisplayBar(){
    cout << string(77,'=') << endl;
}

void Wait(){
    cout << "Press any key to continue...";
    cin.get();
    cout << endl;
}

void Clear(){
#ifdef _WIN32
    system( "cls" ) ;
#else
    cout << string(50,'\n') ;
#endif
}

void DisplayRule()
{
    DisplayBar();
    cout << "Plants vs. Zombies Rule:" << endl << endl
    << "How to win:" << endl
    << "  (1) All zombies are dead." << endl
    << "  (2) At least one plant is live." << endl
    << "  (3) The number of dead bomb plants cannot exceed the number of zombies." << endl << endl
    << "How to lose:" << endl
    << "  All plants are dead." << endl;
    DisplayBar();
    Wait();
    Clear();
}

int main()
{
    srand(time(NULL));

    cout << "-----------------------------" << endl
         << "|     Plants vs. Zombies     |" << endl
         << "-----------------------------" << endl ;
    cout << "Number of lands on the map (1-" << Map::maxLand << ", default:" << Game::defaultLand << ")...>";

    char c ;
    int zombienum = 0 , landnum = 0 ;
    while( c = getchar() , c != '\n' ) {
        landnum *= 10 ;
        landnum += (c-'0') ;
    }
    if( !landnum ) landnum = Game::defaultLand ;

    cout << "Number of zombies on the map (1-" << Zombie::maxZombie << ", default:" << Game::defaultZombie << ")...>";
    while( c = getchar() , c != '\n' ) {
        zombienum *= 10 ;
        zombienum += (c-'0') ;
    }
    if( !zombienum ) zombienum = Game::defaultZombie ;

    Game game(landnum,zombienum);
    DisplayRule();

    do{
        game.DisplayMap();
        DisplayBar();
        game.DisplayZombieInfo();
        DisplayBar();
        game.DisplayOfPlant();

        cout << endl;
        game.PlayerAction();
        Wait();
        if( game.isLose() || game.deadTooMany() ) break ;
        Clear();
        game.ZombieAction();
        Clear();
        game.NextStep();

    }while( !game.isLose() && !game.isWin() ) ;

    Clear() ;
    if( game.deadTooMany() )
        cout << endl << endl << endl << "You lose the game since you cannot use that many bomb plants!" << endl;
    else if(game.isWin())
        cout << endl << endl << endl << "Congratulations! You have killed all zombies!" << endl;
    else if(game.isLose())
        cout << endl << endl << endl << "Oh no... You have no plant on the map ...." << endl;

    Wait();
	return 0;
}


