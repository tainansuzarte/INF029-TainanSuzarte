#include <stdio.h>
#include <stdio.h>

 
// Protótipo da função de ordenação, possui o ponteiro para a apontar para vet que é criado no main
void ordenar(int *a);
 
// Função main
int main(void)
{
  //Declaração inicial do vetor sem organização
 int i, vet[10]={67, 34,99,12,7,5, 1, 50, 20,34};
 
 
 // Chamada da função para Ordenar os valores
 ordenar(vet);
 
 // Impressão do vetor ordenado
 printf("---Valores ordenados Decrescente--\n");
 for(i = 0; i < 10; i++)
 {
  printf("%d - ", vet[i]);
 }
 return 0;
}
 
// Função de Ordenação por Inserção, a variavel temp aloca temporiamente o valor do vetor na posição antes de comparar e realocar
void ordenar(int *a)
{
 int i, j, temp;
  
 for(i = 1; i < 10; i++)
 {
  temp = a[i];
  for(j = i-1; j <= 99 && temp > a[j]; j--)
  {
   a[j+1] = a[j];
  }
  a[j+1] = temp;
 }
}