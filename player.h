#include<string>
#include<vector>
#include<iostream>
#include"weapon.h"
using namespace std;


/* *** ARNAV DEEPAWARE ***
  - Created printWeapons(), printAntiWeapons(), addWeapon(), addAntiWeapon(), changeWeapons(), changeAntiWeapons() functions
*/
class Player
{
    private:
        int health;
        string name;
        bool isAlive = true;
        Weapon currWeapon = Weapon("Fist", 1, false);
        vector<Weapon> playerWeapons;
        vector<Weapon> playerAntiWeapons;

        int battlesWon = 0;
        int riddlesSolved = 0;
        int battlesFleed = 0;



    public:
        int level = 0;
        Player(int health, string name, Weapon w);
        void printWeapons();
        void printAntiWeapons();
        void addWeapon(Weapon w);
        void addAntiWeapon(Weapon w);
        void changeWeapons();
        void useAntiWeapons();
        Weapon getCurrentWeapon();
        void setHealth(int newHealth);
        int getHealth();
        void setIsAlive(bool status);
        bool getIsAlive();
        int getBattlesWon();
        int getRiddlesSolved();
        int getBattlesFleed();
        void addBattlesWon();
        void addRiddlesSolved();
        void addBattlesFleed();
};