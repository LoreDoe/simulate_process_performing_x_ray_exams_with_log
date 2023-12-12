#include "hospital.h"
#include "log.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Criação do log e redirecionamento da saída
    Log *log = criar_log();

    // Chamada da função principal com sleep de 1 segundo
    mainHospital(1);

    // Salva o log em um arquivo
    salvar_log_em_arquivo(log, "log.txt");

    // Libera a memória alocada para o log
    liberar_memoria_log(log);

    return 0;
}
