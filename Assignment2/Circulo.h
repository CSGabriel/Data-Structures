#ifndef CIRCULO_H
#define CIRCULO_H
#include "Punto.h"
#include <iostream>
#include <string>
using namespace std;

class Circulo:public Punto{

private:
  typedef struct node{
    double rad;
    int xCoor;
    int yCoor;
    int valor;
    node *link;
  }* nodePtr;
  nodePtr head;
  nodePtr current;
  nodePtr temp;
  double radio;
public:
  Circulo();
  Circulo(int xCoordinate, int yCoordinate, double radio);
  ~Circulo();
  void capturarCirculo(); //captures data, uses the point class to add x and y and adds node
  void fijarRadio(double rad);
  double obtenerRadio();
  double obtenerArea(int x);
  double obtenerCircunferencia(int x);
  double obtenerDiametro(int x);
  void imprimirCirculos();
  void imprimirPuntos();
  bool emptyList();

};



#endif
