#ifndef __TABLAHASH_H__
#define __TABLAHASH_H__

#include "avl.h"

/**
 * Función puntero para la función hash.
 */
typedef unsigned (*FuncionHash) (wchar_t *dato);

/**
 * Estructura principal que representa la tabla hash.
 * Tiene puntero a un AVL que representa los datos de la tabla (tabla),
 * un size_t que representa la capacidad (capacidad),
 * una función puntero que representa la función hash (hash).
 */
typedef struct _TablaHash {
  AVL *tabla;
  size_t capacidad;
  FuncionHash hash;
}TablaHash;

/**
 * tablahash_crear: size_t -> FuncionHash -> TablaHash*
 * Crea una tabla hash vacía.
 */
TablaHash* tablahash_crear(size_t, FuncionHash);

/**
 * tablahash_insertar: TablaHash * -> wchar_t * -> void
 * Inserta un elemento a la tabla hash.
*/
void tablahash_insertar(TablaHash *, wchar_t *);

/**
 * tablahash_buscar : TablaHash * -> wchar_t * -> int 
 * Devuelve 1 si la palabra se encuentra en la tabla, en caso contrario devuelve
 * 0.
 */
int tablahash_buscar(TablaHash *, wchar_t *);

/**
 * tablahash_destruir: TablaHash * -> void
 * Libera el espacio ocupado en la memoria por una tabla hash y sus datos.
 */
void tablahash_destruir(TablaHash *);

/**
 * tablahash_leer_diccionario : char * -> TablaHash *
 * Recibe el nombre del archivo en que se encuentra el diccionario y lo carga 
 * a una tabla hash.
 */
TablaHash* tablahash_leer_diccionario(char *);

#endif /* __TABLAHASH_H__ */
