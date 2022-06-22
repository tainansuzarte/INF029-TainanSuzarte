#include <stdio.h>
#include <assert.h>

float padovan(int n) {
  if (n==1 || n==0 || n==2)
    return 1;
  else if(n<0){
    printf("Erro! Numero Inteiro menor que 0!");
    return 0;
  }
  else
    return padovan(n-2) + padovan(n-3);
}

int main() {

    int n;


    printf("Insira o termo que deseja saber da seq. Padovan :");
    scanf("%d",&n);

    printf("O número padovan é %0.f",padovan(n-1));

    
    return 0;
}