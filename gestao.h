#include "estrutura.c"
#include "menu.h"
/*------------------------- FUNÇÃO PARA INICIALIZAR MEU VETOR DE STRUCT --------------------------*/
void inicializaClientes(CLIENTES cliente[], int MAX_CLI)
{
    int i=0;
    /*PERCORRE O MEU VETOR DE STRUCT E INICALIZA OS ELEMENTOS ID COM MAX_CLI+1 E COLOCA ATIVO ZERO*/
    for(i=0; i<MAX_CLI; i++)
    {
        cliente[i].id=MAX_CLI+1;
        cliente[i].ativo=0;
    }
}

/*--------------- FUNÇÃO PARA NAVEGAR NO SISTEMA DE ACORDO COM A OPÇÃO DO USUÁRIO ----------------*/
void decisao(CLIENTES cliente[], int MAX_CLI, int opcao)
{
    int op = opcao;
    switch(op)
    {
    case 1:
        listarClientes(cliente, MAX_CLI);
        break;
    case 2:
        cadastrarCliente(cliente, MAX_CLI);
        break;
    case 3:
        excluirCliente(cliente, MAX_CLI);
        break;
    case 4:
        atualizarCliente(cliente, MAX_CLI);
        break;
    case 0:
        menu(cliente, MAX_CLI);
        break;
    case 9:
        obrigado();
        break;
    default:
        printf("Opção inválida!\n\n");
        system("pause");
        menu(cliente, MAX_CLI);
    }
}


/*------------------------------ FUNÇÃO PARA O CADASTRO DE CLIENTES ------------------------------*/
void cadastrarCliente(CLIENTES cliente[], int MAX_CLI)
{
    int i = 0, opcao=0;

    //Como inicializei o vetor de struct com MAX_CLI+1, se o id for diferente deste valor é porque tem cliente cadastrado
    //Verifica até encontrar a posição onde não tem cliente cadastrado para pode iniciar a inclusão a partir ela
    while(cliente[i].id != (MAX_CLI+1))
    {
        i++;
    }

    do
    {
        system("cls");
        printf("\t\t--------------------------------------\n");
        printf("\t\t         CADASTRO DE CLIENTE          \n");
        printf("\t\t--------------------------------------\n");
        cliente[i].id = i+1;
        fflush(stdin);

        cliente[i].ativo=1;

        printf("Nome: ");
        gets(cliente[i].nome);

        printf("CPF: ");
        gets(cliente[i].cpf);

        printf("Sexo: ");
        gets(cliente[i].sexo);

        printf("Data de nascimento: ");
        gets(cliente[i].dataNascimento);

        printf("TELEFONE: ");
        gets(cliente[i].telefone);

        printf("\nCliente cadastrado com sucesso!\n\n");
        printf("\t\t--------------------------------------\n");
        printf("\t\t                  MENU                \n");
        printf("\t\t--------------------------------------\n");
        printf("\t\t[1] Visualizar clientes cadastrados \n");
        printf("\t\t[2] Cadastrar outro cliente \n");
        printf("\t\t[3] Excluir cliente cadastrado \n");
        printf("\t\t[4] Atualizar cliente\n\n");
        printf("\t\t[0] Voltar o menu inicial \n");
        printf("\t\t[9] Sair do sistema\n");
        printf("\t\t--------------------------------------\n");
        printf("\t\t- > ");
        scanf("%d", &opcao);
        fflush(stdin);
        i++;
    }
    while(opcao==2);

    decisao(cliente, MAX_CLI, opcao);

}

