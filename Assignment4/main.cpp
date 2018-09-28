#include "Lista.h"
using namespace std;

void menu(); //Menu that handles interaction with the user
int validInput(int x);//tests that menuChoice is valid

int main(){
  Lista list;
  int menuChoice = 0;
  do {
    menu();
    menuChoice = validInput(menuChoice);

    switch (menuChoice) {
      case 1:{
        int numOfPlayers = 0;
        cout << "Enter the number of players you wish to add: ";
        numOfPlayers = validInput(numOfPlayers);
        while(numOfPlayers <= 0){
          cout << "Not a valid amount of players. Try again: ";
          cin >> numOfPlayers;
        }
        list.addAtEnd(numOfPlayers);
        break;
      }
      case 2:{
        list.searchForPlayer();
        break;
      }
      case 3:{
        list.showPlayers();
        break;
      }
      case 4:{
        int del = 0;
        cout << "Choose a player to delete: ";
        cin >> del;
        list.deletePlayer(del);
        break;
      }
      case 5:{
        list.game();
        break;
      }
      case 6:{
        cout << "---------------------------------------------------------------------------------------------" << endl;
        cout << "Welcome to the game of The Sentence!" << endl;
        cout << "Rules: " << endl;
        cout << "The first player commences by giving a word to start a sentence." << endl;
        cout << "The following players must continue to add a word to the sentence, but" << endl;
        cout << "only if they get the words said by other players before them right." << endl;
        cout << "Not doing so will result in an automatic elimination and the turn goes over the next player." << endl;
        cout << "The winner of the game is the last player standing after all others are eliminated." << endl;
        cout << "NOTE: ALL PLAYERS ARE ELIMINATED AFTER A GAME SESSION." << endl;
        cout << "---------------------------------------------------------------------------------------------" << endl;
        break;
      }
      case 7:{
        cout << "Terminating program..." << endl;
        exit(0);
      }
      default:{
        cout << "Please choose something from the menu!" << endl;
        break;
      }
    }
 } while(menuChoice != 7);
}


void menu(){
  cout << "*******************************************" << endl;
  cout << "*  1) Add players to play the game.       *" << endl;
  cout << "*  2) Look for player.                    *" << endl;
  cout << "*  3) Show All players.                   *" << endl;
  cout << "*  4) Eliminate Player.                   *" << endl;
  cout << "*  5) Play Game!                          *" << endl;
  cout << "*  6) Instructions.                       *" << endl;
  cout << "*  7) Exit.                               *" << endl;
  cout << "*******************************************" << endl;
  cout << "Choose an option: ";
}

int validInput(int x)
{
    std::cin >> x;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout << "Bad entry. Please enter a number: ";
        cin >> x;
    }
    return x;
}
