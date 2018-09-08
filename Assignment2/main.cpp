#include "Circulo.h"
#include "Punto.h"
#include "Punto.cpp"
#include "Circulo.cpp"
#include <iostream>

using namespace std;

void menu();


int main() {
  Punto punto;
  Circulo circulo;
  int menuChoice = 0;
  int X = 0;
  menu();
  cin >> menuChoice;
  do{
    switch(menuChoice){
      case 1:{
        circulo.capturarCirculo();
        menu();
        cin >> menuChoice;
        break;
      }
      case 2:{
        double a= 0.0;
        a = circulo.obtenerArea(X);
        menu();
        cin >> menuChoice;
        break;
      }
      case 3:{
        double circunferencia = 0.0;
        circunferencia = circulo.obtenerCircunferencia(X);
        menu();
        cin >> menuChoice;

        break;
      }
      case 4:{
        double diametro = 0.0;
        diametro = circulo.obtenerDiametro(X);
        menu();
        cin >> menuChoice;
        break;
      }

      case 5:{
        circulo.imprimirCirculos();
        menu();
        cin >> menuChoice;
        break;
      }
      case 6:{
        circulo.imprimirPuntos();
        menu();
        cin >> menuChoice;
        break;
      }
      case 7:{
        cout << "Programa a terminado!" << endl;
        exit(0);
      }
    }
  }while(menuChoice != 7);

  return 0;
}

void menu(){
  cout << "****************************************" << endl;
  cout << "Escoja una de las opciones:" << endl;
  cout << "1) Ingresar datos de un Círculo." << endl;
  cout << "2) Calcular Area de un Círculo." << endl;
  cout << "3) Calcular la circunferencia de un Círculo." << endl;
  cout << "4) Calcular el diámetro de un Círculo." << endl;
  cout << "5) Escribir todos los Círculos." << endl;
  cout << "6) Escribir los puntos de todos los Círculos." << endl;
  cout << "7) Salir." << endl;
  cout << "*****************************************" << endl;
}
