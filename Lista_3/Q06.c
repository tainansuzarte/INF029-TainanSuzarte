#include <stdio.h>
#include <assert.h>


float elevar(int n, int k) {
  float result=0;
  
  if(n == 0)
    return 1;
  else if(n==1)
    return k;
  else
    return k * elevar(n-1 , k);
 }

int main() {

    int n,k;
    int res;
  
      printf("Insira a base :");
      scanf("%d",&k);

      printf("Insira o expoente :");
      scanf("%d",&n);

      

      printf("O resultado da Exponencição é: %0.f ",elevar(n, k));

    
    return 0;
}
