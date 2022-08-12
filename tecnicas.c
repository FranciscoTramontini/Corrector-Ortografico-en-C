#include "tecnicas.h"

#include <stdlib.h>
#include <assert.h>
#include <wchar.h>
#include <wctype.h>

/**
 * Representa la cantidad mínima de sugerencias para cada palabra.
 */
#define CANT_SUGERENCIAS 5
/**
 * Representa la cantidad de técnicas aplicadas.
 */
#define CANT_TECNICAS_APLICADAS 3
/**
 * Representa el diccionario para reemplazar e insertar caracteres.
 */
#define ABECEDARIO L"abcdefghijklmnñopqrstuvwxyzáéíóúöü"

/**
 * Técnica caracteres adyacentes.
 */
Aux tecnica_caracteres_adyacentes(TablaHash *tabla, wchar_t *palabra, 
  int longitud, Aux aux) 
{
  for (int i = 0; i < longitud - 1; i++) 
  {
    wchar_t* temporal = malloc(sizeof (wchar_t) * longitud);
    assert(temporal);
    
    wcscpy(temporal, palabra);

    wchar_t temp = temporal[i];
    temporal[i] = palabra[i + 1];
    temporal[i + 1] = temp;
    
    if (tablahash_buscar(tabla, temporal) == 1)
    {
      if (aux->tecnicasAplicadas == 0 || (aux->tecnicasAplicadas > 0 && 
        aux->longitudSugerencias < CANT_SUGERENCIAS))
      {
        aux->sugerencias = slist_agregar_final(aux->sugerencias, 
          temporal);
        aux->longitudSugerencias = slist_longitud(aux->sugerencias);
      }
    }
    else
    {
      aux->noSugerencias = cola_encolar(aux->noSugerencias, temporal);
      aux->longitudNoSugerencias++;
    }
        
    free(temporal);
  }
  
  return aux;
}

/**
 * Técnica insertar carácter.
 */
Aux tecnica_insertar_caracter(TablaHash *tabla, wchar_t *palabra, 
  int longitud, Aux aux) 
{
  for (int i = 0; i < longitud; i++) 
  {
    for (int j = 0; ABECEDARIO[j] != '\0'; j++)
    {      
      wchar_t* temporal = malloc(sizeof (wchar_t) * (longitud + 1));
      assert(temporal);
      wcscpy(temporal, palabra);

      wchar_t temp = ABECEDARIO[j];
      
      for (int c = i; c < longitud; c++)
        temporal[c+1] = palabra[c];

      temporal[i] = temp;
      
      if (tablahash_buscar(tabla, temporal) == 1)
      {
         if (aux->tecnicasAplicadas == 0 || (aux->tecnicasAplicadas > 0 && 
           aux->longitudSugerencias < CANT_SUGERENCIAS))
        {
          aux->sugerencias = slist_agregar_final(aux->sugerencias, 
            temporal);
          aux->longitudSugerencias = slist_longitud(aux->sugerencias);
        }
      }
      else
      {
        aux->noSugerencias = cola_encolar(aux->noSugerencias, temporal);
        aux->longitudNoSugerencias++;
      }
      
      free(temporal);
    }
  }
  
  return aux;
}

/**
 * Técnica eliminar carácter.
 */
Aux tecnica_eliminar_caracter(TablaHash *tabla, wchar_t *palabra, 
  int longitud, Aux aux)
{
  for (int i = 0; i < longitud - 1; i++) 
  {
    wchar_t* temporal = malloc(sizeof (wchar_t) * longitud);
    assert(temporal);
    wcscpy(temporal, palabra);
    
    for( int c = i; c < longitud; c++) 
      temporal[c] = temporal[c+1];
    
    if (tablahash_buscar(tabla, temporal) == 1)
    {
      if (aux->tecnicasAplicadas == 0 || (aux->tecnicasAplicadas > 0 && 
        aux->longitudSugerencias < CANT_SUGERENCIAS))
      {
        aux->sugerencias = slist_agregar_final(aux->sugerencias, 
          temporal);
        aux->longitudSugerencias = slist_longitud(aux->sugerencias);
      }
    }
    else
    {
      aux->noSugerencias = cola_encolar(aux->noSugerencias, temporal);
      aux->longitudNoSugerencias++;
    }
    
    free(temporal);
  }
  
  return aux;
}

/**
 * Técnica reemplazar carácter.
 */
Aux tecnica_reemplazar_caracter(TablaHash *tabla, wchar_t *palabra, 
  int longitud, Aux aux)
{
  for (int i = 0; i < longitud - 1; i++) 
  {
    for (int j = 0; ABECEDARIO[j] != '\0'; j++) 
    {
      wchar_t* temporal = malloc(sizeof (wchar_t) * longitud);
      assert(temporal);
      
      wcscpy(temporal, palabra);

      wchar_t temp = ABECEDARIO[j];
      temporal[i] = temp;
      
      if (tablahash_buscar(tabla, temporal) == 1)
      {
         if (aux->tecnicasAplicadas == 0 || (aux->tecnicasAplicadas > 0 && 
           aux->longitudSugerencias < CANT_SUGERENCIAS))
        {
          aux->sugerencias = slist_agregar_final(aux->sugerencias, 
            temporal);
          aux->longitudSugerencias = slist_longitud(aux->sugerencias);
        }
      }
      else
      {
        aux->noSugerencias = cola_encolar(aux->noSugerencias, temporal);
        aux->longitudNoSugerencias++;
      }
      
      free(temporal);
    }
  }
  
  return aux;
}

