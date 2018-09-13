#include <iostream>
#include <fstream>
#include "Ventas.h"
#include "Ventas.cpp"

using namespace std;

void menu();

int main(){
  Ventas ***ventas;
  ventas = new Ventas**[12];
  for(int i=0;i<12;++i){
    ventas[i]=new Ventas*[3];

    for(int k=0;k<3;++k)
        ventas[i][k]=new Ventas[7];
  }
  menu();

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
