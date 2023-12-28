#include <iostream>
#include <vector>
using namespace std;

class room {
private:
  // basic properties for the room class,
  string nature;
  string biome;
  bool hasEnemy;
  bool hasMinigame;
  vector<room *> nextRooms;

public:
  // constructor
  room(string nature, string biome, bool hasEnemy, bool hasMinigame);
  // getter functions
  string getBiome();
  string getNature();
  // prints which room you currently are in and a description later on...
  // (hopefully)
  void printRoomInfo();

  // adds a connecting room to the vector nextRoom
  void addRoom(room *Room);

  // prints out the rooms
  void printRooms();

  // sets the currentRoom to the nextRoom
  void nextRoom(room **nextRoomPtr);
  void NextRoom(room **nextRoomPtr);
};
