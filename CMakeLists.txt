cmake_minimum_required(VERSION 3.23)
project(BST)

set(CMAKE_CXX_STANDARD 14)

add_executable(BST Libreria.h Nodo.cpp Nodo.h ABB.cpp ABB.h main.cpp Cliente.cpp Cliente.h RuntimeException.cpp RuntimeException.h Lista.cpp Lista.h ColaPrioritaria.cpp ColaPrioritaria.h Menu.cpp Menu.h Heap.cpp Heap.h)
