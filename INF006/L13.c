#include <stdio.h>
#include <stdio.h>


#include <stdio.h>
#include <stdio.h>

void lernumeros(void){
  int i, j=0;
  int numeros[20], busca, nvetor[20];


  for(i=0; i<20; i++){
    printf("Digite o %d º valor:",i+1);
    scanf("%d", &numeros[i]);
  }

    printf("Digite o numero que deseja buscar e excluir da lista:");
    scanf("%d", &busca);
  
    for(i=0; i<20; i++){
      if(busca!=numeros[i]){
        nvetor[j]=numeros[i];
        j++;
      }
  
      
  }

  printf("---Novo Vetor---\n");

  for(i=0; i<j; i++){
    printf("PosiÇão %d º: %d \n",i+1,nvetor[i]);
  }
  
  
  
}

int main(void){

   
  lernumeros();

  getchar();
  return 0;
  }