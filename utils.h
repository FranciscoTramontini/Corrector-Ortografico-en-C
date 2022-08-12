#ifndef __UTILS_H__
#define __UTILS_H__

#include <stddef.h>

/**
 * hash : wchar_t * -> unsigned
 * Funcion de hash para strings propuesta por Kernighan & Ritchie en "The C
 * Programming Language (Second Ed.)".
 */
unsigned hash(wchar_t *);


#endif  /* __UTILS_H__ */


