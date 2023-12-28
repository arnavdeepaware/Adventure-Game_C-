/* ****ARSH ANAND****
 Worked largely on the enemy class.
 
*/

/* *** Arnav ***
  - Created getDamage function to return damange randomly in a certain range. Further improvised by Aditya to add more intensity in randomness
  - Added isActivist Boolean value to determine whether the enemy is part of activist or pacifist group.
  - We ended up removing the activist vs pacific route to a battle or minigame route
*/


#ifndef ENEMY_H
#define ENEMY_H
#include <string>
using namespace std;

class Enemy {
private:
  // Attributes of Enemy 
  int health;
  int damage;
  string name;
  int level;
  //bool isActivist;

public:
  // Constructors
  Enemy(int health, int damage, string name, int level);

  // Setter Functions
  void setHealth(int h);
  void setDamage(int d);
  void setName(std::string n);

  // Getter Functions
  int getHealth() const;
  int getDamage();
  string getName() const;
  int getLevel();

};

#endif // ENEMY_H
