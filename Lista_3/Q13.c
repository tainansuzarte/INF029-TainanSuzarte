#include <stdio.h>
#include <assert.h>


void desce(int n) {
  
  if(n == 0)
    printf("Você chegou no O! \n");
  else if(n>0){
    printf("Você está no %d \n",n);
    desce(n-1);
  }
 }

int main() {

    int n;
  
      printf("Insira até onde deseja começar :");
      scanf("%d",&n);

      desce(n);

    
    return 0;
}
