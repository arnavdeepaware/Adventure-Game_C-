#include "game.h"
#include "enemy.h"
#include "weapon.h"
#include <ctime>
#include <string>
#include <unistd.h>
#include <vector>
using namespace std;


/* ****ADITYA JHA**** 
  Worked on the game class as a whole. Created the battle function, the play function, the riddle function and the title function
  Worked on proerly formatting and presenting the game to the user.
  Also cleaned up the comments
*/

/* ****ARSH ANAND**** 
  Enemy initialization & its usage compared to player level
  Enemy damage optimized after after testing
*/

/* *** ARNAV DEEPAWARE ***  
  - Created InfoForUser() and randomDrop() functions
  - Improvised switch case when player views weapons or anti-weapons but does not change them. The player's chance is not considered in this        scenario and gets to choose their actions again.
*/




//constructor to initialize the player of this class
game::game(Player &p) 
{ 
  this->player = &p; 
}

void game::initEnemies()
{
  this->Enemies.push_back(Enemy(100, 5, "Americreeper", 1));
  this->Enemies.push_back(Enemy(100, 8, "Frappulon", 2));
  this->Enemies.push_back(Enemy(100, 10, "Cappuchupacabra", 3));
  this->Enemies.push_back(Enemy(100, 14, "Decafdaemon", 4));
  this->Enemies.push_back(Enemy(100, 20, "Caffenix", 5));
  this->Enemies.push_back(Enemy(100, 25, "Espressogeist", 6));
  this->Enemies.push_back(Enemy(100, 27, "JavaGorgon",7));
  this->Enemies.push_back(Enemy(100, 30, "Frappterror",8));
  this->Enemies.push_back(Enemy(100, 35, "Cremacrawler",9));
  this->Enemies.push_back(Enemy(100, 35, "Espresso-Octopus",10));


}

//returns an enemy from the Enemies vector based on the player level
Enemy game::getEnemy(int lv)
{
  //if the player level gets too high (unlikely), repeat thru the toughest enemies
  
  if(lv>=this->Enemies.size())
  {
    srand(0);
    lv = 7+rand()%(this->Enemies.size()-7);
  }
  return this->Enemies.at(lv);
}

// ARSH - Worked on the map. Making the map so that rooms connect to each in a way so that the player can travel through the map
// Initialzed the map

void game::initMap() {
  // add the rooms for start
  start.addRoom(&Room1);
  start.addRoom(&Room2);

  // add the rooms for Room1
  Room1.addRoom(&Room6);

  // add the rooms for Room2
  Room2.addRoom(&Room3);
  Room2.addRoom(&Room5);

  // add the rooms for Room3
  Room3.addRoom(&Room4);

  // add the rooms for Room4
  Room4.addRoom(&Room3);
  Room4.addRoom(&Room5);
  Room4.addRoom(&Room18);

  // add the rooms for Room5
  Room5.addRoom(&Room6);
  Room5.addRoom(&Room4);

  // add the rooms for Room6
  Room6.addRoom(&Room7);
  Room6.addRoom(&Room5);
  Room6.addRoom(&Room18);

  // add the rooms for Room7
  Room7.addRoom(&Room8);
  Room7.addRoom(&Room9);
  Room7.addRoom(&Room10);

  // add the rooms for Room8
  Room8.addRoom(&Room18);
  Room8.addRoom(&Room13);

  // add the rooms for Room9
  Room9.addRoom(&Room16);

  // add the rooms for Room10
  Room10.addRoom(&Room11);
  Room10.addRoom(&Room12);
  Room10.addRoom(&Room13);

  // add the rooms for Room11
  Room11.addRoom(&Room10);
  Room11.addRoom(&Room12);
  Room11.addRoom(&end);

  // add the rooms for Room12
  Room12.addRoom(&end);
  Room12.addRoom(&Room10);

  // add the rooms for Room13
  Room13.addRoom(&Room10);
  Room13.addRoom(&Room14);

  // add the rooms for Room14
  Room14.addRoom(&Room15);
  Room14.addRoom(&end);

  // add the rooms for Room15
  Room15.addRoom(&Room17);

  // add the rooms for Room16
  Room16.addRoom(&Room9);
  Room16.addRoom(&Room11);
  Room16.addRoom(&end);

  // add the rooms for Room17
  Room17.addRoom(&end);

  // add the rooms for Room18
  Room18.addRoom(&Room6);
  Room18.addRoom(&Room8);
  Room18.addRoom(&Room4);
  Room18.addRoom(&Room7);

  // add the END ROOM to the last rooms of both sections. Just as an example for
  // now. Permamnent later on. Espresso.addRoom(&END); Latte.addRoom(&END);

  this->currRoom = &start;
}

