CC = g++
DEPS = init.h basicFunctions.h
OBJ = main.o basicFunctions.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@.out $^ $(CFLAGS)

