/* 
 * File:   main.cpp
 * Author: jakerxd
 *
 * Created on 19 de marzo de 2018, 12:21
 */

#include <iostream>

using namespace std;

int main(int argc, char** argv) 
{
	int MAX = 20;
	bool crear, texto = true, fallo = true;
	char idioma[] = {'U','N','K','N','O','W','N'};
	
	string msgFallo = "La sintaxis introducida es incorrecta.\nFormato de sintaxis -> {-c | -a";
	
	// Empezamos en 1 porque argv[o] es la ruta del ejecutable
	for (int i = 1; i < argc && fallo; i++)
	{
		if (argv[i] == '-c')
		{
			crear = true;
			fallo = false;
		}
		else
		{
			if(argv[i] == '-a')
			{
				crear = false;
				fallo = false;
			}
		}
	}
	
	if (fallo == true)
	{
		cout << msgFallo;
		no compilar;
	}

	for (int i = 1; i < argc && !fallo; i++)
	{
		if (argv[i] == '-b')
			texto = false;
	}
	
	for (int i =1 i < argc; i++)
	{
		if(argv[i] == '-l')
			idioma = argv[i + 1];
	}
}