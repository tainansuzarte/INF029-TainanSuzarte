#include <stdio.h>
#include <assert.h>

float fibo(int n) {
  if (n==1 || n==0)
    return n;
  else
    return fibo(n-1) + fibo(n-2);
}

int main() {

    int n=3;
    int i, fim=10;


    for(i=1; i<fim;i++)  
      printf("O %d º termo da Sequencia de Fibonacci : %0.f \n",i,fibo(i-1));

    
    return 0;
}