#include "Grafo.h"
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

Grafo::Grafo(int n): matrizAdyacencia(n)
{
    valorDefault = "";
    //OJO, cada vez que se agrega un nodo aumentar esta variable pls
    cantidadNodos = n;
    inicializarMatriz();
}

Grafo::Grafo(int n, char * configSrc): matrizAdyacencia(n)
{
    valorDefault = "";
    //OJO, cada vez que se agrega un nodo aumentar esta variable pls
    cantidadNodos = n;
    inicializarMatriz();

    cargarGrafo(configSrc);
}

void Grafo::cargarGrafo(char* configSrc)
{
    ifstream automataConfig(configSrc);
    string t = "";

    do{

        getline (automataConfig, t);

    }while(t != "-1");


    if (automataConfig.is_open())
    {
        while(getline (automataConfig, t))
        {
            int nodo1 = t[0] - '0';
            int nodo2 = t[2] - '0';
            char peso = t[4];
            insertarArista(nodo1, nodo2, peso);
        }
    }
    automataConfig.close();
}

string Grafo::consultarAristas(int nodo1, int nodo2)
{
    return matrizAdyacencia[nodo1][nodo2];
}

void Grafo::modificarArista(int nodo1, int nodo2, char c1, char c2)
{
    if(existeArista(nodo1, nodo2, c1))
    {
        eliminarArista(nodo1, nodo2, c1);
        insertarArista(nodo1, nodo2, c2);
    }
}

bool Grafo::existeArista(int nodo1, int nodo2, char c)
{
    return matrizAdyacencia[nodo1][nodo2].find(c) != string::npos;
}

void Grafo::insertarArista(int nodo1, int nodo2, char c)
{
    if(nodo1 < cantidadNodos && nodo2 < cantidadNodos)
        matrizAdyacencia[nodo1][nodo2] += c;
}

void Grafo::eliminarArista(int nodo1, int nodo2, char c)
{
    string aristas = matrizAdyacencia[nodo1][nodo2];

    if(aristas.find(c) != string::npos)
    {
        int i = 0;
        bool encontrado = false;
        while (!encontrado)
        {
            if (aristas[i] == c)
            {
                matrizAdyacencia[nodo1][nodo2].erase(i,1);
                encontrado = true;
            }
            else i++;
        }
    }
}

void Grafo::insertarNodo(vector<string> nodo)
{
    matrizAdyacencia.push_back(nodo);
    cantidadNodos++;
}

void Grafo::eliminarNodo(int nodo)
{

    for(auto & fila : matrizAdyacencia)
    {
      fila.erase(fila.begin()+ nodo);
    }

    matrizAdyacencia.erase(matrizAdyacencia.begin()+ nodo);

}


void Grafo::inicializarMatriz()
{
    for(auto & fila : matrizAdyacencia)
    {
        fila.resize(cantidadNodos, valorDefault);
    }
}

template <class T>
int buscarIndice(vector<T> vec, T val)
{
    typename vector <T>::iterator it = vec.begin ();

    it = find (vec.begin (), vec.end (), val);
    int pos = 0;

    if (it != vec.end ())
        pos = distance (vec.begin (), it);

    return pos;
}

void Grafo::imprimir()
{
    //sinceramente no conocia este for hasta ahora pero es un for each
    //para cosas que se pueden iterar (este es nuevo de c++11)
    //usen este tipo mejor por consistencia, y por que se ve más bonito
    for(auto & fila : matrizAdyacencia)
    {
        for (auto & columna : fila)
        {
            if(columna != "")
                cout << "Aristas de: " << buscarIndice(matrizAdyacencia, fila) << " a " << buscarIndice(fila, columna) << ": " << columna << "\n";
        }
    }
}
