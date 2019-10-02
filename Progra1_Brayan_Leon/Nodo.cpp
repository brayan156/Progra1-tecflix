#include <cstdlib>
#include <iostream>
#include "Nodo.h"
using namespace std;
template<typename T>

Nodo<T>::Nodo()
{
    dato = NULL;
    next = NULL;
}

template<typename T>
void Nodo<T>::print()
{
    cout << "Node-> " << "Dato: " << dato << " Direcion: " << this << " Siguiente: " << next << endl;
    cout << dato << "-> ";
}

// Constructor por parámetro
template<typename T>
Nodo<T>::Nodo(T data_) {
    dato = data_;
}

template<class T>
Nodo<T>::~Nodo()
{

}
template<typename T>
void Nodo<T>::delete_all()
{
    if (next)
        next->delete_all();
    delete this;
}
