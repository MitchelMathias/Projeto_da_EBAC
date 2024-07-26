#include <stdio.h> // Comunica��o com o usu�rio
#include <stdlib.h> // Aloca��o de mem�ria
#include <locale.h> // Para definir o texto por regi�o
#include <string.h> // Respons�vel pelas strings

int consulta() { // Fun��o consulta
    setlocale(LC_ALL, "portuguese"); // Definindo o Idioma

    printf("Voc� escolheu Consultar um usu�rio!!\n\n");

    char cpf[12], nome[15], sobrenome[15], cargo[30], conteudo[72], cpf_busca[12]; // Declarando Vari�veis

    printf("Digite o CPF: "); // Mensagem para o usu�rio 
    scanf("%s", cpf_busca); // Guarda a entrada na vari�vel cpf_busca

    FILE *arquivo; // Acesse a estrutura FILE e atribua o caminho na vari�vel arquivo
    arquivo = fopen("cadastros.txt", "r"); // abra o arquivo cadastros em txt e leia

    if (arquivo == NULL) { // se arquivo n�o encontrado 
        printf("Usu�rio n�o encontrado!!\n\n"); // Mensagem para o usu�rio se o arquivo n�o foi encontrado � porque n�o teve usu�rio cadastrado 
    }
    int cpf_encontrado = 0; // declarando vari�vel para corrigir o erro de repeti��o de usu�rio n�o cadastrado

    while (fgets(conteudo, sizeof(conteudo), arquivo) != NULL) { // L� cada linha do arquivo e armazena em 'conteudo' at� o tamanho de 'conteudo' ou at� encontrar uma nova linha
        sscanf(conteudo, "%s - %s - %s - %s", cpf, nome, sobrenome, cargo); // Extrai dados formatados da string 'conteudo' e os armazena nas vari�veis 'cpf', 'nome', 'sobrenome' e 'cargo'

        if (strcmp(cpf, cpf_busca) == 0) { // Compare cpf com cpf_busca e se o retorno da FUN��O for == 0 que quer dizer exatamente iguais fa�a os comandos abaixo 
            printf("\nEssas s�o as informa��es do usu�rio!!\n\n");
            printf("\nNome: %s %s\n", nome, sobrenome); // Escreva Nome e depois os conte�dos nome e sobrenome separados por um " "
            printf("Cpf: %s\n", cpf); // Escreva Cpf e depois o dado guardado em cpf 
            printf("Cargo: %s\n\n", cargo); // Escreva Cargo e depois o dado guardado em cargo 
            cpf_encontrado = 1;
            break; // para para n�o fazer isso com todas as linhas no arquivo cadastro.txt
        }
    }

    if (cpf_encontrado == 0) { // Corrigindo o erro de repeti��o de usu�rio n�o cadastrado
        printf("\nUsu�rio n�o cadastrado!!...\n\n"); // Caso n�o encontrou o CPF
    }
    fclose(arquivo);
    system("pause"); // Pausa para o usu�rio entender o que aconteceu 
}

int cadastro() { // Fun��o cadastro
    setlocale(LC_ALL, "portuguese"); // Definindo o Idioma

    printf("Voc� escolheu Cadastrar usu�rio!!\n\n"); // Mensagem para o usu�rio

    char cpf[12], nome[100], sobrenome[15], cargo[30]; // Declarando Vari�veis tipo string caracter
    int cont = 1; // Declarando Vari�veis tipo inteiro

    printf("Vamos Come�ar!!!\n\n"); // Mensagem para o usu�rio

    printf("Digite o CPF: "); // Mensagem para o usu�rio
    scanf("%s", cpf); // Guardando o dado na vari�vel CPF 

    printf("Nome: "); // Mensagem para o usu�rio
    scanf("%s", nome); // Guardando o dado na vari�vel nome 

    printf("Sobrenome: "); // Mensagem para o usu�rio
    scanf("%s", sobrenome); // Guardando o dado na vari�vel sobrenome 

    printf("Cargo: "); // Mensagem para o usu�rio
    scanf("%s", cargo); // Guardando o dado na vari�vel cargo 

    FILE *arquivo; // Acesse a estrutura FILE e atribua o caminho na vari�vel arquivo
    arquivo = fopen("cadastros.txt", "a"); // abra o arquivo do caminho arquivo e atualiza ou cria o arquivo

    if (arquivo == NULL) { // se arquivo == a NULL
        printf("Erro ao abrir o arquivo"); // Mensagem para o usu�rio
        system("pause"); // Para o usu�rio ver a mensagem
    } else { // se diferente de NULL
        fprintf(arquivo, "%s - %s - %s - %s\n", cpf, nome, sobrenome, cargo); // Escreva dentro de arquivo o cpf, nome, sobrenome e cargo separados por um "-" e depois pule uma linha
        fclose(arquivo); // Fecha o arquivo
    }
    printf("\nUsu�rio Cadastrado !!! \n\n"); // Mensagem para o usu�rio
    system("pause"); // Para o usu�rio ver a mensagem
}

