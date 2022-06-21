#include <stdio.h>
#include <assert.h>


void sobe(int limite, int n) {

  if (limite==n)
  	printf("Nível %d \n",n);
  else{
    printf("Nível %d \n",n);
    sobe(limite, n+2);
 }
}

int main() {

    int n;
  
      printf("Insira o numero par até onde deseja ir :");
      scanf("%d",&n);
      if(n%2==0)
       sobe(n, 0); 
      else
        printf("Erro, numero impar!");
       
    return 0;
}
