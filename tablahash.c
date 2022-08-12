#include "tablahash.h"
#include "utils.h"
#include "archivo.h"

#include <stdlib.h>
#include <assert.h>
#include <wchar.h>
#include <wctype.h>

/**
 * Representa el tamaño de la tabla hash.
 */
#define TAMANIOTABLA 1000000

/**
 * Se crea la tabla hash vacía, con una capacidad y función hash dada.
 */
TablaHash* tablahash_crear(size_t capacidad, FuncionHash hash) 
{
  // Pedimos memoria para la estructura principal y las casillas.
  TablaHash *tabla = malloc(sizeof(TablaHash));
  assert(tabla);
  
  tabla->tabla = malloc(sizeof(AVL) * capacidad);
  assert(tabla->tabla);
  
  tabla->capacidad = capacidad;
  tabla->hash = hash;
  
  // Inicializamos las casillas con datos nulos.
  for (size_t idx = 0; idx < capacidad; ++idx)
    tabla->tabla[idx] = avl_crear();

  return tabla;
}

/**
 * Inserta el dato en la tabla hash dado por su función hash, evitando
 * colisiones.
 */
void tablahash_insertar(TablaHash *tabla, wchar_t *dato) 
{
  size_t clave = tabla->hash(dato) % tabla->capacidad; // Clave de hash
  tabla->tabla[clave] = avl_insertar(tabla->tabla[clave], dato);
}

/**
 * Devuelve 1 si el dato se encuentra en la tabla, en caso contrario 0.
 */
int tablahash_buscar(TablaHash *tabla, wchar_t *dato)
{
  size_t clave = tabla->hash(dato) % tabla->capacidad; // Clave de hash
  return avl_buscar(tabla->tabla[clave], dato);
}
/**
 * Libera el espacio ocupado en la memoria por una tabla hash y sus datos.
 */
void tablahash_destruir(TablaHash *tabla)
{
  for (size_t i = 0; i < tabla->capacidad; i++)
    avl_destruir(tabla->tabla[i]);
      
  free(tabla->tabla);
  free(tabla);
}

/**
 * Carga un diccionario que viene en un archivo en una tabla hash.
 */
TablaHash* tablahash_leer_diccionario(char *nombreArchivo) {
  FILE *archivo = archivo_abrir(nombreArchivo, "r");

  TablaHash *diccionario = tablahash_crear(TAMANIOTABLA, hash);
  
  wchar_t buff[80];
  size_t len;
  
  while (fgetws(buff, 80, archivo) != NULL) 
  {
    len = wcslen(buff);

    // Borrar el salto de línea si tiene.
    if (buff[len-1] == '\n') 
    {
      buff[len-1] = '\0';
      len--;
    }
    
    for (int i = 0; buff[i] != '\0'; ++i) // Convierte la palabra a minuscula.
		buff[i] = towlower(buff[i]);
    
    tablahash_insertar(diccionario, buff);
  }
  
  archivo_cerrar(archivo);

  return diccionario;
}
