
// *** Arnav *** --> Created .cpp file based on .h file

#include "weapon.h"

// Constructors 
Weapon::Weapon(string n, int d, bool a){

    if (a){
      damage = 0;
      healing = d;
    }
    else {
      damage = d;
      healing = 0;
    }

    name = n;
    isAntiWeapon = a;
  }

// Setter Functions
void Weapon::setName(string n) {
  name = n;
}

void Weapon::setDamage(int d) {
  damage = d;
}

void Weapon::setHealing(int h) {
  healing = h;
}

void Weapon::setIsAntiWeapon(bool a) {
  isAntiWeapon = a;
}

// Getter Functions
string Weapon::getName() const {
  return name;
}

int Weapon::getDamage() const {
  return damage;
}

int Weapon::getHealing() const {
  return healing;
}

bool Weapon::getIsAntiWeapon() const {
  return isAntiWeapon;
}




