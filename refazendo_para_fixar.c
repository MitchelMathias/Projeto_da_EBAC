#include <stdio.h> // Comunica��o com o usu�rio
#include <stdlib.h> // Alcoa��o de mem�ria
#include <locale.h> // Para definir a Regi�o
#include <string.h> // Respons�vel pelas strings


int consulta(){ // Fun��o consulta
	setlocale(LC_ALL, "portuguese"); //Definindo o Idioma
	
	printf("voc� escolheu Consulatar um usu�rio!!\n\n");
	
	char cpf[12], nome[15], sobrenome[15], cargo[30], conteudo[72],cpf_busca[12]; // Declarando Vari�veis
	
	printf("Digite o CPF: "); // Mensagem pro usu�rio 
	scanf("%s", cpf_busca); // Guarda a entrada na vari�vel Cpf_busca
	
	FILE *arquivo; // Acesse a estrutura FILE e atribua o caminho na varivel arquivo
	arquivo = fopen("cadastros.txt", "r"); // abra o arquivo cadastros em txt e leia
	
	if (arquivo == NULL){ // se arquivo n�o encontrado 
		printf("Usu�rio n�o encontrado!!\n\n"); // Mensagem pro usu�rio	
	}
	
	while(fgets(conteudo, sizeof(conteudo), arquivo) != NULL){ // L� cada linha do arquivo e armazena em 'conteudo' at� o tamanho de 'conteudo' ou at� encontrar uma nova linha
		sscanf(conteudo, "%s - %s - %s - %s", cpf, nome, sobrenome, cargo); // Extrai dados formatados da string 'conteudo' e os armazena nas vari�veis 'cpf', 'nome', 'sobrenome' e 'cargo'
		
		if (strcmp(cpf, cpf_busca) == 0){ // Compare cpf com cpf_busca e se o retorno da FUN��O for == 0 que quer dizer exatamente iguais fa�a os comandos abaixo 
			printf("\nNome: %s %s\n", nome, sobrenome); // Escreva Nome e depois os conteudos nome e sobrenome separados por um " "
			printf("Cpf: %s\n", cpf);// Escreva Cpf e dps o dado guardado em cpf 
			printf("Cargo: %s\n\n", cargo); // Escreve Cargo e dps o dado guardado em cargo 
			break; // para para n�o fazer isso com todas as linhas no arquvio cadastro.txt
		}
		else{
			printf("\nUsu�rio n�o cadastrado!!...\n\n"); // Caso n�o encontre o CPF
		}
	}
	system("pause");// Pausa pro usu�rio entender oque aconteceu 
}
int cadastro(){ // Fun��o cadastro
	setlocale(LC_ALL, "portuguese"); //Definindo o Idioma
	
	printf("Voc� escolheu Cadastrar usu�rio!!\n\n");
	
	char cpf[12], nome[15], sobrenome[15], cargo[30]; //Declarando Vari�veis tipo string caracter
	int cont = 1; //Declarando Vari�veis tipo inteiro
	
	printf("Vamos Come�ar!!!\n\n"); // Mensagem pro usu�rio
	
	printf("Digite o CPF: "); // Mensagem pro usu�rio
	scanf("%s", cpf); // Guardando o dado na vari�vel CPF 
	
	printf("Nome: "); // Mensagem pro usu�rio
	scanf("%s", nome); // Guardando o dado na vari�vel nome 
	
	printf("Sobrenome: "); // Mensagem pro usu�rio
	scanf("%s", sobrenome); // Guardando o dado na vari�vel sobrenome 
	
	printf("Cargo: "); // Mensagem pro usu�rio
	scanf("%s", cargo ); // Guardando o dado na vari�vel cargo 
	
	FILE *arquivo; // Acesse a estrutura FILE e atribua o caminho na varivel arquivo
	arquivo = fopen("cadastros.txt", "a"); // abra o arquivo do caminho arquivo
	
	if (arquivo == NULL){ // se arquivo == a NULL
		printf("Erro ao abrir o arquivo"); // Mensagem pro usu�rio
		system("pause"); // Para o usu�rio ver a mensagem
	}
	else{ // se diferente de NULL
		fprintf(arquivo, "%s - %s - %s - %s\n", cpf, nome, sobrenome, cargo); // Escreva dentro de arquivo o cpf, nome, sobrenome e cargo separado por um "-" e depois pule uma linha
    	fclose(arquivo); // Fecha o arquivo
	}
	printf("\nUsu�rio Cadastrado !!! \n\n"); // Mensagem pro usu�rio
	system("Pause"); // Para o usu�rio ver a mensagem
}
int deletar(){ // Fun��o deletar
	setlocale(LC_ALL, "portuguese");
	
	printf("Digite o Cpf: ");
}

int main(){
	setlocale(LC_ALL, "portuguese"); //Definindo o Idioma
	
	int opcao; //Declarando Vari�veis tipo tipo string caracter
	int repeticao = 1; //Declarando Vari�veis tipo inteiro
	
	while (repeticao == 1){ // Enquanto repeti��o == 1 
		system("cls"); // Limpe a tela
		
		printf("=============== Cart�rioEBAC ===============\n\n"); // Cabe�alho
		printf("\t1 - Consultar cadastros\n"); // Inicio das op��es
		printf("\t2 - Cadastrar Usu�rio\n");
		printf("\t3 - Deletar Usu�rio\n");// fim das op��o 
		printf("\nSua Op��o: "); // Mensagem pro usu�rio
	
		  // L� a entrada do usu�rio e verifica se foi um n�mero inteiro
        if (scanf("%d", &opcao) != 1) {
        	system("cls");
            printf("Op��o inv�lida!! \nDigite apenas n�meros!!\n\n");
            while (getchar() != '\n'); // Limpa o buffer de entrada
            system("pause");
            continue; // Reinicia o loop para solicitar uma nova op��o
        }
		
		system("cls"); // Limpa a tela 
		
		switch(opcao) { // Encadeamento de ifs e else
	        case 1:
	            consulta();
	            break; // Interrompe a execu��o da estrutura
	        case 2:
	            cadastro(); // Chamado da fun��o cadastro 
	            break; // Interrompe a execu��o da estrutura
	        case 3:
	            printf("Deletar usu�rio\n"); // Mensagem pro usu�rio
	            system("pause"); // Pausa pro usu�rio ler a mensagem 
	            break; // Interrompe a execu��o da estrutura
	        default: // Serve como else
	            printf("Op��o Inv�lida!!\n"); // Mensagem pro usu�rio
	            system("pause"); // Pausa pro usu�rio ler a mensagem 
	            break; // Interrompe a execu��o da estrutura
		}
	}
}
