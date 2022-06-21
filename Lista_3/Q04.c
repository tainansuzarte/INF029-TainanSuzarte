#include <stdio.h>
#include <assert.h>
#define TAM 5


float somarVetor(int *vetor, int n) {
  float result=0;
  
  if(n == 1)
    return vetor[n-1];
  else
    return vetor[n-1] + somarVetor(vetor, n-1);
 }

int main() {

    int vet[TAM];
    int i ;


    for(i=0; i<TAM;i++){ 
      printf("Insira o %d º termo do Vetor :",i+1);
      scanf("%d",&vet[i]);
    }

    printf("A soma dos elementos: %0.f ",somarVetor(vet, TAM));

    
    return 0;
}
