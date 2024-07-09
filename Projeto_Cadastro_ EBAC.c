#include <stdio.h> // Biblioteca de comunicação com usuário 
#include <stdlib.h> // Biblioteca de alocação de espaços de memória
#include <locale.h> // Biblioteca de texto por região

int main()
{
	int opcao = 0; // Declarando a variável opção
	
	setlocale(LC_ALL, "Portuguese"); // definindo o idioma (sinais, ç )
	
	printf("========== Cartório EBAC ==========\n"); // Cabeçalho do projeto pro usuario 
	printf("Escolha uma das opções abaixo:\n\n"); // Inicio das oções
	printf("\t1 - Consultar Usuário\n");
	printf("\t2 - Cadastrar Usuário\n");
	printf("\t3 - Deletar Usuário\n\n"); // fim das opções
	printf("Qual opção: "); // Mensagem pro usuário identificar que é aqui que ele vai digitar a sua escolha
	
	scanf("%d", &opcao); // Ler a escolha do usuário
	
	system("cls"); // limpa a tela para o usuário
	
	if (opcao ==  1){ // Aqui usa a estrutura "se" para realizar uma instrução apenas se a função scanf ler o número 1
		printf("Você escolheu Consultar um Usuário!!\n\n");
	}
	if (opcao == 2){ // Aqui usa a estrutura "se" para realizar uma instrução apenas se a função scanf ler o número 2
		printf("Você escolheu Cadastrar um Usuário!!\n\n");
	}
	if (opcao == 3){ // Aqui usa a estrutura "se" para realizar uma instrução apenas se a função scanf ler o número 2
		printf("Você escolheu Deletar um Usuário!!\n\n");
	}
	if (opcao > 3) { // Aqui usa a estrutura "se" para caso o usuário digite qualquer número acima de 1, 2 e 3
		printf("Essa opção é inválida!\n\n");
	}
	if (opcao < 1) { // Aqui usa a estrutura "se" para caso o usuário digite qualquer número abaixo de 1, 2 e 3
		printf("Essa opção é inválida!\n\n");
	}
	printf("\n\nProjeto EBAC - Mitchel Mathias"); // Mensagem informando o nome do projeto e quem desenvolveu
}
	
