#include <stdio.h> // Biblioteca de comunica��o com usu�rio 
#include <stdlib.h> // Biblioteca de aloca��o de espa�os de mem�ria
#include <locale.h> // Biblioteca de texto por regi�o
#include <string.h> // Biblioteca responsavel pelas string 

int consulta(){ // Fun��o que verifica usu�rios

	setlocale(LC_ALL, "Portuguese"); // definindo o idioma (sinais, � )
	
	char conteudo [200],cpf[40], nome[40], sobrenome[40],cargo[40]; // criando as vari�veis que vou usar na fun��o consulta
	
	printf("Digite o CPF do Usu�rio: ");// mensgem pro usu�rio 
	scanf("%s", cpf); // Atribuir o valor da var�avel como uma string 
	
	FILE *ponteiro; // Usando a estrutra pra encontrar o Ponteiro
	ponteiro = fopen(cpf, "r"); // Abrindo o arquivo no ponteiro
	
	if (ponteiro == NULL){ // se ponteiro == a nulo
		printf("\nUsu�rio n�o cadastrado\n\n"); // Escreva que o usu�rio n�o foi cadastrado ainda
		system("pause");// Pausa pro usu�rio ver a mensagem
	}
	else{ // se o ponteiro for encontrado 
		while (fgets(conteudo,sizeof(conteudo), ponteiro) != NULL);{ // Enquanto a fun��o ler fgets l� algo diferente de nulo armazene na variv�vel "conteudo"
			
			// sscanf esta lendo a linha da vari�vel conteudo e guardando nas respctivas vari�veis
			sscanf(conteudo,"%s - %s - %s - %s", cpf, nome, sobrenome, cargo); // Atribui o valor como string nas vari�veis at� encontrar o delimitador "-"
						
			printf("\nEssas s�o as informa��es do Usu�rio: \n"); // Mensagem pro usu�rio
			printf("\nNome: %s %s",nome, sobrenome); // Escrevendo nome e ent�o escrevendo a string no "%s" respectivamente
			printf("\nCPF: %s", cpf); 
			printf("\nEle �: %s", cargo);
			printf("\n\n"); // Pulando duas linhas pra ficar menos poluido
			system("pause"); // Pausando pro usu�rio ler as informa��es
		}
	}
}

int cadastro(){ // Fun��o respons�vel por cadastrar usu�rios

	setlocale(LC_ALL, "Portuguese"); // definindo o idioma (sinais, � )

	char arquivo[40]; // Criando as vari�veis do cadastro 
	char cpf[40]; // Criando as vari�veis do cadastro 
	char nome[40]; // Criando as vari�veis do cadastro 
	char sobrenome[40]; // Criando as vari�veis do cadastro 
	char cargo[40]; // Criando as vari�veis do cadastro 
	
	printf("Digite o N�mero do CPF: "); // Mensagem pro usu�rio
	scanf("%s", cpf); // Ler o CPF e guardar na vari�vel cpf 
	
	strcpy(arquivo, cpf); // Responsavel por copiar o cpf pra arquivo
	
	printf("Digite seu nome: ");
	scanf("%s", nome); // Ler o Nome e guardar na vari�vel nome
	
	printf("Seu Sobrenome: ");
	scanf("%s", sobrenome); // Ler o sobrenome e guardar na vari�vel sobrenome 
	
	printf("Seu Cargo: ");
	scanf("%s", cargo); // Ler o cargo e guardar na vari�vel cargo 
	
	FILE *ponteiro; // FILE � uma estrutura da biblioteca <stdio.h> * � a identifica��o que a variv�vel a seguir vai ser um ponteiro
	ponteiro = fopen(arquivo, "w"); // Vari�vel ponteiro recebe o comando de abrir o arquivo e o "w" � escrever (criar o doc com nome de arquivo que recebeu de cpf)
	fprintf(ponteiro, cpf);// Dentro de arquivo escreva o valor que a vari�vel cpf recebeu
	fprintf(ponteiro, " - "); // Aproveita o arquivo aberto e escreve " - " para divis�rias
	fprintf(ponteiro, nome); // Dentro de arquivo escreva o valor que a vari�vel nome recebeu
	fprintf(ponteiro, " - "); // Escreve " - " para divis�rias
	fprintf(ponteiro, sobrenome); // Dentro de arquivo escreva o valor que a vari�vel sobrenome recebeu
	fprintf(ponteiro, " - "); // Escreve " - " para divis�rias
	fprintf(ponteiro, cargo); // Dentro de arquivo escreva o valor que a vari�vel cargo recebeu
	fclose(ponteiro); // Fecha o arquivo
	
	printf("\nUsu�rio cadastrado com sucesso!!\n\n"); // Pro usu�rio ver que foi cadastrado
	system("pause"); // Pra n�o pular direto pro Menu 
}

int deletar(){ // Fun��o respons�vel por deletar usu�rios
	printf("Voc� escolheu Deletar um Usu�rio!!\n\n");
	system("pause");
}

int main()
{
	char opcao[10];
	int laco = 1; // Declarando a vari�vel op��o
	
	for (laco=1;laco=1;){ // Come�a o la�o
		
		system("cls"); // Limpa pra na repeti��o o usu�rio n�o ter que ver a mesma tela depois de selecionar a op��o
		
		setlocale(LC_ALL, "Portuguese"); // definindo o idioma (sinais, � )
				
		printf("========== Cart�rio EBAC ==========\n"); // Cabe�alho do projeto pro usuario 
		printf("Escolha uma das op��es abaixo:\n\n"); // Inicio das op��es
		printf("\t1 - Consultar Usu�rio\n");
		printf("\t2 - Cadastrar Usu�rio\n");
		printf("\t3 - Deletar Usu�rio\n\n"); // fim das op��es
		printf("Qual op��o: "); // Mensagem pro usu�rio identificar que � aqui que ele vai digitar a sua escolha
		
		scanf("%s", opcao); // Ler a escolha do usu�rio
		
		system("cls"); // limpa a tela para o usu�rio
		
		switch (opcao[0]){
			case '1': // Aqui usa a estrutura de controle "switch case" para realizar uma instru��o apenas se a fun��o scanf ler o n�mero 1
				consulta();
				break; // Serve pra interromper a execu��o do bloco de casos
			
			case '2': // Aqui usa a estrutura controle "switch case" para realizar uma instru��o apenas se a fun��o scanf ler o n�mero 2
				cadastro();
				break; // Serve pra interromper a execu��o do bloco de casos
			
			case '3': // Aqui usa a estrutura "se" para realizar uma instru��o apenas se a fun��o scanf ler o n�mero 2
				deletar();
				break; // Serve pra interromper a execu��o do bloco de casos
				
			default:
				printf("Essa op��o � inv�lida!\n\n");
				system("pause");
				break;	// Serve pra interromper a execu��o do bloco de casos
		}
	}
}

