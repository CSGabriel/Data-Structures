#include "Punto.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

//Constructor
Punto::Punto(){
  x = 0;
  y = 0;
}

Punto::Punto(int xCoordinate, int yCoordinate){
  x = xCoordinate;
  y = yCoordinate;
}

Punto::~Punto(){
  cout << "Deleted puntos" << endl;
}

void Punto::fijarX(int coordinateX){
  x = coordinateX;
}
void Punto::fijarY(int coordinateY){
  y = coordinateY;
}
int Punto::obtenerX(){
  return x;
}
int Punto::obtenerY(){
  return y;
}

void Punto::capturarPunto(){
  int x = 0;
  int y = 0;
  cout << "Inserte coordenada x: " << endl;
  cin >> x;
  fijarX(x);
  cout << "Inserte coordenada y: " << endl;
  cin >> y;
  fijarY(y);
}
