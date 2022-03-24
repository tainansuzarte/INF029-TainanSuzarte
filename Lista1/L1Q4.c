#include <stdio.h>
#include <stdio.h>

int ler3numeros(void){
  int i;
  int numeros[4];

  printf("Digite o primeiro valor:");
  scanf("%d", &numeros[1]);
  printf("Digite o segundo valor:");
  scanf("%d", &numeros[2]);
  printf("Digite o terceiro valor:");
  scanf("%d", &numeros[3]);

  for(i=1; i<4; i++){
    printf("O %d º numero: %d \n",i,numeros[i]);
  }
  return 0;
}

int main(void){
 
   
  ler3numeros();
    
  getchar();
  return 0;
  }