

#include <cstdlib>
#include <iostream>
#include "Lista.h"
#include "Nodo.h"
using namespace std;

// Constructor por defecto
template<typename T>
Lista<T>::Lista()
{
    largo = 0;
    head = NULL;
}

template<class T>
Lista<T>::~Lista()
{

}

// Insertar al inicio
template<typename T>
void Lista<T>::addFirst(T data_)
{
    Nodo<T> *new_node = new Nodo<T> (data_);
    Nodo<T> *temp = head;

    if (!head) {
        head = new_node;
    } else {
        new_node->next = head;
        head = new_node;

        while (temp) {
            temp = temp->next;
        }
    }
    largo++;
}

// Insertar al final
template<typename T>
void Lista<T>::addLast(T data_)
{
    Nodo<T> *new_node = new Nodo<T> (data_);
    Nodo<T> *temp = head;

    if (head==NULL) {
        head = new_node;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    largo++;
}


// Eliminar todos los nodos
template<typename T>
void Lista<T>::clean()
{
    head=NULL;
    head = 0;
}

// Eliminar por dato del NodoArbol
template<typename T>
void Lista<T>::eliminardato(T data_)
{
    Nodo<T> *temp = head;
    Nodo<T> *temp1 = head->next;

    int cont = 0;

    if (head->dato == data_) {
        head = temp->next;
    } else {
        while (temp1) {
            if (temp1->dato == data_) {
                Nodo<T> *aux_node = temp1;
                temp->next = temp1->next;
                delete aux_node;
                cont++;
                largo--;
            }
            temp = temp->next;
            temp1 = temp1->next;
        }
    }

    if (cont == 0) {
        cout << "No existe el dato " << endl;
    }
}

// Eliminar por posición del NodoArbol
template<typename T>
void Lista<T>::eliminarpos(int pos)
{
    Nodo<T> *temp = head;
    Nodo<T> *temp1 = temp->next;

    if (pos < 1 || pos > largo) {
        cout << "Fuera de rango " << endl;
    } else if (pos == 1) {
        head = temp->next;
    } else {
        for (int i = 2; i <= pos; i++) {
            if (i == pos) {
                Nodo<T> *aux_node = temp1;
                temp->next = temp1->next;
                delete aux_node;
                largo--;
            }
            temp = temp->next;
            temp1 = temp1->next;
        }
    }
}

template<typename T>
T Lista<T>::buscarpos(int pos)
{
    Nodo<T> *temp = head;
    Nodo<T> *temp1 = temp->next;

    if (pos < 0 || pos == largo) {
        cout << "Fuera de rango " << endl;
        return 0;
    } else {
        for (int i = 0; i <= pos; i++) {
            if (i == pos) {
                return temp->dato;
            }
            temp = temp->next;
        }
    }
}

template<class T>
void Lista<T>::editar(int pos, int dato)
{
    {
        Nodo<T> *temp = head;


        if (pos < 0 || pos == largo) {
            cout << "Fuera de rango " << endl;
        } else {
            for (int i = 0; i <= pos; i++) {
                if (i == pos) {
                     temp->dato=dato;
                }
                temp = temp->next;

            }
        }
    }
}



// Imprimir la Lista
template<typename T>
void Lista<T>::print()
{
    Nodo<T> *temp = head;
    if (!head) {
        cout << "La Lista está vacía " << endl;
    } else {
        while (temp) {
            temp->print();
            if (!temp->next) cout << "NULL";
            temp = temp->next;
        }
    }
    cout << endl << endl;
}

// Buscar el dato de un NodoArbol
template<typename T>
T Lista<T>::search(T data_)
{
    Nodo<T> *temp = head;
    int cont = 1;
    int cont2 = 0;

    while (temp) {
        if (temp->dato == data_) {
            cout << "El dato se encuentra en la posición: " << cont << endl;
            cont2++;
            return temp;
        }
        temp = temp->next;
        cont++;
    }

    if (cont2 == 0) {
        cout << "No existe el dato " << endl;
        return nullptr;
    }
    cout << endl << endl;
}


