#include "player.h"
#include <unistd.h> 
#include"weapon.h"
#include <iostream>
using namespace std;
// Constructors
Player::Player(int health, string name, Weapon w)
{
    this->health = health;
    this->name = name;
    currWeapon = w;
}


//GETTERS AND SETTERS
Weapon Player::getCurrentWeapon()
{
  return currWeapon;
}

void Player::setHealth(int newHealth)
{
  this->health = newHealth;
}
int Player::getHealth()
{
  return this->health;
}
void Player::setIsAlive(bool status)
{
  this->isAlive = status;
}
bool Player::getIsAlive()
{
  return this->isAlive;
}

void Player::addBattlesWon()
{
  this->battlesWon++;
}
void Player::addRiddlesSolved()
{
  this->riddlesSolved++;
}
void Player::addBattlesFleed()
{
  this->battlesFleed++;
}

int Player::getBattlesWon()
{
  return this->battlesWon;
}

int Player::getRiddlesSolved()
{
  return this->riddlesSolved;
}
int Player::getBattlesFleed()
{
  return this->battlesFleed;
}
// Other Functions
void Player::printWeapons(){
  cout << "This is an inventory of your weapons." << endl <<endl;  
  for (int i = 0; i < playerWeapons.size(); i++){
    cout << i + 1 << ". " << playerWeapons[i].getName() << " || Damage is " << playerWeapons.at(i).getDamage() << endl;  
  }
  cout << endl << "Your current weapons is " << currWeapon.getName() << " with a damage of " << currWeapon.getDamage() << "." << endl;
}

void Player::printAntiWeapons(){
  cout << "This is an inventory of your powerups." << endl << endl;
  for (int i = 0; i < playerAntiWeapons.size(); i++){
    cout << i + 1 << ". " << playerAntiWeapons[i].getName() << " || Healing is " << playerAntiWeapons.at(i).getHealing() << endl;
  }
}

void Player::addWeapon(Weapon w){
  playerWeapons.push_back(w);
}

void Player::addAntiWeapon(Weapon w){
  playerAntiWeapons.push_back(w);
}

void Player::changeWeapons(){
  cout << "To change your weapons, type 'c', else press any key to continue." << endl;
  string c;
  cin >> c;
  if (c == "c"){
    cout << "Enter the number assosiated with the weapon you want to use." << endl;
    int weaponNum;
    cin >> weaponNum;
    weaponNum --;

    while (weaponNum < 0 || weaponNum >= playerWeapons.size()){
      cout << "Invalid weapon number. Please enter a valid weapon number." << endl;
      cin >> weaponNum;
      weaponNum --;
    }

    currWeapon = playerWeapons.at(weaponNum);
    cout << "Changing Weapons" << endl;
    usleep(1000000);
    cout << "...";

    cout << "You have chosen " << currWeapon.getName() << " with a damage of " << currWeapon.getDamage() << endl;
  }
  cout << endl << "Thank you! Moving back to the game." << endl;  
  cout<<"|--------------------------------------------------------------------------------------------|"<<endl;
usleep(1000000);
}

void Player::useAntiWeapons(){
  if(playerAntiWeapons.size() == 0)
  {
    cout << "You have no powerups to use." << endl;
    return;
  }
  cout << endl << "NOTE: Powerups can only be used once and will give a maximum health of 100" << endl;
  cout << "To use your powerups, type 'c', else press any key to continue." << endl;
  string c;
  cin >> c;
  if (c == "c"){
    cout << "Enter the number assosiated with the powerup you want to use." << endl;
    int powerupNum;
    cin >> powerupNum;
    powerupNum --;
    
    while( powerupNum < 0 || powerupNum >= playerAntiWeapons.size()){
      cout << "Invalid powerup number. Please enter a valid powerup number." << endl;
      cin >> powerupNum;
      powerupNum --;
    }
    
    cout << "Drinking " << playerAntiWeapons[powerupNum].getName() << "..." << endl;
    health += playerAntiWeapons[powerupNum].getHealing();
    if (health > 100){health = 100;}
    cout << "Health is now " << health << endl;
    playerAntiWeapons.erase(playerAntiWeapons.begin() + powerupNum);
    }
    cout << "Thank you! Moving back to the game." << endl;
  cout<<"|--------------------------------------------------------------------------------------------|"<<endl;
    
  
}