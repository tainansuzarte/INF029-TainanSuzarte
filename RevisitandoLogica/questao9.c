#include <stdio.h>

int main(){
  int n1, div, cont, control,soma;

  control=1;
  soma=0;
  while(control<11){
    printf("Digite o %d º numero:", control);
    scanf("%d",&n1);
    div=1;
    cont=0;
  
    while(div<=n1){
      if(n1%div==0){
        cont=cont+1;
        
      }
      div=div+1;
    }
  
    if(cont>2){
      printf("Não é primo!\n");
    }
    else{
      printf("Número é primo!\n");
      soma=soma+n1;
    }
    control=control+1;
  }

  printf("A soma dos primos digitados é: %d \n",soma);
  
  
  
  }