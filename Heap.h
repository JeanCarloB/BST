//
// Created by jeanc on 24/09/2022.
//

#ifndef BST_HEAP_H
#define BST_HEAP_H

#define MAX_HEAP 1
#define MIN_HEAP 2

#include "Lista.h"

template <class T>

class Heap {
private:

    Lista<T>* lista;
    int tipo;

public:

    static const int MaxHeap= MAX_HEAP;
    static const int MinHeap= MIN_HEAP;

    Heap(int tipo = MaxHeap)
    {
        lista = new Lista<T>();
        this->tipo = tipo;
        crearHeap();
    }

    Heap(Lista<T>* lista, int tipo = MaxHeap)
    {
        this->tipo = tipo;
        this->lista = lista;
        crearHeap();
    }

    Heap(const Heap& heap)
    {
        this->tipo = heap.tipo;
        this->lista = new Lista<T>(*heap.lista);
        crearHeap();
    }

    bool esVacia()
    {
        return this->lista->esVacia();
    }

    void insertar(T elemento)
    {
        int indice = lista->getUltimo();
        this->lista->insertar(elemento);
        heapifyUp(indice);
    }

    void eliminar(int posicion)
    {
        int ultimo = this->lista->getCantidad();

        if (posicion != ultimo)
        {
            this->lista->intercambiarPosiciones(posicion, ultimo);
        }

        this->lista->eliminarEnPosicion(ultimo);
        heapifyDown(posicion);
    }

    T getPrimeroq()
    {
        if (!esVacia())
        {
            T elemento = this->lista->getPrimero();
            heapifyDown(1);

            return elemento;
        }

        return this->lista->getPrimero();
    }

    int getPadre(int indice)
    {
        return indice / 2;
    }

    int getIzquierdo(int indice)
    {
        return 2 * indice;
    }

    int getDerecho(int indice)
    {
        return (2 * indice) + 1;
    }

    void heapifyUp(int indice)
    {
        int padre = getPadre(indice);
        int izquierdo = getIzquierdo(indice);
        int derecho = getDerecho(indice);
        int maxPrioridad = -1;

        if (this->tipo == MaxHeap)
        {
            maxPrioridad = this->lista->comparaElementoMayor(izquierdo, derecho);
        }

        if (this->tipo == MinHeap)
        {
            maxPrioridad = this->lista->comparaElementoMenor(izquierdo, derecho);
        }

        if (maxPrioridad != -1)
        {
            if (this->tipo == MaxHeap)
            {
                maxPrioridad = this->lista->comparaElementoMayor(maxPrioridad, padre);
            }

            if (this->tipo == MinHeap)
            {
                maxPrioridad = this->lista->comparaElementoMenor(maxPrioridad, padre);
            }

            if (maxPrioridad != padre)
            {
                this->lista->intercambiarPosiciones(padre, maxPrioridad);
                heapifyUp(padre);
            }
        }
    }

    void heapifyDown(int indice)
    {
        int izquierdo = getIzquierdo(indice);
        int derecho = getDerecho(indice);
        int maxPrioridad = -1;

        if (this->tipo == MaxHeap)
        {
            maxPrioridad = this->lista->comparaElementoMayor(izquierdo, derecho);
        }

        if (this->tipo == MinHeap)
        {
            maxPrioridad = this->lista->comparaElementoMenor(izquierdo, derecho);
        }

        if (maxPrioridad != -1)
        {
            if (this->tipo == MaxHeap)
            {
                maxPrioridad = this->lista->comparaElementoMayor(maxPrioridad, indice);
            }

            if (this->tipo == MinHeap)
            {
                maxPrioridad = this->lista->comparaElementoMenor(maxPrioridad, indice);
            }

            if (maxPrioridad != indice)
            {
                this->lista->intercambiarPosiciones(indice, maxPrioridad);
                heapifyDown(maxPrioridad);
            }
        }
    }

    void crearHeap()
    {
        int ultimo = lista->getCantidad() / 2;

        for (int i = ultimo; i > 0; i--)
        {
            heapifyDown(i);
        }
    }

    void Imprimir()
    {
        this->lista->Imprimir();
    }

    ~Heap()
    {
        delete this->lista;
    }
};


#endif //BST_HEAP_H
