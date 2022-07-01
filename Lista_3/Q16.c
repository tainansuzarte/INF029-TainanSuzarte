#include <stdio.h>
#include <assert.h>

float fatorial(int n) {
    if (n == 1)
        return 1;
    else
        return (n * fatorial(n - 2));
}

int main() {

    int n;

      printf("Insira o número impar que deseja saber o fatorial :");
      scanf("%d",&n);
      if(n%2!=0)
       printf("Fatorial de %d: %0.f \n",n,fatorial(n)); 
      else
        printf("Erro, numero par!");

    
    return 0;
}