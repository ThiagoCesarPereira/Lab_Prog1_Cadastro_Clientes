/*--------- TELA INICIAL -------*/
void tela_inicial()
{
    system("Color 0A");
    printf("\t\t\t\t-------------- SisCAD 1.0 2022 --------------\n");
    printf("\t\t\t\t---------------------------------------------\n");
    printf("\t\t\t\t-                                           -\n");
    printf("\t\t\t\t-            BEM-VINDO AO SisCAD            -\n");
    printf("\t\t\t\t-                                           -\n");
    printf("\t\t\t\t---------------------------------------------\n");
    system("pause");

}
/*-------------- FUNÇÃO PARA MOSTRAR AS OPÇÕES INICIAIS DE NAVEGAÇÃO PARA O USUÁRIO --------------*/
void menu(CLIENTES cliente[], int MAX_CLI)
{
    int opcao=0;
    system("cls");
    printf("\t\t--------------------------------------\n");
    printf("\t\t                 MENU                 \n");
    printf("\t\t--------------------------------------\n");
    printf("\t\t[1] - Visualizar clientes cadastrados\n");
    printf("\t\t[2] - Cadastrar novo cliente\n");
    printf("\t\t[3] - Excluir cliente\n");
    printf("\t\t[4] - Atualizar cliente cadastrado\n");
    printf("\t\t\n");
    printf("\t\t[9] - Sair do sistema\n");
    printf("\t\t--------------------------------------\n");
    printf("\t\t- > ");
    scanf("%d", &opcao);

    decisao(cliente, MAX_CLI, opcao);
}

/*------------- FUNÇÃO PARA EXIBIR MENSGEM DE AGRADECIMENTO ANTES DE SAIR DO PROGRAMA -------------*/
void obrigado()
{
    system("cls");
    printf("\t\t--------------------------\n");
    printf("\t\t-        OBRIGADO        -\n");
    printf("\t\t-      VOLTE SEMPRE      -\n");
    printf("\t\t--------------------------\n");
}
