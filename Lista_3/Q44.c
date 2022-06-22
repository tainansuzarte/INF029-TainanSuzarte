#include <stdio.h>
#include <assert.h>


float cubo(int k) {
  
  if(k == 1)
    return 1;
  else
    return k * k * k + cubo(k-1);
 }

int main() {

    int k;
  
      printf("Insira até que base :");
      scanf("%d",&k);
      

      printf("O resultado da Soma dos Cubos até %d é: %0.f ",k,cubo(k));

    
    return 0;
}
