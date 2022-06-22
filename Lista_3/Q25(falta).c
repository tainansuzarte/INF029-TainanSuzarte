#include <stdio.h>
#include <assert.h>

float catalan(int n) {
  if (n==0 || n==1)
    return 1;
  else if(n<0){
    printf("Erro! Numero Inteiro menor que 0!");
    return 0;
  }
  else
    return (((4*n)-2)/(n+1))*catalan(n-1);
}

int main() {

    int n;


    printf("Insira o termo que deseja saber da seq. Catalan :");
    scanf("%d",&n);

    printf("O número catalan é %0.f",catalan(n-1));

    
    return 0;
}