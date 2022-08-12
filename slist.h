#ifndef __SLIST_H__
#define __SLIST_H__

#include <stddef.h>

/**
 * Estructura del nodo de una lista simplemente enlazada.
 * Tiene un puntero a un wchar_t (dato),
 * un puntero al nodo siguiente de la lista (sig).
 */
typedef struct _SNodo 
{
  wchar_t *dato;
  struct _SNodo *sig;
}SNodo;

typedef SNodo *SList;

/**
 * slist_crear : void -> SList
 * Crea una lista simplemente enlazada vacía.
 */
SList slist_crear();

/**
 * slist_destruir : SList -> void
 * Libera el espacio en memoria ocupado por una lista y sus datos.
 */
void slist_destruir(SList);

/**
 * slist_agregar_final : SList -> wchar_t * -> SList
 * Agrega el elemento dado al final de la lista con la particularidad que si 
 * esta repetido el dato no lo agrega.
 */
SList slist_agregar_final(SList, wchar_t *);

/**
 * slist_longitud: SList -> int
 * Devuelve la longitud de la lista dada.
 */
int slist_longitud(SList);

#endif /* __SLIST_H_ */
