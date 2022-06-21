#include <stdio.h>
#include <assert.h>


void sobe(int limite, int n) {

  if (limite==n)
  	printf("Nível %d \n",n);
  else{
    printf("Nível %d \n",n);
    sobe(limite, n+1);
 }
}

int main() {

    int n;
  
      printf("Insira até onde deseja ir :");
      scanf("%d",&n);

      sobe(n, 0);

    
    return 0;
}
