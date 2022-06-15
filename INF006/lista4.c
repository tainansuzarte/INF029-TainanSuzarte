#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM 1000
#define cod1 1000

typedef struct ficha_produto
{
    int cod;
    char nome[30];
    int qtd;
    float valorcompra;
    float valorvenda;
    
} ficha_produto;

ficha_produto *produtos[TAM];


void salvarArquivo();

void cadastrarProduto(){


  produtos= (ficha_produto*)malloc(sizeof(ficha_produto));

  produtos->cod=cod1+1;
  cod1++;
  
  printf("Nome do Produto:");
  fgets(produtos->nome, 31, stdin);
    ln = strlen(consumer.nome) - 1;
    if (produtos->nome == '\n')
        produtos->nome = '\0';
    fflush(stdin);

    while(produtos->qtd==0){
      printf("Quantidade:");
      scanf("%d", produtos->qtd);

      if(produtos->valorcompra==0){
      printf("valor incorreto. Inserir valor diferente de 0")
      }
    }


    while(produtos->valorcompra==0){
       printf("Valor da Compra:");
        scanf("%d", produtos->valorcompra);

        if(produtos->valorcompra==0){
          printf("valor incorreto. Inserir valor diferente de 0")
        }
      }

    salvarArquivo(produtos);  
    produtos->valorvenda=produtos->valorcompra*2.7;
    produtos->prox=NULL;

    
  
 
}

void consultarProduto(){

    ficha_produto *vetorSecundario = produtos;
    ficha_produto *anterior = produtos;

            while (vetorSecundario->prox != NULL)
            {
                if (vetorSecundario->cod == codigo)
                {
                    printf("Nome do Produto: %s", produtos->nome);
                    printf("Quantidade do Produto: %d", produtos->qtd);
                    printf("Valor de Compra do Produto: %d", produtos->valorcompra);
                    printf("Valor de Venda do Produto: %d", produtos->valor venda);
                }
                anterior = vetorSecundario;
                vetorSecundario = vetorSecundario->prox;
  
}
  
}

void atualizarProduto (int codigo){

    ficha_produto *vetorSecundario = produtos;
    ficha_produto *anterior = produtos;

            while (vetorSecundario->prox != NULL)
            {
                if (vetorSecundario->cod == codigo)
                {
                    printf("Nome do Produto:");
                    fgets(produtos->nome, 31, stdin);
                    ln = strlen(consumer.nome) - 1;
                    if (produtos->nome == '\n')
                    produtos->nome = '\0';
                    fflush(stdin);

                    while(produtos->qtd==0){
                        printf("Quantidade:");
                        scanf("%d", produtos->qtd);

                        if(produtos->valorcompra==0){
                        printf("valor incorreto. Inserir valor diferente de 0")
                      }
                    }


                    while(produtos->valorcompra==0){
                        printf("Valor da Compra:");
                      scanf("%d", produtos->valorcompra);

                      if(produtos->valorcompra==0){
                        printf("valor incorreto. Inserir valor diferente de 0")
                      }
                    }


                    produtos->valorvenda=produtos->valorcompra*2.7;
                }
                anterior = vetorSecundario;
                vetorSecundario = vetorSecundario->prox;
  
}
}

void eliminarProduto(int codigo){


    ficha_produto *vetorSecundario = produtos;
    ficha_produto *anterior = produtos;

            while (vetorSecundario->prox != NULL)
            {
                if (vetorSecundario->cod == codigo)
                {
                    produtos->cod = vetorSecundario->prox->cod;
                    produtos->nome = vetorSecundario->prox->nome;
                    produtos->qtd = vetorSecundario->prox->qtd;
                    produtos->valorcompra = vetorSecundario->prox->valorcompra;
                    produtos->valorvenda = vetorSecundario->prox->valorvenda;

                }
                anterior = vetorSecundario;
                vetorSecundario = vetorSecundario->prox;
  
}
  
}

void salvarAquivo(ficha_produto *produto){
  FILE *cadastro_produtos;

    cadastro_produtos = fopen("arquivo1.txt","w");
  if (cadastro_produtos == NULL)
  {
    printf("Erro ao tentar abrir o arquivo!");
    exit(1);
  }else{

    fputc(produto, cadastro_produtos);
  }


  fclose(pont_arq);

  
}

int menu(int op){

  int cod;
  
  switch (op)
{

   case 0:
     op=0;
     return op;
   break;
  
   case 1:
     cadastrarProduto();
     op=9;
     return op;
   break;

   case 2:
     printf("Digite o Código do Produto:");
     scanf("%d", cod);
     consultarProduto(int cod);
     op=9;
     return op;
   break;

    case 3:
     printf("Digite o Código do Produto:");
     scanf("%d", cod);      
     eliminarProduto(int cod);
     op=9;
     return op;      
     break;

    case 4:
     printf("Digite o Código do Produto:");
     scanf("%d", cod);
     atualizarProduto(int cod);
     op=9;
     return op;      
   break;

  default:
     printf ("Opção invalida!\n");
}
  
}

int main(void){

  int op=9;
  
   
  while(op!=0){

    printf("Sistema de Cadastro de Produtos. \n");
    printf("Menu Principal: \n");
    printf("1 - Cadastrar Produto \n");
    printf("2 - Consultar Produto \n");
    printf("3 - Apagar Produto: \n");
    printf("4 - Atualizar Produto \n");
    printf("0 - Sair \n");
    printf("Digite a opção desejada: ");
    scanf("%d", &op);
    op=menu(op);
   } 
  printf("Sistema Encerrado! \n");
  getchar();
  return 0;
  }