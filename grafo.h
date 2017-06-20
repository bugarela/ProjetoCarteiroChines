#include <vector>
using namespace std;

typedef struct{
	int x, y;
	
}Aresta;

typedef struct{

	vector <vector <int> > listaAdj;
	vector <Aresta> listaArestas;
	vector <vector <string> > nomes;
	vector <vector <int> > pesos;
	int tamanho, custo;
	
}Grafo;
