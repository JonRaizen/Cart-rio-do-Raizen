#include <stdio.h> //biblioteca de comunica�ao com o usuario
#include <stdlib.h> //biblioteca de aloca�ao de espa�o em memoria
#include <locale.h> //biblioteca de aloca�oes de texto por regiao
#include <string.h> //biblioteca responsavel por cuidar das string
 
int registro() //fun�ao responsavel por cadastrar os usuarios no sistema
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de variaveis/string
	
	printf("Digite o CPF a ser cadastrado:  ");//coletando infoma��o do usuario 
	scanf("%s", cpf); //%s refere-se a string 
	
	strcpy(arquivo,cpf); //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");// abrir o arquivo ordenado
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
    system("pause");
}

int consultar()
{
	 setlocale(LC_ALL,"Portuguese"); //definindo a linguagem 
     
	 char cpf[40];
     char conteudo[250];
     
     printf("Digite o CPF a ser consultado: ");
     scanf("%s",cpf);
     
     FILE *file;
     file = fopen(cpf,"r");
     
     if(file == NULL)
      {
      	printf("N�o foi possivel abrir o arquivo, n�o localizado!\n");
	  }
	  
	  while(fgets(conteudo, 250, file) != NULL)
	  {
	    printf("\nEssas s�o as informa�oes do usu�rio: ");
	    printf("%s", conteudo);
	    printf("\n\n");
	  }
	  
	  system("pause");
    
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuario a ser deletado:  ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");// abrir o arquivo desejado e "r" significa o comando para ler"read" o arquivo 
	
	if(file == NULL)
	{
		printf("O usuario n�o se encontra no sistema!\n");
		system("pause");
	}
	
}
int main()
     {
      int opcao=0; //definindo variaveis
      int laco=1;
      
      for(laco=1;laco=1;)
      {
      	  system("cls");
      	  
      	  setlocale(LC_ALL,"Portuguese"); //definindo a linguagem 
      	  
      	  printf("### Cartorio do Raizen ###\n\n"); //inico do menu
      	  printf("Escolha a op��o desejada do menu\n\n");
      	  printf("\t1 - Registrar nomes\n");
      	  printf("\t2 - Consultar nomes\n");
      	  printf("\t3 - Deletar nomes\n\n");
      	  printf("Op��o:  "); //fim do menu
      	  
      	  scanf("%d", &opcao); //armazenando a escolha do usuario
      	  
      	  system("cls");//responsavel por limpar a tela
      	  
      	  switch(opcao) //inicio da sele��o do menu
      	  {
      	  	case 1:
      	  	registro();//chamada de fun��es  
      	  	break;
      	  	
      	  	case 2:
      	  	consultar();
      	  	break;
      	  	
      	  	case 3:
      	  	deletar();
      	  	break;
      	  	
      	  	default:
      	  	printf("Essa op��o n�o est� disponivel !\n");
      	  	system("pause");
      	  	break;
      	  	//fim da sele��o
			}
	  }
	 }
