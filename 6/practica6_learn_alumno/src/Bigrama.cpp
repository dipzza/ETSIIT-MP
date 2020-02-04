/** 
 * @file Bigrama.cpp
 * @author Francisco Javier Bolívar Expósito  y  Samuel Jiménez Piñero
*/

#include <cstring>
#include <iostream>
#include "Bigrama.h"

using namespace std;


Bigrama::Bigrama() {
    _bigrama[0] = '\0';
    _frecuencia = -1;
}

const char * Bigrama::getBigrama() const {
    return _bigrama;
}
int Bigrama::getFrecuencia() const {
    return _frecuencia;
}

void Bigrama::setBigrama(const char cadena[]) {
    if (strlen(cadena) <= 2)
        strcpy(_bigrama, cadena);
//    strncpy(_bigrama, cadena, 2); // Diferencias, violaciones de _bigrama[] o de cadena[]
}

void Bigrama::setFrecuencia(int frec) {
    _frecuencia = frec;
}

/**
* @brief Sobrecarga del operador relacional para comparar dos bigramas lexicográficamente
* @param b el segundo bigrama a comparar
* @return this->_bigrama < b
*/
bool Bigrama::operator>(const Bigrama &b)
{	
	bool menor;
	
	if (strcmp(_bigrama, b._bigrama) < 0)
		menor = true;
	else
		menor = false;
	
	return menor;
}

std::ostream& operator<<(std::ostream& os, const Bigrama& bigrama)
{
	os << bigrama._bigrama << " " << bigrama._frecuencia;
	
	return os;
}

std::istream& operator>>(std::istream& is, Bigrama& bigrama)
{
	char cadena [3];
	
	is >> cadena >> bigrama._frecuencia;
	
	bigrama.setBigrama(cadena);
	
	return is;
}