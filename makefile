CC = gcc
CFLAGS = -Wall -Wextra -O3 -std=c99
LDFLAGS =
OBJFILES_C = MNIST_char/main.o MNIST_char/digit/dataset.o MNIST_char/test.o MNIST_char/digit/extract.o MNIST_char/neuron/neuralset.o MNIST_char/neuron/match_unit.o MNIST_char/learning.o MNIST_char/parameter.o MNIST_char/tool.o

OBJFILES_F = MNIST_float/main.o MNIST_float/digit/dataset.o MNIST_float/test.o MNIST_float/digit/extract.o MNIST_float/neuron/neuralset.o MNIST_float/neuron/match_unit.o MNIST_float/learning.o MNIST_float/parameter.o MNIST_float/tool.o

TARGET = main

all: $(TARGET)

$(TARGET): $(OBJFILES_C)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES_C) $(LDFLAGS)

## COMPILATION POUR CHAR ##
char:  $(OBJFILES_C)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES_C) $(LDFLAGS)

## COMPILATION POUR FLOAT ##
float:  $(OBJFILES_F)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES_F) $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(OBJFILES_C) $(TARGET) *~
	rm -f $(OBJFILES_F) $(TARGET) *~
