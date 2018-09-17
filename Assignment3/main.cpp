#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdio>
#include "Ventas.h"

/*TASKS LEFT TO DO:
-Make the menu options functional (switch statement to navigate through the menu)
-Check the data of sales from the file anddont add a vendor or their data if its corrupt(a negative sale)
*/

const int MAX_VENDORS = 12;
const int MAX_PRODUCTS = 3;
const int MAX_DAYS = 7;
using namespace std;

//Prints a menu of interaction for the user
void menu();

//Takes the names in the file "entrada.txt", capitalizes the first letter of first, last names, and middle initial.
string* getNames(string names[]);

//Corrects Capitalization for a given name from "entrada.txt", it's used in getNames function.
string correctName(string n);

//Takes the names the products in the file "entrada.txt" and stores them on the strin p declared in main.
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
  ifstream myFile;
  myFile.open("entrada.txt"); //open entrada.txt file
  string n[MAX_VENDORS];
  string p[MAX_PRODUCTS];
  string *nombres = getNames(n);
  string *productNames = getProductNames(p);
  bool condition = true;
  int menuChoice = 0;

  cout << "Leyendo Datos..." << endl;
  /*Fills dynamic array with n (contains the names for all vendors), and p(contains the name for the products sold by each vendor)*/
  for(int i = 0;i<MAX_VENDORS;i++){
  	int h = 0;
    int j = 0;
    ventas[i][h][j].setNameForVendor(nombres[i]);
  	while(h < MAX_PRODUCTS){
      int num = 0;
      j = 0;
  		ventas[i][h][j].setNameForProduct(productNames[h]);
      while(j < MAX_DAYS){
        if(condition){
          string discard;
          getline(myFile,discard,';');
          myFile >> num;
          if(num < 0){
            cout << "Se encontro data corrupta del vendedor: " << ventas[i][0][0].getNameForVendor() << " en el dia " << j+1 << ". Este dato ha sido removido!" << endl;
            num = 0;

          }
          ventas[i][h][j].setProductos(num);
          condition = false;
        }
        else{
          myFile >> num;
          if(num < 0){
            cout << "Se encontro data corrupta del vendedor: " << ventas[i][0][0].getNameForVendor() << " en el dia " << j+1 << ". Este dato ha sido removido!" << endl;
            num = 0;
          }
          ventas[i][h][j].setProductos(num);
        }
        j++;
      }
  		h++;
	  }
    condition = true;
  }

  myFile.close(); //close entrada.txt file
  ofstream oFile;
	oFile.open("salida.txt");

  //For loop that will be used to print the data out later on.
  //(remember ro declare another int inside the for loop a while loop)
  /*for(int i = 0;i<MAX_VENDORS;i++){
  	int h = 0;
    int j = 0;
  	cout << ventas[i][h][j].getNameForVendor() << ", ";
  	while(h < MAX_PRODUCTS){
      j = 0;
  		cout << ventas[i][h][j].getNameForProduct() << ", ";
      while(j < MAX_DAYS){
        cout << ventas[i][h][j].getProductos() << ", ";
        j++;
      }
  		h++;
	  }
	  cout << endl;
  }
  */
  cout << endl;
  menu();
  cin >> menuChoice;


  do {
    switch (menuChoice) {
      case 1:{
        int totalDeDisks = 0;
        int totalDeSpeakers = 0;
        int totalDeKeyboards = 0;
        for(int i = 0;i<MAX_VENDORS;i++){
          int numProducto = 0;
        	int h = 0;
          int j = 0;
        	while(h < MAX_PRODUCTS){
            j = 0;
            while(j < MAX_DAYS){
              if(numProducto == 0){
                totalDeDisks += ventas[i][h][j].getProductos();
              }
              else if(numProducto == 1){
                totalDeSpeakers += ventas[i][h][j].getProductos();
              }
              else if(numProducto == 2){
                totalDeKeyboards += ventas[i][h][j].getProductos();
              }
              j++;
            }
        		h++;
            numProducto++;
      	  }
        }

        cout << "El total de Discos Duro Externo vendidos fueron: " << totalDeDisks << endl;
        oFile << "El total de Discos Duro Externo vendidos fueron: " << totalDeDisks << endl;
        cout << "El total de Mini Alta Voces vendidos fueron: " << totalDeSpeakers << endl;
        oFile << "El total de Mini Alta Voces vendidos fueron: " << totalDeSpeakers << endl;
        cout << "El total de Teclados vendidos fueron: " << totalDeKeyboards << endl;
        oFile << "El total de Teclados vendidos fueron: " << totalDeKeyboards << endl;
        oFile <<"-----------------------------------------------------------------------------------------------------" << endl;
        menu();
        cin >> menuChoice;
        break;
      }
      case 2:{
        int totalDeDisks = 0;
        int totalDeSpeakers = 0;
        int totalDeKeyboards = 0;
        int total = 0;
        int result = 0;
        int dia = 0;
        string ganador;
        string ganador1 = "Discos Duros";
        string ganador2 = "Mini Altavoces";
        string ganador3 = "Teclados";
        cout << "Indique el dia en que desea ver que producto fue el mas vendido: ";
        cin >> dia;
        while(dia <= 0 || dia > MAX_DAYS){
          cout << "Por favor selecione un dia entre 1 y " << MAX_DAYS << ": ";
          cin >> dia;
        }
        dia--;
        for(int i = 0;i<MAX_VENDORS;i++){
          int numProducto = 0;
        	int h = 0;
        	while(h < MAX_PRODUCTS){
            if (numProducto == 0) {
              totalDeDisks +=ventas[i][h][dia].getProductos();
            }
            else if(numProducto == 1){
              totalDeSpeakers += ventas[i][h][dia].getProductos();
            }
            else if(numProducto == 2){
              totalDeKeyboards += ventas[i][h][dia].getProductos();
            }

        		h++;
            numProducto++;
      	  }
        }
        if(totalDeDisks >= totalDeSpeakers && totalDeDisks >= totalDeKeyboards)
        {
            cout << "El producto mas vendido del dia " << dia+1 << " fueron los Discos Duros con un total de: " << totalDeDisks << endl;
            oFile << "El producto mas vendido del dia " << dia+1 << " fueron los Discos Duros con un total de: " << totalDeDisks << endl;
        }

        if(totalDeSpeakers >= totalDeDisks && totalDeSpeakers >= totalDeKeyboards)
        {
            cout << "El producto mas vendido del dia " << dia+1 << " fueron los Mini Altavoces con un total de: " << totalDeSpeakers << endl;
            oFile << "El producto mas vendido del dia " << dia+1 << " fueron los Mini Altavoces con un total de: " << totalDeSpeakers << endl;
        }

        if(totalDeKeyboards >= totalDeDisks && totalDeKeyboards >= totalDeSpeakers) {
            cout << "El producto mas vendido del dia " << dia+1 << " fueron los teclados con un total de: " << totalDeKeyboards << endl;
            oFile << "El producto mas vendido del dia " << dia+1 << " fueron los teclados con un total de: " << totalDeKeyboards << endl;
        }
        oFile <<"-----------------------------------------------------------------------------------------------------" << endl;
        menu();
        cin >> menuChoice;
        break;
      }
      case 3:{

        int totalDeDisks = 0;
        int totalDeSpeakers = 0;
        int totalDeKeyboards = 0;
        int dia = 0;
        int producto = 0;
        cout << "Indique el dia en que desea: ";
        cin >> dia;
        while(dia <= 0 || dia > MAX_DAYS){
          cout << "Por favor seleccione un dia entre 1 y " << MAX_DAYS << ": ";
          cin >> dia;
        }
        cout << "Indique el producto: ";
        cin >> producto;
        while(producto <= 0 || producto > MAX_PRODUCTS){
          cout << "Por favor sleccione un producto entre 1 y " << MAX_PRODUCTS << ": ";
          cin >> producto;
        }
        dia--;
        producto--;
        for(int i = 0;i<MAX_VENDORS;i++){
        	cout << nombres[i] << ", vendio ";
        	oFile << nombres[i] << ", vendio ";
          cout << ventas[i][producto][dia].getProductos() << " ";
          oFile << ventas[i][producto][dia].getProductos() << " ";
          cout << productNames[producto] << " en el dia " << dia +1 << endl;
          oFile << productNames[producto] << " en el dia " << dia +1 << endl;

        }

        oFile <<"-----------------------------------------------------------------------------------------------------" << endl;
        menu();
        cin >> menuChoice;
        break;
      }
      case 4:{
        cout << "Terminando programa..." << endl;
        exit(0);
      }

      default:{
        cout << "Por favor ingerese una opcion valida: ";
        cin >> menuChoice;
      }
    }
  } while(menuChoice != 4);
  oFile.close();

  //Delete dynamic array
  delete [] ventas;

  return 0;
}

void menu(){
  cout << "Que desea hacer?" << endl;
  cout << "********************************************************************" << endl;
  cout << "1)Imprimir el total de unidades vendidas de cada producto en el mes." << endl;
  cout << "2)Imprimir el producto con mayor cantidad de ventas en un dia dado." << endl;
  cout << "3)Imprimir ventas de todos los vendedores en un dia dado." << endl;
  cout << "4) Salir." << endl;
  cout << "********************************************************************" << endl;
}

string* getNames(string names[]){
  ifstream myFile;
  myFile.open("entrada.txt");
  for(int h = 0;h < MAX_VENDORS;h++){

    string name;
    string discard;//discards strings inside the file that are not need to be stored in names
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
    string discard;//discards strings inside the file that are not need to be stored in p
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
