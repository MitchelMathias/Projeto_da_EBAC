#include <stdio.h> // Comunicação com o usuário
#include <stdlib.h> // Alocação de memória
#include <locale.h> // Para definir o texto por região
#include <string.h> // Responsável pelas strings

int consulta() { // Função consulta
    setlocale(LC_ALL, "portuguese"); // Definindo o Idioma
    
    char cpf[12], nome[15], sobrenome[15], cargo[30], conteudo[72], cpf_busca[12]; // Declarando Variáveis
   
    char repeticao [2]; // Declarando variável
    do { // faça enquanto a condição for verdadeira
    	printf("Você escolheu Consultar um usuário!!\n\n"); // Mensagem pro usuário 
		printf("Digite o CPF: "); // Mensagem para o usuário 
	    scanf("%s", cpf_busca); // Guarda a entrada na variável cpf_busca
	
	    FILE *arquivo; // Acesse a estrutura FILE e atribua o caminho na variável arquivo
	    arquivo = fopen("cadastros.txt", "r"); // abra o arquivo cadastros em txt e leia
	    if (arquivo == NULL) { // se arquivo não encontrado 
	    	printf("Nenhum usuário cadastrado...\n"); // Mensagem pro usuário
	    }
	    
	    int cpf_encontrado = 0; // declarando variável para corrigir o erro de repetição de usuário não cadastrado
	
	    while (fgets(conteudo, sizeof(conteudo), arquivo) != NULL) { // Lê cada linha do arquivo e armazena em 'conteudo' até o tamanho de 'conteudo' ou até encontrar uma nova linha
	        sscanf(conteudo, "%s - %s - %s - %s", cpf, nome, sobrenome, cargo); // Extrai dados formatados da string 'conteudo' e os armazena nas variáveis 'cpf', 'nome', 'sobrenome' e 'cargo'
	
	        if (strcmp(cpf, cpf_busca) == 0) { // Compare cpf com cpf_busca e se o retorno da FUNÇÃO for == 0 que quer dizer exatamente iguais faça os comandos abaixo 
	            printf("\nEssas são as informações do usuário!!\n\n"); // Mensagem pro usuário
	            printf("\nNome: %s %s\n", nome, sobrenome); // Escreva Nome e depois os conteúdos nome e sobrenome separados por um " "
	            printf("Cpf: %s\n", cpf); // Escreva Cpf e depois o dado guardado em cpf 
	            printf("Cargo: %s\n\n", cargo); // Escreva Cargo e depois o dado guardado em cargo 
	            cpf_encontrado = 1; // se tiver um cpf identico ao cpf busca variável recebe o valor de 1
	            break;// pare
	        }
	    }
	
	    if (cpf_encontrado == 0) { // Corrigindo o erro de repetição de usuário não cadastrado
	        printf("\nUsuário não cadastrado!!...\n\n"); // Caso não encontrou o CPF
	    }
	    fclose(arquivo); // fecha o arquivo
	    do { // faça abaixo enquanto a condição for diferente
		    printf("Quer consultar mais 1 usuário? [S/N] --> "); // Mensagem pro usuário
		    scanf("%s", repeticao ); // salve dado tipo string na variável repetição
		    printf("\n");// pula uma linhda
		} while(repeticao[0] != 'S' && repeticao[0] != 's' && repeticao[0] != 'N' && repeticao[0] != 'n'); // faça enquanto a condição é diferente
	
		system("cls"); // Limpa a tela
	}while (repeticao[0] == 'S' || repeticao[0] == 's' ); // enquanto a condição for igual a S repita
	return 0;
}