/*------------------------------- FUNÇÃO PARA O LISTAR OS CLIENTES -------------------------------*/
void listarClientes(CLIENTES cliente[], int MAX_CLI)
{
    int i=0;
    int contador = 0;
    int opcao;

    system("cls");
    printf("\t\t--------------------------------------\n");
    printf("\t\t          CLIENTES CADASTRADOS        \n");
    printf("\t\t--------------------------------------\n");

    for(i=0; i<MAX_CLI; i++)
    {
        /*Percorre o vetor com os dados do cliente. Caso o cliente eteja ativo mostra os dados*/
        if(cliente[i].ativo==1)
        {
            printf("-----------\n");
            printf("[id] - %d\n", cliente[i].id);
            printf("-----------\n");
            printf("[Nome] - %s", cliente[i].nome);
            printf("\n");
            printf("[CPF] - %s", cliente[i].cpf);
            printf("\n");
            printf("[Sexo] - %s", cliente[i].sexo);
            printf("\n");
            printf("[Data de nascimento] - %s", cliente[i].dataNascimento);
            printf("\n");
            printf("[Telefone] - %s", cliente[i].telefone);
            printf("\n");
            printf("\n");
        }
        /*Conta quantos clientes não estão ativos/excluídos.*/
        else
        {
            contador++;
        }
    }
    /*Se a quantidade de clientes inaivos/excluídos for igual ao tamnho do vetor é porque não existem clientes cadastrados*/
    if(contador == MAX_CLI)
    {
        printf("\n");
        printf("Não existem clientes cadastrados.\n\n");
        printf("\t\t--------------------------------------\n");
        printf("\t\t                 MENU                 \n");
        printf("\t\t--------------------------------------\n");
        printf("\t\t[2] Cadastrar novo cliente \n\n");
        printf("\t\t[0] Voltar ao menu inicial\n");
        printf("\t\t[9] Sair do sistema\n");
        printf("\t\t--------------------------------------\n");
        printf("\t\t- > ");
    }
    else
    {
        printf("\t\t--------------------------------------\n");
        printf("\t\t                 MENU                 \n");
        printf("\t\t--------------------------------------\n");
        printf("\t\t[2] Cadastrar cliente \n");
        printf("\t\t[3] Excluir cliente \n");
        printf("\t\t[4] Atualizar cliente \n\n");
        printf("\t\t[0] Voltar ao menu inicial \n");
        printf("\t\t[9] Sair do sistema\n");
        printf("\t\t--------------------------------------\n");
        printf("\t\t- > ");
    }

    scanf("\%d", &opcao);

    decisao(cliente, MAX_CLI, opcao);
}

/*------------------------------ FUNÇÃO PARA O EXCLUI ALGUM CLIENTE ------------------------------*/
void excluirCliente(CLIENTES cliente[], int MAX_CLI)
{
    int id=0, opcao=0;

    system("cls");
    printf("\t\t--------------------------------------\n");
    printf("\t\t           EXCLUIR CLIENTE            \n");
    printf("\t\t--------------------------------------\n");


    printf("Digite o id do cliente: ");
    printf("\n");
    printf("[id] - > ");
    scanf("%d", &id);

    /*Verifica se o id digitado é válido e se o cliente com este id está ativo*/
    if(id<1 || id>MAX_CLI || cliente[id-1].ativo!=1)
    {
        printf("\n\nNão existe cliente com essa id.\n\n");
        system("pause");
        menu(cliente, MAX_CLI);
    }
    else
    {
        /*Aqui é id-1 pois a posição do cliente no vetor é o id dele menos 1*/
        cliente[id-1].ativo = 0;

        printf("\nCliente excluído com sucesso!\n\n");

        printf("\t\t--------------------------------------\n");
        printf("\t\t                 MENU                 \n");
        printf("\t\t--------------------------------------\n");
        printf("\t\t[1] Visualizar clientes \n");
        printf("\t\t[2] Cadastrar cliente \n");
        printf("\t\t[3] Excluir outro cliente \n");
        printf("\t\t[4] Atualizar cliente \n\n");
        printf("\t\t[0] Voltar ao menu inicial\n");
        printf("\t\t[9] Sair do sistema\n");
        printf("\t\t--------------------------------------\n");
        printf("\t\t- > ");
        scanf("%d", &opcao);
        decisao(cliente, MAX_CLI, opcao);
    }
}

