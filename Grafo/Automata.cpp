#include <fstream>
#include <iostream>
#include <sstream>
#include "Automata.h"

Automata::Automata(int n): Grafo(n)
{
}

Automata::Automata(int n, char* c, string nR): Grafo(n, c), nodosFinales()
{
    cargarNodosIniciales(c);
    nombreRegistro = nR;

}

void Automata::escribirRegistro(string mensaje)
{
    ofstream registro;
    registro.open (nombreRegistro);
    registro << mensaje;
    registro << "\n";
    registro.close();
}

string Automata::obtenerRegistro()
{
    ifstream registro(nombreRegistro);
    string t = "";
    string reg = "";
    if (registro.is_open())
    {
        while(getline (registro, t))
            reg += t + "\n";
    }
    registro.close();
    return reg;
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
		if(t != "-1")
            nodosFinales.push_back(nF);
	};

    automataConfig.close();
}

