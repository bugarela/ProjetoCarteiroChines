#include <fstream>
#include "estruturas.h"
using namespace std;

Aresta criaRua(int x,int y,int peso){
	Aresta novaRua;
	novaRua.x = x;
	novaRua.y = y;
	novaRua.peso = peso;
	
	return novaRua;
}

void leMapa(Grafo *G){
	
	int x,y,peso;
	string nomeRua;
	
	ifstream arquivo ("mapa.txt");
	
    if (arquivo.is_open()){
        
        arquivo >> G->tamanho;
        
        /* Zera e redimensiona estruturas */
        G->listaAdj.resize(0);
        G->listaAdj.resize(G->tamanho);
        G->nomes.resize(0);
        G->nomes.resize(G->tamanho);
		for(int i=0; i<G->tamanho;i++){
			G->nomes[i].resize(0);
			G->nomes[i].resize(G->tamanho);
		}
		G->listaArestas.resize(0);
        
        while(arquivo >> x){ // lê enquanto houverem linhas no arquivo
		
			arquivo >> y >> nomeRua >> peso;
			
			Aresta rua = criaRua(x,y,peso);
			G->listaArestas.push_back(rua);
			G->listaAdj[x].push_back(y);
			G->listaAdj[y].push_back(x);
			G->nomes[x][y] = nomeRua;
			G->nomes[y][x] = nomeRua;
		}
		
        arquivo.close();
        
        cout << "Mapa carregado." << endl;
        
	}
		
}

