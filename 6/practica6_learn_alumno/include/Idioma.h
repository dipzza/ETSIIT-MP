/** 
 * @file Idioma.h
 * @author Francisco Javier Bol�var Exp�sito  y  Samuel Jim�nez Pi�ero
*/

#ifndef IDIOMA_H
#define IDIOMA_H


#include "Bigrama.h"

/**
 * @class Idioma
 * @brief Representa el conjunto los bigramas asociados a un idioma junto con el 
 * identificador del idioma
 */
class Idioma {
public:

    /**
     * @brief Constructor base
     */
    Idioma();
    
    /**
     * @brief Constructor para pre-reservar memoria
     * @param nbg N�mero de bigramas pre-reservados
     */
    Idioma(int nbg);
    
    /**
     * @brief Constructor de copia
     * @param orig El idioma que se quiere copiar
     */
    Idioma(const Idioma& orig); 
    
    /**
     * @brief Destructor
     */
    ~Idioma(); 
    
    /**
     * @brief Sobrecarga del operador de asignaci�n
     * @param orig Par�metro rhs de la asignaci�n
     * @return this para concatenaci�n de asignaciones de derecha a izquierda
     */
    Idioma& operator=(const Idioma& orig); 

    /**
     * @brief Consulta el ID del idioma
     * @return ID del idioma
     */
    std::string getIdioma() const;
    
    /**
     * @brief Establece el ID del idioma
     * @param id Nuevo ID del idioma
     */
    void setIdioma(const std::string& id);
    
    /**
     * @brief Consulta la lista de bigramas
     * @param p La posici�n de la lista que se quiere consultar
     * @precond La posici�n @p p es correcta
     * @return El bigrama que ocupa la posici�n @p p
     */
    Bigrama getPosicion(int p) const;
    
    /**
     * @brief A�ade un nuevo bigrama
     * @param p La posici�n en la que se quiere insertar el bigrama
     * @precond La posici�n @p p es correcta
     * @param bg El bigrama a insertar
     */
    void setPosicion(int p, const Bigrama & bg);
    
    /**
     * @brief Consulta el n�mero de bigramas existentes. 
     * @return El tama�o de la lista de bigramas
     */
    inline int getSize() const { return _nBigramas; };

    /**
     * @brief Busca un bigrama en la lista de bigramas
     * @param bg El bigrama que se est� buscando
     * @return La posici�n que ocupa @p bg en la lista, -1 si no est� en la lista
     */
    int findBigrama(const std::string& bg) const;
    
    /**
     * @brief Calcula la distancia entre dos idiomas
     * @param otro El segundo idioma para consultar la distancia
     * @return resultado de la distancia, valor entre 0 y 1
     */
    double distancia(const Idioma& otro) const;
    
    /**
     * @brief Ordena la lista de bigramas de mayor a menor frecuencia
     */
    void ordenar();

    friend std::ostream & operator<<(std::ostream & os, const Idioma & i);
    friend std::istream & operator>>(std::istream & os, Idioma & i);

    /**
     * @brief Serializa y guarda un idioma en un fichero
     * @param fichero El fichero de salida
     * @return @b false si ha habido alg�n tipo de error, @b true en otro caso
     */
    bool salvarAFichero(const char *fichero) const;
    
    /**
     * @brief Recupera una serializaci�n de un idioma desde un fichero y 
     * reconstruye el idioma
     * @param fichero Fichero que contiene un idioma serializado
     * @return @b false si ha habido alg�n tipo de error, @b true en otro caso
     */
    bool cargarDeFichero(const char *fichero);
private:
    std::string _idioma;    /// Identificador del idioma
    Bigrama* _conjunto;     /// Vector din�mico de bigramas
    int _nBigramas;         /// N�mero de bigramas en el vector din�mico

    void reservarMemoria(int n);
    void liberarMemoria();
    void copiar(const Idioma& otro);


};

/**
 * @brief Serializaci�n de un idioma para su inserci�n en un flujo de salida
 * @param os Flujo de salida
 * @param i Idioma a serializar
 * @return El mismo flujo de salida para inserciones consecutivas
 */
std::ostream & operator<<(std::ostream & os, const Idioma & i);

/**
 * @brief Reconstruye un Idioma a partir de una serializaci�n
 * @param is Flujo de entrada desde el que se extrae la serializaci�n
 * @param i Idioma reconstruido
 * @return El mismo flujo de entrada para extracciones consecutivas
 */
std::istream & operator>>(std::istream & is, Idioma & i);


#endif