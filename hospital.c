#include "hospital.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

Patologia lista_patologias[5];

// Função para inicializar a estrutura do hospital
void inicializar_hospital(Hospital *hospital) 
{
    // Inicializa a lista de patologias
    inicializar_patologias();

    // Zera os contadores do hospital
    hospital->count = 0;
    hospital->count_exames = 0;
    hospital->count_laudos = 0;
}

// Função para inicializar a lista de patologias com valores predefinidos
void inicializar_patologias() 
{
    strcpy(lista_patologias[0].nome, "Saúde Normal");
    lista_patologias[0].probabilidade_ocorrencia = 0.3;
    lista_patologias[0].nivel_gravidade = 1;

    strcpy(lista_patologias[1].nome, "Bronquite");
    lista_patologias[1].probabilidade_ocorrencia = 0.2;
    lista_patologias[1].nivel_gravidade = 2;

    strcpy(lista_patologias[2].nome, "Pneumonia");
    lista_patologias[2].probabilidade_ocorrencia = 0.2;
    lista_patologias[2].nivel_gravidade = 3;

    strcpy(lista_patologias[3].nome, "Fratura de Fêmur");
    lista_patologias[3].probabilidade_ocorrencia = 0.15;
    lista_patologias[3].nivel_gravidade = 4;

    strcpy(lista_patologias[4].nome, "Apendicite");
    lista_patologias[4].probabilidade_ocorrencia = 0.15;
    lista_patologias[4].nivel_gravidade = 4;
}

// Função para lidar com a chegada de pacientes
void lidar_com_chegada_paciente(Hospital *hospital, Log *log) 
{
    // Simula a chegada de pacientes com uma probabilidade de 20%
    if (rand() % 100 < 20) {
        // Cria um novo paciente e preenche os detalhes
        Paciente novo_paciente;
        novo_paciente.id = hospital->count + 1;
        hospital->pacientes[hospital->count++] = novo_paciente;

        // Adiciona o paciente à fila de exames
        hospital->exames[hospital->count_exames].id = novo_paciente.id;
        hospital->exames[hospital->count_exames].timestamp = time(NULL);
        hospital->exames[hospital->count_exames].condicao = SAUDE_NORMAL;
        hospital->count_exames++;

        // Registra a chegada do paciente no log
        char mensagem[256];
        sprintf(mensagem, "Chegou paciente %d para exame", novo_paciente.id);
        registrar_evento(log, mensagem);
    }
}

void registrar_metricas_log(const Hospital *hospital, Log *log, int limite_tempo)
{
}

// Função para lidar com a realização de exames
void lidar_com_exames(Hospital *hospital, Log *log) 
{
    // Simula a realização de exames
    for (int i = 0; i < hospital->count_exames; ++i) 
    {
        // Simula a conclusão do exame
        Exame exame_concluido = hospital->exames[i];
        hospital->count_exames--;

        // Adiciona o exame à fila de laudo
        hospital->laudos[hospital->count_laudos++] = exame_concluido;

        // Registra a conclusão do exame no log
        char mensagem[256];
        sprintf(mensagem, "Exame para paciente %d concluído", exame_concluido.id);
        registrar_evento(log, mensagem);
    }
}

// Função para lidar com a realização de laudos
void lidar_com_laudo(Hospital *hospital, Log *log) 
{
    // Simula a realização de laudos
    const int radiologistas_disponiveis = 3;
    int radiologistas_alocados = 0;

    // Itera sobre os exames na fila de laudo
    for (int i = 0; i < hospital->count_laudos && radiologistas_alocados < radiologistas_disponiveis; ++i) 
    {
        // Simula a conclusão do laudo
        Exame laudo_concluido = hospital->laudos[i];
        hospital->count_laudos--;

        // Calcula o tempo de preparo do laudo
        int tempo_preparo_laudo = rand() % 21 + 10;

        // Atualiza o timestamp para incluir o tempo de preparo do laudo
        laudo_concluido.timestamp += tempo_preparo_laudo;

        // Registra o evento no log
        char mensagem[256];
        sprintf(mensagem, "Laudo para Paciente%d concluído (Tempo de Preparo: %d unidades)", laudo_concluido.id, tempo_preparo_laudo);
        registrar_evento(log, mensagem);

        radiologistas_alocados++;
    }
}

// Função para simular o tempo (unidades de 10 em 10)
void simular_tempo(Hospital *hospital, Log *log) 
{
    // Inicializa a semente para geração de números pseudoaleatórios
    srand(time(NULL));

    // Simula o tempo até 43200 unidades de tempo
    for (int tempo = 0; tempo < 43200; tempo += 10) 
    {
        // Chama as funções para lidar com a chegada de paciente, exames, laudos, e relatar métricas a cada 10 unidades de tempo
        lidar_com_chegada_paciente(hospital, log);
        lidar_com_exames(hospital, log);
        lidar_com_laudo(hospital, log);

        if (tempo % 10 == 0) {
            relatar_metricas(hospital, log);
        }
    }
}

// Função para relatar métricas
void relatar_metricas(const Hospital *hospital, Log *log) 
{
    // Calcula e relata métricas a cada 10 unidades de tempo
    float tempo_medio_laudo = calcular_tempo_medio_laudo(hospital);
    float tempo_medio_laudo_patologia = calcular_tempo_medio_laudo_por_patologia(hospital, SAUDE_NORMAL);  // Exemplo com Saúde Normal
    int exames_apos_limite_tempo = contar_exames_apos_limite_tempo(hospital, 7200);

    // Registra as métricas no log
    registrar_metricas_log(hospital, log, 7200);
    char mensagem[256];
    sprintf(mensagem, "Tempo médio de laudo: %.2f unidades", tempo_medio_laudo);
    registrar_evento(log, mensagem);

    sprintf(mensagem, "Tempo médio de laudo por patologia: %.2f unidades", tempo_medio_laudo_patologia);
    registrar_evento(log, mensagem);

    sprintf(mensagem, "Quantidade de exames realizados após o limite de tempo estabelecido: %d", exames_apos_limite_tempo);
    registrar_evento(log, mensagem);
}

// Função para calcular o tempo médio de laudo
float calcular_tempo_medio_laudo(const Hospital *hospital) 
{
    float tempo_total = 0.0;

    for (int i = 0; i < hospital->count_laudos; ++i) 
    {
        tempo_total += hospital->laudos[i].timestamp - hospital->laudos[i].timestamp;
    }

    return hospital->count_laudos > 0 ? tempo_total / hospital->count_laudos : 0.0;
}

// Função para calcular o tempo médio de laudo por patologia
float calcular_tempo_medio_laudo_por_patologia(const Hospital *hospital, PatologiaTipo patologia) 
{
    float tempo_total = 0.0;
    int count_patologia = 0;

    for (int i = 0; i < hospital->count_laudos; ++i) 
    {
        if (hospital->laudos[i].condicao == patologia) 
        {
            tempo_total += hospital->laudos[i].timestamp - hospital->laudos[i].timestamp;
            count_patologia++;
        }
    }

    return count_patologia > 0 ? tempo_total / count_patologia : 0.0;
}

// Função para contar exames realizados após o limite de tempo estabelecido
int contar_exames_apos_limite_tempo(const Hospital *hospital, int limite_tempo) 
{
    int count_exames_apos_limite = 0;

    for (int i = 0; i < hospital->count_laudos; ++i) 
    {
        if (hospital->laudos[i].timestamp > limite_tempo) 
        {
            count_exames_apos_limite++;
        }
    }

    return count_exames_apos_limite;
}
