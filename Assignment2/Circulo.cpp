#include "Circulo.h"
#include "Punto.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;
int val=1;

Circulo::Circulo(){
  radio = 0;
  head = NULL;
  current = NULL;
  temp = NULL;
}
Circulo::Circulo(int xCoordinate,int yCoordinate,double rad)
: Punto(xCoordinate,yCoordinate)
{
  radio = rad;
}

//Destructor de la List
Circulo::~Circulo(){
  nodePtr list = head;
  if(emptyList() == true){
    cout << " \n List vacia, no se puede borar..." << endl;
  }
  else{
    while(head->link != NULL){
      head = head->link;
      delete list;
      list = head;
    }
    delete head;
    head = NULL;
    list = NULL;
    cout << "List has been deleted!" << endl;
  }
}

bool Circulo::emptyList(){
  if(head == NULL){
    return true;
  }
  else{
    return false;
  }
}

//Set del Radio
void Circulo::fijarRadio(double rad){
    radio = rad;
}

//Get del radio
double Circulo::obtenerRadio(){
  return radio;
}

void Circulo::capturarCirculo(){
  double rad;
  Punto::capturarPunto();
  int coordenadaX = Punto::obtenerX();
  int coordenadaY = Punto::obtenerY();
  cout << "Insertar Radio: " << endl;
  cin >> rad;
  if(rad <= 0){
    while(rad <= 0){
      cout << "Radio invalido, intente otra vez: ";
      cin >> rad;
    }
  }

  fijarRadio(rad);
  nodePtr n = new node;
  n->link = NULL;
  n->rad = obtenerRadio();
  n->xCoor = coordenadaX;
  n->yCoor = coordenadaY;
  n->valor = val;
  if(head != NULL){
    current = head;
    while(current->link != NULL){
      current = current->link;
    }
    current->link = n;
  }
  else{
    head = n;
  }
  val++;
}

void Circulo::imprimirCirculos(){
  int count = 1;
  current = head;
  if(current == NULL){
    cout << "There are no items on the list!" << endl;
  }
  while (current != NULL) {
    cout << "Circulo "<< count << ", Radio: " << current->rad << ", Centro de Circulo es el punto: (" << current->xCoor << ", " << current->yCoor <<")"<< endl;
    current = current->link;
    count++;
  }
}

void Circulo::imprimirPuntos(){
  int count = 1;
  current = head;
  if(current == NULL){
    cout << "There are no items on the list!" << endl;
  }
  while (current != NULL) {
    cout << "Punto central del Circulo "<< count << ", es: " << "(" << current->xCoor << ", " << current->yCoor <<")"<< endl;
    current = current->link;
    count++;
  }
}

double Circulo::obtenerArea(int x){
  nodePtr List;
    int i = 0;
    double area = 0;
    if(emptyList() == true)
    {
        cout << "List vacia" << endl;
        return 0;
    }
    else
    cout << "Cual circulo le desea ver el area?: ";
    cin >> x;
    for (List = head; List != NULL; List = List -> link){
      if(x == List -> valor)
      {
        cout << " " << endl;
        cout << "Para el circulo: " << List -> valor << endl;
          area = 3.141592 * List ->rad * List -> rad;
          cout << "Su area es: " << area << endl;
          cout << " "<< endl;
          i++;
      }
    }
    return area;
}

double Circulo::obtenerCircunferencia(int x){
  nodePtr List;
    int i = 0;
    double circunferencia = 0;
    if(emptyList() == true)
    {
        cout << "List vacia" << endl;
        return 0;
    }
    else
    cout << "Cual circulo le desea ver su circunferencia?: ";
    cin >> x;
    for (List = head; List != NULL; List = List -> link){
      if(x == List -> valor)
      {
        cout << " " << endl;
        cout << "Para el circulo: " << List -> valor << endl;
          circunferencia = 3.141592 * List ->rad * 2;
          cout << "Su circunferencia es: " << circunferencia << endl;
          cout << " "<< endl;
          i++;
      }
    }
    return circunferencia;
}

double Circulo::obtenerDiametro(int x){
  nodePtr List;
    int i = 0;
    double diametro = 0;
    if(emptyList() == true)
    {
        cout << "List vacia" << endl;
        return 0;
    }
    else
    cout << "Cual circulo le desea ver su diametro?: ";
    cin >> x;
    for (List = head; List != NULL; List = List -> link){
      if(x == List -> valor)
      {
        cout << " " << endl;
        cout << "Para el circulo: " << List -> valor << endl;
          diametro = List ->rad * 2;
          cout << "Su diametro es: " << diametro << endl;
          cout << " "<< endl;
          i++;
      }
    }
    return diametro;
}
