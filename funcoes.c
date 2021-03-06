#include<stdio.h>
#include<stdlib.h>
#include"funcoes.h"

struct dadosCadastro{
    int id;
    char nome[15];
    char sobrenome[15];
    float credito;
};

void apagaArquivoTemp(){
    system("del temp.txt");
}

int ultimoID(){
    FILE *f;
    int i=0;
    struct dadosCadastro aluno;

    f = fopen("cadastro.txt", "r");

    if(f == NULL)
        printf("Nao possivel abrir CADASTRO.TXT\n");
    else{
        while(!feof(f)){
            fscanf(f, "%d %s %s %f", &aluno.id, aluno.nome, aluno.sobrenome, &aluno.credito);
            i++;
            if(feof(f) && i == 1){
                aluno.id = 0;
                break;
            }
        }
    }
    return aluno.id;
}

void novoUsuario(void){
    FILE *f;
    struct dadosCadastro aluno;

    f = fopen("cadastro.txt", "a");

    if (f == NULL)
        printf("Nao foi possivel abrir CADASTRO.TXT.\n");
    else{
        printf("Digite Nome e Sobrenome <separedos por espaco>: ");
        scanf("%s %s", &aluno.nome, &aluno.sobrenome);
        aluno.id = ultimoID()+1;
        aluno.credito= 0.00;
        fprintf(f, "%-5d %-15s %-15s %.2f\n", aluno.id, aluno.nome, aluno.sobrenome, aluno.credito);    

        fclose(f);

        printf("====== Cadastro efetudao ======\n");
        printf("%-5s %-15s %-15s %s\n", "ID", "NOME", "SOBRENOME", "CREDITO");
        printf("%-5d %-15s %-15s %.2f\n", aluno.id, aluno.nome, aluno.sobrenome, aluno.credito);    
        printf("===============================\n");        
        system("pause");
    }
}

void consultarCredito(void){
    FILE *f;
    int idBusca;
    struct dadosCadastro aluno;

    f = fopen("cadastro.txt", "r");

    if (f == NULL)
        printf("Nao foi possivel abrir CADASTRO.TXT.\n");
    else{
        printf("Digite o ID para busca: ");
        scanf("%d", &idBusca);
        
        while(!feof(f)){
            fscanf(f, "%d %s %s %f", &aluno.id, aluno.nome, aluno.sobrenome, &aluno.credito);
            if (aluno.id == idBusca){
                limpatela();
                printf("%-5s %-15s %-15s %s\n", "ID", "NOME", "SOBRENOME", "CREDITO");
                printf("%-5d %-15s %-15s %.2f\n", aluno.id, aluno.nome, aluno.sobrenome, aluno.credito);
                break;
            }
            else if (feof(f))
                printf("ID nao encontrado.\n");
        }
        system("pause");
    }
}

void copiaTempToCadastro(){
    FILE *aux;
    FILE *f;
    struct dadosCadastro aluno;

    f = fopen("cadastro.txt", "w");
    aux = fopen("temp.txt", "r");

    while(!feof(aux)){
        fscanf(aux, "%d %s %s %f", &aluno.id, aluno.nome, aluno.sobrenome, &aluno.credito);
        if (feof(aux))
            break;
        fprintf(f, "%-5d %-15s %-15s %.2f\n", aluno.id, aluno.nome, aluno.sobrenome, aluno.credito);
    }
    fclose(f);
    fclose(aux);
    apagaArquivoTemp();
}

void comprarCredito(){
    FILE *f;
    FILE *aux;
    struct dadosCadastro aluno;
    float compra;
    int idBusca;

    f = fopen("cadastro.txt", "r");
    aux = fopen("temp.txt", "w");

    if (f == NULL)
        printf("Nao foi possivel abrir CADASTRO.TXT\n");
    else if (aux == NULL)
        printf("Nao foi possivel abrir AUX.TXT\n");
    else{
        printf("Digite o ID do usuario: ");
        scanf("%d", &idBusca);
        
        while(!feof(f)){
            fscanf(f, "%d %s %s %f", &aluno.id, aluno.nome, aluno.sobrenome, &aluno.credito);
            if (feof(f)){
                break;
            }
            else if (aluno.id == idBusca){
                printf("Digite o valor da compra ou desconto: ");
                scanf("%f", &compra);
                compra = aluno.credito + compra;
                fprintf(aux, "%-5d %-15s %-15s %.2f\n", aluno.id, aluno.nome, aluno.sobrenome, compra);

                printf("Compra efetudada.\n");
                system("pause");
            }
            else
                fprintf(aux, "%-5d %-15s %-15s %.2f\n",aluno.id, aluno.nome, aluno.sobrenome, aluno.credito);                        
        }
        fclose(f);
        fclose(aux);
        copiaTempToCadastro();
    }
}

