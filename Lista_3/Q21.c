#include <stdio.h>
#include <assert.h>

float fibo(int n) {
  if (n==1 || n==0)
    return n;
  else
    return fibo(n-1) + fibo(n-2);
}

int main() {

    int n;
    int res;


    printf("Insira o termo que deseja saber da seq. Fibonacci :");
    scanf("%d",&n);

    printf("O número fibonachi é %0.f",fibo(n-1));

    
    return 0;
}