#include <stdio.h>
#include <assert.h>
#define TAM 5


float somar(int n) {
  float result=0;
  
  if(n == 0)
    return 0;
  else
    return n + somar(n-1);
 }

int main() {

    int n;
  
      printf("Insira até onde deseja somar :");
      scanf("%d",&n);

      printf("A soma até %d: %0.f ",n,somar(n));

    
    return 0;
}
