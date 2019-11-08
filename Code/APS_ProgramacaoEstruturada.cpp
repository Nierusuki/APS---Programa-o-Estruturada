//Aluno: Gabriel Fidelis
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
int matr[50], idade[50], i=0, buffer;
char nome[50][30], sexo[50];
float notas[50][4];
void load(void);
FILE *arq;
void opc(void);
void sxo(void)
{
    char aux;
    printf("Digite o sexo do aluno (M/F): ");
    scanf(" %c", &aux);
    if (aux == 'M' || aux == 'm' || aux == 'F' || aux == 'f')
    {
        sexo[i]=aux;
        return;
    }
    else
    {
        printf("Sexo invalido.\n");
        Sleep(1500);
        sxo();
    }
}
void media(void)
{
    for (int j=0;j<3;j++)
    {
        printf("Digite a AV%d do Aluno: ",j+1);
        scanf("%f",&notas[i][j]);
    }
    if (notas[i][0] >= notas[i][1] && notas[i][0] >= notas[i][2])
    {
        if (notas[i][1] >= notas[i][2])
        {
            notas[i][3]=(notas[i][0]+notas[i][1])/2;
        }
        else
        {
            notas[i][3]=(notas[i][0]+notas[i][2]/2)/2;
        }
    }
    else if (notas[i][1] >= notas[i][0] && notas[i][1] >= notas[i][2])
    {
        if (notas[i][0] >= notas[i][2])
        {
            notas[i][3]=(notas[i][0]+notas[i][1])/2;
        }
        else
        {
            notas[i][3]=(notas[i][1]+notas[i][2])/2;
        }
    }
    else if (notas[i][2] >= notas[i][0] && notas[i][2] >= notas[i][1])
    {
        if (notas[i][1] >= notas[i][0])
        {
            notas[i][3]=(notas[i][1]+notas[i][2])/2;
        }
        else
        {
            notas[i][3]=(notas[i][2]+notas[i][0])/2;
        }
    }
    printf("A media final do aluno %s foi: %.1f", nome[i], notas[i][3]);
    Sleep(3000);
    system("cls");
    return;
}
void adicionar(void)
{
    printf("UNICARIOCA - BANCO DE DADOS\nADICIONAR USUARIO\nMatricula: ");
    scanf("%d",&buffer);
    for (int p=0;p<i;p++)
    {
        if (buffer == matr[p])
        {
            printf("Matricula ja registrada. \n");
            Sleep(2500);
            system("cls");
            return;
        }
    }
    if (i >= 50)
    {
        printf("UNICARIOCA - BANCO DE DADOS\nADICIONAR USUARIO");
        printf("\n\nBanco de dados cheio, salve o arquivo e limpe para continuar.\n");
        Sleep(2500);
        system("cls");
        return;
    }
    matr[i]=buffer;
    printf("Digite o nome do Aluno: ");
    scanf(" %[^\n]s",&nome[i]);
    printf("Digite a idade do aluno: ");
    scanf("%d",&idade[i]);
    sxo();
    media();
    i++;
    return;
}
void pesquisar(void)
{
    int finder;
    if (i == 0)
    {
        char flag;
        printf("Nenhum dado encontrado. Procedendo para carregamento de arquivo externo.");
        Sleep(1500);
        system("cls");
        load();
    }

    printf("Digite a matricula para pesquisar o aluno: ");
    scanf("%d",&finder);
    for (int j=0;j<=i;j++)
    {
        if (finder == matr[j])
        {
            printf("Aluno de matricula %d encontrado, dados a seguir:\nNome: %s\nSexo: %c\nIdade: %d\nMedia das avaliacoes: %.1f", matr[j],nome[j], sexo[j],idade[j], notas[j][3]);
            printf("\n\nPressione qualquer tecla para voltar ao menu.");
            getch();
            system("cls");
            return;
        }
    }
    printf("Matricula nao encontrada.\n");
    Sleep(1000);
    system("cls");
}
void exibir(void)
{
    int flag;
    if (i==0)
    {
        printf("Sem usuarios cadastrados, carregando arquivo.");
        Sleep(1500);
        system("cls");
        load();
    }
    printf("UNICARIOCA - BANCO DE DADOS\nEXIBIR USUARIOS\n[1] Aprovados\n[2] Reprovados\n[3] Todos\n[0] Voltar\nSua opcao: ");
    scanf("%d",&flag);
    if (flag == 1)
    {
        system("cls");
        printf("[1]Alunos aprovados com media >=7\n[2]Alunos aprovados com media >=9\n[0] Voltar\nSua opcao: ");
        scanf("%d",&flag);
        if (flag == 1)
        {
            system("cls");
            for (int j=0;j<i;j++)
                if (notas[j][3] >= 7)
                    printf("Aluno: %s\nMatricula: %d\nMedia: %.1f\n--------------------------------------------\n", nome[j], matr[j], notas[j][3]);
            printf("\nPressione qualquer tecla para voltar.");
            getch();
            system("cls");
            return;
        }
        else if (flag == 2)
        {
            system("cls");
            for (int j=0;j<i;j++)
                if (notas[j][3] >= 9)
                    printf("Aluno: %s\nMatricula: %d\nMedia: %.1f\n--------------------------------------------\n", nome[j], matr[j], notas[j][3]);
            printf("\nPressione qualquer tecla para voltar.");
            getch();
            system("cls");
            return;
        }
        else if (flag == 0)
        {
            system("cls");
            exibir();
        }
        else
        {
            opc();
        }
        
    }
    else if (flag == 2)
    {
        system("cls");
        printf("[1]Alunos reprovados com media <7\n[2]Alunos reprovados com media <5\n[0] Voltar\nSua opcao: ");
        scanf("%d",&flag);
        if (flag == 1)
        {
            for (int j=0;j<i;j++)
                if (notas[j][3] < 7)
                    printf("Aluno: %s\nMatricula: %d\nMedia: %.1f\n--------------------------------------------\n", nome[j], matr[j], notas[j][3]);
            printf("\nPressione qualquer tecla para voltar.");
            getch();
            system("cls");
            return;
        }
        else if (flag == 2)
        {
            for (int j=0;j<i;j++)
                if (notas[j][3] < 5)
                    printf("Aluno: %s\nMatricula: %d\nMedia: %.1f\n--------------------------------------------\n", nome[j], matr[j], notas[j][3]);
            printf("\nPressione qualquer tecla para voltar.");
            getch();
            system("cls");
            return;
        }
        else if (flag == 0)
        {
            system("cls");
            exibir();
        }
        else
        {
            opc();
        }
        
    }
    else if (flag == 3)
    {
        for (int j=0;j<i;j++)
            printf("Aluno: %s\nMatricula: %d\nMedia: %.1f\n--------------------------------------------\n", nome[j], matr[j], notas[j][3]);
        printf("\nPressione qualquer tecla para voltar.");
        getch();
        system("cls");
        return;
    }
    else if (flag == 0)
    {
        system("cls");
        return;
    }
    else
    {
        opc();
    }
}
void save(void)
{
    char nomearq[20];
    printf("Digite o nome do arquivo: ");
    scanf(" %s",nomearq);
    strcat(nomearq,".txt");
    arq = fopen(nomearq,"w");
    if (arq == NULL)
        {
            printf("Nao posso abrir o arquivo teste. \n");
            Sleep(1500);
        }
    else
    {
        for (int j=0;j<i;j++)
        {
        fprintf(arq,"Matricula:%d\nAluno:%s\nIdade:%d\nSexo:%c\nAV1:%.1f\nAV2:%.1f\nAV3:%.1f\nMedia:%.1f\n------\n",matr[j], nome[j], idade[j], sexo[j], notas[j][0], notas[j][1], notas[j][2], notas[j][3]);
        }
        fprintf(arq, "Total: 0%d", i);
    }
    fclose(arq);
    system("cls");
    return;
}
void load(void)
{
    char nomearq[20];
    printf("Digite o nome do arquivo para carregar: ");
    scanf(" %s", nomearq);
    strcat(nomearq,".txt");
    arq = fopen(nomearq,"r");
    if (arq == NULL)
    {
        printf("Nao foi possivel ler o arquivo.");
        Sleep(1500);
        system("cls");
        return;
    }
    else
    {
        fseek(arq,-2,2);
        fscanf(arq,"%d",&i);
        fseek(arq, 0, 0);
        for (int j=0;j<i;j++)
        {
            fseek(arq, 10, 1);
            fscanf(arq,"%d\n",&matr[j]);
            fseek(arq,6, 1);
            fscanf(arq, " %[^\n]s",nome[j]);
            fseek(arq,8, 1);
            fscanf(arq, "%d",&idade[j]);
            fseek(arq, 7, 1);
            fscanf(arq, "%c\n",&sexo[j]);
            fseek(arq, 4, 1);
            fscanf(arq, "%f\n",&notas[j][0]);
            fseek(arq, 4, 1);
            fscanf(arq, "%f\n",&notas[j][1]);
            fseek(arq, 4, 1);
            fscanf(arq, "%f\n",&notas[j][2]);
            fseek(arq, 6, 1);
            fscanf(arq, "%f\n",&notas[j][3]);
            fseek(arq, 8, 1);
        }
        fclose(arq);
    }
    system("cls");
    return;
}
void saveloadf(void)
{
    int flag;
    if (i == 0)
    {
        printf("Nenhum dado encontrado, carregando arquivo automaticamente.\n");

        load();
    }
    printf("UNICARIOCA - BANCO DE DADOS\n[1] Salvar\n[2] Carregar\n[0] Voltar\nSua opcao: ");
    scanf("%d",&flag);
    if (flag == 1)
    {
        save();
    }
    else if (flag == 2)
    {
        load();
    }
    else if (flag == 0)
    {
        system("cls");
        return;
    }
}
main()
{
    int flag=1;
    while (flag != 0)
    {
        printf("UNICARIOCA - BANCO DE DADOS\n[1] Adicionar\n[2] Pesquisar\n[3] Exibir\n[4] Salvar/Carregar\n[0] Sair\nSua opcao: ");
        scanf("%d",&flag);
        switch (flag)
        {
            case 1:
            adicionar();break;
            case 2:
            pesquisar();break;
            case 3:
            exibir();break;
            case 4:
            saveloadf();break;
            case 0:break;
            default:
            opc();
        }
    }
}
void opc(void)
{
    printf("Opcao incorreta");
    Sleep(1000);
    system("cls");
    return;
}
