cmake_minimum_required(VERSION 3.23)
project(EP2_Polinomios C)

set(CMAKE_C_STANDARD 99)


add_executable(CLIENTE cliente.c item.h mallocc.c mallocc.h pilha_lista_ligada.c pilha.h)
#[[
add_executable(EP2_Polinomios main.c polinomio.h polinomio.c pilha_lista_ligada.c pilha.h mallocc.c mallocc.h item.h cliente.c)
]]#