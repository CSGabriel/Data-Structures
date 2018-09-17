#include "Ventas.h"

using namespace std;

Ventas::Ventas(){
  numProductos = 0;
  nombreDeVendedor = " ";
  nombreDeProducto = " ";
}

Ventas::~Ventas(){}

void Ventas::setProductos(int n){
  numProductos  = n;
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

string Ventas::getNameForVendor(){
  return nombreDeVendedor;
}

string Ventas::getNameForProduct(){
  return nombreDeProducto;
}
