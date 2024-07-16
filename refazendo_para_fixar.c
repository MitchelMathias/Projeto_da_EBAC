#include <stdio.h> // Comunicação com o usuário
#include <stdlib.h> // Alcoação de memória
#include <locale.h> // Para definir a Região
#include <string.h> // Responsável pelas strings


int consulta(){ // Função consulta
	setlocale(LC_ALL, "portuguese"); //Definindo o Idioma
	
	printf("você escolheu Consultar um usuário!!\n\n");
	
	char cpf[12], nome[15], sobrenome[15], cargo[30], conteudo[72],cpf_busca[12]; // Declarando Variáveis
	
	printf("Digite o CPF: "); // Mensagem pro usuário 
	scanf("%s", cpf_busca); // Guarda a entrada na variável Cpf_busca
	
	FILE *arquivo; // Acesse a estrutura FILE e atribua o caminho na varivel arquivo
	arquivo = fopen("cadastros.txt", "r"); // abra o arquivo cadastros em txt e leia
	
	if (arquivo == NULL){ // se arquivo não encontrado 
		printf("Usuário não encontrado!!\n\n"); // Mensagem pro usuário	se o arquivo não foi encontrado é porque não teve usuário cadastrado 
	}
	int cpf_encontrado = 0; // declarando variável para corrigire o erro de repetição de usuário não cadastrado
	
	while(fgets(conteudo, sizeof(conteudo), arquivo) != NULL){ // Lê cada linha do arquivo e armazena em 'conteudo' até o tamanho de 'conteudo' ou até encontrar uma nova linha
		sscanf(conteudo, "%s - %s - %s - %s", cpf, nome, sobrenome, cargo); // Extrai dados formatados da string 'conteudo' e os armazena nas variáveis 'cpf', 'nome', 'sobrenome' e 'cargo'
		
		if (strcmp(cpf, cpf_busca) == 0){ // Compare cpf com cpf_busca e se o retorno da FUNÇÂO for == 0 que quer dizer exatamente iguais faça os comandos abaixo 
			printf("\nEssas são as informações do usuário!!\n\n");
			printf("\nNome: %s %s\n", nome, sobrenome); // Escreva Nome e depois os conteudos nome e sobrenome separados por um " "
			printf("Cpf: %s\n", cpf);// Escreva Cpf e dps o dado guardado em cpf 
			printf("Cargo: %s\n\n", cargo); // Escreve Cargo e dps o dado guardado em cargo 
			cpf_encontrado = 1;
			break; // para para não fazer isso com todas as linhas no arquvio cadastro.txt
		}
	}
	
	if(cpf_encontrado == 0){ // Corrigindo o erro de repetição de usuário não cadastrado
		printf("\nUsuário não cadastrado!!...\n\n"); // Caso não encontrou o CPF
	}
	fclose(arquivo);
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
	setlocale(LC_ALL, "portuguese"); // Definindo idioma
	
	char cpf[12], nome[15], sobrenome[15], cargo[30], conteudo[72],cpf_busca[12]; // Declarando Variáveis
	
	printf("Digite o CPF do usuário a ser deletado: "); // Mensagem pro usuário
	scanf("%s", cpf_busca); // Guardando o valor na variável cpf_busca 
	
	FILE *arquivo, *temp; // Acesse a estrutura FILE e atribua o caminho na varivel arquivo
	arquivo = fopen("cadastros.txt", "r"); // Abra o arquivo cadastros.txt e leia
	if (arquivo == NULL){ // se não existir
		printf("Nenhum usuário cadastrado"); // Mensagem pro usuário
	}
	temp = fopen("temp.txt", "w"); // Abra o arquivo temp.txt e escreva
	if (temp == NULL){ // se não existir 
		printf("Nenhum usuário cadastrado"); // Mensagem pro usuário 
		fclose(arquivo); // Fecha o arquivo 
	}
	int encontrado = 0; // Declarando variáveis 
	char verificador[10]; // Declarando variáveis 
	
	while(fgets(conteudo, sizeof(conteudo), arquivo) != NULL){ // Lê cada linha do arquivo e armazena em 'conteudo' até o tamanho de 'conteudo' ou até encontrar uma nova linha
		sscanf(conteudo, "%s - %s - %s - %s", cpf, nome, sobrenome, cargo); // Extrai quatro strings de 'conteudo' separadas por " - "
		
		if (strcmp(cpf, cpf_busca) == 0){ // compare cpf com cpf_ busca e "0" quer dizer se forem exatamente iguais
			printf("Confirme os dados do usuário a ser excluido!!\n\n"); // Mensagem pro usuário
			printf("Nome: %s %s", nome, sobrenome); // Escreve justificadamente o conteudo das variáveis Nome e sobrenome 
			printf("\nCPF: %s", cpf); // Escreve justificadamente o conteudo da variável cpf
			printf("\nCargo: %s\n", cargo); // Escreve justificadamente o conteudo da variável cargo
			encontrado = 1; // Variável recebe o valor "1"
			printf("Deseja excluir esse usuário? [S/N] --> "); // mensagem pro usuário 
			scanf("%s", verificador); // Guarda a resposta na variável cerificador
			if (verificador[0] == 'S' || verificador[0] == 's'){ // se verificador na posição 0 for igual a "s" ou "S" 
				printf("\nUsuário deletado\n\n"); // escreva usuário deletado
			}
			else{
				printf("\nUsuário não deletado\n\n"); // Se for diferente da condição si print usuário não deletado
			}
		}
		if (verificador[0] != 'S' || verificador[0] != 's'){ // Se verificador for diferente de 'S' e 's'
		fprintf(temp, "%s - %s - %s - %s\n",  cpf, nome, sobrenome, cargo); // escreva dentro do arquivo tempo de forma justificada  cpf, nome, sobrenome, cargo, separadas por um " - " 
		}
	}
	if (encontrado == 0){ // se o usuário não for encontrado 
		printf("\nUsuário não cadastrado !!... \n\n "); // Mensagem pro usuário
	}
	fclose(arquivo); // Fecha o arquivo no caminho arquivo
	fclose(temp); // Fecha o arquivo no caminho temp
	
	remove("cadastros.txt"); // Apaga o arquivo cadastros.txt
	rename("temp.txt", "cadastros.txt"); // Renomeia o arquivo temp.txt para cadastros.txt
	
	system("pause"); // Pausa pro usuário ler as mensagens 
}
int main(){ // Função principal 
	setlocale(LC_ALL, "portuguese"); //Definindo o Idioma
	
	int opcao; //Declarando Variáveis tipo tipo string caracter
	int repeticao = 1; //Declarando Variáveis tipo inteiro
	
	while (repeticao == 1){ // Enquanto repetição == 1 
		system("cls"); // Limpe a tela
		
		printf("=============== CartórioEBAC ===============\n"); // Cabeçalho
		printf("Escolha uma das opções abaixo: \n\n");
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
	            deletar();
	            break; // Interrompe a execução da estrutura
	        default: // Serve como else
	            printf("Opção Inválida!!\n"); // Mensagem pro usuário
	            system("pause"); // Pausa pro usuário ler a mensagem 
	            break; // Interrompe a execução da estrutura
		}
	}
}
