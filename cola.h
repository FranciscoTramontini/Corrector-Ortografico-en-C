#ifndef __COLA_H__
#define __COLA_H__

#include <stddef.h>

/**
 * Estructura de un nodo de cola con lista circulare doblemente enlazada.
 * Tiene un puntero a wchar_t (dato),
 * un puntero al nodo anterior de la cola (ant),
 * un puntero al nodo siguiente de la cola (sig).
 */
typedef struct _CDList 
{
  wchar_t *dato;
  struct _CDList *ant;
  struct _CDList *sig;
} CDList;

typedef CDList *Cola;

/**
 * cola_crear : void -> Cola
 * Retorna una cola vacía.
 */
Cola cola_crear();

/**
 * cola_primero : Cola -> wchar_t *
 * Devuelve el primer elemento de la cola.
 */
wchar_t* cola_primero(Cola);

/**
 * cola_encolar : Cola -> wchar_t * -> Cola
 * Agrega un elemento al final de la cola.
 */
Cola cola_encolar(Cola, wchar_t *);

/**
 * cola_desencolar : Cola -> Cola
 * Elimina el primer elemento de la cola.
 */
Cola cola_desencolar(Cola);

/**
 * cola_destruir : Cola -> void
 * Libera la memoria pedida por la cola y sus datos.
 */
void cola_destruir(Cola);

#endif /* __COLA_H__ */
