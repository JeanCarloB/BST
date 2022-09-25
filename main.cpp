//
// Created by jeanc on 06/09/2022.
//

#include "Menu.h"

/**
   *
   * Tuvimos problemas al momento de intentar agregar objetos en el arbol por
   * lo que para evitar que el programa se caiga decidimos cargar todos
   * los clientes directamente en la cola
   *
   * Las opciones 1 y 2 del menu no tienen mas que un texto ya que todos los clientes
   * ya se encuentran en la cola
   *
   * Intentamos hacer el orden descendiente pero no funciono la forma en la que lo implementamos
   *
   * **/

int main(){

    Menu* menu=new Menu();
    menu->leerArchivo();
    menu->menuPrincipal();
    delete menu;

    return 0;

}