// A FUNCTION THAT SIMULATES A BATTLE
void game::battle(Enemy &e, vector<Weapon> w, vector<Weapon> p) {

  string enemyName = this->currRoom->getBiome() + " " + e.getName();
  cout << "You have encountered a " << enemyName << endl;

  // the battle loop
  while (true) {
    // if either of them are below 0, the loop just breaks out.
    if (this->player->getHealth() <= 0 || e.getHealth() <= 0) {
      break;
    }

    // before starting there is a time lag. Gives the player time to read the
    // battle info.
    cout << "|-----------------------------------------------------------------"
            "---------------------------|"
         << endl;
    cout << "  Player Health: " << this->player->getHealth()
         << "\t|\t Enemy Health: " << e.getHealth() << endl;
    cout << "|-----------------------------------------------------------------"
            "---------------------------|"
         << endl;
    usleep(3000000);

    // players turn
    bool didActivity = false;

    // there will be some choices later on...
    int input;
    // different becuase break in switch case works differently than in an if
    // statement
    while (!didActivity) {

      cout << "What do you want to do?" << endl << endl;
      cout << "1. Attack" << endl;
      cout << "2. Heal" << endl;
      cout << "3. Change Weapon" << endl;
      cout << "4. Flee" << endl;

      // make a whole input function. makes stuff better looking
      cout << "==> "; 
      cin >> input;
      cout << "|---------------------------------------------------------------"
              "-----------------------------|"
           << endl;

      // we either attack or heal ot change weapons or flee.
      Weapon currentWeapon = this->player->getCurrentWeapon();
      int currentHealth = this->player->getHealth();
      switch (input) {
      case 1:
        cout << endl;
        cout << "You attacked the " << enemyName;
        cout << " You dealt " << this->player->getCurrentWeapon().getDamage()
             << " damage" << endl;
        e.setHealth(e.getHealth() -
                    this->player->getCurrentWeapon().getDamage());
        didActivity = true;
        break;

        // The user will not waste a chance, if he just views the weapon or
        // powerup
      case 2:
        cout << endl;
        this->player->printAntiWeapons();
        this->player->useAntiWeapons();
        if (currentWeapon.getName() !=
            this->player->getCurrentWeapon().getName()) {
          didActivity = true;
        }
        break;

      case 3:
        cout << endl;
        this->player->printWeapons();
        this->player->changeWeapons();
        if (currentHealth > this->player->getHealth()) {
          didActivity = true;
        }
        break;

      case 4:
        didActivity = true;
      }
    }

    // check if fleeing worked
    if (input == 4) {
      // ofcourse you can't just flee. You flee if you get lucky
      srand(time(0));
      int chance = rand() % 100;
      if (chance <= 45) {
        
        this->player->addBattlesFleed();
        cout << "You managed to flee but the " << enemyName
             << " attacked you! ";
        cout << "You suffered " << e.getDamage() << " damage" << endl;
        this->player->setHealth(this->player->getHealth() - e.getDamage());
        break;
        
      }
      // otherwise you just wasted a turn
        //and suffered a LOT OF damage. Think before you run!
      else {
        cout << "You could not escape. ";
        cout << "You suffered " << e.getDamage() << " damage" << endl;
        this->player->setHealth(this->player->getHealth() - e.getDamage());
      }
    }
    // if either of them are below 0, the loop just breaks out.
    if (this->player->getHealth() <= 0 || e.getHealth() <= 0) {
      break;
    }
    
    //before health is printed we need to do some book keeping on player's health.
    //check if player health is exceeding 100. If so, set it to 100
    if (this->player->getHealth() > 100)
    {
      this->player->setHealth(100);
    }
    
    cout << "|-----------------------------------------------------------------"
            "---------------------------|"
         << endl;
    cout << "  Player Health: " << this->player->getHealth()
         << "\t|\t Enemy Health: " << e.getHealth() <<"|"<< endl;
    cout << "|-----------------------------------------------------------------"
            "---------------------------|"
         << endl;
    usleep(3000000);

    // enemy's turn
    cout << endl;
    int damage = e.getDamage();
    cout << "The " << enemyName << " attacked you! ";
    cout << "It dealt " << damage << " damage" << endl;
    player->setHealth(player->getHealth() - damage);
  }

  // once the loop ends at either player or enemy's health going below 0,

  // if the player's health is below 0, they die.
  if (this->player->getHealth() <= 0) {
    cout << "|-----------------------------------------------------------------"
            "---------------------------|"
         << endl;
    cout << "The enemy has defeated you!" << endl;
    cout << "GAME OVER" << endl;
    cout << "|-----------------------------------------------------------------"
            "---------------------------|"
         << endl;

    // RESET THE HEALTH OF THE PLAYER
    //  this->player->setHealth(100);
    // this->currRoom = &start;
  }

  // if it's the enemy that is defeated, they gain a powereup or a weapon
  else if (e.getHealth() <= 0) {
    cout << "|-----------------------------------------------------------------"
            "---------------------------|"
         << endl;
    cout << "You have defeated the " << enemyName <<"|"<<   endl;
    cout<<endl;
    randomDrop(w, p);
    cout<<endl;
    cout<<"You feel good aftter your battle."<<endl;
    cout<<"Your health got restored by 15 points!"<<endl;
    cout<<endl;
    this->player->setHealth(this->player->getHealth() + 15);
    this->player->addBattlesWon();
    cout << "|-----------------------------------------------------------------"
            "---------------------------|"
         << endl;
  }
}

