CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SOURCES = hospital.c log.c main.c
HEADERS = hospital.h log.h
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = hospital_simulation

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE)

hospital.o: hospital.c hospital.h log.h
	$(CC) $(CFLAGS) -c hospital.c

log.o: log.c log.h
	$(CC) $(CFLAGS) -c log.c

main.o: main.c hospital.h log.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
