#include <stdio.h> // Comunica��o com o usu�rio
#include <stdlib.h> // Aloca��o de mem�ria
#include <locale.h> // Para definir o texto por regi�o
#include <string.h> // Respons�vel pelas strings

int consulta() { // Fun��o consulta
    setlocale(LC_ALL, "portuguese"); // Definindo o Idioma
   
    char repeticao [2];
    do {
    	printf("Voc� escolheu Consultar um usu�rio!!\n\n");
    	
	    char cpf[12], nome[15], sobrenome[15], cargo[30], conteudo[72], cpf_busca[12]; // Declarando Vari�veis
	
	    printf("Digite o CPF: "); // Mensagem para o usu�rio 
	    scanf("%s", cpf_busca); // Guarda a entrada na vari�vel cpf_busca
	
	    FILE *arquivo; // Acesse a estrutura FILE e atribua o caminho na vari�vel arquivo
	    arquivo = fopen("cadastros.txt", "r"); // abra o arquivo cadastros em txt e leia
	    if (arquivo == NULL) { // se arquivo n�o encontrado 
	    	printf("Nenhum usu�rio cadastrado...\n");
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
	            break;
	        }
	    }
	
	    if (cpf_encontrado == 0) { // Corrigindo o erro de repeti��o de usu�rio n�o cadastrado
	        printf("\nUsu�rio n�o cadastrado!!...\n\n"); // Caso n�o encontrou o CPF
	    }
	    fclose(arquivo);
	    do {
		    printf("Quer consultar mais 1 usu�rio? [S/N] --> ");
		    scanf("%s", repeticao );
		    printf("\n");
		} while(repeticao[0] != 'S' && repeticao[0] != 's' && repeticao[0] != 'N' && repeticao[0] != 'n');
	
		system("cls");
	}while (repeticao[0] == 'S' || repeticao[0] == 's' );
	return 0;
}

int cadastro() { // Fun��o cadastro
    setlocale(LC_ALL, "portuguese"); // Definindo o Idioma

    printf("Voc� escolheu Cadastrar usu�rio!!\n\n"); // Mensagem para o usu�rio
	
	char repeticao [2];
	int continua_repeticao = 1;
		
	do {
	    char cpf[12], nome[15], sobrenome[15], cargo[30], cpf_busca[12], conteudo[72]; // Declarando Vari�veis tipo string caracter
	    int opcao = 1, cpf_encontrado = 0; // Declarando Vari�veis tipo inteiro
	    
	    FILE *arquivo; // Acesse a estrutura FILE e atribua o caminho na vari�vel arquivo
	    arquivo = fopen("cadastros.txt", "r"); // abra o arquivo do caminho arquivo e atualiza ou cria o arquivo
	    if (arquivo == NULL) { // se arquivo == a NULL
	        printf(""); // Mensagem para o usu�rio
	    }
		
	    printf("Vamos Come�ar!!!\n\n"); // Mensagem para o usu�rio
	
	    printf("Digite o CPF: "); // Mensagem para o usu�rio
	    scanf("%s", cpf); // Guardando o dado na vari�vel CPF 
	    
	    strcpy(cpf_busca, cpf);
	    
	    while(fgets(conteudo, sizeof(conteudo), arquivo) != NULL){
	    	sscanf(conteudo, "%s - %s - %s -%s", cpf, nome, sobrenome, cargo);
	    	
	    	if (strcmp(cpf,cpf_busca) == 0){
	    		printf("\nja tem um usu�rio cadastrado com esse CPF!!");
	    		cpf_encontrado += 1;
	    		break;
			}
		}
		fclose(arquivo);
		
		if (cpf_encontrado >= 1){
			printf("\n\nEscolha uma das op��es abaixo:\n\n");
            printf("\t1 - Deletar registro\n");
            printf("\t2 - Cancelar\n");
            printf("\t\nEscolha uma op��o -->  ");
            scanf("%d", &opcao);
            
            switch(opcao){
            	case 1:
            		system("cls");
            		deletar();
            		break;
            	case 2:
            		system("cls");
            		break;
            	default:
            		system("cls");
            		printf("Op��o inv�lida!!!\n");
            		break;
			}
		}
		else{
			arquivo = fopen("cadastros.txt", "a");
			if(arquivo == NULL){
				printf("Erro ao abrir o arquivo!!\n");
			}
			
			printf("Nome: "); // Mensagem para o usu�rio
		    scanf("%s", nome); // Guardando o dado na vari�vel nome 
		
		    printf("Sobrenome: "); // Mensagem para o usu�rio
		    scanf("%s", sobrenome); // Guardando o dado na vari�vel sobrenome 
		
		    printf("Cargo: "); // Mensagem para o usu�rio
		    scanf("%s", cargo); // Guardando o dado na vari�vel cargo 
		    
		    fprintf(arquivo, "%s - %s - %s - %s\n", cpf_busca, nome, sobrenome, cargo);
		    fclose(arquivo);
		    
		    printf("\nUsu�rio cadastrado com sucesso!!");
			
			do {
			    printf("\nQuer cadastrar mais 1 usu�rio? [S/N] --> ");
			    scanf("%s", repeticao );
			    printf("\n");
			} while(repeticao[0] != 'S' && repeticao[0] != 's' && repeticao[0] != 'N' && repeticao[0] != 'n');
			
			if (repeticao[0] != 'S' && repeticao[0] != 's'){
				continua_repeticao = 0;
			}	
		}
		system("cls");
	}while (continua_repeticao == 1 );
	return 0;
}

int deletar() { // Fun��o deletar
    setlocale(LC_ALL, "portuguese"); // Definindo idioma
	
	char repeticao[2];
	
	do {
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
	    char verificador[2]; // Declarando vari�veis 
	
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
	                continue;
	            } else {
	                printf("\nUsu�rio n�o deletado\n\n"); // Se for diferente da condi��o acima, print usu�rio n�o deletado
	            }
	        }
	        fprintf(temp, "%s - %s - %s - %s\n", cpf, nome, sobrenome, cargo); // escreva dentro do arquivo temp de forma justificada cpf, nome, sobrenome, cargo, separados por um " - " 
	    }
	    if (encontrado == 0) { // se o usu�rio n�o for encontrado 
	        printf("\nUsu�rio n�o cadastrado !!... \n\n"); // Mensagem para o usu�rio
	    }
	    fclose(arquivo); // Fecha o arquivo no caminho arquivo
	    fclose(temp); // Fecha o arquivo no caminho temp
	
	    remove("cadastros.txt"); // Apaga o arquivo cadastros.txt
	    rename("temp.txt", "cadastros.txt"); // Renomeia o arquivo temp.txt para cadastros.txt
	    
		printf("Quer deletar mais Algum usu�rio? [S/N]--> ");
		scanf("%s", repeticao);
		
		system("cls");
	    
	} while (repeticao[0] == 's' || repeticao[0] == 'S');
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
            	break; // interrompe
            default: // Serve como else
                printf("Op��o Inv�lida!!\n"); // Mensagem para o usu�rio
                system("pause"); // Pausa para o usu�rio ler a mensagem 
                break; // Interrompe a execu��o da estrutura
        }
    }
}

