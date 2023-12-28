#include<iostream>
#include<ctime>
#include "room.h"

using namespace std;

/* **** ADITYA JHA **** 
  Worked on the room class and the rooms.cpp file entirely. 
*/

//constructor 
room::room(string nature, string biome, bool hasEnemy, bool hasMinigame)
{
    this->nature = nature;
    this->biome = biome;
    this->hasEnemy = hasEnemy;
    this->hasMinigame = hasMinigame;
}

//getter and setter functions
string room::getBiome()
{
    return this->biome;
}

string room::getNature()
{
  return this->nature;
}

//prints current room

void room::printRoomInfo()
{
    cout<< endl << "You are in the "<<this->getBiome()<<" room"<<endl;
    // cout<<"This is a _________ room (description subject to change)"<<endl;
}

void room::addRoom(room *Room)
{
    nextRooms.push_back(Room);
}

//prints the next rooms player can go to .
void room::printRooms()
{
    cout << endl;
    if(this->nextRooms.size()==1)
    {
        cout<<"You see only "<<this->nextRooms.size()<<" path in front of you:"<<endl;
    }
    else
    {
        cout<<"You see "<<this->nextRooms.size()<<" paths in front of you:"<<endl;
    }
    for(int i=0;i<this->nextRooms.size();i++)
    {
        room *r = this->nextRooms.at(i);
        cout<<(i+1)<<". "<<r->getBiome()<<" room."<<endl;
    }
}

//sets the pointer of the currentRoom pointer to the room the player wants to go to.
void room::nextRoom(room **nextRoomPtr)
{
    int input;
    cout<< endl << "Enter the room number you want to go to..."<<endl;
    cout<<"==> ";
    cin>>input;
    while(input>this->nextRooms.size()||input<1)
    {
        cout<<"Please enter a valid room number..."<<endl;
        cout<<"==> ";
        cin>>input;
    }
    *nextRoomPtr = this->nextRooms.at(input-1);
}

//I FORGOT WHAT THIS DOES :(
void room::NextRoom(room **nextRoomPtr)
{
    srand(time(0));
    int index = rand()%this->nextRooms.size();
    *nextRoomPtr = this->nextRooms.at(index);
}