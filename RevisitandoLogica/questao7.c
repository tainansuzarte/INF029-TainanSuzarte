#include <stdio.h>

int main(){
  int n1, div, cont;
  
  printf("Digite um numero: \n");
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
    printf("O número digitado  não é primo!");
  }
  else{
    printf("O número digitado é primo");
  }
  
  
  }