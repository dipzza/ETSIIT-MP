/*
 * Metodología de la Programación: Práctica final
 * Curso 2017/2018
 */

/** 
 * @file ContadorBigramas.h
 * @author Francisco Javier Bol�var Exp�sito  y  Samuel Jim�nez Pi�ero
*/
#ifndef CONTADOR_BIGRAMAS_H
#define CONTADOR_BIGRAMAS_H

#include "Idioma.h"

class ContadorBigramas {
public:
    
    /**
    * @brief Constructor base. Es imprescindible pasar la cadena de caracteres válidos para poder dimensionar la matriz 2D
    * @param caracteresValidos Cadena que contiene los únicos caracteres que serán considerados para contabilizar bigramas
    */
    ContadorBigramas(const std::string& caracteresValidos);
    
    /**
    * @brief Constructor de copia
    * @param orig El objeto que se copia en en el constructor
    */
    ContadorBigramas(const ContadorBigramas & orig);
    
    /**
    * @brief Destructor de la clase 
    */
    ~ContadorBigramas(); 
    
    /**
    * @brief Devuelve el número de filas de la matriz 2D, que debe coincidir con la longitud de la cadena de caracteres válidos
    * @return El número de filas de la matriz
    */
    int getSize() const;
    
    /**
    * @brief Devuelve el número de bigramas de la matriz 2D cuya frecuencia es > 0
    * @return El número de bigramas con frecuencia > 0
    */
    int getBigramasActivos() const;
    
    /**
    * @brief Añade un bigrama a la matriz 2D indicando su frecuencia. Si frecuencia = 0, se incrementará en uno la frecuencia del bigrama añadido, sino se le asigna la frecuencia
    * @param cadena[] el bigrama que se desea añadir
    * @param la frecuencia del bigrama
    * @return Verdadero si el bigrama es valido y se añade a la matriz 2D, falso en otro caso
    */
    bool addBigrama(const char cadena[], int frecuencia=0);
    
    /**
    * @brief Sobrecarga del operador de asignación
    * @param orig Parámetro de la asignación
    * @return this 
    */
    ContadorBigramas& operator=(const ContadorBigramas& orig); // Operador asignación
    
    /**
    * @brief Sobrecarga del operador de suma
    * @param rgs Parámetro que se usa para sumar
    * @return this 
    */ 
    ContadorBigramas& operator+=(const ContadorBigramas& rhs);

	
    /**
    * @brief Carga en la matriz de 2D, los bigramas validos encontrados en el fichero
    * @param fichero a leer
    * @return Verdadero si se ha podido leer el fichero, falso en otro caso
    */
    bool calcularFrecuenciasBigramas(const char* nfichero);
    

    /**
    * @brief Pasa la matriz 2D a un objeto de la clase Idioma
    */
    Idioma toIdioma() const; 
    

    /**
    * @brief Pasa la los bigramas del objeto Idioma a la matriz 2D
    */     
    void fromIdioma(const Idioma &i);

private:
    int** _bigramas; // Matriz 2D con la frecuencia para cada bigrama
    std::string _caracteresValidos; // Cadena de caracteres válidos.
    
    //Métodos privados de apoyo a los públicos.
    void reservarMemoria(int n);
    void liberarMemoria();
    void copiar(const ContadorBigramas & otro);


};

#endif
