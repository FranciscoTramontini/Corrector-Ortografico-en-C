#include "aux.h"

#include <stdlib.h>
#include <assert.h>

/**
 * Crea una estructura Aux vacía.
 */
Aux aux_crear()
{
  SList sugerencias = slist_crear();
  Cola noSugerencias = cola_crear();
  
  Aux aux = malloc(sizeof(NodoAux));
  assert(aux);
  
  aux->sugerencias = sugerencias;
  aux->noSugerencias = noSugerencias;
  aux->longitudSugerencias = 0;
  aux->longitudNoSugerencias = 0;
  aux->tecnicasAplicadas = 0;
  
  return aux;
}

/**
 * Libera la memoria pedida por la estructura Aux y sus datos.
 */
void aux_destruir(Aux aux) 
{
  slist_destruir(aux->sugerencias);
  cola_destruir(aux->noSugerencias);
  free(aux);
}