int cadastro() { // Função cadastro
    setlocale(LC_ALL, "portuguese"); // Definindo o Idioma

    printf("Você escolheu Cadastrar usuário!!\n\n"); // Mensagem para o usuário
	
	char repeticao [2]; // Declarando variável 
	int continua_repeticao = 1; // Declarando variável e atribuindo o valor de 1
	char cpf[12], nome[15], sobrenome[15], cargo[30], cpf_busca[12], conteudo[72]; // Declarando Variáveis tipo string caracter
	int opcao = 1, cpf_encontrado = 0; // Declarando Variáveis tipo inteiro
		
	do { // faça enquanto a condição por verdadeira
	    cpf_encontrado = 0;
	    
	    FILE *arquivo; // Acesse a estrutura FILE e atribua o caminho na variável arquivo
	    arquivo = fopen("cadastros.txt", "r"); // abra o arquivo do caminho arquivo e atualiza ou cria o arquivo
	    if (arquivo == NULL) { // se arquivo == a NULL
	        printf(""); // Mensagem para o usuário
	    }
		
	    printf("Vamos Começar!!!\n\n"); // Mensagem para o usuário
	
	    printf("Digite o CPF: "); // Mensagem para o usuário
	    scanf("%s", cpf); // Guardando o dado na variável CPF 
	    
	    strcpy(cpf_busca, cpf); // copia o dado da variável cpf_busca pra cpf
	    
	    while(fgets(conteudo, sizeof(conteudo), arquivo) != NULL){ // Enquanto houver linhas para ler no arquivo (fgets retorna um ponteiro não nulo) lê a linha do arquivo e armazena no (buffer == armazenamento temporário) 'conteudo' com tamanho máximo especificado.
	    	sscanf(conteudo, "%s - %s - %s -%s", cpf, nome, sobrenome, cargo); // Separa e armzena o conteudo do buffer em variáveis 
	    	
	    	if (strcmp(cpf,cpf_busca) == 0){ // Se o retorno da função strcmp() for == 0 quer dizer que é exatamente iguais
	    		printf("\nja tem um usuário cadastrado com esse CPF!!"); // Mensagem pro usuário
	    		cpf_encontrado += 1; // Variável recebe ela mesmo +1
	    		break; // Sai do loop
			}
		}
		fclose(arquivo); // fecha o arquivo
		
		if (cpf_encontrado >= 1){ // Se cpf_encontrador for maior que 1 faça
			printf("\n\nEscolha uma das opções abaixo:\n\n"); // Cabeçalho do menu
            printf("\t1 - Deletar registro\n"); // Opção 1
            printf("\t2 - Cancelar\n"); // Opção 2
            printf("\t\nEscolha uma opção -->  ");// mensagem pro usuário
            scanf("%d", &opcao); // salva tipo inteiro na variável opção
            
            switch(opcao){ // Ifs e else 
            	case 1: // opção 1
            		system("cls"); // limpa tela
            		deletar(); // chama a função deletar
            		break; 
            	case 2: // Opção 2
            		system("cls"); // limpa a tela e não faz nada demais 
            		break;
            	default: // caso contrario 
            		system("cls"); // limpa tela
            		printf("Opção inválida!!!\n");// escreve pro usuário
            		break;
			}
		}
		else{ // Se cpf encontrado for menor que 1 
			arquivo = fopen("cadastros.txt", "a"); // Abre o arquivo
			if(arquivo == NULL){ // Se não existir o arquivo 
				printf("Erro ao abrir o arquivo!!\n"); // escreva a mensagem
			}
			
			printf("Nome: "); // Mensagem para o usuário
		    scanf("%s", nome); // Guardando o dado na variável nome 
		
		    printf("Sobrenome: "); // Mensagem para o usuário
		    scanf("%s", sobrenome); // Guardando o dado na variável sobrenome 
		
		    printf("Cargo: "); // Mensagem para o usuário
		    scanf("%s", cargo); // Guardando o dado na variável cargo 
		    
		    fprintf(arquivo, "%s - %s - %s - %s\n", cpf_busca, nome, sobrenome, cargo); // Escreva no arquivo de maneira formatada
		    fclose(arquivo); // Fecha o arquivo
		    
		    printf("\nUsuário cadastrado com sucesso!!"); // Escreve a mensagem pro usuário 
			
			do {// Faça enquanto a condição for verdadeira
			    printf("\nQuer cadastrar mais 1 usuário? [S/N] --> "); // Mensagem pro usuário
			    scanf("%s", repeticao ); // Salva como string na variável repetição
			    printf("\n");
			} while(repeticao[0] != 'S' && repeticao[0] != 's' && repeticao[0] != 'N' && repeticao[0] != 'n'); // Enquanto diferente de 'SsNn'
			
			if (repeticao[0] != 'S' && repeticao[0] != 's'){ // se repetição na posição zero for diferente de 'Ss'
				continua_repeticao = 0; // continua repetição recebe o valor de zero
			}	
		}
		system("cls"); // Limpa tela
	}while (continua_repeticao == 1 ); // enquanto continua_repeticao for == 1
	return 0;
}

