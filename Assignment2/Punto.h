#ifndef PUNTO_H
#define PUNTO_H
#include <iostream>
#include <string>
using namespace std;

class Punto{
protected:
  int x;
  int y;
public:
  Punto();
  Punto(int x, int y);
  ~Punto();
  void capturarPunto();
  void fijarX(int x);
  void fijarY(int y);
  int obtenerX();
  int obtenerY();
};

#endif
