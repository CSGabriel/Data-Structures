#include <iostream>
#include <fstream>
#include <cctype>
#include "Ventas.h"
#include "Ventas.cpp"

const int MAX_VENDORS = 12;
const int MAX_PRODUCTS = 3;
const int MAX_DAYS = 7;
using namespace std;

//Prints a menu of interaction for the user
void menu();

//Takes the names of the file "entrada.txt", capitalizes the first letter of first,,last names, and middle initial
string* getNames(string names[]);

//Corrects Capitalization for a given name from "entrada.txt"
string correctName(string n);

string* getProductNames(string p[]);

int main(){
  //Tridimensional-Dynamic Array of objects of Ventas Creation
  Ventas ***ventas;
  ventas = new Ventas**[MAX_VENDORS]; //Num de Vendedores
  for(int i=0;i<MAX_VENDORS;++i){
    ventas[i]=new Ventas*[MAX_PRODUCTS]; //Num de Productos
    for(int k=0;k<MAX_PRODUCTS;++k)
        ventas[i][k]=new Ventas[MAX_DAYS]; //Num de Dias
  }
  
  int count = 0;
  ifstream myFile;
  myFile.open("entrada.txt");
  string n[MAX_VENDORS];
  string p[MAX_PRODUCTS];
  string *nombres = getNames(n);
  string *productNames = getProductNames(p);
  
  /*Fills dynamic array with n (contains the names for all vendors), and p(contains the name for the products sold by each vendor)*/
  for(int i = 0;i<MAX_VENDORS;i++){
  	int h = 0;
  	ventas[i][h][0].setNameForVendor(nombres[i]);
  	while(h != MAX_PRODUCTS){
  		ventas[i][h][0].setNameForProduct(productNames[h]);
  		h++;
	  }
  }
  
   for(int i = 0;i<MAX_VENDORS;i++){
  	int h = 0;
  	cout << ventas[i][h][0].getNameForVendor() << ", ";
  	while(h != MAX_PRODUCTS){
  		cout << ventas[i][h][0].getNameForProduct() << ", ";
  		h++;
	  }
	  cout << endl;
  }

  menu();

  //Delete dynamic array
  delete [] ventas;

  return 0;
}

void menu(){
  cout << "Que desea hacer?" << endl;
  cout << "********************************************************************" << endl;
  cout << "1)Imprimir el total de unidades vendidas de cada producto en el mes." << endl;
  cout << "2)Imprimir el producto con mayor cantidad de ventas en un dia dado." << endl;
  cout << "3)Imprimir ventas de todos los vendedores  en un dia dado." << endl;
  cout << "4) Salir." << endl;
  cout << "********************************************************************" << endl;
}

string* getNames(string names[]){
  ifstream myFile;
  myFile.open("entrada.txt");
  for(int h = 0;h < 12;h++){

    string name;
    string discard;//discard remaining of the line
    getline(myFile,name,'.');
    getline(myFile,discard);
	name = correctName(name);
    names[h] = name;
  }
  myFile.close();

  return names;
}

string correctName(string n){
    int nameLength = n.length();
    int index = 0;
    
    char currentChar = n[index];

    // Verify that first letter in first last name is capitalized
    if (!isupper(currentChar)){
        n[index] = toupper(currentChar);
    }
    
    // Continue with the rest of the name
    index++;
    
    while (index < nameLength){
        currentChar = n[index];
        while (!isspace(currentChar) && index < nameLength){
            currentChar = n[++index];
        }
        
        // Move from space to first letter of next name substring
        index++;
        currentChar = n[index];
        // Verify that first letter in  name's substring is capitalized
        if (!isupper(currentChar)){
            n[index++] = toupper(currentChar);
        }
    }
    return n;
}

string* getProductNames(string p []){
	  ifstream myFile;
	  int count = 0;
  myFile.open("entrada.txt");
  for(int h = 0;h < MAX_PRODUCTS;h++){
    string name;
    string discard;//discard remaining of the line
    if(count == 0){
    	getline(myFile,discard,'.');
    	getline(myFile,name,'.');
    	getline(myFile,discard);
	}
	else if(count == 1){
    	getline(myFile,discard,'.');
    	getline(myFile,discard,'.');
    	getline(myFile,name,'.');
    	getline(myFile,discard);
	}
	else if(count == 2){
		getline(myFile,discard,'.');
    	getline(myFile,discard,'.');    	
    	getline(myFile,discard,'.');
    	getline(myFile,name,'.');
    	getline(myFile,discard);
	}
	count++;
    p[h] = name;
  }
  myFile.close();

  return p;
}
