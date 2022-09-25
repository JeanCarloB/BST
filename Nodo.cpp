//
// Created by jeanc on 06/09/2022.
//
#include "Nodo.h"
template<class T>
Nodo<T>::Nodo(T elemento, int indice,  Nodo<T>* anterior, Nodo<T>* siguiente)
{
    this->elemento = elemento;
    this->indice = indice;
    this->anterior = anterior;
    this->siguiente = siguiente;
}
template<class T>
void Nodo<T>::setElemento(T elemento)
{
    this->elemento = elemento;
}
template<class T>
T Nodo<T>::getElemento() const
{
    return this->elemento;
}
template<class T>
void Nodo<T>::setIndice(int indice)
{
    this->indice = indice;
}
template<class T>
int Nodo<T>::getIndice() const
{
    return this->indice;
}
template<class T>
void Nodo<T>::setAnterior(Nodo<T>* anterior)
{
    this->anterior = anterior;
}
template<class T>
Nodo<T>* Nodo<T>::getAnterior() const
{
    return this->anterior;
}
template<class T>
void Nodo<T>::setSiguiente(Nodo<T>* siguiente)
{
    this->siguiente = siguiente;
}
template<class T>
Nodo<T>* Nodo<T>::getSiguiente() const
{
    return this->siguiente;
}
template<class T>
Nodo<T>::~Nodo()
{

}