CC = gcc
SRC = *.c
DEPS = *.h
OBJ = *.o

%.o: %.c $(DEPS)
	$(CC) -c $(SRC)

TP : $(OBJ)
	$(CC) -o TP $(SRC)
	./TP
	rm TP $(OBJ)