# Corrector-Ortografico-en-C

## En la carpeta del programa se encuentra:
  - slist.h, slist.c : contiene las funciones para una LSE (Lista Simplemente
                       Enlazada).
  - cola.h, cola.c : contiene las funciones para una Cola mediante una LCDE
                     (Lista Circular Doblemente Enlazada).
  - aux.h, aux.c : contiene las funciones para una estructura que contendrá
                   las sugerencias y no sugerencias de una palabra.
  - avl.h, avl.c : contiene las funciones para un AVL.
  - utils.h, utils.c : contiene la función hash para una tabla hash.
  - tablahash.h, tablahash.c : contiene las funciones para la tabla hash,
                               además contiene la función de leer el
                               diccionario que viene en un archivo.
  -archivo.h, archivo.c : contiene las funciones para archivos, además contiene
                          la función para escribir el archivo final y el
                          corrector ortográfico.
  tecnicas.h, tecnicas.c : contiene las técnicas pedidas por el trabajo, además
                           contiene la función para calcular las sugerencias y
                           no sugerencias.
  main.c : función principal del programa.
  makefile : para correr el programa.


## Compilación y ejecución del programa:

  Compilación:
    Se utiliza gcc. Abrir la terminal de comandos donde se encuentran los 
    archivos del programa y luego ingresar la siguiente función:
      ....$ make

  Ejecución:
    El resultado anterior nos da un ejecutable. El mismo lo corremos de la
    siguiente manera (seguir leyendo para saber que contiene los archivos)
      .... $ ./main archivoEntrada.txt archivoSalida.txt
 
  *) archivoEntrada.txt:
    Es un archivo que se tendrá que encontrar dentro de la carpeta donde se
    encuentran los archivos del programa. Este archivo contiene el texto a
    ser analizado por el corrector.
    Puede tener múltiples líneas de texto. Cada una de ellas pueden tener 
    varias palabras, las cuales estarán separadas por un solo espacio; también 
    pueden estar los siguientes carácteres especiales inmediatamente a 
    continuación de una palabra, los cuales deben ser ignorados: 
    “:”, “;”, “,”, “.”, “?”, “!”.
    También, en el archivo de entrada podrían existir líneas vacías. Considere
    que las palabras podrı́an estar escritas con mayúsculas, minúsculas, o una
    mezcla de ambas.

  *) archivoSalida.txt:
    No hace falta que sea creado, se creará automáticamente cuando una palabra
    no este en el diccionario y asi sucesivamente con las demas palabras.
    Por cada palabra no incluida en nuestro diccionario que encontremos en el
    archivo de entrada, se deberá imprimir un bloque como se indica a 
    continuación. Al final de cada bloque se deberá imprimir una línea vacía 
    para separar.

    El bloque debe decir:
    Linea N, "PALABRA" no esta en el diccionario.
    Quizas quiso decir: SUGERENCIA_1 , SUGERENCIA_2 , ... , SUGERENCIA_N


## Estructuras de datos elegidas para el trabajo y otras observaciones sobre el
código:

  *  Elegí para guardar las palabras del diccionario una Tabla Hash que 
  consiste en un arreglo de 1689 casillas donde en cada casilla hay un AVL, de 
  esta forma, evitamos las colisiones. Cuando a una palabra se le asigna su 
  índice mediante la función de hash, la palabra es insertada en el AVL y así 
  de esta forma se hace mas rápida la búsqueda de palabras en el diccionario.

  *   Para las funciones que trabajan con strings se usa la librería "wchar.h"
  que nos permite facilitar el problema de caracteres especiales tales como
  la 'ñ', las palabras acentuadas, etc.

  *   Idea para la generación de sugerencias:
  Cuando una palabra leída desde el archivo de entrada no es encontrada en el 
  diccionario debemos generar distintas sugerencias posibles para esa palabra.
  La idea para realizar esto es la siguiente:

  Se toma la palabra a buscar, si no está en el diccionario se le aplican las
  cinco técnicas dadas en el trabajo práctico y si algunas de esas sugerencias
  se encuentran en el diccionario se guardan en una LSE (Lista Simplemente
  Enlazada), las que no se encuentren se guardarán en una Cola 
  (Lista Circulares Doblemente Enlazada), salvo las que no se encuentren en la 
  técnica de separar palabras.
  Si la cantidad de sugerencias es cinco o mayor el archivo se imprimirán todas
  las sugerencias dadas, en cambio, cuando no supera las 5 sugerencias se 
  vuelve a aplicar las cuatro técnicas (se saca la técnica de separar palabras) 
  las veces que sean necesarias hasta llegar a las 5 sugerencias.
  Una vez hecho esto se imprime en el archivo de salida, se vacía todo y vuelve
  a comenzar con una nueva palabra del archivo de entrada, así sucesivamente
  hasta terminar.


  *) Observación: debido a la enorme cantidad de palabras que se generan con 
  las sugerencias es probable que suceda que si al programa se le da una 
  palabra larga (con longitud mayor a 7 u 8 aproximadamente), el mismo tarde en 
  generar las sugerencias o incluso puede pasar que no se pueda terminar la 
  ejecución debido a la falta de memoria que es necesaria para generar y 
  guardar tantas palabras.
