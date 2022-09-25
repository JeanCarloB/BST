//
// Created by jeanc on 19/09/2022.
//

#include "ColaPrioritaria.h"
template <class T>
ColaPrioritaria<T>::ColaPrioritaria(int tipo)
{
    this->heap = new Heap<T>();
    this->tipo = tipo;
}
template <class T>
ColaPrioritaria<T>::ColaPrioritaria(const ColaPrioritaria& cola)
{
    this->heap = new Heap<T>(*cola.heap);
    this->tipo = cola.tipo;
}
template <class T>
ColaPrioritaria<T>::ColaPrioritaria(Lista<T>& lista, int tipo)
{
this->heap = new Heap<T>(new Lista<T>(lista), tipo);
this->tipo = tipo;
}
template <class T>
bool ColaPrioritaria<T>::esVacia()
{
    return this->heap->esVacia();
}
template <class T>
void ColaPrioritaria<T>::enqueue(T elemento)
{
    this->heap->insertar(elemento);
}
template <class T>
T ColaPrioritaria<T>::dequeue()
{
    return this->heap->getPrimeroq();
}
template <class T>
void ColaPrioritaria<T>::eliminar(int posicion)
{
    this->heap->eliminar(posicion);
}
template <class T>
void ColaPrioritaria<T>::Imprimir()
{
    this->heap->Imprimir();
}
template <class T>
ColaPrioritaria<T>::~ColaPrioritaria()
{

    delete this->heap;
}