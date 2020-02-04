/** 
 * @file Idioma.cpp
 * @author DECSAI
 * @warning Código incompleto. Implementar la clase completa
*/

#include "Idioma.h"
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;
/**
* @brief Constructor base
*/
Idioma::Idioma()
{
	_idioma = "N";
	_nBigramas = 0;
}
    
/**
* @brief Constructor para pre-reservar memoria
* @param nbg Número de bigramas pre-reservados
**/
Idioma::Idioma(int nbg)
{
	if (nbg > 0)
	{
		_idioma = "N";
		_conjunto = new Bigrama[nbg];
		_nBigramas = 0;
	}
}

/**
* @brief reserva memoria para @a n bigramas,
* en caso de que ya hubiese memoria reservada, esta
* debe eliminarse
* @param n número de bigramas a reservar
*/
void Idioma::reservarMemoria(int n)
{

	if (_nBigramas != 0)
	{
		delete []_conjunto;
	}
		
	_conjunto = new Bigrama[n];
	_nBigramas = n;

}

/**
* @brief reserva memoria para @a n bigramas adicionales
* a los que ya haya reservados, manteniendo los datos
* que hubiese podido haber reservados
* @param n número de bigramas a ampliar
*/
void Idioma::ampliarMemoria(int n)
{
	Bigrama *conjuntoamp = new Bigrama[_nBigramas + n];

	for (int i=0; i<_nBigramas; i++)
	{
		conjuntoamp[i] = _conjunto[i];
	}
	
	delete []_conjunto;
	_conjunto = conjuntoamp;
}

/**
* @brief Libera la memoria
*/
void Idioma::liberarMemoria()
{
	delete []_conjunto;
	_conjunto = 0;
}

/**
* @brief Consulta el ID del idioma
* @return ID del idioma
*/
std::string Idioma::getIdioma() const { return _idioma; }

/**
* @brief Establece el ID del idioma
* @param id Nuevo ID del idioma
*/
void Idioma::setIdioma(const std::string& id){ _idioma = id; }
    
/**
     * @brief Consulta la lista de bigramas
     * @param p La posición de la lista que se quiere consultar
     * @precond La posición @p p es correcta
     * @return El bigrama que ocupa la posición @p p
     */
Bigrama Idioma::getPosicion(int p) const
{
	if (p < _nBigramas && p >= 0)
		return _conjunto[p];
}
    
/**
* @brief Añade un nuevo bigrama
     * @param p La posición en la que se quiere insertar el bigrama
     * @precond La posición @p p es correcta
     * @param bg El bigrama a insertar
     */
void Idioma::setPosicion(int p, const Bigrama & bg)
{

	if (p < _nBigramas && p >= 0)
	{
		_conjunto[p] = bg;
	}

}

    /**
     * @brief Busca un bigrama en la lista de bigramas
     * @param bg El bigrama que se está buscando
     * @return La posición que ocupa @p bg en la lista, -1 si no está en la lista
     */
int Idioma::findBigrama(const std::string bg) const
{
	
	bool encontrado = false;
	int pos;

	for(int i=0; i < _nBigramas && !encontrado; i++){
		if(bg == getPosicion(i).getBigrama())
		{
			pos = i;
			encontrado = true;
		}
	}
	
	if(!encontrado)
	{
		pos= -1;
	}

	return pos;	

}

	 /**
	  * @brief Añade un nuevo bigrama a la lista. Si el bigrama se añade por primera vez
	  * se debe incrementar el tamaño del vector para alojar el nuevo bigrama. Si el bigrama
	  * ya existe, se deben de sumar ambas frecuencias, la existente y la nueva
	  * @param bg El bigrama a añadir
	  */
void Idioma::addBigrama(const Bigrama &bg)
{
	bool existente = false;
	
	for (int i=0; i<_nBigramas; i++)
		if (strcmp(_conjunto[i].getBigrama(), bg.getBigrama()) == 0)
		{
			existente = true;
			_conjunto[i].setFrecuencia(_conjunto[i].getFrecuencia() + bg.getFrecuencia());
		}
			
	if (!existente)
	{
		ampliarMemoria(1);
		_conjunto[_nBigramas] = bg;
		_nBigramas++;
	}
}
	 
    
    /**
     * @brief Recupera una serialización de un idioma desde un fichero y 
     * reconstruye el idioma. Muestra en pantalla el idioma cargado
     * @param fichero Fichero que contiene un idioma serializado
     * @return @b false si ha habido algún tipo de error, @b true en otro caso
     */
bool Idioma::cargarDeFichero(const char *fichero)
{

	ifstream f;
	string idioma;
	char bigrama[2];
	int nv, frecuencia;
	Bigrama bg;
	bool correcto = true;

	cout << endl << "Abriendo fichero " << fichero << endl;
	f.open(fichero);
	if(f){
		f >> idioma;
		f >> idioma;
		f >> nv;
	    _idioma=idioma;

		cout << "Idioma detectado " << idioma << endl;
		cout << "Leyendo " << nv << " bigramas" << endl;
		
		reservarMemoria(nv);
		for(int i=0; i < nv && correcto; i++)
		{
			f >> bigrama;
			f >> frecuencia;
			
			bg.setBigrama(bigrama);
			bg.setFrecuencia(frecuencia);
			_conjunto[i] = bg;					// Cambiar por setposicion
		}	
		
		if(!f)
		{
			cerr << "ERROR cargando datos del fichero " << fichero << endl;
			correcto=false;
		}
		else
			cout << "OK" << endl;
			
	f.close();
 	}else{
		cerr << "ERROR abriendo fichero " << fichero << endl;
		correcto=false;
	}
	
	return correcto;  
}
	 
/**
* @brief Método similar a @a cargarDeFichero pero en vez de cargar un idioma nuevo
* desde el fichero (que debe contener un idioma serializado), los bigramas del fichero
* se añaden al diccionario que ya existe.
* @param fichero Contiene los bigramas a añadir al idioma existente
* @return @b false si ha habido algún tipo de error, @b true en otro caso
* @pre El objeto ya debe tener un idioma cargado y deben coincidir ambos
*/
bool Idioma::addDeFichero(const char *fichero)
{
	ifstream fentrada;
	bool noerror = true;
	Bigrama nuevo;
	char cadena[2];
	int frec, nBigramas, error = 0;
	string idioma;
	
	cout << endl << "Abriendo fichero " << fichero << endl;
	fentrada.open(fichero);
	if (fentrada)
	{
		fentrada >> idioma;
		fentrada >> idioma;
		fentrada >> nBigramas;
		
		cout << "Idioma detectado " << idioma << endl;
		if (idioma == _idioma)
		{
			cout << "Leyendo " << nBigramas << " bigramas" << endl;
			
			for (int i=0; i<nBigramas; i++)
			{
				fentrada >> cadena;
				fentrada >> frec;
				nuevo.setBigrama(cadena);
				nuevo.setFrecuencia(frec);
				addBigrama(nuevo);
			}
		
			if (!fentrada)
			{
				cerr << "ERROR cargando datos del fichero " << fichero << endl;
				noerror = false;
			}
			else
				cout << "OK" << endl;
			
			fentrada.close();
		}
		else
		{
			cerr << "ERROR Idioma no compatible con " << _idioma << endl;
			noerror = false;
			error = 1;
		}
	}
	else
	{
		cerr << "ERROR Abriendo fichero " << fichero << endl;
		noerror = false;
	}
	
	return noerror;
}