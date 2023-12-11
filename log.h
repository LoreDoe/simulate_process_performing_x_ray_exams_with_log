#ifndef LOG_H
#define LOG_H

#include <time.h>

// Estrutura para armazenar informações sobre um evento de log
typedef struct {
    char mensagem[256];  // Mensagem do evento
    time_t timestamp;     // Timestamp do evento 
} EventoLog;

// Estrutura para representar um log que armazena uma lista de eventos
typedef struct {
    EventoLog eventos[1000];  // Array para armazenar até 1000 eventos
    int count;                // Contador para acompanhar o número de eventos atualmente no log
} Log;

// Função para criar e inicializar uma estrutura de log
Log* criar_log();

// Função para registrar um evento no log
void registrar_evento(Log *log, const char *mensagem);

// Função para salvar o log em um arquivo
void salvar_log_em_arquivo(const Log *log, const char *filename);

#endif
