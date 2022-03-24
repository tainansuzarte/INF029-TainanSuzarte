#include <stdio.h>
#include <stdio.h>

typedef struct lista_numeros
  {
    int num1;
    int num2;
    int num3;
  } numeros; 

numeros ler4numeros(void){
  int i;
  numeros lista;

  printf("Digite o primeiro valor:");
  scanf("%d", &lista.num1);
  printf("Digite o segundo valor:");
  scanf("%d", &lista.num2);
  printf("Digite o terceiro valor:");
  scanf("%d", &lista.num3);


  return (lista);
}

int main(void){

  numeros listamain;
   
  listamain = ler4numeros();

  printf("O primeiro numero foi %d \n",listamain.num1);
  printf("O segundo numero foi %d \n",listamain.num2);
  printf("O terceiro numero foi %d \n",listamain.num3);
  
    
  getchar();
  return 0;
  }