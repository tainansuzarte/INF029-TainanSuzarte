#include <stdio.h>

int main(){
  int i1;
  
  printf("Digite a sua idade:");
  scanf("%d",&i1);

  while(i1>=0){
  if(i1<18){
    printf("Você é Menor de Idade! \n");
  }
  else{
    printf("Você é Maior de Idade! \n");
  }
    printf("Digite a sua idade(negativo para sair):");
    scanf("%d",&i1);
    
    }
    printf("Fim do Programa. \n");
  }