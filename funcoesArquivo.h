#include <fstream>
#include "estruturas.h"
using namespace std;

Aresta criaRua(int x,int y){
	Aresta novaRua;
	novaRua.x = x;
	novaRua.y = y;
	
	return novaRua;
}

void leMapa(Grafo *G){
	
	int x,y,peso;
	string nomeRua;
	
	G->custo = 0;
	
	ifstream arquivo ("mapa.txt");
	
    if (arquivo.is_open()){
        
        arquivo >> G->tamanho;
        
        /* Zera e redimensiona estruturas */
        G->listaAdj.resize(0);
        G->listaAdj.resize(G->tamanho);
        G->nomes.resize(0);
        G->nomes.resize(G->tamanho);
        G->pesos.resize(0);
        G->pesos.resize(G->tamanho);
		for(int i=0; i<G->tamanho;i++){
			G->nomes[i].resize(0);
			G->nomes[i].resize(G->tamanho);
			G->pesos[i].resize(0);
			G->pesos[i].resize(G->tamanho);
		}
		G->listaArestas.resize(0);
        
        while(arquivo >> x){ // lê enquanto houverem linhas no arquivo
		
			arquivo >> y >> nomeRua >> peso;
			
			Aresta rua = criaRua(x,y);
			G->listaArestas.push_back(rua);
			G->listaAdj[x].push_back(y);
			G->listaAdj[y].push_back(x);
			G->nomes[x][y] = nomeRua;
			G->nomes[y][x] = nomeRua;
			G->pesos[x][y] = peso;
			G->pesos[y][x] = peso;
			
			G->custo += peso;
		}
		
        arquivo.close();
        
        cout << "Mapa carregado." << endl;
        
	}
		
}

