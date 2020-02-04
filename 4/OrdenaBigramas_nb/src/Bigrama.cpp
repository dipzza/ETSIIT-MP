/**
 * @file Bigrama.cpp
 * @author DECSAI
 * @warning Código incompleto
*/

#include <cstring>
#include <iostream>
#include "Bigrama.h"

using namespace std;


Bigrama::Bigrama() 
{
    _bigrama[0] = '\0';
    _frecuencia = -1;
}

const char* Bigrama::getBigrama() const
{
	return _bigrama;
}

int Bigrama::getFrecuencia() const
{
	return _frecuencia;
}

void Bigrama::setBigrama(const char cadena[])
{
	if ( strlen(cadena) == 2)
		strcpy(_bigrama,cadena);
}

void Bigrama::setFrecuencia(int frec)
{
	if (frec > 0)
		_frecuencia = frec;
}

void ordenaAscFrec(Bigrama *v, int n)
{
	bool intercambiar = true;
	Bigrama aux;
	
	for (int izda = 0; izda < n && intercambiar; izda++)
	{
		intercambiar = false;
		
		for (int i = n - 1; i > izda; i--)
		{
			if (v[i].getFrecuencia() < v[i-1].getFrecuencia())
			{
				intercambiar = true;
				aux = v[i];
				v[i] = v[i-1];
				v[i-1] = aux;
			}
		}
	}	
	
}

void ordenaAscBigr(Bigrama *v, int n)
{
	bool intercambiar = true;
	Bigrama aux;
	
	for (int izda = 0; izda < n && intercambiar; izda++)
	{
		intercambiar = false;
		
		for (int i = n - 1; i > izda; i--)
		{
			if (strcmp(v[i].getBigrama(), v[i-1].getBigrama()) < 0)
			{
				intercambiar = true;
				aux = v[i];
				v[i] = v[i-1];
				v[i-1] = aux;
			}
		}
	}
}

void imprimeBigramas(const Bigrama *v, int n)
{	
	
	for(int i=0; i < n; i++){
		
		cout << "El bigrama " << i+1 << " es:  ";

		for(int j=0; j < 2; j++){

			cout << " " << v[i].getBigrama()[j];
		}
		
		cout << " con frecuencia " << v[i].getFrecuencia() << endl;
	}
}
void sumaBigramas(const Bigrama *v1, int nv1, const Bigrama *v2, int nv2, Bigrama *res, int &nres)
{
	bool encontrado = true;
	
	if (nv1 != nv2)
		nres = 0;
	else
		nres = nv1;
	
	for (int i=0; i < nres && encontrado; i++)
	{
		encontrado = false;
		
		for (int j=0; j < nres && !encontrado; j++)
		{
			if(strcmp(v1[i].getBigrama(), v2[j].getBigrama()) == 0)
			{
				encontrado = true;
				res[i].setBigrama(v1[i].getBigrama());
				res[i].setFrecuencia(v1[i].getFrecuencia() + v2[j].getFrecuencia());
			}
		}
		
		if(!encontrado)
			nres = 0;
	}
}