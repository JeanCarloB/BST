//
// Created by jeanc on 19/09/2022.
//

#ifndef BST_LISTA_H
#define BST_LISTA_H

#include "Nodo.cpp"
#include "Libreria.h"

template<class T>
class Lista
{
private:

    Nodo<T>* primero;
    int cantidad;

public:

    Lista();

    Lista(const Lista& lista);

    bool esVacia();

    int getCantidad() const;

    void insertar(T elemento);

    void eliminar(Nodo<T>* nodoPorEliminar);

    void eliminarEnPosicion(int posicion);

    T getPrimero();

    int getUltimo();

    Nodo<T>* getPosicion(int posicion);

    int comparaElementoMayor(int i, int j);

    int comparaElementoMenor(int i, int j);

    bool adyacentes(Nodo<T>* i, Nodo<T>* j);

    void intercambiarIndices(Nodo<T>* i, Nodo<T>* j);

    void intercambiarPosiciones(int i, int j);

    void Imprimir();

    ~Lista();
};

#endif //BST_LISTA_H
