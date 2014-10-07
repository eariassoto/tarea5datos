#ifndef AUTOMATA_H_
#define AUTOMATA_H_
#include <string>
#include "Grafo.h"

class Automata : public Grafo
{

public:

    Automata(int);
    Automata(int, char*);

    string obtenerRegistro();
	bool validarHilera(string);
	bool validarHilera(int, int, string);

private:

    vector<int> nodosFinales;
	
    void cargarNodosIniciales(char*);

};
#endif /* AUTOMATA_H_ */

