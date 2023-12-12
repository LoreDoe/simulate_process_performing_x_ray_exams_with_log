#ifndef HOSPITAL_H
#define HOSPITAL_H

#define MAX_PATIENTS 100
#define MAX_EXAMS 100
#define MAX_RADIOLOGISTS 3

// Definição da estrutura de dados para representar um paciente.
typedef struct
{
    int id;           // Identificador único do paciente.
    char name[30];    // Nome do paciente.
    char cpf[12];     // Número do CPF do paciente.
    int age;          // Idade do paciente.
} Patient;

// Definição da estrutura de dados para representar uma patologia.
typedef struct
{
    int id;              // Identificador único da patologia.
    char name[30];       // Nome da patologia.
    double probability;  // Probabilidade de ocorrência.
    int severity;        // Gravidade da patologia.
} Pathology;

// Definição da estrutura de dados para representar um exame.
typedef struct
{
    int patientId;      // Identificador do paciente associado ao exame.
    int timestamp;      // Timestamp do momento em que o exame foi realizado.
    char condition[30]; // Condição ou patologia identificada no exame.
} Exam;

// Definição da estrutura de dados para representar um radiologista.
typedef struct
{
    int id;    // Identificador único do radiologista.
    int busy;  // Flag indicando se o radiologista está ocupado.
} Radiologist;

// Função principal que simula o funcionamento do hospital ao longo do tempo.
void mainHospital(int sleepDuration);

// Função para inicializar o estado dos radiologistas.
void initializeRadiologists();

// Função que simula a chegada de pacientes ao hospital.
void arrivalOfPatients(int time);

// Função que simula a realização de exames de raio-X pelos radiologistas.
void performExams(int time);

// Função que simula a geração de laudos médicos com base nos resultados dos exames.
void performReports(int time);

// Função que exibe métricas de desempenho a cada intervalo de tempo.
void displayMetrics(int time);

// Função para gerar um nome aleatório.
char *generateRandomName();

// Função para gerar um número de CPF aleatório.
char *generateRandomCPF();

// Função para gerar uma idade aleatória.
int generateRandomAge();

// Função para gerar uma patologia aleatória.
Pathology generateRandomPathology();

// Função para gerar dados de um paciente com um ID específico.
Patient generateRandomPatient(int id);

// Função para gerar um exame para um paciente em um determinado timestamp.
Exam generateRandomExam(int patientId, int timestamp);

#endif
