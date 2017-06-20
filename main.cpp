/* Esse trabalho contém funcionalidades do c++11, portanto precisa ser compilado com o comando -std=c++11 (pode ser adicionado em "Compiler Options" na IDE, ou adicionado a linha de comando no terminal */

#include <iostream>
#include <vector>
#include "PCC.h"

using namespace std;

int main(){
	
	Grafo G;
	
	leMapa(&G);
	
	PCC(G,0);
	
	cout << "Custo da rota: " << G.custo << endl;

	return 0;
}
