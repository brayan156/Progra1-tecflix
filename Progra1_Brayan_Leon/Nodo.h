#ifndef NODO_H
#define NODO_H


using namespace std;

template <class T>

class Nodo {

    public:
        Nodo *next;
        T dato;

        Nodo();
        Nodo(T);
        ~Nodo();



        void delete_all();
        void print();
    };


#endif // NODO_H
