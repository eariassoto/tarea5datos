#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Automata.h"

Automata::Automata(int n): Grafo(n)
{
}

Automata::Automata(int n, char* c): Grafo(n, c), nodosFinales()
{
    cargarNodosIniciales(c);
}

void Automata::cargarNodosIniciales(char* configSrc){
	ifstream automataConfig(configSrc);
    string t = "";
    getline (automataConfig, t); //con esto me brinco el tamano

	while(t != "-1")
	{
		getline (automataConfig, t);
		stringstream ss(t);
        int nF;
        ss >> nF;
		if(t != "-1"){
            nodosFinales.push_back(nF);
		}
	};

    automataConfig.close();
}

bool Automata::validarHilera(string hilera){
	return validarHilera(0, 0, hilera);
}

bool Automata::validarHilera(int nodo, int indice, string hilera){
	if(indice == (int)hilera.size()){
		if(find(nodosFinales.begin(), nodosFinales.end(), nodo) != nodosFinales.end()){
			return true;
		}else{
			return false;
		}
	}else{
		for(int j = 0; j < cantidadNodos; j++){
			if(existeArista(nodo, j, hilera[indice])){
				return false || validarHilera(j, indice+1, hilera);
			}
		}
	}
	return false;
}
