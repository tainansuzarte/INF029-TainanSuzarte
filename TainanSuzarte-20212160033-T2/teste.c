#include <stdio.h>
#include <stdlib.h>
#define TAM 10



#include "TainanSuzarte-20212160033-T2.h"

vetorSecundario *vetorPrincipal[TAM];
void show_log(char *str);

int criarEstruturaAuxiliar(int posicao, int tamanho)
{
  int retorno = 0;

  if (posicao<1 || posicao>10){
      
      // se posição é um valor válido {entre 1 e 10}
      retorno = POSICAO_INVALIDA;
  }else if (tamanho<1){
      retorno = TAMANHO_INVALIDO; 
  }else if (vetorPrincipal[posicao - 1] != NULL){
      // a posicao pode já existir estrutura auxiliar
      retorno = JA_TEM_ESTRUTURA_AUXILIAR;
  }else{
      vetorPrincipal[posicao - 1] = (vetorSecundario *)malloc(sizeof(vetorSecundario) * tamanho);


      vetorPrincipal[posicao - 1][0].tam = tamanho;
      vetorPrincipal[posicao - 1][0].espaco = tamanho;
      retorno = SUCESSO;
  }  

    return retorno;
}




int inserirNumeroEstrutura(int posicao, int valor)
{
    int retorno = 0;
    int existeEstruturaAuxiliar = 0;
    int temEspaco = 0;
    int posicao_invalida = 0;

    if (posicao<1 || posicao>10)
        retorno = POSICAO_INVALIDA;
    else
    {
        // testar se existe a estrutura auxiliar
        if (vetorPrincipal[posicao - 1]!=NULL)
        {
            if (vetorPrincipal[posicao - 1][0].espaco!=0)
            {
                //insere
                vetorPrincipal[posicao - 1][0].espaco=vetorPrincipal[posicao - 1][0].espaco-1;
                retorno = SUCESSO;
            }
            else
            {
                retorno = SEM_ESPACO;
            }
        }
        else
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

    return retorno;
}

void inicializar()
{
  int i;
  for(i=0;i<TAM;i++){
    vetorPrincipal[i]=NULL;
  }
    
}


void finalizar()
{
      for (int i = 0; i < TAM; i++)
        free(vetorPrincipal[i]);
}

void testeCriarEstrutura();
void testeInserirSemNada();
void testeInserirComEstrutura();

int main()
{
    inicializar();
    testeInserirSemNada();
    testeCriarEstrutura();
    testeInserirComEstrutura();
    
    /*testeCriarEstrutura();
    testeInserirComEstrutura();
    testeExcluir();
    testeExcluirNumeroEspecifico();
    testeListar();
    testeRetornarTodosNumeros();
    testeMudarTamanhoEstrutura();
    testeListaEncadeada();*/
    finalizar();
}


void testeCriarEstrutura()
{
    //show_log("testeCriarEstrutura()");
    printf("%d\n", criarEstruturaAuxiliar(-2, 5) == POSICAO_INVALIDA);
    printf("%d\n", criarEstruturaAuxiliar(0, 5) == POSICAO_INVALIDA);
    printf("%d\n", criarEstruturaAuxiliar(11, 5) == POSICAO_INVALIDA);
    printf("%d\n", criarEstruturaAuxiliar(2, -5) == TAMANHO_INVALIDO);
    printf("%d\n", criarEstruturaAuxiliar(2, 0) == TAMANHO_INVALIDO);
    printf("%d\n", criarEstruturaAuxiliar(2, 3) == SUCESSO);
    printf("%d\n", criarEstruturaAuxiliar(2, 6) == JA_TEM_ESTRUTURA_AUXILIAR);
}

void testeInserirSemNada()
{
    //show_log("testeInserirSemNada()");
    printf("%d\n", inserirNumeroEstrutura(2, 2) == SEM_ESTRUTURA_AUXILIAR);
    printf("%d\n", inserirNumeroEstrutura(-2, 2) == POSICAO_INVALIDA);
    printf("%d\n", inserirNumeroEstrutura(0, 2) == POSICAO_INVALIDA);
    printf("%d\n", inserirNumeroEstrutura(11, 2) == POSICAO_INVALIDA);
}

void testeInserirComEstrutura()
{
    //show_log("testeInserirComEstrutura()");
    //###  int inserirNumeroEmEstrutura(int valor, int posicao); ###
    printf("%d\n", inserirNumeroEstrutura(2, 4) == SUCESSO);
    printf("%d\n", inserirNumeroEstrutura(2, -2) == SUCESSO);
    printf("%d\n", inserirNumeroEstrutura(2, 6) == SUCESSO);
    printf("%d\n", inserirNumeroEstrutura(2, 5) == SEM_ESPACO);
}