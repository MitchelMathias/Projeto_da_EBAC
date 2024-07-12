#include <stdio.h> // Biblioteca de comunicação com usuário 
#include <stdlib.h> // Biblioteca de alocação de espaços de memória
#include <locale.h> // Biblioteca de texto por região
#include <string.h> // Biblioteca responsavel pelas string 

int consulta(){ // Função que verifica usuários

	setlocale(LC_ALL, "Portuguese"); // definindo o idioma (sinais, ç )
	
	char conteudo [200],cpf[40], nome[40], sobrenome[40],cargo[40]; // criando as variáveis que vou usar na função consulta
	
	printf("Digite o CPF do Usuário: ");// mensgem pro usuário 
	scanf("%s", cpf); // Atribuir o valor da varíavel como uma string 
	
	FILE *ponteiro; // Usando a estrutra pra encontrar o Ponteiro
	ponteiro = fopen(cpf, "r"); // Abrindo o arquivo no ponteiro
	
	if (ponteiro == NULL){ // se ponteiro == a nulo
		printf("\nUsuário não cadastrado\n\n"); // Escreva que o usuário não foi cadastrado ainda
		system("pause");// Pausa pro usuário ver a mensagem
	}
	else{ // se o ponteiro for encontrado 
		while (fgets(conteudo,sizeof(conteudo), ponteiro) != NULL);{ // Enquanto a função ler fgets lê algo diferente de nulo armazene na varivável "conteudo"
			
			// sscanf esta lendo a linha da variável conteudo e guardando nas respctivas variáveis
			sscanf(conteudo,"%s - %s - %s - %s", cpf, nome, sobrenome, cargo); // Atribui o valor como string nas variáveis até encontrar o delimitador "-"
						
			printf("\nEssas são as informações do Usuário: \n"); // Mensagem pro usuário
			printf("\nNome: %s %s",nome, sobrenome); // Escrevendo nome e então escrevendo a string no "%s" respectivamente
			printf("\nCPF: %s", cpf); 
			printf("\nEle é: %s", cargo);
			printf("\n\n"); // Pulando duas linhas pra ficar menos poluido
			system("pause"); // Pausando pro usuário ler as informações
		}
	}
}

int cadastro(){ // Função responsável por cadastrar usuários

	setlocale(LC_ALL, "Portuguese"); // definindo o idioma (sinais, ç )

	char arquivo[40]; // Criando as variáveis do cadastro 
	char cpf[40]; // Criando as variáveis do cadastro 
	char nome[40]; // Criando as variáveis do cadastro 
	char sobrenome[40]; // Criando as variáveis do cadastro 
	char cargo[40]; // Criando as variáveis do cadastro 
	
	printf("Digite o Número do CPF: "); // Mensagem pro usuário
	scanf("%s", cpf); // Ler o CPF e guardar na variável cpf 
	
	strcpy(arquivo, cpf); // Responsavel por copiar o cpf pra arquivo
	
	printf("Digite seu nome: ");
	scanf("%s", nome); // Ler o Nome e guardar na variável nome
	
	printf("Seu Sobrenome: ");
	scanf("%s", sobrenome); // Ler o sobrenome e guardar na variável sobrenome 
	
	printf("Seu Cargo: ");
	scanf("%s", cargo); // Ler o cargo e guardar na variável cargo 
	
	FILE *ponteiro; // FILE é uma estrutura da biblioteca <stdio.h> * é a identificação que a varivável a seguir vai ser um ponteiro
	ponteiro = fopen(arquivo, "w"); // Variável ponteiro recebe o comando de abrir o arquivo e o "w" é escrever (criar o doc com nome de arquivo que recebeu de cpf)
	fprintf(ponteiro, cpf);// Dentro de arquivo escreva o valor que a variável cpf recebeu
	fprintf(ponteiro, " - "); // Aproveita o arquivo aberto e escreve " - " para divisórias
	fprintf(ponteiro, nome); // Dentro de arquivo escreva o valor que a variável nome recebeu
	fprintf(ponteiro, " - "); // Escreve " - " para divisórias
	fprintf(ponteiro, sobrenome); // Dentro de arquivo escreva o valor que a variável sobrenome recebeu
	fprintf(ponteiro, " - "); // Escreve " - " para divisórias
	fprintf(ponteiro, cargo); // Dentro de arquivo escreva o valor que a variável cargo recebeu
	fclose(ponteiro); // Fecha o arquivo
	
	printf("\nUsuário cadastrado com sucesso!!\n\n"); // Pro usuário ver que foi cadastrado
	system("pause"); // Pra não pular direto pro Menu 
}

int deletar(){ // Função responsável por deletar usuários
	printf("Você escolheu Deletar um Usuário!!\n\n");
	system("pause");
}

int main()
{
	char opcao[10];
	int laco = 1; // Declarando a variável opção
	
	for (laco=1;laco=1;){ // Começa o laço
		
		system("cls"); // Limpa pra na repetição o usuário não ter que ver a mesma tela depois de selecionar a opção
		
		setlocale(LC_ALL, "Portuguese"); // definindo o idioma (sinais, ç )
				
		printf("========== Cartório EBAC ==========\n"); // Cabeçalho do projeto pro usuario 
		printf("Escolha uma das opções abaixo:\n\n"); // Inicio das opções
		printf("\t1 - Consultar Usuário\n");
		printf("\t2 - Cadastrar Usuário\n");
		printf("\t3 - Deletar Usuário\n\n"); // fim das opções
		printf("Qual opção: "); // Mensagem pro usuário identificar que é aqui que ele vai digitar a sua escolha
		
		scanf("%s", opcao); // Ler a escolha do usuário
		
		system("cls"); // limpa a tela para o usuário
		
		switch (opcao[0]){
			case '1': // Aqui usa a estrutura de controle "switch case" para realizar uma instrução apenas se a função scanf ler o número 1
				consulta();
				break; // Serve pra interromper a execução do bloco de casos
			
			case '2': // Aqui usa a estrutura controle "switch case" para realizar uma instrução apenas se a função scanf ler o número 2
				cadastro();
				break; // Serve pra interromper a execução do bloco de casos
			
			case '3': // Aqui usa a estrutura "se" para realizar uma instrução apenas se a função scanf ler o número 2
				deletar();
				break; // Serve pra interromper a execução do bloco de casos
				
			default:
				printf("Essa opção é inválida!\n\n");
				system("pause");
				break;	// Serve pra interromper a execução do bloco de casos
		}
	}
}

