cmake_minimum_required(VERSION 3.23)
project(EP2_Polinomios C)

set(CMAKE_C_STANDARD 99)

add_executable(EP2_Polinomios main.c polinomio.h polinomio.c fila_lista_ligada.c fila.h malocc.c malocc.h)
