#include <cstdlib>
#include "RomanNumerals.h"
#include "RomanNumerals.cpp"
using namespace std;

//Menu of the program for the user to interact with
void menu(){
  cout << endl;
  cout << "**********************************************************" << endl;
  cout << "Wellcome to the Roman to Decimal Converter!" << endl;
  cout << "Select one of the the following options below to proceed: " << endl;
  cout << "1)Store a Roman Numeral." << endl;
  cout << "2)Print a Roman Numeral." << endl;
  cout << "3)Print the Roman Numeral as Decimal." << endl;
  cout << "4)Print the list of Roman Numerls stored." << endl;
  cout << "5)Delete a roman Numeral on the list." << endl;
  cout << "6)Exit the Program." << endl;
  cout << "**********************************************************" << '\n';
  cout << endl;
}

int main() {
  menu();
  int menuChoice = 0;
  string userRomanNumeral;
  RomanNumeral roman;
  cout << "Enter one of the options: ";
  cin >> menuChoice;

  do {
    switch (menuChoice) {
      case 1:{
        cout << "Enter a roman numeral you wish to add " << '\n' <<
        "(if the number entered is not a roman numeral, then it will default to 0)";
        cin >> userRomanNumeral;
        roman.addNode(userRomanNumeral);
        cout << "The roman numeral " << userRomanNumeral << " has been added to the list!" << endl;
        menu();
        cout << "Enter one of the options: ";
        cin >> menuChoice;
        break;
      }
      case 2:{
        cout << "Enter a roman numeral already stored to print it out: ";
        cin >> userRomanNumeral;
        roman.printARoman(userRomanNumeral);
        menu();
        cout << "Enter one of the options: ";
        cin >> menuChoice;
        break;
      }
      case 3:{
        cout << "Enter a roman numeral already stored to print its decimal value: ";
        cin >> userRomanNumeral;
        roman.printRomanAsDecimal(userRomanNumeral);
        menu();
        cout << "Enter one of the options: ";
        cin >> menuChoice;
        break;
      }
      case 4:{
        roman.printList();
        menu();
        cout << "Enter one of the options: ";
        cin >> menuChoice;
        break;
      }
      case 5:{
        cout << "Enter the roman numeral you wish to delete: ";
        cin >> userRomanNumeral;
        roman.deleteNode(userRomanNumeral);
        menu();
        cout << "Enter one of the options: ";
        cin >> menuChoice;
        break;
      }
      case 6:{
        cout << "Terminating program..." << endl;
        exit(1);
      }
      default:{
        cout << "Please choose something from the menu!" << endl;
        menu();
        cout << "Enter one of the options: ";
        cin >> menuChoice;
      }
    }
  }while (menuChoice != 6);
  return 0;
}
