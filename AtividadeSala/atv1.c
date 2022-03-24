#include <stdio.h>
#include <stdio.h>

int soma(int N1, int N2){
  int result;

  result=N1+N2;

  return(result);
}

int subtracao(int N1, int N2){
  int result;

  result=N1-N2;

  return(result);
}

int multiplicacao(int N1, int N2){
  int result;

  result=N1*N2;

  return(result);
}

int main(){
 
  int V1, V2, rsoma, rsub, rmult;
  
  printf("Digite o primeiro valor:");
  scanf("%d", &V1);
  printf("Digite o segundo valor:");
  scanf("%d", &V2);
  
 
  rsoma = soma(V1,V2);
  rsub = subtracao(V1,V2);
  rmult = multiplicacao(rsoma, rsub);
  
  printf("Resultado da Soma = %d\n", rsoma);
  printf("Resultado da Subtração = %d\n", rsub);
  printf("Resultado da Multiplicacao dos Resultados = %d\n", rmult);
  
  
  getchar();
  return 0;
  }