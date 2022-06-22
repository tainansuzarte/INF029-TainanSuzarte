#include <stdio.h>
#include <assert.h>

float pell(int n) {
  if (n==0)
    return 0;
  if (n==1)
    return 1;
  else if(n<0){
    printf("Erro! Numero Inteiro menor que 0!");
    return 0;
  }
  else
    return 2*pell(n-1) + pell(n-2);
}

int main() {

    int n;


    printf("Insira o termo que deseja saber da seq. Pell :");
    scanf("%d",&n);

    printf("O número pell é %0.f",pell(n-1));

    
    return 0;
}