#include <stdio.h>

int main(){
  int n1, res;
  
  printf("Digite um numero: \n");
  scanf("%d",&n1);
  res=1;
  
  while(n1>0){
    res=res*n1;
    n1=n1-1;
  }

    printf("O  fatorial do número digitado é : %d \n",res);
 
    
  }