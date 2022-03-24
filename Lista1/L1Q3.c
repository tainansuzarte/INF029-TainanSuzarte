#include <stdio.h>
#include <stdio.h>

int fatorial(int N1){
  int result, buffer;

  if(N1<0){
    printf("Não é possível calcular o fatorial");
  }
  else{
    result=1;
    while(N1>0){
      result=N1*result;
      N1=N1-1;
    } 
  }
 

  return(result);
}

int main(void){
 
  int V1, resultado;
  printf("Digite o valor:");
  scanf("%d", &V1);
   
  resultado = fatorial(V1);
  
  printf("Resultado do Fatorial = %d\n", resultado);
  
  getchar();
  return 0;
  }