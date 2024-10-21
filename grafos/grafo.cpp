#include <iostream>
#include "matriz_adj.hpp"

int main(){
    Grafo g(5);
    for(int i = 0; i < 5; i++)
        for (int j = i+1; j < 5; j++)
            g.insereAresta(i,j,i+j);

    g.imprime();

    return 0;
}