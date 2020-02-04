// Autores: Francisco Javier Bolívar Expósito  y  Samuel Jiménez Piñero
#ifndef H_INTERVALO
#define H_INTERVALO

class Intervalo{
private:
    bool cerradoInf;
    bool cerradoSup;
    double cotaInf;
    double cotaSup;

public:
    /** 
     *  @brief Intervalo vacio por defectoSup
     *  valorInf = valorSup & abiertoInf + abierto
     */
    Intervalo();
    /** 
     * @brief Crea un Intervalo  cerrado por defecto
     * @param cotaInferior
     * @param cotaSuperior
     * @precond cotaInferior <= cotaSuperior
     */
    Intervalo(double cotaInferior, double cotaSuperior);
    /** 
     * @brief Crea Intervalo
     * @param cerradoInferior
     * @param cerradoSuperior
     * @param cotaInferior
     * @param cotaSuperior
     * @precond cotaInferior <= cotaSuperior
     */
    Intervalo(double cotaInferior, double cotaSuperior, bool cerradoInferior, bool cerradoSuperior);
    /** 
     * @brief Devuelve la cota inferior del intervalo
     * @return El valor de la cota
     */
    double getCotaInf()const;
    /** 
     * @brief Devuelve la cota superior del intervalo
     * @return El valor de la cota
     */
    double getCotaSup()const;
    /** 
     * @brief Consulta si el intervalo es cerrado en su cota inferior
     * @return @retval true si es cerrado @retval false si es cerrado
     */
    bool dentroCotaInf()const;
    /** 
     * @brief Consulta si el intervalo es cerrado en su cota superior
     * @return @retval true si es cerrado @retval false si es cerrado
     */
    bool dentroCotaSup()const;
    /** 
     * @brief Define los valores del intervalo
     * @param cerradoInferior
     * @param cerradoSuperior
     * @param cotaInferior
     * @param cotaSuperior
     * @precond cotaInferior <= cotaSuperior
     */
    void setIntervalo(double cotaInferior, double cotaSuperior, bool cerradoInferior, bool cerradoSuperior);
    /** 
     * @brief Consulta si el intervalo almacenado es vacío o no
     * @return @retval true si es un intervalo vacío, @retval false en otro caso 
     */
    bool esVacio()const;
    /** 
     * @brief Consulta si un determinado valor está dentro del intervalo
     * @param n El valor consultado
     * @return @retval true si el valor @p n pertenece al intervalo, @retval false en otro caso 
     */
    bool estaDentro(double n)const;
};

/******************************/

/**
* @brief comprueba que los argumentos definen un intervalo correcto
* cotaInferior <= cotaSuperior
* @param cotaInferior
* @param cotaSuperior
* @return @retval true si correcto
*/
bool valido(double cinf, double csup, bool cerrinf, bool cerrsup);

/** 
* @brief Imprime los valores de un intervalo de forma visual según lo indicado en el guión
* @param  obj El intervalo
*/
void escribir(const Intervalo &obj);

/** 
* @brief Lee los valores del intervalo según el formato indicado en el guión
* @param obj El intervalo
*/
void leer(Intervalo &obj);

/** 
* @brief Muestra un mensaje en pantalla indicando si el intervalo es vacío o no
* @param obj El intervalo
*/
void comprobarVacio(Intervalo obj);

Intervalo interseccion(const Intervalo&i1, const Intervalo&i2);

#endif
