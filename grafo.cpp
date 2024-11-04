#include <stdio.h>
#include "matriz_adj.hpp"

int main (){
    Grafo grafo = Grafo(5);

    for (int i=0; i<5; i++){
        for (int j=i+1; j<5; j++){
            grafo.insereAresta(i,j,i+j);
        }
    }
    //grafo.insereAresta(1,2,1);
    grafo.imprime();

    return 0;
}