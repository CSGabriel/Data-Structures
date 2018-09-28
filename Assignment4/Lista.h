#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include <string>
using namespace std;

class Lista{
private:
  typedef struct node{
    string nombre;
    string palabra;
    int playerNum;
    node *next;
  }*nodePtr;

  nodePtr head;
  nodePtr end;
  int keepTrack;
  int once;

public:
  Lista(); // Default Constructor of the class
  ~Lista(); // Destructor of the class
  bool emptyList(); //checks of list is initially empty
  void addPlayer(int numOfPlayers); //adds a player
  void addAtEnd(int n); //inserts a player at the end of list
  void showPlayers();//shows players on the list
  void searchForPlayer(); //looks up a player on the list
  void deletePlayer(int n); //deletes a player from the list
  void game();

};

#endif
