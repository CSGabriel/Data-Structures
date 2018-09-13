#include <cstdlib>
#include <iostream>
#include <string>
#include "RomanNumerals.h"

using namespace std;

//Constructor
RomanNumeral::RomanNumeral(){
  head = NULL;
  current = NULL;
  temp = NULL;
}

//Destructor
RomanNumeral::~RomanNumeral(){
  nodePtr list = head;
  if(emptyList() == true){
    cout << " \n List is empty, it cant be deleted..." << endl;
  }
  else{
    while(head->link != NULL){
      head = head->link;
      delete list;
      list = head;
    }
    delete head;
    head = NULL;
    list = NULL;
    cout << "List has been deleted!" << endl;
  }
}

//Checks to see if the list is empty
bool RomanNumeral::emptyList(){
  if(head == NULL){
    return true;
  }
  else{
    return false;
  }
}

//Adds a roman numeral to the linked list
void RomanNumeral::addNode(string addData){
  int decimal = convertToDecimal(addData);
  nodePtr n = new node;
  n->link = NULL;
  n->stringValue = addData;
  n->decimalValue = decimal;
  if(head != NULL){
    current = head;
    while(current->link != NULL){
      current = current->link;
    }
    current->link = n;
  }
  else{
    head = n;
  }
}

//Goes through the list and deletes a node if wanted, if it's not in the list it prints the appropiate message
void RomanNumeral::deleteNode(string delData){
  nodePtr delPtr = NULL;
  temp = head;
  current = head;
  while(current != NULL && current->stringValue != delData){
    temp = current;
    current = current->link;
  }
  if(current == NULL){
    cout << delData << " was not in the list!" << endl;
    delete delPtr;
  }
  else{
    delPtr = current;
    current = current->link;
    temp->link = current;
    if(delPtr == head){
      head = head->link;
      temp = NULL;
    }
    delete delPtr;
    cout << "The value " << delData << " was deleted!" << endl;
  }
}

//Prints the list of all the roman numerals added
void RomanNumeral::printList(){
  current = head;
  if(current == NULL){
    cout << "There are no items on the list!" << endl;
  }
  while (current != NULL) {
    cout << current->stringValue << "=" << current->decimalValue <<  endl;
    current = current->link;
  }
}

//Looks for a roman numeral already in the list and prints it
void RomanNumeral::printARoman(string findThisRoman){
  nodePtr findPtr = NULL;
  temp = head;
  current = head;
  while(current != NULL && current->stringValue != findThisRoman){
    temp = current;
    current = current->link;
  }
  if(current == NULL){
    cout << findThisRoman << " was not in the list!" << endl;
  }
  else{
    findPtr = current;
    current = current->link;
    temp->link = current;
    cout <<"Seems like " << findThisRoman << " is the Roman Numeral you requested." << endl;
  }
}

//looks for a roman numeral already in list and prints its decimal value
void RomanNumeral::printRomanAsDecimal(string convertThisRoman){
  int compare = convertToDecimal(convertThisRoman);
  nodePtr findPtr = NULL;
  temp = head;
  current = head;
  while(current != NULL && current->decimalValue != compare){
    temp = current;
    current = current->link;
  }
  if(current == NULL){
    cout << convertThisRoman << " was not in the list!" << endl;
  }
  else{
    findPtr = current;
    current = current->link;
    temp->link = current;
    cout << "Seems like the roman numeral " << convertThisRoman << "s' conversion is " << compare << endl;
  }
}

//Converts the value of a roman numera to decimal
int RomanNumeral::convertToDecimal(string roman){
  int n, ans=0, p=0;
  n= roman.length()-1;

  for(int i=n; i>=0; i--)
  {
   if( value(roman[i]) >= p)
    ans = ans + value(roman[i]);
   else
    ans = ans - value(roman[i]);

  p = value(roman[i]);
  }
  return ans;
}

//Assigns a value to the roman letters
int RomanNumeral::value(char roman){
  int num = 0;
 switch(roman)
 {
    case 'I':{
      num= 1;
      break;
    };
   case 'V':{
     num =  5;
     break;
   }

   case 'X':{
     num =  10;
     break;
   }
   case 'L':{
     num = 50;
     break;
   }
   case 'C':{
     num = 100;
     break;
   }
   case 'D':{
     num =500;
     break;
   }
   case 'M':{
     num = 1000;
     break;
   }
 }
 return num;
}
