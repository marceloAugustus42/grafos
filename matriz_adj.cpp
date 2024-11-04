#include "matriz_adj.hpp"
#include <stack>

Grafo::Grafo( istream &in )
    {
    int v1, v2, peso;
    in >> this->numVertices;
    this->mat = new int*[numVertices];
    for (int i = 0; i < numVertices; i++) 
        this->mat[i] = new int[numVertices];
    this->pos = new int[numVertices]; 
    
    for (int i = 0; i < this->numVertices; i++) {
        for (int j = 0; j < this->numVertices; j++) this->mat[i][j] = 0;
        this->pos[i] = -1; 
    }
    capacidade.resize(numVertices, vector<int>(numVertices, 0));
    fluxo.resize(numVertices, vector<int>(numVertices, 0));

    while (in>>v1>>v2>>peso) {
        Grafo::Aresta *a = new Grafo::Aresta (v1, v2, peso);
        this->insereAresta (a->_v1 (), a->_v2 (), a->_peso ());
        this->adicionarAresta(a->_v1 (), a->_v2 (), a->_peso ());
        delete a;
    }
}

Grafo::Grafo (int numVertices) {
    this->mat = new int*[numVertices];
    for (int i = 0; i < numVertices; i++) 
        this->mat[i] = new int[numVertices];
    this->pos = new int[numVertices]; 
    this->numVertices = numVertices; 
    for (int i = 0; i < this->numVertices; i++) {
        for (int j = 0; j < this->numVertices; j++) this->mat[i][j] = 0;
        this->pos[i] = -1; 
    }
    capacidade.resize(numVertices, vector<int>(numVertices, 0));
    fluxo.resize(numVertices, vector<int>(numVertices, 0));
  }
  
  /*Grafo::Grafo (int numVertices, int numArestas) {
    this->mat = new int*[numVertices];
    for (int i = 0; i < numVertices; i++) 
      this->mat[i] = new int[numVertices];
    this->pos = new int[numVertices]; 
    this->numVertices = numVertices; 
    for (int i = 0; i < this->numVertices; i++) {
      for (int j = 0; j < this->numVertices; j++) this->mat[i][j] = 0;
      this->pos[i] = -1; 
    }
  }	  */

void Grafo::insereAresta (int v1, int v2, int peso) {
    this->mat[v1][v2] = peso; 
}

bool Grafo::existeAresta (int v1, int v2) const {
    return (this->mat[v1][v2] > 0);
}
  
bool Grafo::listaAdjVazia (int v) const {
    for (int i = 0; i < this->numVertices; i++)
        if (this->mat[v][i] > 0) 
        return false;
    return true;
}

void Grafo::adicionarAresta(int u, int v, int capacidade) {
    this->capacidade[u][v] = capacidade;
}

bool Grafo::buscaEmLargura(int origem, int destino, vector<int> &caminho){
    void visitaBfs(int u);
    string cor[this->numVertices];
    int dist[this->numVertices];
    int antecessor[this->numVertices];
    for (int i = 0; i < this->numVertices; i++){
        cor[i] = "branco";
        dist[i]= -10;
        antecessor[i] = -1;
    }
    for (int i = 0; i < this->numVertices; i++)
    {
        if (cor[i] == "branco")
        {
            visitaBfs(i);
        }
    }

    void visitaBfs(int i){
        dist[i] = 0;
        cor[i] = "cinza";
        queue<int> fila;
        fila.push(i);
        while (!fila.empty()){
            i = fila.pop();
            for (int j = 0; j < this->numVertices; j++){
                
            }
            
        }
        

    }
    
}

bool Grafo::buscaEmProfundidade(int origem, int destino, vector<int> &caminho){
    this->pos[origem];
    
}

Grafo::Aresta *Grafo::lerAresta()  {
    cout << "Aresta:" << endl;
    cout << "  V1:"; int v1 = 0;
    cin >> v1;
    cout << "  V2:"; int v2 = 0;
    cin >> v2;
    cout << "  Peso:"; int peso = 0;
    cin >> peso;
    return new Aresta (v1, v2, peso);
}

Grafo::Aresta *Grafo::primeiroListaAdj (int v) {
    // @{\it Retorna a primeira aresta que o v\'ertice v participa ou}@ 
    // @{\it {\bf NULL} se a lista de adjac\^encia de v for vazia}@
    this->pos[v] = -1; return this->proxAdj (v);
}
  
Grafo::Aresta *Grafo::proxAdj (int v) {
    // @{\it Retorna a pr\'oxima aresta que o v\'ertice v participa ou}@ 
    // @{\it {\bf NULL} se a lista de adjac\^encia de v estiver no fim}@ 
    this->pos[v] ++;
    while ((this->pos[v] < this->numVertices) && 
           (this->mat[v][this->pos[v]] == 0)) this->pos[v]++;
    if (this->pos[v] == this->numVertices) 
        return NULL;
    else 
        return new Aresta (v, this->pos[v], this->mat[v][this->pos[v]]);
}
  
Grafo::Aresta *Grafo::retiraAresta (int v1, int v2) {
    if (this->mat[v1][v2] == 0) return NULL; // @{\it Aresta n\~ao existe}@
    else {
        Aresta *aresta = new Aresta (v1, v2, this->mat[v1][v2]);
        this->mat[v1][v2] = 0; return aresta;
    }
  }
  
void Grafo::imprime () const {
    cout << "   ";
    for (int i = 0; i < this->numVertices; i++) 
        cout << i << "   "; 
    cout << endl;
    for (int i = 0; i < this->numVertices; i++) { 
        cout << i <<  "  ";
        for (int j = 0; j < this->numVertices; j++)
            cout << this->mat[i][j] << "   ";
        cout << endl;
    }
}
  
int Grafo::_numVertices () const { 
    return this->numVertices; 
}
  
Grafo *Grafo::grafoTransposto () {
    Grafo *grafoT = new Grafo (this->numVertices); 
    for (int v = 0; v < this->numVertices; v++)
        if (!this->listaAdjVazia (v)) {
        Aresta *adj = this->primeiroListaAdj (v);
        while (adj != NULL) {
            grafoT->insereAresta (adj->_v2 (), adj->_v1 (), adj->_peso ());
            delete adj;
            adj = this->proxAdj (v);
        }
    }
    return grafoT;
}

Grafo *Grafo::grafoNaoDirecionado () {
    Grafo *grafoND = new Grafo (this->numVertices); 
    cout << "   ";
    for (int i = 0; i < this->numVertices; i++) { 
        for (int j = 0; j < this->numVertices; j++)
            if(this->existeAresta(i, j)){
                grafoND->insereAresta(i, j, this->mat[i][j]);
                grafoND->insereAresta(j, i, this->mat[i][j]);
            }
    }
    return grafoND;
}