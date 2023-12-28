
/* *** Arnav ***
  - Created attributes, setter functions, getter functions and constructors for Weapon class.
*/

#ifndef WEAPON_H
#define WEAPON_H
#include <string>
using namespace std;

class Weapon {
private:
  // Attributes of Weapon
  string name;
  int damage;
  int healing;
  bool isAntiWeapon;

public:
  // Constructor
  Weapon(string n, int d, bool a);

  // Setter Functions
  void setName(string n);
  void setDamage(int d);
  void setHealing(int h);
  void setIsAntiWeapon(bool a);

  // Getter Functions
  string getName() const;
  int getDamage() const;
  int getHealing() const;
  bool getIsAntiWeapon() const;


};
#endif 
