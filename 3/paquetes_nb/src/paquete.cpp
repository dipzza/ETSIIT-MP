/**
   @file paquete.cpp
   @author decsai.ugr.es
**/
#include "paquete.h"

Paquete::Paquete(): _id(_SIN_IDENT) {}

Paquete::Paquete(int id)
{
	if (id > 0)
	{
		_id = id;
		_peso = _largo = _ancho = _alto = 0;
	}
	else
		_id = _SIN_IDENT;
}

Paquete::Paquete(int id, double peso, int largo, int ancho, int alto)
{
	if (id > 0 && peso > 0 && largo > 0 && ancho > 0 && alto > 0)
	{
		_id = id;
		_peso = peso;
		_largo = largo;
		_ancho = ancho;
		_alto = alto;
	}
	else
	{
		if (id > 0 && peso == 0 && largo == 0 && ancho == 0 && alto == 0)
			peso = largo = ancho = alto = 0;
		else
			_id = _SIN_IDENT;
	}
}

void Paquete::setId(int id)
{
   if (id > 0)
	   _id = id;
}

int Paquete::getId()const
{
	return _id;
}

void Paquete::setPeso(int peso)
{
	if (peso > 0)
		_peso = peso;
}

double Paquete::getPeso()const
{
	return _peso;
}

void Paquete::setLargo(int largo)
{
	if (largo > 0)
		_largo = largo;
}

int Paquete::getLargo()const
{
	return _largo;
}

void Paquete::setAncho(int ancho)
{
	if (ancho > 0)
		_ancho = ancho;
}

int Paquete::getAncho()const
{
	return _ancho;
}

void Paquete::setAlto(int alto)
{
	if (alto >0)
		_alto = alto;
}

int Paquete::getAlto()const
{
	return _alto;
}

void Paquete::setPaquete(int id, int peso, int largo, int ancho, int alto)
{
	if (id > 0 && peso > 0 && largo > 0 && ancho > 0 && alto > 0)
	{
		_id = id;
		_peso = peso;
		_largo = largo;
		_ancho = ancho;
		_alto = alto;
	}
	if (id > 0 && peso == 0 && largo == 0 && ancho == 0 && alto == 0)
		peso = largo = ancho = alto = 0;
}

double Paquete::getVolumen()const{

	return _ancho*_largo*_alto;

}

double Paquete::calculaPesoVolumetrico()const
{
	double pesoVol = getVolumen() / _FACTORVOLUMETRICO;
	double pesoFinal;
	
	if (pesoVol > _peso)
		pesoFinal = pesoVol;
	else
		pesoFinal = _peso;
	
	return pesoFinal;
}

double Paquete::getFactura()const
{
	double factura, pesovol = calculaPesoVolumetrico();
	
	if( pesovol <= 5 ){
		if(pesovol <= 2)
			factura=15.69;
		else
			factura=20.36;
	}else{
		factura=35.48;
	}

	return factura;
}