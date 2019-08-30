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

class Pila{
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

    Pila(){
      inicio = nullptr;
    }
};

class Pila2{
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

    Pila2(){
      inicio = nullptr;
    }
};

int main()
{
    Pila pila1;
    Pila2 pila2; 

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
          *num = par++;
        }
        else if(*num%2!=0){
          *num = impar++; 
        }
        num ++; 
    }

    
    pila1.push(par);
    pila2.push(impar);
    
    cout << "pila1" << endl;
    pila1.mostrarPila();
    cout << "" << endl;

    cout << "pila2" << endl;
    pila2.mostrarPila(); 
    cout << "" << endl;
    
    if (par > impar){
        cout << "la pila 1 tiene mas numeros "<< endl;
    }else
        cout << "la pila 2 tiene mas numeros " << endl;

    return 0; 

}