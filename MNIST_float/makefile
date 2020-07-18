CC = gcc
CFLAGS = -Wall -Wextra -O3 -std=c99
LDFLAGS =
OBJFILES = main.o ./digit/dataset.o test.o ./digit/extract.o ./neuron/neuralset.o ./neuron/match_unit.o learning.o parameter.o tool.o
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~
