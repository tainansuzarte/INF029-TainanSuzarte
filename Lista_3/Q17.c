#include <stdio.h>
#include <assert.h>

float fatorial1(int n) {
    int x;
    if (n == 0)
        return 1;
    else
        x=n*2;
        return (x * fatorial1(n-1)) ;
}

float fatorial2(int n) {
    if (n == 0)
        return 1;
    else
        return (n * fatorial2(n - 1)) ;
}

int main() {

    int n;

      printf("Insira o número que deseja saber o fatorial Quadruplo:");
      scanf("%d",&n);
      printf("Fatorial Quadruplo de %d: %0.f \n",n,(fatorial1(n)/fatorial2(n))); 


    
    return 0;
}