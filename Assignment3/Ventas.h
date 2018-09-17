#ifndef VENTAS_H
#define VENTAS_H
#include <string>
using namespace std;

class Ventas{
private:
  int numProductos;
  string nombreDeVendedor;
  string nombreDeProducto;

public:
  Ventas();
  ~Ventas();
  void setProductos(int n);
  void setNameForVendor(string name);
  void setNameForProduct(string name);
  int getProductos();
  string getNameForVendor();
  string getNameForProduct();

};


#endif
