/**
   @file secuenciapaquete.cpp
   @author decsai.ugr.es
**/

#include "paquete.h"
#include "secuenciapaquete.h"


void cleanSecuenciaPaq(Paquete s[], int &util){
	
	for(int i=0; i < util; i++)
	{
		s[i].setPaquete(s[i].getId(),0,0,0,0);
	}
	
	util = 0;
}


bool addSecuenciaPaq(Paquete s[], int &util, const Paquete &p)
{
	bool anadido = true;
	
	if (util < MAXPAQ)
	{
		s[util] = p;
		util++;
	}
	else
		anadido = false;
	
	return anadido;
}


double getTotalSecuenciaPaq(const Paquete s[], int util){

	double suma = 0;

	for(int i=0; i<util; i++){
		
		suma += s[i].getFactura();

	}

	return suma;
}


Paquete paqueteMayorSecuenciaPaq(const Paquete s[], int util)
{
	Paquete mayorVolumen;
	int mayor = -1, pos = -1;
	
	for (int i = 0; i < util; i++)
	{
		if (s[i].getVolumen() > mayor)
		{
			mayor = s[i].getVolumen();
			pos = i;
		}
	}
	
	if (pos > -1)
		mayorVolumen = s[pos];
	
	return mayorVolumen;
}


double getMediaSecuenciaPaq(const Paquete s[],  int util){

	double total, resultado = 0;

	total = getTotalSecuenciaPaq(s, util);

	if (util > 0)
		resultado = total/util;
	
	return resultado;
}


int numPaqueteAltosSecuenciaPaq(const Paquete s[], int util, int altura)
{
	int nmayores = 0;
	
	for (int i = 0; i < util; i++)
	{
		if (s[i].getAlto() > altura)
			nmayores++;
	}
	
	return nmayores;
}


int numPaquetesSuperiorSecuenciaPaq(const Paquete s[], int util){

	double media, cont=0;	

	media = getMediaSecuenciaPaq(s, util);

	for(int i=0; i<util; i++){

		if(s[i].getFactura() > media){
		cont++;
		}
	}
	
	return cont;
}
