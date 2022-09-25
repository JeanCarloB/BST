//
// Created by jeanc on 24/09/2022.
//

#ifndef BST_HEAP_H
#define BST_HEAP_H

#define MAX_HEAP 1
#define MIN_HEAP 2

#include "Lista.cpp"

template <class T>

class Heap {
private:

    Lista<T>* lista;
    int tipo;

public:

    static const int MaxHeap= MAX_HEAP;
    static const int MinHeap= MIN_HEAP;

    Heap(int tipo = MaxHeap);

    Heap(Lista<T>* lista, int tipo = MaxHeap);

    Heap(const Heap& heap);

    bool esVacia();

    void insertar(T elemento);

    void eliminar(int posicion);

    T getPrimeroq();

    int getPadre(int indice);

    int getIzquierdo(int indice);

    int getDerecho(int indice);

    void heapifyUp(int indice);

    void heapifyDown(int indice);

    void crearHeap();

    void Imprimir();

    ~Heap();
};


#endif //BST_HEAP_H
