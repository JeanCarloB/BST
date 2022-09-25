//
// Created by jeanc on 23/09/2022.
//

#ifndef BST_MENU_H
#define BST_MENU_H

#include "ColaPrioritaria.cpp"
#include "Cliente.h"


class Menu {

private:
    ColaPrioritaria<Cliente*> *colaCliente;
    Lista<Cliente*> *listaCliente;
public:
    Menu();
    virtual ~Menu();
    void menuPrincipal();
    void encolarTodos();
    void encolarIndividual();
    void atenderCincoClientes();
    void mostrarSiguienteAtender();
    void simularAtencion();
    void agregarCliente();
    void leerArchivo();
};



#endif //BST_MENU_H