/**
 * Técnica separar palabra.
 */
Aux tecnica_separar_palabras(TablaHash *tabla, wchar_t *palabra, 
int longitud, Aux aux)
{
  for (int i = 1; i < longitud - 1; i++) 
  {
    wchar_t *temporal = malloc(sizeof(wchar_t) * (longitud + 1));
    assert(temporal);
    
    wcscpy(temporal, palabra);

    temporal[i] = ' ';
    for (int c = i; c < longitud; c++)
      temporal[c+1] = palabra[c];

    wchar_t *aux1 = malloc(sizeof(wchar_t) * (i + 1));
    assert(aux1);

    wchar_t *aux2 = malloc(sizeof(wchar_t) * (longitud - i));
    assert(aux2);
    
    // Aca se usa el token de separación para copiar las dos palabras obtenidas
    // en dos variables definidas anteriormente
    wchar_t *ptr;
    wchar_t *temp = malloc(sizeof(wchar_t) * (longitud + 1));
    wcscpy(temp, temporal);
    wchar_t* token = wcstok(temp, L" ", &ptr);
    int i = 0;
    while(token)
    {
      if(i == 0)
        wcscpy(aux1, token);
      else
        wcscpy(aux2, token);
      
      i++;
      token = wcstok(NULL, L" ", &ptr);  
    }
    
    if ((tablahash_buscar(tabla, aux1) == 1) && 
      (tablahash_buscar(tabla, aux2) == 1))
    {
      aux->sugerencias = slist_agregar_final(aux->sugerencias, temporal);
      aux->longitudSugerencias = slist_longitud(aux->sugerencias);
    }
    
    free(temporal);
    free(temp);
    free(aux1);
    free(aux2);
  }
  
  return aux;
}

/**
 * Aplica todas las técnicas anteriores y llega hasta un mínimo de cinco
 * sugerencias, en caso que al aplicar las técnicas una vez y haya mas de cinco
 * sugerencias guarda todas las sugerencias.
 */
Aux sugerencias(TablaHash *tabla, wchar_t *palabra) 
{
  for (int i = 0; palabra[i] != '\0'; ++i) // Convierte la palabra a minuscula.
		palabra[i] = towlower(palabra[i]);     

  Aux aux = aux_crear();
  
  if (tablahash_buscar(tabla, palabra) == 1)
    return aux;

  int longitud = wcslen(palabra) + 1;
  aux = tecnica_caracteres_adyacentes(tabla, palabra, longitud, aux);
  aux = tecnica_insertar_caracter(tabla, palabra, longitud, aux);
  aux = tecnica_eliminar_caracter(tabla, palabra, longitud, aux);
  aux = tecnica_reemplazar_caracter(tabla, palabra, longitud, aux);
  aux = tecnica_separar_palabras(tabla, palabra, longitud, aux);
  
  aux->tecnicasAplicadas++;
  while (aux->longitudSugerencias < CANT_SUGERENCIAS && 
    aux->tecnicasAplicadas < CANT_TECNICAS_APLICADAS)
  {
    int temp = aux->longitudNoSugerencias;
    for (int i = 0; i <= temp && aux->longitudSugerencias < CANT_SUGERENCIAS; 
      aux->noSugerencias = aux->noSugerencias->sig, i++) 
    {
      wchar_t *primero = cola_primero(aux->noSugerencias);
      
      int longitud = wcslen(primero) + 1;
      wchar_t* temporal = malloc(sizeof(wchar_t) * longitud);
      assert(temporal);
      wcscpy(temporal, cola_primero(aux->noSugerencias));
      
      aux->noSugerencias = cola_desencolar(aux->noSugerencias);
      aux->longitudNoSugerencias--;
    
      if (aux->longitudSugerencias < CANT_SUGERENCIAS)
        aux = tecnica_caracteres_adyacentes(tabla, temporal, longitud, aux);
      if (aux->longitudSugerencias < CANT_SUGERENCIAS)
        aux = tecnica_insertar_caracter(tabla, temporal, longitud, aux);
      if (aux->longitudSugerencias < CANT_SUGERENCIAS)
        aux = tecnica_eliminar_caracter(tabla, temporal, longitud, aux);
      if (aux->longitudSugerencias < CANT_SUGERENCIAS)
        aux = tecnica_reemplazar_caracter(tabla, temporal, longitud, aux);
      
      free(temporal);
    }
    
    aux->tecnicasAplicadas++;
  }
  
  return aux;
}
