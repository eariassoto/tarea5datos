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

int main(int argc, char* argv[])
{
    time_t hora;
    struct tm * infoHora;
    time ( &hora );
    infoHora = localtime ( &hora );

    if(argc > 2)
    {
        char * configSrc = argv[1];
        char * hileraVerificar = argv[2];

        stringstream ss(leerTamanoGrafo(configSrc));
        int t;
        ss >> t;

        Automata a(t, configSrc, "registro.txt");

        cout << "ENTRADA: " << " @ " << asctime (infoHora) << "\n";

    }
    return 0;
}
