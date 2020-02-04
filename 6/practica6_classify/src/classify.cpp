/** 
 * @file classify.cpp
 * @author Francisco Javier Bol�var Exp�sito  y  Samuel Jim�nez Pi�ero
*/

#include <iostream>
#include "Bigrama.h"
#include "Idioma.h"
#include "ContadorBigramas.h"

using namespace std;


int main(int argc, char *argv[])
{
	string valid="abcdefghijklmnopqrstuvwxyz\xE0\xE1\xE2\xE3\xE4\xE5\xE6\xE7\xE8\xE9\xEA\xEB\xEC\xED\xEE\xEF\xF0\xF1\xF2\xF3\xF4\xF5\xF6\xF8\xF9\xFA\xFB\xFC\xFD\xFE\xFF";
	Idioma known, unknown;
	ContadorBigramas tabla(valid);
	double distMenor, tmp;
	string idiomaDetectado;
	
	if (argc > 2)
	{
		tabla.calcularFrecuenciasBigramas(argv[1]);
		known = tabla.toIdioma();
		
		unknown.cargarDeFichero(argv[2]);
		distMenor = known.distancia(unknown);
		idiomaDetectado = unknown.getIdioma();
		
		for (int i=3; i<argc; i++)
		{
			unknown.cargarDeFichero(argv[i]);
			
			tmp = known.distancia(unknown);
			if (tmp < distMenor)
			{
				distMenor = tmp;
				idiomaDetectado = unknown.getIdioma();
			}
		}
	
		
		cout << idiomaDetectado << endl;
	}
	else
		cout << "ERROR: N� de argumentos introducidos incorrectos.\n\n	Sintaxis: ficherodelIdiomaDesconocido ficheroIdioma1 ficheroidioma2 ... ficheroidioman";

	return 0;
}