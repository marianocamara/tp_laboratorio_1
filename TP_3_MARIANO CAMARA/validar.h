#ifndef VALIDAR_H_INCLUDED
#define VALIDAR_H_INCLUDED



#endif // VALIDAR_H_INCLUDED

void myFgets(char* buffer, int limite ,FILE* archivo);

int val_getNombre(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_validarNombre(char* buffer);

int val_getUnsignedInt(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_validarUnsignedInt(char* buffer);

int val_getFloat(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_esNumericoFlotante(char* buffer);

int val_getDireccion(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_esAlfaNumerico(char str[]);

int val_validarTipoPantalla(char* buffer);
int val_getTipoPantalla(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);

int val_getNombreVideo(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_validarNombreVideo(char str[]);

int val_getCuit(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_esCuit(char* buffer);

int val_getLink(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_validarLink(char* buffer);

