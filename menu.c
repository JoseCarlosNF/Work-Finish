void menu(){
    int operacao;
    operacao = 1;
    while(operacao != 0){
        system("cls");

        printf("Lotacao atual: <lotacaoAtual> pessoas as <horaAtual>\n");
        printf("Lotacao media:\n");
        printf("   11:00 - 11:30: 050 pessoas\n");
        printf("   11:30 - 12:00: 100 pessoas\n");
        printf("   12:00 - 12:30: 150 pessoas\n");
        printf("   12:30 - 13:00: 200 pessoas\n");
        printf("   13:00 - 13:30: 200 pessoas\n");
        printf("   13:30 - 14:00: 150 pessoas\n");

        printf("=====/ MENU RU /=====\n");
        printf("1 - Novo Usuario\n");
        printf("2 - Creditos\n");
        printf("3 - Entrar no RU\n");
        printf("0 - Sair do Programa\n");
        printf("=====================\n");

        scanf("%d", &operacao);
        
        switch (operacao){
            case 1:printf("novoUsuario\n";break;
            case 2:printf("controleCredito\n");break;
            case 3:printf("entrarRU\n");break;
            case 0:printf("SAINDO...\n"); break;
            default:printf("OPCAO INVALIDA\n");break;
        }
    }
}

int main(){
    menu();
    return 0;
}