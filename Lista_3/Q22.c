#include <stdio.h>
#include <assert.h>

float tetra(int n) {
  if (n==1 || n==0 || n==2)
    return 0;
  else if(n==3)
    return 1;
  else
    return tetra(n-1) + tetra(n-2) + tetra(n-3) + tetra(n-4);
}

int main() {

    int n;


    printf("Insira o termo que deseja saber da seq. Tetranaci :");
    scanf("%d",&n);

    printf("O número tetranachi é %0.f",tetra(n-1));

    
    return 0;
}