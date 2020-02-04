/** 
 * @file main.cpp
 * @author DECSAI
 * @warning Código incompleto. Completar donde se indica
*/
#include <iostream>
#include <cstring>
#include "Bigrama.h"
#include "Idioma.h"
using namespace std;

int main(int narg, char * args[])
{
    /// Completar variables
	Idioma fusion;
	Bigrama A;
	int size;
	bool noFallo = true;
	
    if (narg < 3)
    {
        cerr << "Error en la llamada.\n   idioma <bigrama> <fich1.bgr> <fich2.bgr> ..." << endl;
        return 1;
    }
	
	if (strlen(args[1]) != 2)
	{
		cout << "El Bigrama debe tener 2 caracteres";
		return 1;
	}
	
	
	
	noFallo = fusion.cargarDeFichero(args[2]);
	
	for (int i=3; i<narg; i++)
		if (noFallo)
			noFallo = fusion.addDeFichero(args[i]);
	
	A = fusion.getPosicion(fusion.findBigrama(args[1]));
	
	size = fusion.getSize();
	if (noFallo)
		cout << endl << "El bigrama " << A.getBigrama() << " tiene una frecuencia de " << A.getFrecuencia() << " en el idioma " << fusion.getIdioma() << " (" << size << " bigramas)" << endl;
	
    /// Completar el main
	fusion.liberarMemoria();
    return 0;
}