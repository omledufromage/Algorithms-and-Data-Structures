cmake_minimum_required(VERSION 3.23)
project(Filas C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled main.c fila_lista_ligada.c fila.h item.c mallocc.c mallocc.h item.h)
