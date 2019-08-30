#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct Nodo{
  int dato;
  Nodo *sig;
}*inicio;

struct Nodo2{
  int dato;
  Nodo2 *sig;
}*inicio2;

class PilaDeNumerosPares{
  public:
    Nodo *crearNodo(int valor){
      Nodo *n = new Nodo;
      n->dato = valor;
      n->sig=nullptr;
      return n;
    }

    void push(int valor){
      Nodo *n = crearNodo(valor);
      n->sig = inicio;
      inicio = n;
    }

    void pop(){
      Nodo *temp = inicio;
      inicio = inicio -> sig; 
      free(temp);
    }

    void mostrarPila(){
      Nodo *temp = inicio;
      if(!inicio)
        cout<<"the stack is empty"<<endl;
      else
      while(temp){
        cout<< temp -> dato << ",";
        temp = temp ->sig;
      }
    }

    PilaDeNumerosPares(){
      inicio = nullptr;
    }
};

class PilaDeNumerosImpares{
  public:
    Nodo2 *crearNodo(int valor){
      Nodo2 *n = new Nodo2;
      n->dato = valor;
      n->sig=nullptr;
      return n;
    }

    void pusha(int valor){
      Nodo2 *n = crearNodo(valor);
      n->sig = inicio2;
      inicio2 = n;
    }

    void pop(){
      Nodo2 *temp = inicio2;
      inicio2 = inicio2 -> sig; 
      free(temp);
    }

    void mostrarPila2(){
      Nodo2 *temp = inicio2;
      if(!inicio2)
        cout<<"the stack is empty"<<endl;
      else
      while(temp){
        cout<< temp -> dato << ",";
        temp = temp ->sig;
      }
    }

    PilaDeNumerosImpares(){
      inicio2 = nullptr;
    }
};

int main()
{
    PilaDeNumerosPares pila1;
    PilaDeNumerosImpares pila2; 

    int numeros[5], *num, par=0, impar=0;
    cout << "Por favor ingrese 5 nùmeros: \n";
    for(int i = 0; i < 5; i++)
    {
        cin >> numeros[i];
    }

    num = numeros;

   for(int i = 0; i < 5; i++)
    {
        if (*num%2==0){
          par++;
          pila1.push(*num);
        }
        else if(*num%2!=0){
          impar++; 
          pila2.pusha(*num);
        }
        num ++; 
    }

    
    cout << "pila1: ";
    pila1.mostrarPila();
    cout << "" << endl;

    cout << "pila2: ";
    pila2.mostrarPila2(); 
    cout << "" << endl;
    
    if (par > impar){
        cout << "la pila 1 tiene mas numeros "<< endl;
    }else
        cout << "la pila 2 tiene mas numeros " << endl;

    return 0; 

}