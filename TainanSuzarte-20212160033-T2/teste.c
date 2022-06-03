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

              vetorPrincipal[posicao-1]->valor=valor;
              
              vetorPrincipal[posicao - 1][0].espaco=vetorPrincipal[posicao - 1][0].espaco-1;
              //printf("%d.",vetorPrincipal[posicao - 1]->valor);
              //printf("Espaço: %d \n",vetorPrincipal[posicao - 1]->espaco);
              vetorPrincipal[posicao-1]->next=NULL;
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



int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    int retorno = SUCESSO;
    int i,j;
  
    if (posicao<1 || posicao>10)
        retorno = POSICAO_INVALIDA;
    else
    {
        // testar se existe a estrutura auxiliar
        if (vetorPrincipal[posicao - 1]!=NULL)
        {
            if (vetorPrincipal[posicao - 1][0].espaco!=vetorPrincipal[posicao - 1][0].tam)
            {
                //exclui
              
              vetorPrincipal[posicao - 1][0].espaco=vetorPrincipal[posicao - 1][0].espaco+1;
              //printf("Novo Espaco %d \n",vetorPrincipal[posicao - 1]->espaco);

              retorno = SUCESSO;
            }
            else
            {
                retorno = ESTRUTURA_AUXILIAR_VAZIA;
            }
        }
        else
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

    return retorno;
    
}

int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
  int retorno=0;
  int vetaux[1000], tam2, i, j=0;
  
    if (posicao<1 || posicao>10)
        retorno = POSICAO_INVALIDA;
    else
    {
        // testar se existe a estrutura auxiliar
        if (vetorPrincipal[posicao - 1]!=NULL)
        {
            if (vetorPrincipal[posicao - 1][0].espaco!=vetorPrincipal[posicao - 1][0].tam)
            {
                tam2=vetorPrincipal[posicao - 1][0].tam;
                //exclui
              while(i!=tam2+1){
                if(vetorPrincipal[posicao-1]->valor!=valor){
                  vetaux[i]=vetorPrincipal[posicao-1]->valor;
                  j++;
                }
                vetorPrincipal[posicao-1]->valor=NULL;
                vetorPrincipal[posicao-1]=vetorPrincipal[posicao-1]->next;                
              }

              for(i=0;i<j;i++){
                vetorPrincipal[posicao-1]->valor=vetaux[i];
                vetorPrincipal[posicao-1]=vetorPrincipal[posicao-1]->next;
              }
              
              vetorPrincipal[posicao - 1][0].espaco=tam2-j;
              printf("%d.",vetorPrincipal[posicao - 1]->espaco);
              if(j=0){
                retorno = SUCESSO;
              }else{
                retorno=NUMERO_INEXISTENTE;
              }
              
            }
            else
            {
                retorno = ESTRUTURA_AUXILIAR_VAZIA;
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
void testeExcluir();
void testeExcluirNumeroEspecifico()

int main()
{
    inicializar();
    //testeInserirSemNada();
    //testeCriarEstrutura();
    //testeInserirComEstrutura();
    //testeExcluir();
    testeExcluirNumeroEspecifico();
    
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

void testeExcluir()
{
    //show_log("testeExcluir()");
    //###  int excluirNumeroDoFinaldaEstrutura(int posicao); ###
    printf("%d\n", excluirNumeroDoFinaldaEstrutura(2) == SUCESSO);
    printf("%d\n", excluirNumeroDoFinaldaEstrutura(2) == SUCESSO);
    printf("%d\n", excluirNumeroDoFinaldaEstrutura(0) == POSICAO_INVALIDA);
    printf("%d\n", excluirNumeroDoFinaldaEstrutura(1) == SEM_ESTRUTURA_AUXILIAR);
    printf("%d\n", excluirNumeroDoFinaldaEstrutura(2) == SUCESSO);
    printf("%d\n", excluirNumeroDoFinaldaEstrutura(2) == ESTRUTURA_AUXILIAR_VAZIA);
}

void testeExcluirNumeroEspecifico()
{
    //show_log("testeExcluirNumeroEspecifico()");
    //###  int excluirNumeroEspecificoDeEstrutura(int posicao, int valor); ###
    printf("%d\n", criarEstruturaAuxiliar(9, 3) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(9, 7) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(9, 4) == SUCESSO);
    printf("%d\n", excluirNumeroEspecificoDeEstrutura(9, 12) == NUMERO_INEXISTENTE);
    printf("%d\n", excluirNumeroEspecificoDeEstrutura(9, 7) == SUCESSO);
    printf("%d\n", excluirNumeroEspecificoDeEstrutura(9, 4) == SUCESSO);
    printf("%d\n", excluirNumeroEspecificoDeEstrutura(1, 2) == SEM_ESTRUTURA_AUXILIAR);
}