#include "avl.h"

#include <stdlib.h>
#include <assert.h>
#include <wchar.h>

/**
 * Retorna un árbol AVL vacío.
 */
AVL avl_crear() 
{
  return NULL;
}

/**
 * Destruye el árbol AVL y sus datos.
 */
void avl_destruir(AVL raiz) 
{
  if (raiz != NULL) 
  {
    // Destruye los nodos en postorden
    avl_destruir(raiz->izq);
    avl_destruir(raiz->der);
    free(raiz->dato);
    free(raiz);
  }
}

/**
 * Retorna 1 si el dato se encuentra o 0 en caso contrario.
 */
int avl_buscar(AVL raiz, wchar_t* dato) 
{
  if (raiz == NULL)
    return 0;
    
  else if (wcscmp(dato, raiz->dato) == 0) // raiz->dato == dato
    return 1;
    
  else if (wcscmp(dato, raiz->dato) < 0) // dato < raiz->dato
    return avl_buscar(raiz->izq, dato);
    
  else // dato > raiz->dato
    return avl_buscar(raiz->der, dato);
}

/**
 * retorna la altura del árbol.
 */
int avl_altura(AVL raiz) 
{
  return (raiz == NULL ? -1 : raiz->altura);
}

/**
 * Retorna la máxima altura de los hijos.
 */
int avl_max_altura_hijos(AVL raiz) 
{
  assert(raiz);
  int alturaIzq = avl_altura(raiz->izq);
  int alturaDer = avl_altura(raiz->der);
  
  return (alturaIzq < alturaDer ? alturaDer : alturaIzq);
}

/**
 * Retorna el factor de balance de un nodo.
 */
int avl_factor_balance(AVL raiz) 
{
  assert(raiz);
  int factor = avl_altura(raiz->der) - avl_altura(raiz->izq);
  assert(-2 <= factor || factor <= 2);
  
  return factor;
}

/**
 * Rotación simple a izquierda y retorna la nueva raźz.
 */
AVL avl_rotacion_simple_izq(AVL raiz) 
{
  AVLNodo* hijoDer = raiz->der;
  assert(hijoDer);
  
  // actualizar punteros
  raiz->der = hijoDer->izq;
  hijoDer->izq = raiz;
  
  // actualizar alturas
  raiz->altura = 1 + avl_max_altura_hijos(raiz);
  hijoDer->altura = 1 + avl_max_altura_hijos(hijoDer);
  
  return hijoDer;
}

/**
 * Rotación simple a derecha y retorna la nueva raíz.
 */
AVL avl_rotacion_simple_der(AVL raiz) 
{
  AVLNodo* hijoIzq = raiz->izq;
  assert(hijoIzq);
  
  raiz->izq = hijoIzq->der;
  hijoIzq->der = raiz;
  
  raiz->altura = 1 + avl_max_altura_hijos(raiz);
  hijoIzq->altura = 1 + avl_max_altura_hijos(hijoIzq);
  
  return hijoIzq;
}

/**
 * Inserta un dato no repetido en el árbol.
 */
AVL avl_insertar(AVL raiz, wchar_t* dato) 
{
  if (raiz == NULL) // Se inserta el nuevo elemento
  {
    AVLNodo* nuevoNodo = malloc(sizeof(AVLNodo));
    assert(nuevoNodo);
    
    nuevoNodo->dato = malloc(sizeof(wchar_t) * (wcslen(dato) + 1));
    assert(nuevoNodo->dato);
    nuevoNodo->dato = wcscpy(nuevoNodo->dato, dato);
    
    nuevoNodo->izq = nuevoNodo->der = NULL;
    nuevoNodo->altura = 0;
    
    return nuevoNodo;
  }
  else if (wcscmp(dato, raiz->dato) < 0) // El dato debe ir en el subarbol izq
  { 
    raiz->izq = avl_insertar(raiz->izq, dato);
    
    // Chequear balance
    if (avl_factor_balance(raiz) == -2) 
    {  // Casos 1 o 2
      if (avl_factor_balance(raiz->izq) == 1) // Caso 2
        raiz->izq = avl_rotacion_simple_izq(raiz->izq);
    
      raiz = avl_rotacion_simple_der(raiz); // Caso 1
    }
    
    raiz->altura = 1 + avl_max_altura_hijos(raiz);
    
    return raiz;
  }
  else if (wcscmp(dato, raiz->dato) > 0) // El dato debe ir en el subarbol der
  { 
    raiz->der = avl_insertar(raiz->der, dato);
    
    if (avl_factor_balance(raiz) == 2) 
    {
      if (avl_factor_balance(raiz->der) == -1)
        raiz->der = avl_rotacion_simple_der(raiz->der);
        
      raiz = avl_rotacion_simple_izq(raiz);
    }
    
    raiz->altura = 1 + avl_max_altura_hijos(raiz);
    
    return raiz;
  }
  else // No agrega elementos repetidos
    return raiz;
}

