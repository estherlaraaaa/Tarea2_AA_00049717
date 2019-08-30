#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

//nodo para la pila1 de numeros pares
struct Nodo{
  int dato;
  Nodo *sig;
}*inicio;

//nodo para la pila2 de numeros impares
struct Nodo2{
  int dato;
  Nodo2 *sig;
}*inicio2;


//creando la clase de la pila1 con todas sus funcionalidades
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

//creando la clase de la pila2 con todas sus funcionalidades 
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

  //inicializamos las pilas y les damos nombre
    PilaDeNumerosPares pila1;
    PilaDeNumerosImpares pila2; 

  //este for es para pedirle los numeros al usuario 
    int numeros[6], *num, par=0, impar=0;
    cout << "Por favor ingrese 6 nùmeros: \n";
    for(int i = 0; i < 6; i++)
    {
        cin >> numeros[i];
    }

    num = numeros;

  //este for es para ver si es par o impar
  //tambien llena la respectiva pila dependiendo del caso
   for(int i = 0; i < 6; i++)
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

  //mostramos las dos pilas llenas 
    cout << "Pila1: ";
    pila1.mostrarPila();
    cout << "" << endl;

    cout << "Pila2: ";
    pila2.mostrarPila2(); 
    cout << "" << endl;
    
  //decidimos que pila tiene mas numeros o si son igual de tamaño
    if (par > impar){
        cout << "La pila 1 tiene mas numeros "<< endl;
    }else if (par < impar){
        cout << "La pila 2 tiene mas numeros " << endl;
    } else
        cout << "Ambas pilas tienen la misma cantidad " << endl; 
    return 0; 

}