CC = gcc
CFLAGS = -Wall -Wextra

# Listar todos os arquivos fonte
SRC_FILES = hospital.c log.c main.c

# Gerar os nomes dos arquivos objetos
OBJ_FILES = $(SRC_FILES:.c=.o)

# Nome do executável
EXECUTABLE = hospital_simulation

all: $(EXECUTABLE)

# Regra para compilar os arquivos objetos
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para o executável
$(EXECUTABLE): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

# Limpeza
clean:
	rm -f $(OBJ_FILES) $(EXECUTABLE)