// A MINIGAME ABOUT RIDDLES!!
void game::initRiddles() {
  // The questions and answers
  riddles.push_back("What has to be broken before you can use it?");
  answers.push_back("egg");
  riddles.push_back(
      "I’m tall when I’m young, and I I’m short when I’m old. What am I?");
  answers.push_back("candle");
  riddles.push_back("How many months of the year have 28 days?");
  answers.push_back("Twelve");
  riddles.push_back("What is full of holes but still holds water?");
  answers.push_back("sponge");
  riddles.push_back("What goes up but never comes down?");
  answers.push_back("age");
  riddles.push_back("What has hands but cannot clap?");
  answers.push_back("clock");
  riddles.push_back("What has a head and a tail but no body?");
  answers.push_back("coin");
  riddles.push_back("What goes up and down but cannot move?");
  answers.push_back("staircase");
  riddles.push_back("What has a neck but no head?");
  answers.push_back("bottle");
  riddles.push_back("What is the antiderivative of sin(x^2)^(e*sin(3x))");
  answers.push_back("NO ANSWERS GIVEN HAHA");
}

void game::Riddles(vector<Weapon> w, vector<Weapon> p) {
  // parallel vectors for questions and answers

  // randomly choose a question
  srand(time(0));
  int index = rand() % riddles.size();

  cout << "|-------------------------------------------------------------------"
          "-------------------------|"
       << endl;
  cout << "You see a big wall as soon as you enter the room" << endl<<endl;
  cout << "A small carving on the wall says: " << endl;
  cout << riddles[index] << endl<<endl;
  cout << "To proceed further inside the room, you must answer the riddle" << endl;
  
  cout << "|-------------------------------------------------------------------"
    "-------------------------|"<<endl;
  usleep(3000000);

  cout << "A voice booms: " << endl;
  cout << "PROVIDE THE ANSWER IN ONE WORD AND IN LOWERCASE! NOW! OR FACE YOUR "
          "DEMISE!"
       << endl;
  string answer;
  cout << "Enter your answer: ";
  cin >> answer;
  cout << "You hear clicking noises coming from within the wall" << endl;
  cout << "|-------------------------------------------------------------------"
          "-------------------------|"
       << endl;
  usleep(4000000);
  // the question for 9 is just a little bit of trolling
  if (answers[index] == "NO ANSWERS GIVEN HAHA" ) {
    cout << "NO YOUR ANSWER IS WRONG! TRY AGAIN!" << endl;
    cout << "Enter your answer: ";
    cin >> answer;
    cout << "|-----------------------------------------------------------------"
            "---------------------------|"
         << endl;
    cout << "ARE YOU GUESSING OR DID YOU ACTUALLY TRY TO FIND THE "
            "ANTIDERIVATIVE?"
         << endl;
    cout << "Being a Benevolent Overseer, I shall give you one more chance!"
         << endl;
    cout << "Enter your answer: ";
    cin >> answer;
    cout << "|-----------------------------------------------------------------"
            "---------------------------|"
         << endl;
    cout << "EH, I am too bored to check your answer." << endl;
    cout << "I shall let you pass this test for free" << endl;
    cout << "|-----------------------------------------------------------------"
            "---------------------------|"
         << endl;
    cout << "You realize that there is no way someone is actually checking "
            "your answers, the builders of this place were ancient"
         << endl;
    cout << "You come to the conclusion that you got trolled by an ancient "
            "builder, who perished centuries ago"
         << endl;
    cout << "You feel embarssed and move on..." << endl;
    cout<<endl;
    randomDrop(w, p);
    cout<<endl;
    cout<<"Your health got restored by 5 points!"<<endl;
    this->player->setHealth(this->player->getHealth() + 5);
    cout << "|-----------------------------------------------------------------"
            "---------------------------|"
         << endl;
    this->player->addRiddlesSolved();
    riddles.erase(riddles.begin() + index);
    answers.erase(answers.begin() + index);
  }
  // when we are not trolling we have a system to check if answer is correct
  else {

    // if correct you go to the next room and also get a powerup or a weapon
    if (answer == answers[index]) {
      cout << "BRAVE ADVENTURER! YOU HAVE PASSED THE TEST!" << endl;
      cout << "YOU ARE FREE TO GO AHEAD!!" << endl;
      cout<<endl;
      randomDrop(w, p);
      cout<<endl;
      cout<<"Your health got restored by 10 points!"<<endl;
      this->player->setHealth(this->player->getHealth() + 10);
      cout << "|---------------------------------------------------------------"
              "-----------------------------|"
           << endl;
      // removes the already asked question
      riddles.erase(riddles.begin() + index);
      answers.erase(answers.begin() + index);
      this->player->addRiddlesSolved();
      usleep(3000000);
    }
    // else you die
    else {
      cout << "YOU HAVE FAILED THE TEST!" << endl;
      cout << "YOU ARE NOW FREE TO DIE!" << endl;
      cout << "GAME OVER" << endl;
      cout << "|---------------------------------------------------------------"
              "-----------------------------|"
           << endl;
      this->player->setHealth(0);
      usleep(3000000);
      // this->currRoom = &start;
    }
  }
}

