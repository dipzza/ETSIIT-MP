/** 
 * @file main.cpp
 * @author DECSAI
*/
#include <iostream>
#include <cstring>
#include "Bigrama.h"

using namespace std;

int main() 
{
    char s[3];
    int frec, nv1, nv2, nv3;
    Bigrama *v1 = 0, *v2 = 0, *v3 = 0;
   
	
    // Lee numero de elementos del primer vector
	do
	{
		cout << endl <<"Introduce cuantos bigramas tiene la cadena 1: ";
		cin >> nv1;
	}	while(nv1 < 1);
	
	v1 = new Bigrama [nv1];
	
	// Lee el primer vector
	for (int i=0; i < nv1; i++)
	{
		do
		{
			cout <<"Introduce el Bigrama con el formato 'bigrama frec' " << ": ";
			cin >> s >> frec;
		} while(frec < 1 || s[3] != '\0');
		
		v1[i].setBigrama(s);
		v1[i].setFrecuencia(frec);
	}
	
	
    // Lee numero de elementos del segundo vector
	do
	{
		cout << endl <<"Introduce cuantos bigramas tiene la cadena 2: ";
		cin >> nv2;
	}	while(nv2 < 1);
	
	v2 = new Bigrama [nv2];
	
	// Lee el segundo vector
	for (int i=0; i < nv2; i++)
	{
		do
		{
			cout <<"Introduce el Bigrama con el formato 'bigrama frec' " << ": ";
			cin >> s >> frec;
		} while(frec < 1 || s[3] != '\0');
		
		v2[i].setBigrama(s);
		v2[i].setFrecuencia(frec);
	}
	
    cout << endl <<"Contenido de v1" << endl; imprimeBigramas(v1, nv1);
    cout << endl <<"Contenido de v2" << endl; imprimeBigramas(v2, nv2);
   
    // Posibles operaciones intermedias sobre v1 o v2 
	
    v3 = new Bigrama[nv1];
    sumaBigramas(v1, nv1, v2, nv2, v3, nv3);
    ordenaAscFrec(v3, nv3);
    cout << endl <<"Contenido de v3" << endl; imprimeBigramas(v3, nv3);

    // Limpieza de memoria
    delete [] v1;
	delete [] v2;
	delete [] v3;
	return 0;
}
