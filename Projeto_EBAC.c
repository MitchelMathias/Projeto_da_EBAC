#include <stdio.h> // Comunicação com o usuário
#include <stdlib.h> // Alocação de memória
#include <locale.h> // Para definir o texto por região
#include <string.h> // Responsável pelas strings
#include <windows.h> // Nesse Programa estou usando a função sleep
//
int consulta() { // Função consulta
    setlocale(LC_ALL, "portuguese"); // Definindo o Idioma
    
    char cpf[12], nome[15], sobrenome[15], cargo[30], conteudo[72], cpf_busca[12]; // Declarando Variáveis
   
    char repeticao[2]; // Declarando variável
    do { // faça enquanto a condição for verdadeira
        printf("Você escolheu Consultar um usuário!!\n\n"); // Mensagem para o usuário 
        printf("Digite o CPF: "); // Mensagem para o usuário 
        scanf("%s", cpf_busca); // Guarda a entrada na variável cpf_busca
    
        FILE *arquivo; // Acesse a estrutura FILE e atribua o caminho na variável arquivo
        arquivo = fopen("cadastros.txt", "r"); // Abra o arquivo cadastros em txt e leia
        if (arquivo == NULL) { // Se arquivo não encontrado 
            printf("Nenhum usuário cadastrado...\n"); // Mensagem para o usuário
        }
        
        int cpf_encontrado = 0; // Declarando variável para corrigir o erro de repetição de usuário não cadastrado
    
        while (fgets(conteudo, sizeof(conteudo), arquivo) != NULL) { // Lê cada linha do arquivo e armazena em 'conteudo' até o tamanho de 'conteudo' ou até encontrar uma nova linha
            sscanf(conteudo, "%s - %s - %s - %s", cpf, nome, sobrenome, cargo); // Extrai dados formatados da string 'conteudo' e os armazena nas variáveis 'cpf', 'nome', 'sobrenome' e 'cargo'
    
            if (strcmp(cpf, cpf_busca) == 0) { // Compare cpf com cpf_busca e se o retorno da FUNÇÃO for == 0, o que quer dizer exatamente iguais, faça os comandos abaixo 
                printf("\nEssas são as informações do usuário!!\n\n"); // Mensagem para o usuário
                printf("\nNome: %s %s\n", nome, sobrenome); // Escreve Nome e depois os conteúdos nome e sobrenome separados por um " "
                printf("Cpf: %s\n", cpf); // Escreve Cpf e depois o dado guardado em cpf 
                printf("Cargo: %s\n\n", cargo); // Escreve Cargo e depois o dado guardado em cargo 
                cpf_encontrado = 1; // Se tiver um cpf idêntico ao cpf busca, a variável recebe o valor de 1
                break; // Pare
            }
        }
    
        if (cpf_encontrado == 0) { // Corrigindo o erro de repetição de usuário não cadastrado
            printf("\nUsuário não cadastrado!!...\n\n"); // Caso não encontrou o CPF
        }
        fclose(arquivo); // Fecha o arquivo
        do { // Faça abaixo enquanto a condição for diferente
            printf("Quer consultar mais 1 usuário? [S/N] --> "); // Mensagem para o usuário
            scanf("%s", repeticao ); // Salve dado tipo string na variável repetição
            printf("\n"); // Pula uma linha
        } while(repeticao[0] != 'S' && repeticao[0] != 's' && repeticao[0] != 'N' && repeticao[0] != 'n'); // Faça enquanto a condição for diferente
    
        system("cls"); // Limpa a tela
    } while (repeticao[0] == 'S' || repeticao[0] == 's'); // Enquanto a condição for igual a S repita
    return 0;
}
int deletar() { // Função deletar
    setlocale(LC_ALL, "portuguese"); // Definindo o idioma
    
    char repeticao[2];
    char cpf[12], nome[15], sobrenome[15], cargo[30], conteudo[72], cpf_busca[12]; // Declarando variáveis
    
    do {
        printf("Digite o CPF do usuário a ser deletado: "); // Mensagem para o usuário
        scanf("%s", cpf_busca); // Guardando o valor na variável cpf_busca 
    
        FILE *arquivo, *temp; // Acesse a estrutura FILE e atribua o caminho na variável arquivo
        arquivo = fopen("cadastros.txt", "r"); // Abra o arquivo cadastros.txt e leia
        if (arquivo == NULL) { // Se não existir
            printf("Nenhum usuário cadastrado"); // Mensagem para o usuário
            return 1; // Encerrar a função se o arquivo não puder ser aberto
        }
        temp = fopen("temp.txt", "w"); // Abra o arquivo temp.txt e escreva
        if (temp == NULL) { // Se não existir 
            printf("Não foi possível criar o arquivo temporário"); // Mensagem para o usuário 
            fclose(arquivo); // Fecha o arquivo 
            return 1; // Encerrar a função se o arquivo não puder ser criado
        }
        int encontrado = 0; // Declarando variáveis 
        char verificador[2]; // Declarando variáveis 
    
        while (fgets(conteudo, sizeof(conteudo), arquivo) != NULL) { // Lê cada linha do arquivo e armazena em 'conteudo' até o tamanho de 'conteudo' ou até encontrar uma nova linha
            sscanf(conteudo, "%s - %s - %s - %s", cpf, nome, sobrenome, cargo); // Extrai quatro strings de 'conteudo' separadas por " - "
    
            if (strcmp(cpf, cpf_busca) == 0) { // Compare cpf com cpf_busca e "0" quer dizer se forem exatamente iguais
                printf("Confirme os dados do usuário a ser excluído!!\n\n"); // Mensagem para o usuário
                printf("Nome: %s %s", nome, sobrenome); // Escreve justificadamente o conteúdo das variáveis Nome e sobrenome 
                printf("\nCPF: %s", cpf); // Escreve justificadamente o conteúdo da variável cpf
                printf("\nCargo: %s\n", cargo); // Escreve justificadamente o conteúdo da variável cargo
                encontrado = 1; // Variável recebe o valor "1"
                printf("Deseja excluir esse usuário? [S/N] --> "); // Mensagem para o usuário 
                scanf("%s", verificador); // Guarda a resposta na variável verificador
                if (verificador[0] == 'S' || verificador[0] == 's') { // Se verificador na posição 0 for igual a "s" ou "S" 
                    printf("\nUsuário deletado\n\n"); // Escreve usuário deletado
                    continue;
                } else {
                    printf("\nUsuário não deletado\n\n"); // Se for diferente da condição acima, imprime usuário não deletado
                }
            }
            fprintf(temp, "%s - %s - %s - %s\n", cpf, nome, sobrenome, cargo); // Escreve dentro do arquivo temp de forma justificada cpf, nome, sobrenome, cargo, separados por um " - " 
        }
        if (encontrado == 0) { // Se o usuário não for encontrado 
            printf("\nUsuário não cadastrado !!... \n\n"); // Mensagem para o usuário
        }
        fclose(arquivo); // Fecha o arquivo no caminho arquivo
        fclose(temp); // Fecha o arquivo no caminho temp
    
        remove("cadastros.txt"); // Apaga o arquivo cadastros.txt
        rename("temp.txt", "cadastros.txt"); // Renomeia o arquivo temp.txt para cadastros.txt
        
        printf("Quer deletar mais algum usuário? [S/N] --> "); // Mensagem para o usuário
        scanf("%s", repeticao); // Salva como string na variável repetição
        
        system("cls"); // Limpa a tela
        
    } while (repeticao[0] == 's' || repeticao[0] == 'S'); // Enquanto for igual a 's' ou 'S'
    
    return 0;
}
int cadastro() { // Função cadastro
    setlocale(LC_ALL, "portuguese"); // Definindo o idioma

    printf("Você escolheu Cadastrar usuário!!\n\n"); // Mensagem para o usuário
    
    char repeticao[2]; // Declarando variável 
    int continua_repeticao = 1; // Declarando variável e atribuindo o valor de 1
    char cpf[12], nome[15], sobrenome[15], cargo[30], cpf_busca[12], conteudo[72]; // Declarando variáveis tipo string caracteres
    int opcao = 1, cpf_encontrado = 0; // Declarando variáveis tipo inteiro
    
    do { // Faça enquanto a condição for verdadeira
        cpf_encontrado = 0;
        
        FILE *arquivo; // Acesse a estrutura FILE e atribua o caminho na variável arquivo
        arquivo = fopen("cadastros.txt", "r"); // Abra o arquivo do caminho arquivo e atualiza ou cria o arquivo
        if (arquivo == NULL) { // Se arquivo == a NULL
            printf(""); // Mensagem para o usuário
        }
        
        printf("Vamos Começar!!!\n\n"); // Mensagem para o usuário
    
        printf("Digite o CPF: "); // Mensagem para o usuário
        scanf("%s", cpf); // Guardando o dado na variável CPF 
        
        strcpy(cpf_busca, cpf); // Copia o dado da variável cpf_busca para cpf
        
        while(fgets(conteudo, sizeof(conteudo), arquivo) != NULL){ // Enquanto houver linhas para ler no arquivo (fgets retorna um ponteiro não nulo) lê a linha do arquivo e armazena no (buffer = armazenamento temporário) 'conteudo' com tamanho máximo especificado.
            sscanf(conteudo, "%s - %s - %s - %s", cpf, nome, sobrenome, cargo); // Separa e armazena o conteúdo do buffer em variáveis 
            
            if (strcmp(cpf, cpf_busca) == 0){ // Se o retorno da função strcmp() for == 0 quer dizer que são exatamente iguais
                printf("\nJá tem um usuário cadastrado com esse CPF!!"); // Mensagem para o usuário
                cpf_encontrado += 1; // Variável recebe ela mesma +1
                break; // Sai do loop
            }
        }
        fclose(arquivo); // Fecha o arquivo
        
        if (cpf_encontrado >= 1){ // Se cpf_encontrado for maior que 1 faça
            printf("\n\nEscolha uma das opções abaixo:\n\n"); // Cabeçalho do menu
            printf("\t1 - Deletar registro\n"); // Opção 1
            printf("\t2 - Cancelar\n"); // Opção 2
            printf("\t\nEscolha uma opção -->  ");// Mensagem para o usuário
            scanf("%d", &opcao); // Salva tipo inteiro na variável opção
            
            switch(opcao){ // Ifs e else 
                case 1: // Opção 1
                    system("cls"); // Limpa tela
                    deletar(); // Chama a função deletar
                    return 0;
                    break; 
                case 2: // Opção 2
                    system("cls"); // Limpa a tela e não faz nada demais 
                    return 0;
                    break;
                default: // Caso contrário 
                    system("cls"); // Limpa tela
                    printf("Opção inválida!!!\n");// Escreve para o usuário
                    break;
            }
        }
        else{ // Se cpf encontrado for menor que 1 
            arquivo = fopen("cadastros.txt", "a"); // Abre o arquivo
            if(arquivo == NULL){ // Se não existir o arquivo 
                printf("Erro ao abrir o arquivo!!\n"); // Escreva a mensagem
            }
            
            printf("Nome: "); // Mensagem para o usuário
            scanf("%s", nome); // Guardando o dado na variável nome 
        
            printf("Sobrenome: "); // Mensagem para o usuário
            scanf("%s", sobrenome); // Guardando o dado na variável sobrenome 
        
            printf("Cargo: "); // Mensagem para o usuário
            scanf("%s", cargo); // Guardando o dado na variável cargo 
            
            fprintf(arquivo, "%s - %s - %s - %s\n", cpf_busca, nome, sobrenome, cargo); // Escreva no arquivo de maneira formatada
            fclose(arquivo); // Fecha o arquivo
            
            printf("\nUsuário cadastrado com sucesso!!"); // Escreve a mensagem para o usuário 
            
            do { // Faça enquanto a condição for verdadeira
                printf("\nQuer cadastrar mais 1 usuário? [S/N] --> "); // Mensagem para o usuário
                scanf("%s", repeticao ); // Salva como string na variável repetição
                printf("\n");
            } while(repeticao[0] != 'S' && repeticao[0] != 's' && repeticao[0] != 'N' && repeticao[0] != 'n'); // Enquanto diferente de 'SsNn'
            
            if (repeticao[0] != 'S' && repeticao[0] != 's'){ // Se repetição na posição zero for diferente de 'Ss'
                continua_repeticao = 0; // continua repetição recebe o valor de zero
            }    
        }
        system("cls"); // Limpa tela
    } while (continua_repeticao == 1 ); // Enquanto continua_repeticao for == 1
    return 0;
}
int main() { // Função principal onde puxa as outras funções
    setlocale(LC_ALL, "portuguese"); // Definindo o idioma

    int opcao; // Declarando variável tipo inteiro
    int repeticao = 1; // Declarando variável tipo inteiro
    char login[] = " ", senha[] = " ";

    printf("=============== Cartório EBAC ===============\n");
    printf("\tLogin: ");
    scanf("%s", login);
    printf("\tSenha: ");
    scanf("%s", senha);

    if (strcmp(senha, "admin") == 0 || strcmp(login, "admin") == 0) {
        printf("Acessando o Sistema...");
        printf("3..");
        Sleep(300);
        printf("2..");
        Sleep(300);
        printf("1..");
        Sleep(300);

        while (repeticao == 1) { // Enquanto repeticao == 1 
            system("cls"); // Limpa a tela

            printf("=============== Cartório EBAC ===============\n"); // Cabeçalho
            printf("Escolha uma das opções abaixo: \n\n");
            printf("\t1 - Consultar cadastros\n"); // Início das opções
            printf("\t2 - Cadastrar Usuário\n");
            printf("\t3 - Deletar Usuário\n"); // Fim das opções 
            printf("\t4 - Sair do sistema\n"); // Sai do programa
            printf("\nSua Opção: "); // Mensagem para o usuário

            // Lê a entrada do usuário e verifica se foi um número inteiro
            if (scanf("%d", &opcao) != 1) {
                system("cls");
                printf("Opção inválida!! \nDigite apenas números!!\n\n");
                while (getchar() != '\n'); // Limpa o buffer de entrada
                system("pause");
                continue; // Reinicia o loop para solicitar uma nova opção
            }

            system("cls"); // Limpa a tela 

            switch (opcao) { // Encadeamento de ifs e else
                case 1:
                    consulta();
                    break; // Interrompe a execução da estrutura
                case 2:
                    cadastro(); // Chama a função cadastro 
                    break; // Interrompe a execução da estrutura
                case 3:
                    deletar();
                    break; // Interrompe a execução da estrutura
                case 4:
                    printf("Obrigado por usar nosso sistema!!\n"); // Mensagem para o usuário
                    return 0; // Retorna que não houve erro
                default: // Serve como else
                    printf("Opção Inválida!!\n"); // Mensagem para o usuário
                    system("pause"); // Pausa para o usuário ler a mensagem 
                    break; // Interrompe a execução da estrutura
            }
        }
    } else {
        printf("Usuário não autorizado a acessar o Sistema\n\n");
        printf("Saindo do Sistema");
        system("pause");
    }
}
