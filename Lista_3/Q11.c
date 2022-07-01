#include <stdio.h>
#include <assert.h>
#define TAM 5


float multiplicar(int n,int x) {
  float result=0;
  
  if(n == 0)
    return 0;
  else
    return x + multiplicar(n-1, x);
 }

int main() {

    int n, x;
  
      printf("Insira o primeiro número da multiplicação :");
      scanf("%d",&n);

      printf("Insira o segundo número da multiplicação :");
      scanf("%d",&x);  

      printf("A multiplicação é: %0.f ",multiplicar(n,x));

    
    return 0;
}
