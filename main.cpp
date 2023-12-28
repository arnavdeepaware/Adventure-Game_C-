#include<iostream>
#include<string>
#include"game.h"
#include"weapon.h"
using namespace std;
/* **** ADITYA JHA **** 
worked on the ascii art 
*/

/*  *** ARNAV DEEPAWARE ***
- Created Welcome() and Printlore() 
- Created vectors of game weapons and anti-weapons(healing potions)
- Cleaned the code and created functions to increase readability
*/

void printWelcome(){
  //copied from a website that converts text to ASCII ART
  //https://patorjk.com/software/taag/#p=testall&f=Graffiti&t=AMERICANO%20BONES%20
  cout<<"           __  __ ______ _____  _____ _____          _   _  ____     ____   ____  _   _ ______  _____  "<<endl;
  cout<<"     /\\   |  \\/  |  ____|  __ \\|_   _/ ____|   /\\   | \\ | |/ __ \\   |  _ \\ / __ \\| \\ | |  ____|/ ____| "<<endl;
  cout<<"    /  \\  | \\  / | |__  | |__) | | || |       /  \\  |  \\| | |  | |  | |_) | |  | |  \\| | |__  | (___   "<<endl;
  cout<<"   / /\\ \\ | |\\/| |  __| |  _  /  | || |      / /\\ \\ | . ` | |  | |  |  _ <| |  | | . ` |  __|  \\___ \\  "<<endl;
  cout<<"  / ____ \\| |  | | |____| | \\ \\ _| || |____ / ____\\ | |\\  | |__| |  | |_) | |__| | |\\  | |____ ____) | "<<endl;
  cout<<" /_/    \\_\\_|  |_|______|_|  \\_\\_____\\_____/_/    \\_\\_| \\_|\\____/   |____/ \\____/|_| \\_|______|_____/"<<endl; 

}

void printLore(){
  cout<< endl<< endl;
  cout << "Welcome to American Bones!! You are a lone warrior who has been trapped in the coffee land. Your goal is to escape the coffee land and return to the city.\"" << endl << endl;

  cout << "The rules are simple. You will battle with coffee-monsters on your quest out. You will have the chance to aquire different weapons and powerups. Your weapons will boost your attack, while powerups will boost your health. Good luck!!!" << endl << endl;

  cout << "Throughout your game you can see your weapons and change it. You can also see your powerups to manage your health." << endl << endl;
}

void oneRound(vector<Weapon> w, vector<Weapon> a){
  //initialize the player and the weapon for the game loop
  Player p(100,"TEST", w.at(0));
  p.addWeapon( w.at(0));
  game Main(p);
  Main.initRiddles();
  Main.initEnemies();
  //printout the intro and the ~~~LORE~~~
  printWelcome();
  printLore();
  // Main.InfoForUser();

  //initialize the map 
  Main.initMap();
  Main.play(w, a);
}

int main(){  
  vector<Weapon> gameWeapons;
  vector<Weapon> gameAntiWeapons;
  // All possible weapons in the game
  gameWeapons.push_back(Weapon("Espresso Blaster", 15, false));
  gameWeapons.push_back(Weapon("Cappuccino Cutter", 20, false));
  gameWeapons.push_back(Weapon("Latte Lasher", 25, false));
  gameWeapons.push_back(Weapon("Mocha Mauler", 30, false));
  gameWeapons.push_back(Weapon("Americano Avenger", 25, false));
  gameWeapons.push_back(Weapon("Macchiato Slicer", 30, false));
  gameWeapons.push_back(Weapon("Bean Crusher", 35, false));
  gameWeapons.push_back(Weapon("Java Javelin", 40, false));
  gameWeapons.push_back(Weapon("Frothy Fury", 45, false));
  gameWeapons.push_back(Weapon("Decaf Destroyer", 50, false));

  // All possible anti-weapons (powerups) in the game
  gameAntiWeapons.push_back(Weapon("Brew Elixir", 15, true));
  gameAntiWeapons.push_back(Weapon("Creamy Recovery Concoction", 20, true));
  gameAntiWeapons.push_back(Weapon("Sugar Rush Serum", 25, true));
  gameAntiWeapons.push_back(Weapon("Barista's Blessing", 30, true));
  gameAntiWeapons.push_back(Weapon("Espresso Rejuvenator", 40, true));
  gameAntiWeapons.push_back(Weapon("Mocha Mend", 50, true));
  gameAntiWeapons.push_back(Weapon("Caffeine Cure", 60, true));
  gameAntiWeapons.push_back(Weapon("Cream and Sugar Salvation", 70, true));
  gameAntiWeapons.push_back(Weapon("Frothy Fixer", 80, true));


  while (true){
    oneRound(gameWeapons, gameAntiWeapons);          
    cout<<"|--------------------------------------------------------------------------------------------|"<<endl;
    cout<<"Would you like to play again? \n Enter y to play again \n Enter anything else to quit"<<endl;
    cout<<"==> ";
    char choice;
    cin>>choice;

    if(choice == 'y'){
      cout<<"|--------------------------------------------------------------------------------------------|"<<endl;
      continue;
    } else {
      cout<<"|--------------------------------------------------------------------------------------------|"<<endl;
      cout<<"Thanks for playing!"<<endl;
      break;
    }      
  }


  
  return 0;
}