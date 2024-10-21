#ifndef __matriz_adj_H_INCLUDED__   // if x.h hasn't been included yet...
#define __matriz_adj_H_INCLUDED__ 

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <array>
#include <cstring>
#include <float.h>
#include <climits>

using namespace std;



class Grafo {
	public:
		class Aresta {
	        private:
	        int v1, v2, peso; 
	        public: 
            Aresta (int v1, int v2, int peso) {
                this->v1 = v1; this->v2 = v2; this->peso = peso; int num = 0;
            }
        
            int _peso () { return this->peso; }
            int _v1 () { return this->v1; }
            int _v2 () { return this->v2; }
            ~Aresta () {}
	    };

	private:
	    int **mat; // @{\it pesos do tipo inteiro}@
        int numVertices;
        int *pos; // @{\it posi\c{c}\~ao atual ao se percorrer os adjs de um v\'ertice v}@
        vector<vector<int> > fluxo;
        vector<vector<int> > capacidade;

    public:
        Grafo (int numVertices);
        Grafo(istream &in);
        //Grafo(int numVertices, int numArestas);
        void insereAresta(int v1, int v2, int peso);
        bool existeAresta(int v1, int v2) const;
        bool listaAdjVazia(int v) const;
        Aresta *lerAresta();
        Aresta *primeiroListaAdj(int v);
        Aresta *proxAdj(int v);
        Aresta *retiraAresta(int v1, int v2);
        void imprime() const;
        int _numVertices() const;
        Grafo *grafoTransposto();
        Grafo *grafoNaoDirecionado();
        bool ExisteCaminhoEuler();
        bool ExisteCicloEuler();
        vector<int> listaAdj(int v1);
        void floydWarshall(int origem, int destino);
        bool buscaEmLargura(int origem, int destino, vector<int> &caminho);
        int fordFulkerson(int origem, int destino);
        bool verificaVisitaEVizinhanca(int v, int pos, vector<int> &caminho);
        bool cicloHamiltonianoAux(vector<int> &caminho, int pos);
        bool cicloHamiltoniano();
        void adicionarAresta(int u, int v, int capacidade);
        //~Grafo ();	  
	};


#endif 