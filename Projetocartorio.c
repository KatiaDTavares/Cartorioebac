#include <stdio.h>//biblioteca de comunicação com o usuário
#include <stdlib.h>//biblioteca de alocação de espaços em memória
#include <locale.h>//biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsável por cuidar das string

int registro()//  função responsável por cadastrar os usuários no sistema
{
	//inicio da criação das strings (conjunto de variáveis)
   char arquivo[40];
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo[40];
   //final da criação das strings (conjunto de variáveis)
   
   
   printf("Digite o CPF a ser cadastrado:  ");//coletando informação do usuario
   scanf("%s",cpf);// %S refere-se a strings
   
   strcpy(arquivo, cpf); // responsavel por copiar os valores das string
   
   FILE *file; // cria o arquivo
   file= fopen(arquivo,"w"); // cria o arquivo e o "W" significa escrever
   fprintf(file,"CPF: ");
   fprintf(file,cpf); // salvo valor da variavel
   fclose(file); // fecha o arquivo
   
   file=fopen(arquivo,"a");
   fprintf(file,", Nome: ");
   fclose(file);
   
   printf("Digite o Nome a ser cadastrado: ");
   scanf("%s",nome);
   
   file= fopen(arquivo,"a"); // cria o arquivo
   fprintf(file,nome); // salvo vlor da variavel
   fclose(file); // fecha o arquivo
   
   file = fopen(arquivo, "a");
   fprintf(file," ");
   fclose(file);

   
   printf("Digite o Sobrenome a ser cadastrado: ");
   scanf("%s",sobrenome);
   
   file= fopen(arquivo,"a"); // cria o arquivo
   fprintf(file,sobrenome); // salvo vlor da variavel
   fclose(file); // fecha o arquivo
   
   file = fopen(arquivo, "a");
   fprintf(file,", Cargo: ");
   fclose(file);
   
   printf("Digite o Cargo a ser cadastrado: ");
   scanf("%s",cargo);
   
   file= fopen(arquivo,"a"); // cria o arquivo
   fprintf(file,cargo); // salvo vlor da variavel
   fclose(file); // fecha o arquivo
   
   system("pause");
   
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
  	char cpf[40];
  	char conteudo[200];
  	
  	printf("Digite o CPF a ser consultado: ");  
	scanf("%s",cpf);
	
	FILE *file; 
    file=fopen(cpf,"r");
    
    if(file ==NULL)
    {
    	printf("\nCPF não localizado, aperte o Enter e tente novamente!\n\n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\nEssas são as informações do usuario:\n\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
}

int deletar()
{
    char cpf[40];
    
    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%S",cpf);
    
    remove(cpf);
    
    FILE*file;
    file =fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf("O usuário nao se encontra no sistema!\n");
    	system("pause");
	}
}


int main()
{
	int opcao=0; // definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	    system("cls"); // Limpa a tela
	    
    	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
     	printf("#### Cartório da Katia ####\n\n"); // Inicio do menu
    	printf("Escolha a opção abaixo:\n\n");
        printf("\t1 - Registrar nomes:\n");
	    printf("\t2 - Consultar nomes:\n");
    	printf("\t3 - Deletar nomes:\n\n\n");
    	printf("\t4 - Sair do Sistema:\n\n");
	    printf("Qual opção você deseja: "); // Final do menu
	    	
    
        scanf("%d",&opcao); // Armazendo as informações, a escolha do usuario
    
        system("cls"); // Limpa a tela
        
        switch(opcao) // inicio da seleção
        {
        	case 1:
            registro();
			break;
			
			case 2:	
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			default:
			printf("Essa opção nao existe!!\n");
    		system("pause");
			break;	
			
			case 4:
			printf("Obrigada por ultilizar o sistema!\n");
			return 0;
			break;
			
		} // fim da seleção
     
    }
}
