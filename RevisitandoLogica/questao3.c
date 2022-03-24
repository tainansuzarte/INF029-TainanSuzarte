#include <stdio.h>

int main(){
  int n1, n2;
  
  printf("Digite o 1ª numero: \n");
  scanf("%d",&n1);
  printf("Digite o 2ª numero: \n");
  scanf("%d",&n2);
  n1=n1+n2;
  n2=n1-n2;
  n1=n1-n2;  
  
  printf("Agora, o 1º numero é: %d ; e o 2º: %d",n1,n2);
  
  }