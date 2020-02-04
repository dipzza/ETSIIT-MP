/** 
 * @file Idioma.cpp
 * @author Francisco Javier Bolívar Expósito  y  Samuel Jiménez Piñero
*/

#include "Idioma.h"
#include <fstream>
#include <iostream>
#include <math.h>
#include <cstring>

using namespace std;


Idioma::Idioma()
{
	_idioma = "unknown";
	_nBigramas = 0;
	_conjunto = 0;
}

Idioma::Idioma(int nbg)
{
	_idioma = "unknown";
	_conjunto = 0;
	
	if (nbg > 0)
		reservarMemoria(nbg);
	else
	{
		_nBigramas = 0;
	}
}

Idioma::Idioma(const Idioma &orig)
{
	_conjunto = 0;
	_nBigramas = 0;
	
	copiar(orig);
}

Idioma::~Idioma()
{
	liberarMemoria();
}

Idioma& Idioma::operator =(const Idioma& orig)
{
	copiar(orig);
	
	return *this;
}

std::string Idioma::getIdioma() const { return _idioma; }

void Idioma::setIdioma(const std::string &id){ _idioma = id; }

Bigrama Idioma::getPosicion(int p) const
{
	if (p < _nBigramas && p >= 0)
		return _conjunto[p];
}

void Idioma::setPosicion(int p, const Bigrama & bg)
{
	if (p < _nBigramas && p >= 0)
	{
		_conjunto[p] = bg;
	}
}

int Idioma::findBigrama(const std::string& bg) const
{
	bool encontrado = false;
	int pos;

	for(int i=0; i < _nBigramas && encontrado == false; i++){
		if(bg == getPosicion(i).getBigrama())
		{
			pos = i;
			encontrado = true;
		}
	}
	
	if(!encontrado)
	{
		pos = _nBigramas;
	}

	return pos;
}

double Idioma::distancia(const Idioma& otro) const
{
	double distanciaGlobal = 0;
	
	for (int i = 0; i < otro._nBigramas; i++)
	{
		distanciaGlobal += fabs(findBigrama(otro._conjunto[i].getBigrama()) - double(i))/(otro._nBigramas * double(otro._nBigramas));
	}
	
	return distanciaGlobal;
}

void Idioma::ordenar()
{
	Bigrama a_insertar;
	int i;
	
	for (int izda=1; izda<_nBigramas; izda++)
	{
		a_insertar = _conjunto[izda];
		
		for (i = izda; i > 0 && a_insertar.getFrecuencia() > _conjunto[i-1].getFrecuencia(); i--)
			_conjunto[i] = _conjunto[i-1];
		
		_conjunto[i] = a_insertar;
	}
}

bool Idioma::salvarAFichero(const char* fichero) const
{
	ofstream f;
	bool correcto;
	
	cout << endl << "Creando fichero " << fichero << endl;
	f.open(fichero);
	
	if (f)
	{
		cout << "Escribiendo datos";
		
		f << *this;
		
		if (!f)
		{
			cerr << "ERROR escribiendo en el fichero " << fichero << endl;
			correcto=false;
		}
		else
			cout << endl << "OK" << endl;
	}
	else
	{
		cerr << "ERROR creando fichero " << fichero << endl;
		correcto=false;
	}
	
	f.close();
	
	return correcto;
}

// ERROR cuando el nº bigramas del fichero es incorrecto!
bool Idioma::cargarDeFichero(const char *fichero)
{

	ifstream f;
	string idioma;
	char bigrama[3];
	int nv, frecuencia;
	Bigrama bg;
	bool correcto = true;

	bigrama[2] = '\0';
	cout << endl << "Abriendo fichero " << fichero << endl;
	f.open(fichero);
	if(f){
		f >> idioma;
		f >> idioma;
		f >> nv;
	    _idioma=idioma;

		cout << "Idioma detectado " << idioma << endl;
		cout << "Leyendo " << nv << " bigramas" << endl;
		
		liberarMemoria();
		reservarMemoria(nv);
		for(int i=0; f && !f.eof(); i++)
		{
			f >> bigrama;
			f >> frecuencia;

			bg.setBigrama(bigrama);
			bg.setFrecuencia(frecuencia);
			
			setPosicion(i, bg);
		}

			
	f.close();
 	}else{
		cerr << "ERROR abriendo fichero " << fichero << endl;
		correcto=false;
	}
	
	ordenar();
	
	return correcto;
}


// Funciones privadas
void Idioma::reservarMemoria(int n)
{
	if (n > 0 && _conjunto == 0)
	{
		_conjunto = new Bigrama[n];
		_nBigramas = n;
	}
}

void Idioma::liberarMemoria()
{
	if (_conjunto != 0)
	{
		delete []_conjunto;
		_conjunto = 0;
	}
}

void Idioma::copiar(const Idioma& otro)
{
	this -> _idioma = otro._idioma;
	
	if (_nBigramas != otro._nBigramas)
	{
		this -> liberarMemoria();
		this -> reservarMemoria(otro._nBigramas);
	}
	
	for (int i = 0; i < _nBigramas; i++)
		this ->_conjunto[i] = otro._conjunto[i];
}

//Funciones externas
std::ostream & operator<<(std::ostream & os, const Idioma & i)
{
	os << "MP-BIGRAMAS_IDIOMA-T-1.0" << endl << i._idioma << endl << i._nBigramas << endl;
	
	for (int j=0; j<i._nBigramas; j++)
		os << i._conjunto[j].getBigrama() << " " << i._conjunto[j].getFrecuencia() << endl;
	
	return os;
}

std::istream & operator>>(std::istream & is, Idioma & i)
{
	string lang;
	char cadena [3];
	int nBigramas, frec;
	Bigrama bg;
	
	is >> lang >> lang >> nBigramas;
	
	i._idioma = lang;
	i.reservarMemoria(nBigramas);
	
	for (int j=0; j<nBigramas; j++)
	{
		is >> cadena >> frec;
		
		bg.setBigrama(cadena);
		bg.setFrecuencia(frec);
		i.setPosicion(j, bg);
	}
	
	return is;
}