#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <time.h>
#include "Grafo.h"
#include "Automata.h"

using namespace std;

string leerTamanoGrafo (char * configSrc)
{
    ifstream automataConfig(configSrc);
    string t = "";
    if (automataConfig.is_open())
    {
        getline (automataConfig, t);
    }
    automataConfig.close();
    return t;
}

string cargarNodosFinales(char* configSrc){
	ifstream automataConfig(configSrc);
    string nodosFinales = "\"nodosFinales\":[";
	string t = "";
    getline (automataConfig, t); //con esto me brinco el tamano
	
	while(t != "-1")
	{
		getline (automataConfig, t);
		if(t != "-1"){
            nodosFinales += t + ", ";
		}
	}
	
	char a = ',';
	if(nodosFinales[nodosFinales.size()-2] == a){
		nodosFinales[nodosFinales.size()-2] = ' ';
	}
	nodosFinales += "], ";

    automataConfig.close();
	return nodosFinales;
}

string cargarAristas(char* configSrc)
{
    ifstream automataConfig(configSrc);
    string aristas = "\"aristas\":[";
	string t = "";

    do{
        getline (automataConfig, t);
    }while(t != "-1");

    if (automataConfig.is_open())
    {
        while(getline (automataConfig, t))
        {
			aristas += string("[") + t[0] + ", " + t[2] + ", " + "\"" + t[4] + "\"" + "], ";
        }
    }
	char a = ',';
	if(aristas[aristas.size()-2] == a){
		aristas[aristas.size()-2] = ' ';
	}
	aristas += "]";
    automataConfig.close();
	return aristas;
}

string obtenerGrafo(char * configSrc){
	string json = "";
	
	string numNodos = leerTamanoGrafo(configSrc);
	
	json = "{ \"numNodos\": " + numNodos + ", " + cargarNodosFinales(configSrc) + cargarAristas(configSrc) + " }";
	return json;
}

void escribirRegistro(string mensaje)
{
    ofstream registro;
    registro.open ("registro.txt", ios::app);
    registro << mensaje;
    registro.close();
}

string obtenerRegistro()
{
    ifstream registro("registro.txt");
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

int main(int argc, char* argv[])
{
    time_t hora;
    struct tm * infoHora;
    time ( &hora );
    infoHora = localtime ( &hora );

    if(argc == 3)
    {
		string s = argv[2];
		if(s == "-g"){
			char * configSrc = argv[1];
			cout << obtenerGrafo(configSrc);
			
		}else{
			char * configSrc = argv[1];
			string hileraVerificar = argv[2];

			stringstream ss(leerTamanoGrafo(configSrc));
			int t;
			ss >> t;

			Automata a(t, configSrc);
			string msg = "";
			if(a.validarHilera(hileraVerificar)){
				msg = "correcta";
			}else{
				msg = "incorrecta";
			}
			
			string respuesta = "ENTRADA: " + hileraVerificar + " RESULTADO: " + msg + " @ " + asctime (infoHora) + "\n";
			escribirRegistro(respuesta);
			cout << respuesta;
		}
    }
    return 0;
}
