#include "tablahash.h"
#include "archivo.h"

#include <stdlib.h>
#include <locale.h>

/**
 * Función principal del programa.
 * Los argumentos son los pasados después del ./main, tienen que ser dos
 * el nombre del archivo donde está el texto a corregir (debe existir en la
 * carpeta donde estan los archivos y llamarlo tal cual figura),
 * el nombre del archivo donde se guardaran las sugerencias si es que hay.
 * (se puede poner solo nombre sin agregarle el formato .txt, etc.)
 * 
 * Aclaración:
 * La compilación y ejecución del programa se deja en el README.txt que se
 * encuentra en la carpeta del programa.
 */
int main(int argc, char **argv) 
{
  setlocale(LC_ALL, "");
   
  if ((argc > 3) || (argc <= 2)) 
  {
    puts("Error al pasar argumentos, el maximo de argumentos es 2");
    exit(1);
  }
  
  if (argc == 3) 
  {
    TablaHash *diccionario = tablahash_leer_diccionario("diccionario.txt");
    corrector_ortografico(diccionario, argv[1], argv[2]);
    tablahash_destruir(diccionario);
  }
  
  return 0;
}
