#include <stdio.h> // Biblioteca de comunica��o com usu�rio 
#include <stdlib.h> // Biblioteca de aloca��o de espa�os de mem�ria
#include <locale.h> // Biblioteca de texto por regi�o

int main()
{
	setlocale(LC_ALL, "Portuguese");
	printf("========== Cart�rio EBAC ==========\n");
	printf("Escolha uma das op��es abaixo:\n\n");
	printf("\t1 - Consultar Usu�rio\n");
	printf("\t2 - Cadastrar Usu�rio\n");
	printf("\t3 - Deletar Usu�rio\n");
	
	printf("\n\nProjeto EBAC - Mitchel Mathias");
}
