#include <stdio.h> // Biblioteca de comunicação com usuário 
#include <stdlib.h> // Biblioteca de alocação de espaços de memória
#include <locale.h> // Biblioteca de texto por região

int main()
{
	setlocale(LC_ALL, "Portuguese");
	printf("========== Cartório EBAC ==========\n");
	printf("Escolha uma das opções abaixo:\n\n");
	printf("\t1 - Consultar Usuário\n");
	printf("\t2 - Cadastrar Usuário\n");
	printf("\t3 - Deletar Usuário\n");
	
	printf("\n\nProjeto EBAC - Mitchel Mathias");
}
