#ifndef AUTOMATA_H_
#define AUTOMATA_H_
#include <string>
#include "Grafo.h"

class Automata : public Grafo
{

public:

    Automata(int);
    Automata(int, char*, string);

    string obtenerRegistro();

    bool comprobarHilera(string);

private:

    vector<int> nodosFinales;
    string      nombreRegistro;

    void escribirRegistro(string);
    void cargarNodosIniciales(char* configSrc);

};
#endif /* AUTOMATA_H_ */

