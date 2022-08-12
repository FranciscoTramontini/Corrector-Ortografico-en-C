#include "slist.h"

#include <stdlib.h>
#include <assert.h>
#include <wchar.h>

/**
 * Crea una lista simplemente enlazada vacía.
 */
SList slist_crear() 
{
  return NULL;
}

/**
 * Libera el espacio en memoria ocupado por una lista y sus datos.
 */
void slist_destruir(SList lista) 
{
  SNodo *nodoAEliminar;
  while (lista != NULL)
  {
    nodoAEliminar = lista;
    lista = lista->sig;
    free(nodoAEliminar->dato);
    free(nodoAEliminar);
  }
}

/**
 * Agrega el elemento dado al final de la lista. Si el elemento está en la
 * lista, no lo agrega.
 */
SList slist_agregar_final(SList lista, wchar_t *dato)
{
  SNodo* nuevoNodo = malloc(sizeof(SNodo));
  assert(nuevoNodo);
  
  nuevoNodo->dato = malloc(sizeof(wchar_t) * (wcslen(dato) + 1));
  assert(nuevoNodo->dato);
  nuevoNodo->dato = wcscpy(nuevoNodo->dato, dato);
  
  nuevoNodo->sig = NULL;

  if (lista == NULL)
    return nuevoNodo;
  
  SNodo *nodo = lista;
  for ( ; nodo->sig != NULL; nodo = nodo->sig) // Se verifica que el dato que se
  {                                           //  inserta no está en la lista
    if (! wcscmp(nodo->dato, dato)) 
    {
      free(nuevoNodo->dato);
      free(nuevoNodo);
      
      return lista;
    }
  }
  
  if (! wcscmp(nodo->dato, dato))       // Se verifica que el dato que se
  {                                     // inserta no este al final de la lista.
    free(nuevoNodo->dato);
    free(nuevoNodo);
    
    return lista;
  }
  
  nodo->sig = nuevoNodo;  // Si llega hasta acá el elemento no está y lo
                          // agrega al final de la lista.
  return lista;
}

/**
 * Devuelve la longitud de la lista.
*/
int slist_longitud(SList lista) 
{
  int longitud = 0;
  for (SNodo* nodo = lista; nodo != NULL; nodo = nodo->sig, longitud++);
    
  return longitud;
}
