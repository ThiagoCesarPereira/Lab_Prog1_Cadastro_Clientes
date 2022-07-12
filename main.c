#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "gestao.h"
#define MAX_CLI 1000/*Constante que define o tamanho do meu vetor de struct. Pode ser alterado pelo gestor que o programa funcionará normalmente*/

int main()
{
    setlocale(LC_ALL,"Portuguese");

    CLIENTES cliente[MAX_CLI];

    tela_inicial();

    inicializaClientes(cliente, MAX_CLI);

    menu(cliente, MAX_CLI);

    return 0;
}

