CC = gcc
CFLAGS = -Wall -g

# Nazwa pliku wynikowego (programu)
TARGET = main

# Pliki obiektowe potrzebne do zbudowania programu
# DODANO: djikstra.o
OBJS = main.o struct.o djikstra.o

# Reguła domyślna: buduj program
all: $(TARGET)

# Linkowanie (łączenie plików .o w program)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Kompilacja main.c -> main.o
main.o: main.c struct.h djikstra.h
	$(CC) $(CFLAGS) -c main.c

# Kompilacja struct.c -> struct.o
struct.o: struct.c struct.h
	$(CC) $(CFLAGS) -c struct.c

# DODANO: Kompilacja djikstra.c -> djikstra.o
djikstra.o: djikstra.c djikstra.h struct.h
	$(CC) $(CFLAGS) -c djikstra.c

# Czyszczenie (usuwanie plików tymczasowych)
clean:
	rm -f *.o $(TARGET)