//gives a title to the player based on actions the player takes while playing the game
void game::getTitle()
{
  //used chatGPT to get inspiration for these titles
  //ft. chatGPT means I essential copied the name from chatGPT
  if((this->player->getBattlesWon() > this->player->getRiddlesSolved())&&(this->player->getBattlesWon() > this->player->getBattlesFleed()))
  {
    cout<<"Sentinel of Courage"<<endl;
  }
  else if((this->player->getBattlesWon() < this->player->getRiddlesSolved())&&(this->player->getBattlesFleed() < this->player->getRiddlesSolved()))
  {
    cout<<"Paragon of Profound Intellect"<<endl; //ft. chat GPT
  }
  else if((this->player->getBattlesFleed() > this->player->getRiddlesSolved())&&(this->player->getBattlesWon() < this->player->getBattlesFleed()))
  {
    cout<<"Master of Tactical Retreat"<<endl;
  }
  else
  {
    cout<<"Grand Arbiter of Genius and Gallantry"<<endl;//ft. chat GPT
  }
}

//starts a game loop that keeps the game going till u either win or DIE!!!...

void game::play(vector<Weapon> w, vector<Weapon> p) {
  while (this->currRoom->getBiome() != "END") {
    cout << "|---------------------------------------------------------------"
      "-----------------------------|";
    this->currRoom->printRoomInfo();

    if (this->currRoom->getNature() == "MINIGAME") 
    {
      this->Riddles(w, p);
    } 
    else if (this->currRoom->getNature() == "BATTLE") 
    {
      Enemy e = this->getEnemy(this->player->level);
      this->battle(e, w, p);
    }
    // randomDrop(w, p);

    if (this->player->getHealth() <= 0) {
      // this->player->setHealth(100);
      return;
    }

    //check if player health is exceeding 100. If so, set it to 100
    if (this->player->getHealth() > 100)
    {
      this->player->setHealth(100);
    }
    
    this->InfoForUser();
    this->currRoom->printRooms();
    this->currRoom->nextRoom(&currRoom);
  }

  cout<<"Congratulations! You have reached the city"<<endl;
  cout<<"You fought bravely and survived the trials of intellectual warfare"<<endl;
  cout<<"You have earned the title of: "<<endl;
  getTitle();
  cout<<"From now onwards, you shall be known throught the living world as: "<<endl;
  cout<<"AMERICANO BONES : The ";
  getTitle();
  cout<<"|------------------------------------------------THE END-------------------------------------|"<<endl;
}
  