int deletar() { // Função deletar
    setlocale(LC_ALL, "portuguese"); // Definindo idioma
	
	char repeticao[2];
	char cpf[12], nome[15], sobrenome[15], cargo[30], conteudo[72], cpf_busca[12]; // Declarando Variáveis
	
	do {
	    printf("Digite o CPF do usuário a ser deletado: "); // Mensagem para o usuário
	    scanf("%s", cpf_busca); // Guardando o valor na variável cpf_busca 
	
	    FILE *arquivo, *temp; // Acesse a estrutura FILE e atribua o caminho na variável arquivo
	    arquivo = fopen("cadastros.txt", "r"); // Abra o arquivo cadastros.txt e leia
	    if (arquivo == NULL) { // se não existir
	        printf("Nenhum usuário cadastrado"); // Mensagem para o usuário
	    }
	    temp = fopen("temp.txt", "w"); // Abra o arquivo temp.txt e escreva
	    if (temp == NULL) { // se não existir 
	        printf("Nenhum usuário cadastrado"); // Mensagem para o usuário 
	        fclose(arquivo); // Fecha o arquivo 
	    }
	    int encontrado = 0; // Declarando variáveis 
	    char verificador[2]; // Declarando variáveis 
	
	    while (fgets(conteudo, sizeof(conteudo), arquivo) != NULL) { // Lê cada linha do arquivo e armazena em 'conteudo' até o tamanho de 'conteudo' ou até encontrar uma nova linha
	        sscanf(conteudo, "%s - %s - %s - %s", cpf, nome, sobrenome, cargo); // Extrai quatro strings de 'conteudo' separadas por " - "
	
	        if (strcmp(cpf, cpf_busca) == 0) { // compare cpf com cpf_busca e "0" quer dizer se forem exatamente iguais
	            printf("Confirme os dados do usuário a ser excluído!!\n\n"); // Mensagem para o usuário
	            printf("Nome: %s %s", nome, sobrenome); // Escreve justificadamente o conteúdo das variáveis Nome e sobrenome 
	            printf("\nCPF: %s", cpf); // Escreve justificadamente o conteúdo da variável cpf
	            printf("\nCargo: %s\n", cargo); // Escreve justificadamente o conteúdo da variável cargo
	            encontrado = 1; // Variável recebe o valor "1"
	            printf("Deseja excluir esse usuário? [S/N] --> "); // mensagem para o usuário 
	            scanf("%s", verificador); // Guarda a resposta na variável verificador
	            if (verificador[0] == 'S' || verificador[0] == 's') { // se verificador na posição 0 for igual a "s" ou "S" 
	                printf("\nUsuário deletado\n\n"); // escreva usuário deletado
	                continue;
	            } else {
	                printf("\nUsuário não deletado\n\n"); // Se for diferente da condição acima, print usuário não deletado
	            }
	        }
	        fprintf(temp, "%s - %s - %s - %s\n", cpf, nome, sobrenome, cargo); // escreva dentro do arquivo temp de forma justificada cpf, nome, sobrenome, cargo, separados por um " - " 
	    }
	    if (encontrado == 0) { // se o usuário não for encontrado 
	        printf("\nUsuário não cadastrado !!... \n\n"); // Mensagem para o usuário
	    }
	    fclose(arquivo); // Fecha o arquivo no caminho arquivo
	    fclose(temp); // Fecha o arquivo no caminho temp
	
	    remove("cadastros.txt"); // Apaga o arquivo cadastros.txt
	    rename("temp.txt", "cadastros.txt"); // Renomeia o arquivo temp.txt para cadastros.txt
	    
		printf("Quer deletar mais Algum usuário? [S/N]--> "); // Mensagem pro usuário
		scanf("%s", repeticao); // Salva como string na variável repetição
		
		system("cls"); // Limpa a tela
	    
	} while (repeticao[0] == 's' || repeticao[0] == 'S'); // Equanto for diferente de 'Ss'
}

int main() { // Função principal onde puxa as outras funções
    setlocale(LC_ALL, "portuguese"); // Definindo o Idioma

    int opcao; // Declarando Variáveis tipo inteiro
    int repeticao = 1; // Declarando Variáveis tipo inteiro

    while (repeticao == 1) { // Enquanto repetição == 1 
        system("cls"); // Limpe a tela

        printf("=============== CartórioEBAC ===============\n"); // Cabeçalho
        printf("Escolha uma das opções abaixo: \n\n");
        printf("\t1 - Consultar cadastros\n"); // Início das opções
        printf("\t2 - Cadastrar Usuário\n");
        printf("\t3 - Deletar Usuário\n"); // fim das opções 
        printf("\t4 - Sair do sistema\n"); // Sai do programa
        printf("\nSua Opção: "); // Mensagem para o usuário

        // Lê a entrada do usuário e verifica se foi um número inteiro
        if (scanf("%d", &opcao) != 1) {
            system("cls");
            printf("Opção inválida!! \nDigite apenas números!!\n\n");
            while (getchar() != '\n'); // Limpa o buffer de entrada
            system("pause");
            continue; // Reinicia o loop para solicitar uma nova opção
        }

        system("cls"); // Limpa a tela 

        switch (opcao) { // Encadeamento de ifs e else
            case 1:
                consulta();
                break; // Interrompe a execução da estrutura
            case 2:
                cadastro(); // Chama da função cadastro 
                break; // Interrompe a execução da estrutura
            case 3:
                deletar();
                break; // Interrompe a execução da estrutura
            case 4:
            	printf("Obrigado por usar nosso sistema!!\n"); // Mensagem pro usuário
				return 0; // Retorna que não teve erro
            	break; // interrompe
            default: // Serve como else
                printf("Opção Inválida!!\n"); // Mensagem para o usuário
                system("pause"); // Pausa para o usuário ler a mensagem 
                break; // Interrompe a execução da estrutura
        }
    }
}

