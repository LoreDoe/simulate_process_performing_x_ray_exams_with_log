#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "log.h"

// Enumeração que representa os diferentes tipos de patologias
typedef enum {
    SAUDE_NORMAL,
    BRONQUITE,
    PNEUMONIA,
    FRACTURA_FEMUR,
    APENDICITE
} PatologiaTipo;

// Estrutura que define uma patologia com seu nome, probabilidade de ocorrência e nível de gravidade
typedef struct {
    char nome[50];
    float probabilidade_ocorrencia;
    int nivel_gravidade;
} Patologia;

// Lista de patologias disponíveis
extern Patologia lista_patologias[5];

// Estrutura que define um paciente com nome, CPF, idade e ID
typedef struct {
    char nome[50];
    char cpf[15];
    int idade;
    int id;
} Paciente;

// Estrutura que define um exame com ID, timestamp e condição (patologia)
typedef struct {
    int id;
    time_t timestamp;
    PatologiaTipo condicao;
} Exame;

// Estrutura que define um hospital com listas de pacientes, exames e laudos, além de contadores
typedef struct {
    Paciente pacientes[1000];
    int count;
    Exame exames[1000];
    int count_exames;
    Exame laudos[1000];
    int count_laudos;
} Hospital;

// Função para inicializar as patologias na lista_patologias
void inicializar_patologias();

// Função para lidar com a chegada de pacientes ao hospital
void lidar_com_chegada_paciente(Hospital *hospital, Log *log);

// Função para lidar com a realização de exames no hospital
void lidar_com_exames(Hospital *hospital, Log *log);

// Função para lidar com a realização de laudos no hospital
void lidar_com_laudo(Hospital *hospital, Log *log);

// Função para simular o tempo no hospital, incluindo chegada de pacientes, exames e laudos
void simular_tempo(Hospital *hospital, Log *log);

// Função para relatar métricas, como tempo médio de laudo e quantidade de exames após um limite de tempo
void relatar_metricas(const Hospital *hospital, Log *log);

// Função para registrar métricas no log, como tempo médio de laudo
void registrar_metricas_log(const Hospital *hospital, Log *log, int limite_tempo);

// Função para calcular o tempo médio de laudo
float calcular_tempo_medio_laudo(const Hospital *hospital);

// Função para calcular o tempo médio de laudo por patologia específica
float calcular_tempo_medio_laudo_por_patologia(const Hospital *hospital, PatologiaTipo patologia);

// Função para contar o número de exames realizados após um limite de tempo específico
int contar_exames_apos_limite_tempo(const Hospital *hospital, int limite_tempo);

#endif
