#include <iostream>
#include "grafo.h"
using namespace std;

bool compara(Aresta a, Aresta b){
	return a.peso < b.peso; 
}


void removeNo(int no, Grafo *G){
	
	// remove da lista
	
	G->listaAdj.erase(G->listaAdj.begin() + no); // remove a linha referente ao nó
	
	for(int i=0;i<G->listaAdj.size();i++)
		for(int j=0;j<G->listaAdj[i].size();j++){
			if(G->listaAdj[i][j] == no) // remove as conexões para aquele nó
				G->listaAdj[i].erase(G->listaAdj[i].begin() + j);
			else if (G->listaAdj[i][j] > no) // decrementa os nós com índice maior que o nó removido para manter a consistência
				G->listaAdj[i][j]--;
		}
}

void removeAresta(int a, int b, Grafo *G){
		
	for(int i=0;i<G->listaAdj[a].size();i++)
		if(G->listaAdj[a][i] == b) // remove as conexões de a para b
			G->listaAdj[a].erase(G->listaAdj[a].begin()+i);
	

}
