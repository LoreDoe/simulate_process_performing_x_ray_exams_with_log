#include "log.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cria e inicializa uma estrutura de log.
Log *criar_log() 
{
    Log *log = (Log*)malloc(sizeof(Log));  // Aloca dinamicamente memória para a estrutura Log.
    log->count = 0;  // Inicializa o contador de eventos como zero.
    return log;  // Retorna o ponteiro para a estrutura de log criada.
}

// Registra um evento no log.
void registrar_evento(Log *log, const char *mensagem) 
{
    if (log->count < 1000)  // Verifica se ainda há espaço para mais eventos no log (limite de 1000).
    {
        EventoLog evento;
        strcpy(evento.mensagem, mensagem);  // Copia a mensagem para a estrutura do evento.
        evento.timestamp = time(NULL);  // Obtém o timestamp atual e atribui ao evento.
        log->eventos[log->count++] = evento;  // Adiciona o evento ao array de eventos no log.
    }
}

// Salva o log em um arquivo.
void salvar_log_em_arquivo(const Log *log, const char *filename) 
{
    FILE *arquivo = fopen(filename, "w");  // Abre um arquivo para escrita.

    if (arquivo != NULL)  // Verifica se o arquivo foi aberto com sucesso.
    {
        for (int i = 0; i < log->count; ++i)  // Itera sobre os eventos no log.
        {
            fprintf(arquivo, "[%ld] %s\n", log->eventos[i].timestamp, log->eventos[i].mensagem);  // Escreve no arquivo.
        }

        fclose(arquivo);  // Fecha o arquivo após a escrita.
    }
}
