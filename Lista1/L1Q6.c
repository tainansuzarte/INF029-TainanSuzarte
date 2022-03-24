#include <stdio.h>
#include <string.h>

typedef struct lista_letras
  {
    char let1;
    char let2;
    char let3;
  } letras; 

letras ler3letras(void){
  int ln;
  letras lista;

  printf("Digite a primeira letra:");
  lista.let1=getc(stdin);
  fflush(stdin);
  
  printf("Digite a segunda letra:");
  lista.let2=getchar();
  fflush(stdin);
  
  printf("Digite a terceira letra:");
  lista.let3=getchar();
  fflush(stdin);


  return (lista);
}

int main(void){

  letras listamain;
   
  listamain = ler3letras();

  printf("O primeiro numero foi %c \n",listamain.let1);
  printf("O segundo numero foi %c \n",listamain.let2);
  printf("O terceiro numero foi %c \n",listamain.let3);
  
    
  getchar();
  return 0;
  }