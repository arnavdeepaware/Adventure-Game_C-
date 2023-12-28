#include "enemy.h"
#include <vector>

using namespace std;


/*
 ****ARSH ANAND****
  Worked with the function here
*/


// Constructors
Enemy::Enemy(int health, int damage, string name, int level)
{
  this->health = health;
  this->damage = damage;
  this->name = name;
  this->level = level;
}


// Setter Functions
void Enemy::setHealth(int h) {
  health = h;
}

void Enemy::setDamage(int d) {
  damage = d;
}

void Enemy::setName(string n) {
  name = n;
}

// Getter Functions
int Enemy::getHealth() const {
  return health;
}

int Enemy::getDamage(){
  srand(time(0));
  int r = rand()%100;
  int d;
  if(r>95)
  {
     d = rand()%5 + damage+15;
  }
  else
  {
     d = rand()%15 + damage;
  }
  
  
  return d;
}

string Enemy::getName() const {
  return name;
}

int Enemy::getLevel()
{
  return level;
}


