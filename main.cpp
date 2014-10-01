//ESTRUCTURAS DE DATOS
//EJEMPLO DE MANIPULACIÓN DE ENTRADA Y ARCHIVO
//ricardogang@gmail.com

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

int main(int argc, char *argv[])
{
//obtener hora local
    time_t hora;
    struct tm * infoHora;
    time ( &hora );
    infoHora = localtime ( &hora );

//hacer algo con la entrada , imprimir + archivar
    if (argc>0) {
        cout << "ENTRADA: " << argv[1] << " @ " << asctime (infoHora) << "\n"; //entrada impresa
        ofstream file;
        file.open ("in.dat", ios::out | ios::app);
        file << "ENTRADA: " << argv[1] << " @ " << asctime (infoHora) << "\n"; //entrada -> archivo
        file.close();
    } else {
        cout << "NO SE RECIBIERON DATOS.." ;
    }
    
    return EXIT_SUCCESS;
}
