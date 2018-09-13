#include "Ventas.h"

using namespace std;

Ventas::Ventas(){
  numProductos = 0;
  numDias = 0;
  nombreDeVendedor = " ";
  nombreDeProducto = " ";
}

Ventas::~Ventas(){
  cout << "Objetos de la clase venta han sido destruidos!" << endl;
}

void Ventas::setProductos(int n){
  numProductos  = n;
}

void Ventas::setDias(int n){
  numDias = n;
}

void Ventas::setNameForVendor(string name){
  nombreDeVendedor = name;
}

void Ventas::setNameForProduct(string name){
  nombreDeProducto = name;
}

int Ventas::getProductos(){
  return numProductos;
}

int Ventas::getDias(){
  return numDias;
}

string Ventas::getNameForVendor(){
  return nombreDeVendedor;
}

string Ventas::getNameForProduct(){
  return nombreDeProducto;
}
