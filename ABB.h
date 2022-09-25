//
// Created by jeanc on 06/09/2022.
//

#ifndef BST_ABB_H
#define BST_ABB_H

#include "Libreria.h"
#include "RuntimeException.h"
template<class T>
        class Nodo;
template<class T>
        class Lista;
template<class T>

class ABB {
public:
    ABB();
    ~ABB();
    void insert(T *x);
    void remove(T *x);
    void display();
    void search(T *x);
    void leerDatos(Nodo<T>*);
    T* recorre(Nodo<T>*);
    Lista<T>* doubleLinkedList(Nodo<T>* r);
    int getSize();
    Nodo<T> *getRoot() const;

private:
    int n;
    Nodo<T>* root;
    Nodo<T>* makeEmpty(Nodo<T>* t);
    Nodo<T>* insert(T *x, Nodo<T>* t);
    Nodo<T>* findMin(Nodo<T>* t);
    Nodo<T>* findMax(Nodo<T>* t);
    Nodo<T>* remove(T *x, Nodo<T>* t);
    void inOrder(Nodo<T>* t);
    Nodo<T>* find(Nodo<T>* t, T *x);
};

#endif //BBS_ABB_H
