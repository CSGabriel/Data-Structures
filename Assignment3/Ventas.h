#ifndef VENTAS_H
#define VENTAS_H
#include <string>
using namespace std;

class Ventas{
private:
  int numProductos;
  int numDias;
  string nombreDeVendedor;
  string nombreDeProducto;

public:
  Ventas();
  ~Ventas();
  void setProductos(int n);
  void setDias(int n);
  void setNameForVendor(string name);
  void setNameForProduct(string name);
  int getProductos();
  int getDias();
  string getNameForVendor();
  string getNameForProduct();

};


#endif
