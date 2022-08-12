#ifndef __AVL_H__
#define __AVL_H__

#include <stddef.h>

/**
 * Estructura del nodo del árbol AVL.
 * Tiene un puntero a wchar_t (dato),
 * un puntero al nodo raíz del subarbol izquierdo (izq),
 * un puntero al nodo raíz del subarbol derecho (der),
 * un entero para representar la altura del árbol (altura).
 */
typedef struct _AVLNodo 
{
  wchar_t* dato;
  struct _AVLNodo *izq, * der;
  int altura;
}AVLNodo;

typedef AVLNodo *AVL;

/**
 * avl_crear : void -> AVL
 * Retorna un árbol AVL vacío.
 */
AVL avl_crear();

/**
 * avl_destruir : AVL -> void
 * Destruye el árbol AVL y sus datos.
 */
void avl_destruir(AVL);

/**
 * avl_buscar : AVL -> wchar_t * -> int
 * Retorna 1 si el dato se encuentra en el árbol AVL o 0 en caso contrario.
 */
int avl_buscar(AVL, wchar_t *);

/**
 * avl_nodo_altura : AVL -> int
 * Devuelve la altura del árbol, la altura del árbol vacío se define como -1.
 */
int avl_altura(AVL);

/**
 * avl_max_altura_hijos : AVL -> int
 * Retorna la máxima altura de los hijos.
 */
int avl_max_altura_hijos(AVL);

/**
 * avl_factor_balance : AVL -> int
 * Retorna el factor de balance de un nodo.
 */
int avl_factor_balance(AVL);

/**
 * avl_rotacion_simple_izq : AVL -> AVL
 * Realiza una rotación simple a izquierda y retorna la nueva raíz.
 */
AVL avl_rotacion_simple_izq(AVL);

/**
 * avl_rotacion_simple_der : AVL -> AVL
 * Realiza una rotación simple a derecha y retorna la nueva raíz.
 */
AVL avl_rotacion_simple_der(AVL);

/**
 * avl_insertar : AVL -> wchar_t * -> AVL
 * Inserta un dato no repetido en el árbol, manteniendo la propiedad de los
 * arboles AVL.
 */
AVL avl_insertar(AVL, wchar_t *);

#endif /* __AVL_H__*/
