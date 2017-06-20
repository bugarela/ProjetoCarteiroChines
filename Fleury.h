#include "conexidade.h"
using namespace std;

bool ehPonte(int a, int b, Grafo G){
	// verifica se uma aresta de a para b é ponte, removendo a aresta e verificando se o grafo permanece conexo.
	
	Grafo GTemp = G;
	removeAresta(a,b,&GTemp);
	if(ehConexo(GTemp))
		return false;	
	return true;
}

void PCC(Grafo G, int noInicial){
			
	Grafo GTemp = G;
			
	int noAtual = noInicial;
	int noDestino = GTemp.listaAdj[noAtual][noInicial]; // primeira aresta analisada é a do nó inicial para sua primeira conexão
	int i;
	
	vector<int> correcao;
	correcao.resize(0);
	correcao.resize(G.listaAdj.size());
	
	while (noDestino != noInicial){
		

		noDestino = GTemp.listaAdj[noAtual][0]; // analisa a próxima conexão possível
		
		i=0;
					
		while(ehPonte(noAtual,noDestino,G) || noDestino == 0){ // evita pontes e voltar ao nó incial, enquanto possível
			
			i++;
			
			if(GTemp.listaAdj[noAtual].size()>i) // se tiver outra opção
				noDestino=GTemp.listaAdj[noAtual][i]; // tenta com ela
			else 								// se não, desiste
				break;
		}
		
		
		removeAresta(noAtual,noDestino,&GTemp); // remove a aresta escolhida
		cout << noAtual << " " << noAtual + correcao[noAtual] << endl;
		cout << noDestino << " " << noDestino + correcao[noDestino] << endl;
		cout << "--" << endl;
		
		
		if(GTemp.listaAdj[noAtual].size() == 0 && noAtual != noInicial){ // se o nó ficar desconexo e não for o nó inicial, remove ele
			
			removeNo(noAtual,&GTemp);
			
			for(int j=noAtual+correcao[noAtual]+1;j<correcao.size();j++)
				correcao[j]++;
			
			if(noAtual < noDestino)		
				noDestino--;
			// como o algoritmo de remover nó decrementa o índice dos nós maiores que ele, corrigimos o valor de noDestino.
		}
	
		noAtual = noDestino;
	
	}
			
	
			
	
}	
