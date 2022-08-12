#include "cola.h"

#include <stdlib.h>
#include <assert.h>
#include <wchar.h>

/**
 * Crea una cola vacía.
 */
Cola cola_crear() 
{ 
  return NULL; 
}

/**
 * Retorna el primer elemento de la cola. 
 */
wchar_t* cola_primero(Cola cola) 
{ 
  return cola->dato; 
}

/**
 * Inserta un dato al final de la cola. 
 */
Cola cola_encolar(Cola cola, wchar_t* dato) {
  Cola nuevoDato = malloc(sizeof(struct _CDList));
  assert(nuevoDato);
  
  nuevoDato->dato = malloc(sizeof(wchar_t) * (wcslen(dato) + 1));
  assert(nuevoDato->dato);
  wcscpy(nuevoDato->dato, dato);

  if (cola == NULL) 
  {
    nuevoDato->sig = nuevoDato;
    nuevoDato->ant = nuevoDato;
    cola = nuevoDato;
  }
  else 
  {
    Cola ultimo = cola->ant;
    nuevoDato->sig = cola;
    cola->ant = nuevoDato;
    nuevoDato->ant = ultimo;
    ultimo->sig = nuevoDato;
  }

  return cola;
}

/**
 * Elimina el primer elemento de la cola. 
 */

Cola cola_desencolar(Cola cola) {
  if (cola != NULL) 
  {
    if (cola->sig == cola->ant) // Hay un solo elemento
    {  
      free(cola->dato);
      free(cola);
    } 
    else 
    {
      Cola primero = cola;
      primero->ant->sig = primero->sig;
      primero->sig->ant = primero->ant;
      cola = primero->sig;
      free(primero->dato);
      free(primero);
    }
  }
  
  return cola;
}

/**
 * Destruye la memoria pedida de la cola y sus elementos.
 */
void cola_destruir(Cola cola) 
{
  if (cola == NULL)
    return;
    
  Cola nodoAEliminar;
  while (cola->sig != cola) 
  {
    nodoAEliminar = cola->sig;
    cola->sig = nodoAEliminar->sig;
    free(nodoAEliminar->dato);
    free(nodoAEliminar);
  }
  
  // Se borra el primer nodo
  free(cola->dato);
  free(cola);
}
