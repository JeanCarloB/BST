//
// Created by jeanc on 06/09/2022.
//

#include "ABB.h"

template<class T>
Nodo<T>* ABB<T>::makeEmpty(Nodo<T>* t){
    if(t == nullptr)
        return nullptr;
    {
        makeEmpty(t->getAnterior());
        makeEmpty(t->getSiguiente());
        delete t;

    }
    return nullptr;
}

template<class T>
Nodo<T>* ABB<T>::insert(T* x, Nodo<T>* t){
    if(t == nullptr){
        t = new Nodo<T>(x);

    }else if(*(x) < *(t->getDato())){
        t->setAnterior(insert(x, t->getSiguiente()));
    }else if(*(x) > *(t->getDato())){
        t->setSiguiente(insert(x, t->getSiguiente()));
    }
    return t;

}

template<class T>
Nodo<T>* ABB<T>::findMin(Nodo<T>* t){
    if(t == nullptr){
        return nullptr;
    }else if(t->getAnterior() == nullptr){
        return t;
    }else{
        return findMin(t->getAnterior());
    }
}

template<class T>
Nodo<T>* ABB<T>::findMax(Nodo<T>* t){
    if(t == nullptr){
        return nullptr;
    }else if(t->getSiguiente() == nullptr){
        return t;
    }else{
        return findMax(t->getSiguiente());
    }
}

template<class T>
Nodo<T>* ABB<T>::remove(T *x, Nodo<T>* t){
    Nodo<T>* temp;

    if(t == nullptr){
        return nullptr;
    }else if(x < t->getDato()){
        t->setAnterior(remove(x, t->getAnterior()));
    }else if(x > t->getDato()){
        t->setSiguiente(remove(x, t->getSiguiente()));
    }else if(t->getAnterior() && t->getSiguiente()){
        temp = findMin(t->getSiguiente());
        t->setDato(temp->getDato());
        t->setSiguiente(remove(t->getDato(), t->getSiguiente()));
    }else{
        temp = t;
        if(t->getAnterior() == nullptr){
            t = t->getSiguiente();
        }else if(t->getSiguiente() == nullptr){
            t = t->getAnterior();
        }
        delete temp;
    }
    return t;
}

template<class T>
void ABB<T>::inOrder(Nodo<T>* t){
    if(t == nullptr){
        return;
    }
    inOrder(t->getAnterior());
    cout << *t->getDato() << "\n";
    inOrder(t->getSiguiente());
}

template<class T>
Nodo<T>* ABB<T>::find(Nodo<T>* t, T *x){
    if(t == nullptr){
        return nullptr;
    }else if(x < t->getDato()){
        return find(t->getAnterior(), x);
    }else if(x > t->getDato()){
        return find(t->getSiguiente(), x);
    }else{
        return t;
    }
}

template<class T>
ABB<T>::ABB() {
    root = nullptr;
    n=0;
}

template<class T>
ABB<T>::~ABB(){
    root = makeEmpty(root);
}

template<class T>
void ABB<T>::insert(T *x){
    root = insert(x, root);
    n++;
}

template<class T>
void ABB<T>::remove(T *x){
    root = remove(x, root);
    n--;
}

template<class T>
void ABB<T>::display(){
    inOrder(root);
    cout << endl;
}

template<class T>
void ABB<T>::search(T *x){
    root = find(root, x);
}

template<class T>
void ABB<T>::leerDatos(Nodo<T>* nodo) {

    string nombre, id, ingNino, emb, aduMay, categoria;
    bool ingresaNino, embarazo, adultoMayor;


    ifstream f("../DatosBancoUno.txt", ios::in);

    if (f.is_open()) {
        while (!f.eof()) {
            getline(f,nombre,',');
            getline(f,id,',');
            getline(f,ingNino,',');
            getline(f,emb,',');
            getline(f,aduMay,',');
            getline(f,categoria,'\n');

            if (ingNino == "Yes") ingresaNino = false;
            else ingresaNino = true;

            if (emb == "Yes") embarazo = false;
            else embarazo = true;

            if (aduMay == "Yes") adultoMayor = false;
            else adultoMayor = true;
            insert(new T(nombre, id, ingresaNino, embarazo, adultoMayor, categoria));
        }
        f.close();
    }else{
        throw RuntimeException("Error al abrir archivo");
    }
}

template<class T>
Nodo<T> *ABB<T>::getRoot() const {
    return root;
}

template<class T>
int ABB<T>::getSize() {
    return n;
}

template<class T>
T *ABB<T>::recorre(Nodo<T> * nodo) {
    if(nodo!= nullptr){
        return recorre(nodo->getAnterior());
        return recorre(nodo->getSiguiente());
        cout<<*nodo->getDato();
    }
    return nullptr;
}

template<class T>
Lista<T> *ABB<T>::doubleLinkedList(Nodo<T> * r) {
    Nodo<T>* h= nullptr;
    Nodo<T>* prev = nullptr;

    // Recursively convert left subtree
    doubleLinkedList(r->getAnterior(), h);

    // Now convert this node
    if (prev == nullptr)
        *h = r;
    else
    {
        r->left = prev;
        prev->right = r;
    }
    prev = r;

    // Finally convert right subtree
    doubleLinkedList(r->getSiguiente(), h);
}
