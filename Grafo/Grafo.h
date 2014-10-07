
/** \class Grafo
 * \brief Representa un grafo por medio de una matriz de adyacencia
 *
 */
#ifndef GRAFO_H_
#define GRAFO_H_
#include <vector>
#include <string>

using namespace std;
class Grafo
{

public:

    Grafo(int);
    Grafo(int, char*);

    void insertarArista(int, int, char);
    void eliminarArista(int, int, char);
	void imprimir();

	bool   existeArista(int, int, char);
	void modificarArista(int nodo1, int nodo2, char c1, char c2);
	string consultarAristas(int, int);

protected:

    void inicializarMatriz();
	void inicializarFila(vector<string>);
	void cargarGrafo(char*);
	void insertarNodo(vector<string> nodo);
	void eliminarNodo(int nodo);

    int                      cantidadNodos;
    string                   valorDefault;
	vector< vector<string> > matrizAdyacencia;


};
#endif /* GRAFO_H_ */
