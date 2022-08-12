#ifndef __TECNICAS_H__
#define __TECNICAS_H__

#include "aux.h"
#include "tablahash.h"

/**
 * tecnica_caracteres_adyacentes: TablaHash * -> wchar_t * -> int -> Aux -> Aux
 * Se toma una palabra, su longitud y se intercambia cada par de caracteres 
 * adyacentes de la palabra. Si encontramos la palabra la guardamos en la lista 
 * de sugerencias, caso contrario en la cola de no sugerencias. Y devolvemos la 
 * estructura que contiene ambas.
 */
Aux tecnica_caracteres_adyacentes(TablaHash *, wchar_t *, int, Aux);

/**
 * tecnica_insertar_caracter: TablaHash * -> wchar_t * -> int -> Aux -> Aux
 * Se toma una palabra, su longitud y se inserta un carácter entre cada par de 
 * caracteres de la palabra, inserta cada letra de la 'a' a la 'z'. Si 
 * encontramos la palabra se guarda en la lista de sugerencias, caso contrario 
 * en la cola de no sugerencias. Se devuelve la estructura que contiene ambas.
 */
Aux tecnica_insertar_caracter(TablaHash *, wchar_t *, int, Aux);

/**
 * tecnica_eliminar_caracter: TablaHash * -> wchar_t * -> int -> Aux -> Aux
 * Se toma una palabra, su longitud y se elimina un carácter, si encontramos la 
 * palabra la se guarda en la lista de sugerencias, caso contrario en la cola de
 * no sugerencias. Y devolvemos la estructura que contiene ambas.
 */
Aux tecnica_eliminar_caracter(TablaHash *, wchar_t *, int, Aux);
  
/**
 * tecnica_reemplazar_caracter: TablaHash * -> wchar_t * -> int -> Aux -> Aux
 * Se toma una palabra, su longitud y se reemplaza el carácter de la palabra con 
 * cada letra de la 'a' a la 'z', si se encuentra la palabra se guarda en la 
 * lista de sugerencias, caso contrario en la cola de no sugerencias. Se 
 * devuelve la estructura que contiene ambas.
 */
Aux tecnica_reemplazar_caracter(TablaHash *, wchar_t *, int, Aux);
  
/**
 * tecnica_separar_palabras: TablaHash * -> wchar_t * -> int -> Aux -> Aux
 * Se toma una palabra, su longitud, se separa y se busca las dos palabras 
 * formadas en la tabla. Si esta se guarda en la lista de sugerencias, caso 
 * contrario, se guarda en la cola de no sugerencias. Se devuelve la estructura 
 * que contiene ambas.
 */
Aux tecnica_separar_palabras(TablaHash *, wchar_t *, int, Aux);

/**
 * sugerencias: TablaHash * -> wchar_t * -> Aux
 * Aplica las técnicas pedidas a la palabra que recibe, si supera las 5 
 * sugerencias en la lista de sugerencias termina, si no aplica las técnicas
 * hasta tres veces a las palabras que se encuentran en la cola de no 
 * sugerencias y devuelve la estructura Aux con las sugerencias y no 
 * sugerencias.
 */ 
Aux sugerencias(TablaHash *, wchar_t *);
  
#endif /* __TECNICAS_H__ */
