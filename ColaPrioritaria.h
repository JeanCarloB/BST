//
// Created by jeanc on 19/09/2022.
//

#ifndef BST_COLAPRIORITARIA_H
#define BST_COLAPRIORITARIA_H

#define MAX_PRIO_COL 1
#define MIN_PRIO_COL 2

#include "Heap.h"
#include "RuntimeException.h"

template<class T>
class ColaPrioritaria{
private:

    Heap<T>* heap;
    int tipo;

public:

    static const int MaxCola= MAX_PRIO_COL;
    static const int MinCola= MIN_PRIO_COL;

    ColaPrioritaria(int tipo = MaxCola)
    {
        this->heap = new Heap<T>();
        this->tipo = tipo;
    }

    ColaPrioritaria(const ColaPrioritaria& cola)
    {
        this->heap = new Heap<T>(*cola.heap);
        this->tipo = cola.tipo;
    }

    ColaPrioritaria(Lista<T>& lista, int tipo = MaxCola)
    {
        this->heap = new Heap<T>(new Lista<T>(lista), tipo);
        this->tipo = tipo;
    }

    bool esVacia()
    {
        return this->heap->esVacia();
    }

    void enqueue(T elemento)
    {
        this->heap->insertar(elemento);
    }

    T dequeue()
    {
        return this->heap->getPrimeroq();
    }

    void eliminar(int posicion)
    {
        this->heap->eliminar(posicion);
    }

    void Imprimir()
    {
        this->heap->Imprimir();
    }

    ~ColaPrioritaria()
    {

        delete this->heap;
    }
};
#endif //BST_COLAPRIORITARIA_H
