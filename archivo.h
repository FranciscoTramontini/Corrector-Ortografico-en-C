#ifndef __ARCHIVO_H__
#define __ARCHIVO_H__

#include "tablahash.h"
#include "aux.h"

#include <stdio.h>

/**
 * archivo_abrir : char * -> char * -> FILE *
 * Dado el nombre del archivo y la forma, lo abre en la forma pasada como 
 * argumento, también verifica que se abra en forma correcta.
 */
FILE* archivo_abrir(char *, char *);

/**
 * archivo_salida : Aux -> FILE * -> wchar_t * -> int -> void
 * Completa el archivo con las sugerencias de la palabra que no se 
 * encuentra en el diccionario. Esas palabras se encuentran en Aux, y le 
 * pasamos en que linea se encuentra la palabra en el texto para más 
 * especificación.
 */
void archivo_salida(Aux, FILE *, wchar_t *, int);

/**
 * corrector_ortografico : TablaHash * -> char * -> char * -> void
 * Dada una tabla hash que representa el diccionario y el nombre de los archivos 
 * de entrada y salida, se abren los archivos, leemos el primer archivo 
 * (entrada) que tendrá el texto a corregir, y se devuelven las sugerencias si 
 * es que las hay de las palabras que no se encuentran en el diccionario 
 * en el segundo archivo (salida).
 */
void corrector_ortografico(TablaHash *, char *, char *);

/**
 * archivo_cerrar : FILE * -> void
 * Cierra el archivo.
 */
void archivo_cerrar(FILE *);

#endif /* __ARCHIVO_H__ */
