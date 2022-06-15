#include <stdio.h>
#include <assert.h>

float fatorial(int n) {
    if (n == 0)
        return 1;
    else
        return (n * fatorial(n - 1));
}

int main() {

    int i;
    int fim=20;
  
    for(i=0;i<=fim;i++){
      printf("Fatorial de %d: %0.f \n",i,fatorial(i));
    }
    
    return 0;
}