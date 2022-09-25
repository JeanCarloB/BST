//
// Created by jeanc on 19/09/2022.
//

#ifndef BST_COLAPRIORITARIA_H
#define BST_COLAPRIORITARIA_H

#define MAX_PRIO_COL 1
#define MIN_PRIO_COL 2

#include "Heap.cpp"
#include "RuntimeException.h"

template<class T>
class ColaPrioritaria{
private:

    Heap<T>* heap;
    int tipo;

public:

    static const int MaxCola= MAX_PRIO_COL;
    static const int MinCola= MIN_PRIO_COL;

    ColaPrioritaria(int tipo = MaxCola);

    ColaPrioritaria(const ColaPrioritaria& cola);

    ColaPrioritaria(Lista<T>& lista, int tipo = MaxCola);

    bool esVacia();

    void enqueue(T elemento);

    T dequeue();

    void eliminar(int posicion);

    void Imprimir();

    ~ColaPrioritaria();
};
#endif //BST_COLAPRIORITARIA_H
