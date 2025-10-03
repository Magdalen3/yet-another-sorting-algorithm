CFLAGS= -lraylib

executable: main.c 
	gcc main.c $(CFLAGS) -o executable
