#include <stdio.h>
#include <stdio.h>

int subtrai(int N1, int N2, int N3){
  int result;

  result=(N1-N2)-N3;

  return(result);
}

int main(void){
 
  int V1, V2, V3, resultado;
  printf("Digite o primeiro valor:");
  scanf("%d", &V1);
  printf("Digite o segundo valor:");
  scanf("%d", &V2);
  printf("Digite o terceiro valor:");
  scanf("%d", &V3);
  
 
  resultado = subtrai(V1,V2,V3);
  
  printf("Resultado da Subtração = %d\n", resultado);
  
  getchar();
  return 0;
  }