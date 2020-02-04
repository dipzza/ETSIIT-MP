/** 
 * @file ContadorBigramas.cpp
 * @author Francisco Javier Bolívar Expósito  y  Samuel Jiménez Piñero
*/

#include "ContadorBigramas.h"
#include <fstream>


using namespace std;

ContadorBigramas::ContadorBigramas(const std::string& caracteresValidos)
{
	int l = caracteresValidos.length();

	reservarMemoria(l);
	
	_caracteresValidos = caracteresValidos;
	for (int i=0; i<l; i++)
		for (int j=0; j<l; j++)
			_bigramas[i][j] = 0;
}

ContadorBigramas::ContadorBigramas(const ContadorBigramas & orig)
{
	_bigramas = 0;

	copiar(orig);
}

ContadorBigramas::~ContadorBigramas()
{
	liberarMemoria();
}


int ContadorBigramas::getSize() const
{
	return _caracteresValidos.length();
}

int ContadorBigramas::getBigramasActivos() const
{
	int nBigramasActivos=0, l=_caracteresValidos.length();
	
	for (int i=0; i<l; i++)
		for (int j=0; j<l; j++)
			if (_bigramas[i][j] > 0)
				nBigramasActivos++;
		
	return nBigramasActivos;
}
    
bool ContadorBigramas::addBigrama(const char cadena[], int frecuencia)
{
	bool encontrado = false, valido=true;
	int fil, col, l=_caracteresValidos.length();
	
	// Busqueda de la posición del bigrama en la matriz y comprobación de si es válido.
	for (int i=0; i<2 && valido; i++)
	{
		for (int j=0; j<l && !encontrado; j++)
			if (cadena[i] == _caracteresValidos[j])
			{
				encontrado = true;
				
				if (i == 0)
					fil = j;
				else
					col = j;
			}
		
		if (!encontrado)
			valido = false;
		
		encontrado = false;
	}
	
	// Añade el bigrama a la matriz si es válido
	if (valido)
	{
		if (frecuencia == 0)
			_bigramas[fil][col]++;
		else
			_bigramas[fil][col] = frecuencia;
	}
	
	return valido;
}

ContadorBigramas& ContadorBigramas::operator=(const ContadorBigramas& orig)
{
	copiar(orig);
	
	return *this;
}

ContadorBigramas& ContadorBigramas::operator+=(const ContadorBigramas& rhs)
{
	if (_caracteresValidos == rhs._caracteresValidos)
	{
		int l = getSize();

		for(int i=0; i<l ; i++)
			for(int j=0; j<l; j++)
				_bigramas[i][j] += rhs._bigramas[i][j];
	}
	
	return *this;
}

bool ContadorBigramas::calcularFrecuenciasBigramas(const char* nfichero)
{
	ifstream f;
	string palabra;
	char cadena[2];
	bool correcto = true;

	cout << endl << "Abriendo fichero " << nfichero << endl;
	f.open(nfichero);
	if(f){

		cout << "Calculando frecuencias" << endl;

		for(int i=0; !f.eof(); i++)
		{
			f >> palabra;
			
			for (int j=0; j<palabra.length() - 1; j++)
			{
				for (int k=0; k<2; k++)
				{
					cadena[k] = tolower(palabra[j+k]);
				}
				
				addBigrama(cadena);
			}
		}

			
	f.close();
 	}else{
		cerr << "ERROR abriendo fichero " << nfichero << endl;
		correcto=false;
	}
	
	return correcto;  
}

Idioma ContadorBigramas::toIdioma() const
{
	Idioma nuevoIdioma(getBigramasActivos());
	Bigrama bg;
	char cad[3];
	int pos = 0;
	
	
	cad[2] = '\0';
	for(int i=0; i < getSize(); i++)
	{
		for(int j=0; j < getSize(); j++)
		{
			if(_bigramas[i][j] !=0)
			{
				cad[0] = _caracteresValidos[i];
				cad[1] = _caracteresValidos[j];
				
				bg.setBigrama(cad);
				bg.setFrecuencia(_bigramas[i][j]);
				
				nuevoIdioma.setPosicion(pos, bg);
				pos++;
			}
		}
	}
	
	nuevoIdioma.ordenar();
	
	return nuevoIdioma;
}

void ContadorBigramas::fromIdioma(const Idioma &i)
{
	for (int j=0; j < getSize(); j++)
	{
		addBigrama(i.getPosicion(j).getBigrama(), i.getPosicion(j).getFrecuencia());
	}
}

    
void ContadorBigramas::reservarMemoria(int n)
{
	if (n > 0)
	{
		_bigramas = new int* [n];
		for (int i=0; i<n; i++)
			_bigramas[i] = new int [n];
	}
}

void ContadorBigramas::liberarMemoria()
{
	if (_bigramas != 0)
	{
		for (int i=0; i<_caracteresValidos.length(); i++)
		{
			delete[] _bigramas[i];
		}
		delete[] _bigramas;
		_bigramas = 0;
	}
}

void ContadorBigramas::copiar(const ContadorBigramas & otro)
{
	int l=otro._caracteresValidos.length();
	
	if (_caracteresValidos.length() != l)
	{
		liberarMemoria();
		reservarMemoria(l);
	}
	_caracteresValidos = otro._caracteresValidos;
	for (int i=0; i<l; i++)
		for (int j=0; j<l; j++)
			_bigramas[i][j] = otro._bigramas[i][j];
}