int entrarRU(){
    FILE *f;
    FILE *aux;
    struct dadosCadastro aluno;
    float compra;
    int idBusca;
    int retorno;

    f = fopen("cadastro.txt", "r");
    aux = fopen("temp.txt", "w");

    if (f == NULL)
        printf("Nao foi possivel abrir CADASTRO.TXT\n");
    else if (aux == NULL)
        printf("Nao foi possivel abrir TEMP.TXT\n");
    else{
        printf("Digite o ID do usuario: ");
        scanf("%d", &idBusca);
        
        while(!feof(f)){
            fscanf(f, "%d %s %s %f", &aluno.id, aluno.nome, aluno.sobrenome, &aluno.credito);
            if (feof(f)){
                break;                
            }
            else if (aluno.id == idBusca){
                if(aluno.credito >= 1){
                    compra = aluno.credito - 1;
                    fprintf(aux, "%-5d %-15s %-15s %.2f\n", aluno.id, aluno.nome, aluno.sobrenome, compra);                    
                    retorno = 1;
                    printf("Entrada Autorizada.\n");
                }
                else{
                    fprintf(aux, "%-5d %-15s %-15s %.2f\n",aluno.id, aluno.nome, aluno.sobrenome, aluno.credito);                
                    retorno = 0;
                    printf("Saldo insuficiente.\n");
                }                    
            }
            else
                fprintf(aux, "%-5d %-15s %-15s %.2f\n",aluno.id, aluno.nome, aluno.sobrenome, aluno.credito);                        
        }
        fclose(f);
        fclose(aux);

        copiaTempToCadastro();
    }
    return retorno;
}

void arquivoTexto(){
    FILE *f;
    struct dadosCadastro aluno;

    f = fopen("cadastro.txt", "r");

    if (f == NULL)
        printf("Nao foi possivel abrir CADASTRO.TXT.\n");
    else{
        printf("%-5s %-15s %-15s %s\n", "ID", "NOME", "SOBRENOME", "CREDITO");
        while(!feof(f)){
            fscanf(f, "%d %s %s %f", &aluno.id, aluno.nome, aluno.sobrenome, &aluno.credito);
            if (feof(f))
                break;
            printf("%-5d %-15s %-15s %.2f\n", aluno.id, aluno.nome, aluno.sobrenome, aluno.credito);
        }
    }
}

int lotacaoMedia(int lotacao, int hora, int minuto){
    int tempo = hora*60 + minuto;
    int minutos_por_entrada = 10;
    int lotacaoM1, lotacaoM2, lotacaoM3,
        lotacaoM4, lotacaoM5, lotacaoM6;

    printf("Lotacao atual: %d pessoas as %d:%-0d\n", lotacao, hora, minuto);
    printf("Lotacao media:\n");

    if (tempo >= 690){
        lotacaoM1 = 30/minutos_por_entrada;
        printf("   11:00 - 11:30: %d pessoas\n", lotacaoM1);
    }
    if (tempo >= 720){
        lotacaoM2 = 60/minutos_por_entrada;
        printf("   11:30 - 12:00: %d pessoas\n", lotacaoM2);
    }
    if (tempo >= 750){
        lotacaoM3 = 90/minutos_por_entrada;
        printf("   12:00 - 12:30: %d pessoas\n", lotacaoM3);
    }
    if (tempo >= 780){
        lotacaoM4 = 120/minutos_por_entrada;
        printf("   12:30 - 13:00: %d pessoas\n", lotacaoM4);
    }
    if (tempo >= 810){
        lotacaoM5 = 150/minutos_por_entrada;
        printf("   13:00 - 13:30: %d pessoas\n", lotacaoM5);
    }
    if (tempo >= 840){
        lotacaoM6 = 180/minutos_por_entrada;
        printf("   13:30 - 14:00: %d pessoas\n", lotacaoM6);
    }
}