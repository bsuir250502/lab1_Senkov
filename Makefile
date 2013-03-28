OBJ = main.o lib1.o
CFLAGS = -Wall -std=c99
EXECUTABLE_NAME = bin

all: $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME): $(OBJ)
	gcc $(CFLAGS) $(OBJ) -o $(EXECUTABLE_NAME)

%.o : %.c
	gcc $(CFLAGS) -c $<

clean:
	rm $(EXECUTABLE_NAME) $(OBJ)
