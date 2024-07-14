#include <stdio.h> // Comunicação com o usuário
#include <stdlib.h> // Alcoação de memória
#include <locale.h> // Para definir a Região
#include <string.h> // Responsável pelas strings


int consulta(){ // Função consulta
	setlocale(LC_ALL, "portuguese"); //Definindo o Idioma
	
	printf("você escolheu Consulatar um usuário!!\n\n");
	
	char cpf[12], nome[15], sobrenome[15], cargo[30], conteudo[72],cpf_busca[12]; // Declarando Variáveis
	
	printf("Digite o CPF: "); // Mensagem pro usuário 
	scanf("%s", cpf_busca); // Guarda a entrada na variável Cpf_busca
	
	FILE *arquivo; // Acesse a estrutura FILE e atribua o caminho na varivel arquivo
	arquivo = fopen("cadastros.txt", "r"); // abra o arquivo cadastros em txt e leia
	
	if (arquivo == NULL){ // se arquivo não encontrado 
		printf("Usuário não encontrado!!\n\n"); // Mensagem pro usuário	
	}
	
	while(fgets(conteudo, sizeof(conteudo), arquivo) != NULL){ // Lê cada linha do arquivo e armazena em 'conteudo' até o tamanho de 'conteudo' ou até encontrar uma nova linha
		sscanf(conteudo, "%s - %s - %s - %s", cpf, nome, sobrenome, cargo); // Extrai dados formatados da string 'conteudo' e os armazena nas variáveis 'cpf', 'nome', 'sobrenome' e 'cargo'
		
		if (strcmp(cpf, cpf_busca) == 0){ // Compare cpf com cpf_busca e se o retorno da FUNÇÂO for == 0 que quer dizer exatamente iguais faça os comandos abaixo 
			printf("\nNome: %s %s\n", nome, sobrenome); // Escreva Nome e depois os conteudos nome e sobrenome separados por um " "
			printf("Cpf: %s\n", cpf);// Escreva Cpf e dps o dado guardado em cpf 
			printf("Cargo: %s\n\n", cargo); // Escreve Cargo e dps o dado guardado em cargo 
			break; // para para não fazer isso com todas as linhas no arquvio cadastro.txt
		}
		else{
			printf("\nUsuário não cadastrado!!...\n\n"); // Caso não encontre o CPF
		}
	}
	system("pause");// Pausa pro usuário entender oque aconteceu 
}
int cadastro(){ // Função cadastro
	setlocale(LC_ALL, "portuguese"); //Definindo o Idioma
	
	printf("Você escolheu Cadastrar usuário!!\n\n");
	
	char cpf[12], nome[15], sobrenome[15], cargo[30]; //Declarando Variáveis tipo string caracter
	int cont = 1; //Declarando Variáveis tipo inteiro
	
	printf("Vamos Começar!!!\n\n"); // Mensagem pro usuário
	
	printf("Digite o CPF: "); // Mensagem pro usuário
	scanf("%s", cpf); // Guardando o dado na variável CPF 
	
	printf("Nome: "); // Mensagem pro usuário
	scanf("%s", nome); // Guardando o dado na variável nome 
	
	printf("Sobrenome: "); // Mensagem pro usuário
	scanf("%s", sobrenome); // Guardando o dado na variável sobrenome 
	
	printf("Cargo: "); // Mensagem pro usuário
	scanf("%s", cargo ); // Guardando o dado na variável cargo 
	
	FILE *arquivo; // Acesse a estrutura FILE e atribua o caminho na varivel arquivo
	arquivo = fopen("cadastros.txt", "a"); // abra o arquivo do caminho arquivo
	
	if (arquivo == NULL){ // se arquivo == a NULL
		printf("Erro ao abrir o arquivo"); // Mensagem pro usuário
		system("pause"); // Para o usuário ver a mensagem
	}
	else{ // se diferente de NULL
		fprintf(arquivo, "%s - %s - %s - %s\n", cpf, nome, sobrenome, cargo); // Escreva dentro de arquivo o cpf, nome, sobrenome e cargo separado por um "-" e depois pule uma linha
    	fclose(arquivo); // Fecha o arquivo
	}
	printf("\nUsuário Cadastrado !!! \n\n"); // Mensagem pro usuário
	system("Pause"); // Para o usuário ver a mensagem
}
int deletar(){ // Função deletar
	setlocale(LC_ALL, "portuguese");
	
	printf("Digite o Cpf: ");
}

int main(){
	setlocale(LC_ALL, "portuguese"); //Definindo o Idioma
	
	int opcao; //Declarando Variáveis tipo tipo string caracter
	int repeticao = 1; //Declarando Variáveis tipo inteiro
	
	while (repeticao == 1){ // Enquanto repetição == 1 
		system("cls"); // Limpe a tela
		
		printf("=============== CartórioEBAC ===============\n\n"); // Cabeçalho
		printf("\t1 - Consultar cadastros\n"); // Inicio das opções
		printf("\t2 - Cadastrar Usuário\n");
		printf("\t3 - Deletar Usuário\n");// fim das opção 
		printf("\nSua Opção: "); // Mensagem pro usuário
	
		  // Lê a entrada do usuário e verifica se foi um número inteiro
        if (scanf("%d", &opcao) != 1) {
        	system("cls");
            printf("Opção inválida!! \nDigite apenas números!!\n\n");
            while (getchar() != '\n'); // Limpa o buffer de entrada
            system("pause");
            continue; // Reinicia o loop para solicitar uma nova opção
        }
		
		system("cls"); // Limpa a tela 
		
		switch(opcao) { // Encadeamento de ifs e else
	        case 1:
	            consulta();
	            break; // Interrompe a execução da estrutura
	        case 2:
	            cadastro(); // Chamado da função cadastro 
	            break; // Interrompe a execução da estrutura
	        case 3:
	            printf("Deletar usuário\n"); // Mensagem pro usuário
	            system("pause"); // Pausa pro usuário ler a mensagem 
	            break; // Interrompe a execução da estrutura
	        default: // Serve como else
	            printf("Opção Inválida!!\n"); // Mensagem pro usuário
	            system("pause"); // Pausa pro usuário ler a mensagem 
	            break; // Interrompe a execução da estrutura
		}
	}
}
