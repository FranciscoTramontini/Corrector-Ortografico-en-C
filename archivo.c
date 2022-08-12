#include "archivo.h"
#include "tecnicas.h"

#include <stdlib.h>
#include <assert.h>
#include <wchar.h>
#include <wctype.h>

/**
 * Abre el archivo en la forma pedida y verifica que se abra correctamente.
 */
FILE* archivo_abrir(char *nombreArchivo, char *forma)
{
  FILE *archivo;
  if (! (archivo = fopen(nombreArchivo, forma))) 
  {
    printf("Error al abrir el archivo %s\n", nombreArchivo);
    exit(1);
  }
  
  return archivo;
}

/**
 * Archivo que completa las sugerencias.
 */
void archivo_salida(Aux aux, FILE *archivo, wchar_t *palabra, int linea)
{
  if (aux->sugerencias != NULL || aux->tecnicasAplicadas > 0)
  {
    if (aux->sugerencias != NULL)
      for (int i = 0; palabra[i] != '\0'; ++i) //Escribe la palabra en mayúscula
        palabra[i] = towupper(palabra[i]);
    
    fwprintf(archivo, 
      L"Linea %d, ''%ls'' no esta en el diccionario.\nQuizas quiso decir: ", 
      linea, palabra);
    
    if (aux->sugerencias != NULL)
    {
      SNodo* nodo = aux->sugerencias;
      for (; nodo->sig != NULL; nodo = nodo->sig) 
        fwprintf(archivo, L"%ls, ", nodo->dato);
      
      // Para estética en el archivo de salida, sin la coma al final
      fwprintf(archivo, L"%ls\n\n", nodo->dato); 
    }
    else
      fwprintf(archivo, L"\n\n");
  }
  
  aux_destruir(aux);
}

/**
 * Archivo que devuelve todas las sugerencias de las palabras que no están.
 */
void corrector_ortografico(TablaHash *tabla, char *archivoEntrada, 
  char *archivoSalida) 
{
  FILE *texto = archivo_abrir(archivoEntrada, "r");
  FILE *archivoSugerencias = archivo_abrir(archivoSalida, "w");
  
  wchar_t temp[80];
  int linea = 1;
  while (fwscanf(texto, L"%ls", temp) != EOF) 
  {
    int longitudLinea = wcslen(temp) + 1;

    wchar_t* palabra = malloc(sizeof(wchar_t) * longitudLinea);
    assert(palabra);
    wcscpy(palabra, temp);
    
    // Se le quita los caracteres especiales más usados
    palabra[wcscspn(palabra, L":")] = L'\0';
    palabra[wcscspn(palabra, L";")] = L'\0';
    palabra[wcscspn(palabra, L",")] = L'\0';
    palabra[wcscspn(palabra, L".")] = L'\0';
    palabra[wcscspn(palabra, L"?")] = L'\0';
    palabra[wcscspn(palabra, L"!")] = L'\0';

    if (wcscmp(palabra, L"\0") != 0)
    {
      Aux aux = sugerencias(tabla, palabra); // Se busca las sugerencias
      archivo_salida(aux, archivoSugerencias, palabra, linea);
    }
    
    free(palabra);
    
    if (fgetwc(texto) == L'\n') // Se ve si hubo un salto de línea
      linea++;
  }
  
  archivo_cerrar(texto);
  archivo_cerrar(archivoSugerencias);
}

/**
 * Se cierra el archivo.
 */
void archivo_cerrar(FILE *archivo)
{
  fclose(archivo);  
}
