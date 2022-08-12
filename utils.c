#include "utils.h"

/**
 * Funcion de hash para strings propuesta por Kernighan & Ritchie
 */
unsigned hash(wchar_t *s) 
{
  unsigned hashval;
  for (hashval = 0; *s != '\0'; ++s) {
    hashval = *s + 31 * hashval;
  }
  
  return hashval;
}