void atualizarCliente(CLIENTES cliente[], int MAX_CLI)
{

    int id=0, opcao=0;

    system("cls");
    printf("\t\t--------------------------------------\n");
    printf("\t\t      ATUALIZAR CLIENTE CADASTRADO    \n");
    printf("\t\t--------------------------------------\n");

    printf("Digite o id do cliente: ");
    printf("\n");
    printf("[id] - > ");
    scanf("%d", &id);

    /*Verifica se o id digitado é válido e se o cliente com este id está ativo*/
    if(id<1 || id>MAX_CLI || cliente[id-1].ativo!=1)
    {
        printf("\n\nNão existe cliente com essa id.\n\n");
        system("pause");
        menu(cliente, MAX_CLI);
    }
    else
    {
        printf("\n");
        printf("\t\t------------------------------\n");
        printf("\t\t       DADOS CADASTRADOS      \n");
        printf("\t\t------------------------------\n");
        printf("\t\t[Nome] - %s", cliente[id-1].nome);
        printf("\n");
        printf("\t\t[CPF] - %s", cliente[id-1].cpf);
        printf("\n");
        printf("\t\t[Sexo] - %s", cliente[id-1].sexo);
        printf("\n");
        printf("\t\t[Data de nascimento] - %s", cliente[id-1].dataNascimento);
        printf("\n");
        printf("\t\t[Telefone] - %s", cliente[id-1].telefone);
        printf("\n");
        printf("\t\t------------------------------\n");
        printf("\n");

        printf("\nDigite qual dado gostaria de atualizar:\n\n");
        printf("-------------------------\n");
        printf("Opção \t\t Dado\n");
        printf("-------------------------\n");
        printf("[1]   \t\t Nome\n");
        printf("[2]   \t\t CPF\n");
        printf("[3]   \t\t Sexo\n");
        printf("[4]   \t\t Data de nascimento\n");
        printf("[5]   \t\t Telefone\n");

        printf("-------------------------\n");
        printf("- > ");
        scanf("%d", &opcao);

        switch(opcao)
        {
        case 1:
            printf("Digite o novo nome: ");
            fflush(stdin);
            gets(cliente[id-1].nome);
            printf("\nO nome foi atualizado com sucesso!");
            break;
        case 2:
            printf("Digite o novo CPF: ");
            fflush(stdin);
            gets(cliente[id-1].cpf);
            printf("\nO CPF foi atualizado com sucesso!");
            break;
        case 3:
            printf("Digite o novo sexo: ");
            fflush(stdin);
            gets(cliente[id-1].sexo);
            printf("\nO sexo foi atualizado com sucesso!");
            break;
        case 4:
            printf("Digite a nova data de nascimento: ");
            fflush(stdin);
            gets(cliente[id-1].dataNascimento);
            printf("\nA data de nascimento foi atualizado com sucesso!");
            break;
        case 5:
            printf("Digite o novo telefone: ");
            fflush(stdin);
            gets(cliente[id-1].telefone);
            printf("\nO telefone foi atualizado com sucesso!");
            break;
        default:
            printf("\nOpção inválida!");
            break;
        }

        printf("\n\n");
        printf("\t\t--------------------------------------\n");
        printf("\t\t                 MENU                 \n");
        printf("\t\t--------------------------------------\n");
        printf("\t\t[1] Visualizar clientes \n");
        printf("\t\t[2] Cadastrar cliente \n");
        printf("\t\t[3] Excluir cliente \n");
        printf("\t\t[4] Atualizar cliente \n\n");
        printf("\t\t[0] Voltar ao menu inicial\n");
        printf("\t\t[9] Sair do sistema\n");
        printf("\t\t--------------------------------------\n");
        printf("\t\t- > ");
        scanf("%d", &opcao);

        decisao(cliente, MAX_CLI, opcao);
    }
}


