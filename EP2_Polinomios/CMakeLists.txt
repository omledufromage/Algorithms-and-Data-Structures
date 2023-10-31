cmake_minimum_required(VERSION 3.23)
project(EP2_Polinomios C)

set(CMAKE_C_STANDARD 99)

add_executable(EP2_Polinomios main.c mallocc.c mallocc.h polinomio.h polinomio.c)
target_link_libraries(EP2_Polinomios m)

#[[
add_executable(CLIENTE cliente.c item.h mallocc.c mallocc.h pilha_lista_ligada.c pilha.h)

gcc -std=c99 -pedantic -O2 -Wall -c mallocc.c
gcc -std=c99 -pedantic -O2 -Wall -c pilha_lista_ligada.c
gcc -std=c99 -pedantic -O2 -Wall -c cliente.c
gcc -std=c99 -pedantic -O2 -Wall mallocc.o pilha_lista_ligada.o cliente.o -o cliente
./cliente
]]#
