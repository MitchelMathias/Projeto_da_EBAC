#include <stdio.h> // Biblioteca de comunica��o com usu�rio 
#include <stdlib.h> // Biblioteca de aloca��o de espa�os de mem�ria
#include <locale.h> // Biblioteca de texto por regi�o

int main()
{
	int opcao = 0; // Declarando a vari�vel op��o
	
	setlocale(LC_ALL, "Portuguese"); // definindo o idioma (sinais, � )
	
	printf("========== Cart�rio EBAC ==========\n"); // Cabe�alho do projeto pro usuario 
	printf("Escolha uma das op��es abaixo:\n\n"); // Inicio das o��es
	printf("\t1 - Consultar Usu�rio\n");
	printf("\t2 - Cadastrar Usu�rio\n");
	printf("\t3 - Deletar Usu�rio\n\n"); // fim das op��es
	printf("Qual op��o: "); // Mensagem pro usu�rio identificar que � aqui que ele vai digitar a sua escolha
	
	scanf("%d", &opcao); // Ler a escolha do usu�rio
	
	system("cls"); // limpa a tela para o usu�rio
	
	if (opcao ==  1){ // Aqui usa a estrutura "se" para realizar uma instru��o apenas se a fun��o scanf ler o n�mero 1
		printf("Voc� escolheu Consultar um Usu�rio!!\n\n");
	}
	if (opcao == 2){ // Aqui usa a estrutura "se" para realizar uma instru��o apenas se a fun��o scanf ler o n�mero 2
		printf("Voc� escolheu Cadastrar um Usu�rio!!\n\n");
	}
	if (opcao == 3){ // Aqui usa a estrutura "se" para realizar uma instru��o apenas se a fun��o scanf ler o n�mero 2
		printf("Voc� escolheu Deletar um Usu�rio!!\n\n");
	}
	if (opcao > 3) { // Aqui usa a estrutura "se" para caso o usu�rio digite qualquer n�mero acima de 1, 2 e 3
		printf("Essa op��o � inv�lida!\n\n");
	}
	if (opcao < 1) { // Aqui usa a estrutura "se" para caso o usu�rio digite qualquer n�mero abaixo de 1, 2 e 3
		printf("Essa op��o � inv�lida!\n\n");
	}
	printf("\n\nProjeto EBAC - Mitchel Mathias"); // Mensagem informando o nome do projeto e quem desenvolveu
}
	
