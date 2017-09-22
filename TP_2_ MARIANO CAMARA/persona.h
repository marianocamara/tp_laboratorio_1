#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

typedef struct {
    char nombre[50];
    int edad;
    char dni[50];
    int estado;
}ePersona;

#endif // PERSONA_H_INCLUDED

#define PERSONA_LIBRE 0
#define PERSONA_OCUPADO 1

/** \brief Inicializa el campo estado de la estructura como LIBRE
 * \param array de la estructura
 * \param longitud del array
 * \return -1 error -- 0 OK
 */
int persona_initPersona (ePersona* arrayPersonas, int longitud);

/** \brief Dar de alta una persona (nombre, edad, DNI)
 * \param array de la estructura
 * \param longitud del array
 * \return -1 error -- 0 OK
 */
int persona_CargarPersona (ePersona* arrayPersonas, int index);

/** \brief Imprime una lista de las personas ordenada alfabeticamente por nombre
 * \param array de la estructura
 * \param longitud del array
 * \return -1 error -- 0 OK
 */
int persona_printPersona (ePersona* arrayPersonas, int longitud);

/** \brief Busca la primer posision del array con estado LIBRE
 * \param array de la estructura
 * \param longitud del array
 * \return -1 error -- 0 OK
 */
int persona_buscarPosicionPersonaLibre (ePersona* arrayPersonas, int longitud);

/** \brief Busca una persona por DNI y cambia su estado a LIBRE
 * \param array de la estructura
 * \param longitud del array
 * \return -1 error -- 0 OK
 */
int persona_borrarPersonaPorDni (ePersona* arrayPersonas, int longitud);

/** \brief Imprime grafico barras (eje x grupo por edad, eje y cantidad de personas)
 * \param array de la estructura
 * \param longitud del array
 * \return -1 error -- 0 OK
 */
int persona_imprimirGraficoEdades(ePersona* arrayPersonas,int longitud);


