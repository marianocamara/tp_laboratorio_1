#ifndef VALIDAR_H_INCLUDED
#define VALIDAR_H_INCLUDED



#endif // VALIDAR_H_INCLUDED

/** \brief Obtiene input usuario (myFgets) que deben ser solo caracteres numericos (validarUnsignedInt)
 * \param destino, donde se guarda el dato
 * \param mensaje para el usuario
 * \param mensaje de error para el usuario
 * \param cantidad oportunidades que el usuario tiene para ingresar los datos correctamente
 * \param longitud del array destino
 * \return -1 ingreso erroneo luego de los intentos -- 0 ok
 */
int val_getUnsignedInt(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);


/** \brief Obtiene input usuario (myFgets) que deben ser solo letras en minuscula (validarNombre)
 * \param array de caracteres
 * \param mensaje con indicaciones para el usuario
 * \param mensaje de error
 * \param cantidad oportunidades que el usuario tiene para ingresar los datos correctamente
 * \param longitud del array destino
 * \return -1 ingreso erroneo luego de los intentos -- 0 ok
 */
int val_getNombre(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
