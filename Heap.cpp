//
// Created by jeanc on 24/09/2022.
//

#include "Heap.h"
template <class T>
Heap<T>::Heap(int tipo)
{
    lista = new Lista<T>();
    this->tipo = tipo;
    crearHeap();
}
template <class T>
Heap<T>::Heap(Lista<T>* lista, int tipo)
{
this->tipo = tipo;
this->lista = lista;
crearHeap();
}
template <class T>
Heap<T>::Heap(const Heap& heap)
{
    this->tipo = heap.tipo;
    this->lista = new Lista<T>(*heap.lista);
    crearHeap();
}
template <class T>
bool Heap<T>::esVacia()
{
    return this->lista->esVacia();
}
template <class T>
void Heap<T>::insertar(T elemento)
{
    int indice = lista->getUltimo();
    this->lista->insertar(elemento);
    heapifyUp(indice);
}
template <class T>
void Heap<T>::eliminar(int posicion)
{
    int ultimo = this->lista->getCantidad();

    if (posicion != ultimo)
    {
        this->lista->intercambiarPosiciones(posicion, ultimo);
    }

    this->lista->eliminarEnPosicion(ultimo);
    heapifyDown(posicion);
}
template <class T>
T Heap<T>::getPrimeroq()
{
    if (!esVacia())
    {
        T elemento = this->lista->getPrimero();
        heapifyDown(1);

        return elemento;
    }

    return this->lista->getPrimero();
}
template <class T>
int Heap<T>::getPadre(int indice)
{
    return indice / 2;
}
template <class T>
int Heap<T>::getIzquierdo(int indice)
{
    return 2 * indice;
}
template <class T>
int Heap<T>::getDerecho(int indice)
{
    return (2 * indice) + 1;
}
template <class T>
void Heap<T>::heapifyUp(int indice)
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
template <class T>
void Heap<T>::heapifyDown(int indice)
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
template <class T>
void Heap<T>::crearHeap()
{
    int ultimo = lista->getCantidad() / 2;

    for (int i = ultimo; i > 0; i--)
    {
        heapifyDown(i);
    }
}
template <class T>
void Heap<T>::Imprimir()
{
    this->lista->Imprimir();
}
template <class T>
Heap<T>::~Heap()
{
    delete this->lista;
}