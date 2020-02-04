#include <iostream>
#include "enteros.h"
using namespace std;

int main()
{
    int i = -1, x, MAX = 50, v[MAX];
    
    do
    {
		i++;
        cout << "Introduce valor: ";
        cin >> v[i];
    }while(v[i] != 0 && i < MAX - 1);
	
	if (i == MAX -1)
		v[MAX -1] = 0;
    
	
    cout << "El vector es: ";
    Mostrar(v);
    cout << endl;
    
    cout << "Su media es: " << Media(v) << endl;
    
    cout << "El máximo es: " << Maximo(v) << endl;
    
    cout << "Introduce el valor que quieras buscar: ";
    cin >> x;
    
    cout << "El valor se encuentra en la posición: " << Buscar(v, x) << endl;
    
    cout << "El vector invertido es: ";
    
    Invertir(v, MAX);
    Mostrar (v);
    
    
}
