#include "hospital.h"

int main() 
{
    // Cria uma instância da estrutura Hospital para representar o hospital.
    Hospital hospital; 

    // Cria um log para registrar eventos relacionados às operações do hospital.
    Log *log = criar_log(); 
  
    // Inicializa as estruturas e variáveis do hospital.
    inicializar_hospital(&hospital);
  
    // Realiza uma simulação de eventos ao longo do tempo no hospital.
    simular_tempo(&hospital, log); 

    // Gera relatórios e métricas com base nas operações realizadas no hospital.
    relatar_metricas(&hospital, log); 

    // Salva o log em um arquivo chamado "log.txt".
    salvar_log_em_arquivo(log, "log.txt"); 

    // Libera a memória alocada dinamicamente para o log.
    free(log); 

    return 0; // Retorna 0 para indicar que o programa foi executado com sucesso.
}