int deletar() { // Fun��o deletar
    setlocale(LC_ALL, "portuguese"); // Definindo idioma

    char cpf[12], nome[15], sobrenome[15], cargo[30], conteudo[72], cpf_busca[12]; // Declarando Vari�veis

    printf("Digite o CPF do usu�rio a ser deletado: "); // Mensagem para o usu�rio
    scanf("%s", cpf_busca); // Guardando o valor na vari�vel cpf_busca 

    FILE *arquivo, *temp; // Acesse a estrutura FILE e atribua o caminho na vari�vel arquivo
    arquivo = fopen("cadastros.txt", "r"); // Abra o arquivo cadastros.txt e leia
    if (arquivo == NULL) { // se n�o existir
        printf("Nenhum usu�rio cadastrado"); // Mensagem para o usu�rio
    }
    temp = fopen("temp.txt", "w"); // Abra o arquivo temp.txt e escreva
    if (temp == NULL) { // se n�o existir 
        printf("Nenhum usu�rio cadastrado"); // Mensagem para o usu�rio 
        fclose(arquivo); // Fecha o arquivo 
    }
    int encontrado = 0; // Declarando vari�veis 
    char verificador[10]; // Declarando vari�veis 

    while (fgets(conteudo, sizeof(conteudo), arquivo) != NULL) { // L� cada linha do arquivo e armazena em 'conteudo' at� o tamanho de 'conteudo' ou at� encontrar uma nova linha
        sscanf(conteudo, "%s - %s - %s - %s", cpf, nome, sobrenome, cargo); // Extrai quatro strings de 'conteudo' separadas por " - "

        if (strcmp(cpf, cpf_busca) == 0) { // compare cpf com cpf_busca e "0" quer dizer se forem exatamente iguais
            printf("Confirme os dados do usu�rio a ser exclu�do!!\n\n"); // Mensagem para o usu�rio
            printf("Nome: %s %s", nome, sobrenome); // Escreve justificadamente o conte�do das vari�veis Nome e sobrenome 
            printf("\nCPF: %s", cpf); // Escreve justificadamente o conte�do da vari�vel cpf
            printf("\nCargo: %s\n", cargo); // Escreve justificadamente o conte�do da vari�vel cargo
            encontrado = 1; // Vari�vel recebe o valor "1"
            printf("Deseja excluir esse usu�rio? [S/N] --> "); // mensagem para o usu�rio 
            scanf("%s", verificador); // Guarda a resposta na vari�vel verificador
            if (verificador[0] == 'S' || verificador[0] == 's') { // se verificador na posi��o 0 for igual a "s" ou "S" 
                printf("\nUsu�rio deletado\n\n"); // escreva usu�rio deletado
            } else {
                printf("\nUsu�rio n�o deletado\n\n"); // Se for diferente da condi��o acima, print usu�rio n�o deletado
            }
        }
        if (verificador[0] != 'S' && verificador[0] != 's') { // Se verificador for diferente de 'S' e 's'
            fprintf(temp, "%s - %s - %s - %s\n", cpf, nome, sobrenome, cargo); // escreva dentro do arquivo temp de forma justificada cpf, nome, sobrenome, cargo, separados por um " - " 
        }
    }
    if (encontrado == 0) { // se o usu�rio n�o for encontrado 
        printf("\nUsu�rio n�o cadastrado !!... \n\n"); // Mensagem para o usu�rio
    }
    fclose(arquivo); // Fecha o arquivo no caminho arquivo
    fclose(temp); // Fecha o arquivo no caminho temp

    remove("cadastros.txt"); // Apaga o arquivo cadastros.txt
    rename("temp.txt", "cadastros.txt"); // Renomeia o arquivo temp.txt para cadastros.txt

    system("pause"); // Pausa para o usu�rio ler as mensagens 
}

int main() { // Fun��o principal onde puxa as outras fun��es
    setlocale(LC_ALL, "portuguese"); // Definindo o Idioma

    int opcao; // Declarando Vari�veis tipo inteiro
    int repeticao = 1; // Declarando Vari�veis tipo inteiro

    while (repeticao == 1) { // Enquanto repeti��o == 1 
        system("cls"); // Limpe a tela

        printf("=============== Cart�rioEBAC ===============\n"); // Cabe�alho
        printf("Escolha uma das op��es abaixo: \n\n");
        printf("\t1 - Consultar cadastros\n"); // In�cio das op��es
        printf("\t2 - Cadastrar Usu�rio\n");
        printf("\t3 - Deletar Usu�rio\n"); // fim das op��es 
        printf("\t4 - Sair do sistema\n"); // Sai do programa
        printf("\nSua Op��o: "); // Mensagem para o usu�rio

        // L� a entrada do usu�rio e verifica se foi um n�mero inteiro
        if (scanf("%d", &opcao) != 1) {
            system("cls");
            printf("Op��o inv�lida!! \nDigite apenas n�meros!!\n\n");
            while (getchar() != '\n'); // Limpa o buffer de entrada
            system("pause");
            continue; // Reinicia o loop para solicitar uma nova op��o
        }

        system("cls"); // Limpa a tela 

        switch (opcao) { // Encadeamento de ifs e else
            case 1:
                consulta();
                break; // Interrompe a execu��o da estrutura
            case 2:
                cadastro(); // Chama da fun��o cadastro 
                break; // Interrompe a execu��o da estrutura
            case 3:
                deletar();
                break; // Interrompe a execu��o da estrutura
            case 4:
            	printf("Obrigado por usar nosso sistema!!\n"); // Mensagem pro usu�rio
				return 0; // Retorna que n�o teve erro
            	break; // para
            default: // Serve como else
                printf("Op��o Inv�lida!!\n"); // Mensagem para o usu�rio
                system("pause"); // Pausa para o usu�rio ler a mensagem 
                break; // Interrompe a execu��o da estrutura
        }
    system("Pause");
    }
}