//gives info about current weapons, healing potions and health of the player
void game::InfoForUser() {
  cout << "|---------------------------------------------------------------"
      "-----------------------------|"
       << endl
       << endl;
  cout << "Player Health: " << this->player->getHealth() << endl;
  cout << "\n1. Continue\n2. Change Weapon \n3. Use Powerup \n" << endl;
  int choice;
  cout << "==> ";
  cin >> choice;
  bool isValid = false;

  while (!isValid) {
    switch (choice) {
    case 1:
      isValid = true;
      break;
    case 2:
      this->player->printWeapons();
      this->player->changeWeapons();
      cout << "\n1. Continue\n2. Change Weapon \n3. Use Powerup \n" << endl;
      cout << "==> ";
      cin >> choice;
      break;
    case 3:
      this->player->printAntiWeapons();
      this->player->useAntiWeapons();
      cout << "\n1. Continue\n2. Change Weapon \n3. Use Powerup \n" << endl;
      cout << "==> ";
      cin >> choice;
      break;
    }
  }

  cout << "|---------------------------------------------------------------"
      "-----------------------------|"
       << endl
       << endl;
}

//randomly drops(adds to players inventory) either a weapon or a healing potion
void game::randomDrop(vector<Weapon> w, vector<Weapon> p) {
  this->player->level ++;
  srand(time(0));
  int randNum = rand() % 2;
  
  int lv = this->player->level;
  //unlikely but just in case level gets too high, we can keep giving the player the last few items.
  if(lv>=w.size() || lv>=p.size())
    {
      srand(0);
      lv = 6+rand()%(w.size()-7);
    }
  if (randNum == 0) {
    cout << "You found a health potion! || "
         << p.at(lv).getName() << " with healing of ";
    cout << p.at(lv).getHealing() << endl;
    this->player->addAntiWeapon(p.at(this->player->level));
  } else {
    cout << "You found a weapon! || " << w.at(lv + 1).getName()
         << " with a damage of ";
    cout << w.at(lv+1).getDamage() << endl;
    this->player->addWeapon(w.at(this->player->level + 1));
  }
}