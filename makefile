CC = gcc #Compilador
CFLAGS = -Wall -Wextra -Werror -std=c99 -g #Banderas de compilación

main: main.c slist.o cola.o aux.o avl.o utils.o tablahash.o tecnicas.o archivo.o
	$(CC) $(CFLAGS) -o main main.c slist.o cola.o aux.o avl.o utils.o tablahash.o tecnicas.o archivo.o
archivo.o: archivo.c archivo.h
	$(CC) $(CFLAGS) -c archivo.c
tecnicas.o: tecnicas.c tecnicas.h
	$(CC) $(CFLAGS) -c tecnicas.c
tablahash.o: tablahash.c tablahash.h
	$(CC) $(CFLAGS) -c tablahash.c
utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c
avl.o: avl.c avl.h
	$(CC) $(CFLAGS) -c avl.c
aux.o: aux.c aux.h
	$(CC) $(CFLAGS) -c aux.c
cola.o: cola.c cola.h
	$(CC) $(CFLAGS) -c cola.c
slist.o: slist.c slist.h
	$(CC) $(CFLAGS) -c slist.c
