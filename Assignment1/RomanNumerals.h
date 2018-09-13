#ifndef ROMANNUMERLAS_H
#define ROMANNUMERLAS_H
#include <iostream>
#include <string>
using namespace std;

class RomanNumeral{
private:
  /*Node for the linked list with the 2 values that it will hold for each stored romanNumeral
  (decimalValue of the stored romanNumeral and the romanNumeral itself)*/
  typedef struct node{
    int decimalValue;
    string stringValue;
    node *link;
  }* nodePtr;
  nodePtr head;
  nodePtr current;
  nodePtr temp;

public:
  RomanNumeral();
  ~RomanNumeral();
  bool emptyList();
  void addNode(string addData);
  void deleteNode(string delData);
  void printList();
  void printARoman(string findThisRoman);
  void printRomanAsDecimal(string convertThisRoman);
  int convertToDecimal(string roman);
  int value(char roman);
};

#endif
