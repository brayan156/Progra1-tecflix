#ifndef LISTA_H
#define LISTA_H


#include "Nodo.h"
#include "Nodo.cpp"


using namespace std;

template <class T>

class Lista {
public:
    Lista();
    ~Lista();

    void addFirst(T);
    void addLast(T);
    void clean();
    void eliminardato(T);
    void eliminarpos(int);
    T search(T);
    void print();
    T buscarpos(int);
    void editar(int, int);

private:
    Nodo<T> *head;
    int largo;

};

#endif // LISTA_H
