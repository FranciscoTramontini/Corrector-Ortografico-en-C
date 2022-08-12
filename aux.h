#ifndef __AUX_H__
#define __AUX_H__

#include "slist.h"
#include "cola.h"

/**
 * Estructura para guardar las palabras que representan las sugerencias y las 
 * no sugerencias.
 * Tiene una lista simplemente enlazada donde se guardaran las sugerencias 
 * (sugerencias),
 * una Cola para guardar las no sugerencias (noSugerencias),
 * un entero que representa la longitud de la lista de sugerencias 
 * (longitudSugerencias),
 * un entero que representa la longitud de la cola de no sugerencias 
 * (longitudNoSugerencias),
 * un entero que representa las técnicas aplicadas a las palabras 
 * (tecnicasAplicadas).
 */
typedef struct _NodoAux{
  SList sugerencias;
  Cola noSugerencias;
  int longitudSugerencias;
  int longitudNoSugerencias;
  int tecnicasAplicadas;
}NodoAux;

typedef NodoAux *Aux;

/**
 * aux_crear : void -> Aux
 * Crea una estructura Aux vacía.
 */
Aux aux_crear();

/**
 * aux_destruir : Aux -> void
 * Libera la memoria pedida por la estructura Aux y sus datos.
 */
void aux_destruir(Aux); 

#endif /* __LISTAS_H__ */
