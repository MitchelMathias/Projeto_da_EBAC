#include <stdio.h> // Biblioteca de comunicação com usuário 
#include <stdlib.h> // Biblioteca de alocação de espaços de memória
#include <locale.h> // Biblioteca de texto por região

int main()
{
	int opcao = 0, laco = 1; // Declarando a variável opção
	
	for (laco=1;laco=1;){ // Começa o laço
		
		system("cls"); // Limpa pra na repetição o usuário não ter que ver a mesma tela depois de selecionar a opção
		
		setlocale(LC_ALL, "Portuguese"); // definindo o idioma (sinais, ç )
				
		printf("========== Cartório EBAC ==========\n"); // Cabeçalho do projeto pro usuario 
		printf("Escolha uma das opções abaixo:\n\n"); // Inicio das opções
		printf("\t1 - Consultar Usuário\n");
		printf("\t2 - Cadastrar Usuário\n");
		printf("\t3 - Deletar Usuário\n\n"); // fim das opções
		printf("Qual opção: "); // Mensagem pro usuário identificar que é aqui que ele vai digitar a sua escolha
		
		scanf("%d", &opcao); // Ler a escolha do usuário
		
		system("cls"); // limpa a tela para o usuário
		
		switch (opcao){
			case 1: // Aqui usa a estrutura de controle "switch case" para realizar uma instrução apenas se a função scanf ler o número 1
				printf("Você escolheu Consultar um Usuário!!\n\n");
				system("pause");
				break; // Serve pra interromper a execução do bloco de casos
			
			case 2: // Aqui usa a estrutura controle "switch case" para realizar uma instrução apenas se a função scanf ler o número 2
				printf("Você escolheu Cadastrar um Usuário!!\n\n");
				system("pause");
				break; // Serve pra interromper a execução do bloco de casos
			
			case 3: // Aqui usa a estrutura "se" para realizar uma instrução apenas se a função scanf ler o número 2
				printf("Você escolheu Deletar um Usuário!!\n\n");
				system("pause");
				break; // Serve pra interromper a execução do bloco de casos
				
			default:
				printf("Essa opção é inválida!\n\n");
				system("pause");
				break;	// Serve pra interromper a execução do bloco de casos
		}
	}
}

