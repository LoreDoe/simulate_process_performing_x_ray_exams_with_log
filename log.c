#include "log.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para criar e inicializar uma estrutura de log
Log* criar_log() {
    Log *log = (Log*)malloc(sizeof(Log));
    log->count = 0;
    return log;
}

// Função para registrar um evento no log
void registrar_evento(Log *log, const char *mensagem) {
    // Verificar se ainda há espaço para mais eventos no log (limite de 1000)
    if (log->count < 1000) {
        EventoLog evento;
        // Copiar a mensagem para a estrutura do evento
        strcpy(evento.mensagem, mensagem);
        // Obter o timestamp atual e atribuir ao evento
        evento.timestamp = time(NULL);
        // Adicionar o evento ao array de eventos no log
        log->eventos[log->count++] = evento;
    }
}

// Função para salvar o log em um arquivo
void salvar_log_em_arquivo(const Log *log, const char *filename) {
    // Abrir um arquivo para escrita
    FILE *arquivo = fopen(filename, "w");
    // Verificar se o arquivo foi aberto com sucesso
    if (arquivo != NULL) {
        // Iterar sobre os eventos no log e escrever no arquivo
        for (int i = 0; i < log->count; ++i) {
            fprintf(arquivo, "[%ld] %s\n", log->eventos[i].timestamp, log->eventos[i].mensagem);
        }
        // Fechar o arquivo após a escrita
        fclose(arquivo);
    }
}
