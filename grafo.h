#include <vector>
using namespace std;

typedef struct{
	int x, y;
	int peso;	
	
}Aresta;

typedef struct{

	vector <vector <int> > listaAdj;
	vector <Aresta> listaArestas;
	vector <vector <string> > nomes;
	int tamanho;
	
}Grafo;
