#include<iostream>
#include"room.h"
#include "player.h"
#include "enemy.h"
#include<vector>

using namespace std;

/*
  ****ARSH ANAND**** 
  Worked here on the game class on the pointers to the rooms
  Defined the rooms and its types for use in the game.
*/

class game{
  private:
    room* currRoom = nullptr;
    Player* player = nullptr;

  
    //the rooms
    room start{"NEUTRAL","Start",false,false};
    // Room1 (B) - Filter Foyer
    room Room1{"NEUTRAL","Filter Foyer",true,false};
    //Room2 (M) - Aroma Arcade
    room Room2{"MINIGAME","Aroma Arcade",false,true};
    //Room3 (B) - Barista Boudoir
    room Room3{"BATTLE","Barista Boudoir",true,false};
    //Room4 (B) - Roaster's Retreat
    room Room4{"BATTLE","Roaster's Retreat",true,false};
    //Room5 (M) - Espresso Enclave
    room Room5{"MINIGAME","Espresso Enclave",false,true};
    //Room6 (B) - Mocha Maze
    room Room6{"BATTLE","Mocha Maze",true,false};
    //Room7 (M) - Latte Lounge
    room Room7{"MINIGAME","Latte Lounge",false,true};
    //Room8 (B)- Crema Castle
    room Room8{"BATTLE","Crema Castle",true,false};
    //Room9 (B) - Bean Chamber
    room Room9{"BATTLE","Bean Chamber",true,false};
    //Room10 (B) - Decaf Den
    room Room10{"BATTLE","Decaf Den",true,false};
    //Room11 (B) - Scone Salon
    room Room11{"BATTLE","Scone Salon",true,false};
    //Room12 (M) - Pour-Over Passage
    room Room12{"MINIGAME","Pour-Over Passage",false,true};
    //Room13 (M) - Lobby Latte
    room Room13{"MINIGAME","Lobby Latte",false,true};
    //Room14 (B) - Cappuccino Corridor
    room Room14{"BATTLE","Cappuccino Corridor",true,false};
    //Room15 (M) - Java Jamboree
    room Room15{"MINIGAME","Java Jamboree",false,true};
    //Room16 (M) - Beanstalk Ballroom
    room Room16{"MINIGAME","Beanstalk Ballroom",false,true};
    //Room17 (B) - French Press Fortress
    room Room17{"BATTLE","French Press Fortress",true,false};
    //Room18 (M) - Brewer's Havem
    room Room18{"MINIGAME","Brewer's Havem",false,true};
    //end room
    room end{"Neutral","END",false,false};


    //vector of enemies
    vector<Enemy> Enemies;
               
    //vector of riddles and their answers
    vector<string> riddles;
    vector<string> answers;

               
  public:
//declaration of all the functions we will use in the game
    game(Player &p);
    void initMap();
    void battle(Enemy &Opponent,vector<Weapon> w, vector<Weapon> p);
    void play(vector<Weapon> w, vector<Weapon> p);
    void Riddles(vector<Weapon> w, vector<Weapon> p);
    void InfoForUser();
    void randomDrop(vector<Weapon> w, vector<Weapon> p);
    void initRiddles();
    Player *getPlayer();
    void getTitle();
    Enemy getEnemy(int lv);
    void initEnemies();

};