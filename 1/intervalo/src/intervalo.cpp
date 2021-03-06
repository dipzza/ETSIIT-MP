#include <iostream>
#include "intervalo.h"

using namespace std;

Intervalo::Intervalo()
    :cotaInf(0), cotaSup(0), cerradoInf(false), cerradoSup(false) {}

Intervalo::Intervalo(double cotaInferior, double cotaSuperior)
{
    if (cotaInferior <= cotaSuperior)
    {
        cotaInf = cotaInferior;
        cotaSup = cotaSuperior;
        
        cerradoInf = true;
        cerradoSup = true;
    }
    else
    {
        cotaInf = 0;
        cotaSup = 0;
        
        cerradoInf = false;
        cerradoSup = false;
    }
}

Intervalo::Intervalo(double cotaInferior, double cotaSuperior, bool cerradoInferior, bool cerradoSuperior)
{
    if ((cotaInferior < cotaSuperior) || (cotaInferior == cotaSuperior && cerradoInferior == cerradoSuperior))
    {
        cotaInf = cotaInferior;
        cotaSup = cotaSuperior;
        
        cerradoInf = cerradoInferior;
        cerradoSup = cerradoSuperior;
    }
    else
    {
        cotaInf = 0;
        cotaSup = 0;
        
        cerradoInf = false;
        cerradoSup = false;
    }
}


double Intervalo::getCotaInf()const
{
    return cotaInf;
}

double Intervalo::getCotaSup()const
{
    return cotaSup;
}

bool Intervalo::dentroCotaInf()const
{
    return cerradoInf;
}

bool Intervalo::dentroCotaSup()const
{
    return cerradoSup;
}


void Intervalo::setIntervalo(double cotaInferior, double cotaSuperior, bool cerradoInferior, bool cerradoSuperior)
{
    if ((cotaInferior < cotaSuperior) || (cotaInferior == cotaSuperior && cerradoInferior == cerradoSuperior))
    {
        cotaInf = cotaInferior;
        cotaSup = cotaSuperior;
        
        cerradoInf = cerradoInferior;
        cerradoSup = cerradoSuperior;
    }
    else
    {
        cotaInf = 0;
        cotaSup = 0;
        
        cerradoInf = false;
        cerradoSup = false;
    }
}

bool Intervalo::esVacio()const
{
    bool vacio = false;
    
    if (cotaInf == cotaSup && !cerradoInf && !cerradoSup)
        vacio = true;
    
    return vacio;
}

bool Intervalo::estaDentro(double n)const
{
    bool dentro = true;
    
    if ((n > cotaSup || n < cotaInf) || (n == cotaInf && cerradoInf == false) || (n == cotaSup && cerradoSup == false))
        dentro = false;
    
    return dentro;
}

bool valido(double cinf, double csup, bool cerrinf, bool cerrsup)
{
    return (( cinf < csup ) || ( cinf == csup && cerrinf == cerrsup));
}

void escribir(const Intervalo &obj)
{
    if (obj.esVacio())
        cout << "Intervalo Vacio";
    else 
    {
        if (obj.dentroCotaInf())
            cout << '[';
        else 
            cout << '(';
        
        cout << obj.getCotaInf() << "," << obj.getCotaSup();
        
        if (obj.dentroCotaSup())
            cout << ']';
        else 
            cout << ')';
    }
    cout << endl;
}

void leer(Intervalo &obj)
{
    // Formato de lectura del intervalo: [|( x,y )|]
    bool cerradoInf = true;
    bool cerradoSup = true;
    double cotaInf, cotaSup;
    char car;
    
    cin >> car;
    if (car == '(')
        cerradoInf = false;
    cin >> cotaInf;
    cin >> car;
    cin >> cotaSup;
    cin >> car;
    if (car == ')')
        cerradoSup = false;
    
    obj.setIntervalo(cotaInf, cotaSup, cerradoInf, cerradoSup);
}

void comprobarVacio(Intervalo obj)
{
    escribir(obj);
    
    if (obj.esVacio())
        cout << "Vacio";
    else
        cout << "NO Vacio";
    cout << endl;
}
