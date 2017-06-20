#include "conexidade.h"
using namespace std;

bool ehPonte(int a, int b, Grafo G, set<int> nosRestantes){
	// verifica se uma aresta de a para b é ponte, removendo a aresta e verificando se o grafo permanece conexo.
	
	Grafo GTemp = G;
	removeAresta(a,b,&GTemp);
	if((busca(0,G,nosRestantes)).empty())
		return false;	
	return true;
}

void PCC(Grafo G, int noInicial){
			
	Grafo GTemp = G;
			
	int noAtual = noInicial;
	int noDestino = GTemp.listaAdj[noAtual][0]; // primeira aresta analisada é a do nó inicial para sua primeira conexão
	int i,c=0,d=0;
	
	set<int> nosRestantes;
	
	for(int i=0; i<G.listaAdj.size(); i++)
		nosRestantes.insert(i);
	

	while (noDestino != noInicial){
		

		noDestino = GTemp.listaAdj[noAtual][0]; // analisa a próxima conexão possível
		
		i=0;
		
		while(noDestino == noInicial && GTemp.listaAdj.size()!=0){ // não volta ao nó Inicial
			
			i++;
			
			if(GTemp.listaAdj[noAtual].size()>i) // se tiver outra opção
				noDestino=GTemp.listaAdj[noAtual][i]; // tenta com ela
			else 								// se não, desiste
				break;
		}	
			
		while(ehPonte(noAtual,noDestino,GTemp,nosRestantes)){ // evita pontes enquanto possível
			
			i++;
			
			if(GTemp.listaAdj[noAtual].size()>i) // se tiver outra opção
				noDestino=GTemp.listaAdj[noAtual][i]; // tenta com ela
			else 								// se não, desiste
				break;
		}
		
		
		removeAresta(noAtual,noDestino,&GTemp); // remove a aresta escolhida
		cout << noAtual << " " << noDestino << endl;
		c++;

		
		
		if(GTemp.listaAdj[noAtual].size() == 0 && noAtual != noInicial){ // se o nó ficar desconexo e não for o nó inicial, remove ele
			
			nosRestantes.erase(noAtual);
			d++;
		
		}
	
		noAtual = noDestino;
	
	}	
	cout << "d: " << d << endl;
	imprimeListaAdj(GTemp);
	cout << noAtual << " " << noDestino << endl;
	
}	
