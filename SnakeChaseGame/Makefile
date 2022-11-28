CC = gcc
CFLAGS = -Wall -pedantic -ansi -g
OBJ = program.o gameOperations.o interface.o terminal.o map.o mapsize.o print.o linkedList.o
EXEC = maze


$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

program.o : program.c gameOperations.h interface.h mapsize.h
	$(CC) -c program.c $(CFLAGS)
	
gameOperations.o : gameOperations.c terminal.h print.h linkedList.h
	$(CC) -c gameOperations.c $(CFLAGS)
	
interface.o : interface.c map.h 
	$(CC) -c interface.c $(CFLAGS)
	
terminal.o : terminal.c terminal.h
	$(CC) -c terminal.c $(CFLAGS)
	
map.o : map.c map.h
	$(CC) -c map.c $(CFLAGS)

mapsize.o : mapsize.c mapsize.h
	$(CC) -c mapsize.c $(CFLAGS)

print.o : print.c print.h
	$(CC) -c print.c $(CFLAGS)

linkedList.o : linkedList.c linkedList.h
	$(CC) -c linkedList.c $(CFLAGS)

clean: 
	rm -f $(EXEC) $(OBJ)
