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

int main()
{
    Pila pila1;
    Pila pila2; 

    int numeros[5], *num, par, impar;
    cout << "Por favor ingrese 5 nùmeros: \n";
    for(int i = 0; i < 5; i++)
    {
        cin >> numeros[i];
    }

    num = numeros;

   for(int i = 0; i < 5; i++)
    {
        if (*num%2==0){
          cout<<"numero par "<<*num<<endl;  
          *num = par; 
        }
        else if(*num%2!=0){
          cout<<"numero impar "<<*num<<endl;
          *num = impar; 
        }
        num ++; 
    }

    cout << par << endl;
    cout << impar << endl; 

    pila1.push(par);
    pila2.push(impar);

    cout << "pila1" << endl;
    pila1.mostrarPila();

    cout << "pila2" << endl;
    pila2.mostrarPila(); 

    return 0; 

}