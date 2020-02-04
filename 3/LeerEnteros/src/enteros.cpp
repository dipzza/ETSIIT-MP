#include "enteros.h"
#include <iostream>

using namespace std;

int Maximo (const int v[])
{
    int mayor;
    
    if (v[0] != 0)
        mayor = v[0];
    else
        mayor = 0;
    
    for (int i = 1; v[i] != 0; i++)
    {
        if (v[i] > mayor)
            mayor = v[i];
    }
    
    return mayor;
}

void Mostrar (const int v[])
{
    for (int i = 0; v[i] != 0; i++)
		cout << v[i] << " ";
}

double Media (const int v[])
{
    double media = 0;
	int i;
    
    for (i = 0; v[i] != 0; i++)
    {
        media += v[i];
    }
    
    return media/i;
}

int Buscar (const int v[], int x)
{
    int pos = -1;
    
    bool encontrado = false;
    
    for (int i = 0; v[i] != 0 && !encontrado; i++)
    {
        if (v[i] == x)
        {
            pos = i;
            encontrado = true;
        }
    }
    
    return pos + 1;
}

void Invertir (int v[], int MAX)
{
    int util, w[MAX];
	
	for (util = 0; v[util] != 0; util++);
	
    for (int i = 0; i < util; i++)
    {
        w[util - i - 1] = v[i];
    }
    
    for (int i = 0; i < util; i++)
    {
        v[i] = w[i];
    }
}
