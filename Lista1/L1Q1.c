#include <stdio.h>
#include <stdio.h>


int main(void){
 
  int x, quant;
  float y, estoque, 

  cont=1;
  quant=0;
  estoque=0;

  while(cont==1){
    printf("Digite a quantidade de itens do produto:");
    scanf("%d", &x);
    getchar();
    printf("Digite o preço unitario do produto:");
    scanf("%d", &y);
    getchar();

    estoque=estoque+(x*y);
    quant=quant+x;
    printf("Deseja Continuar inserindo? (1- Sim, 0-Não):");
    scanf("%d", &cont);
    getchar();
    }
  printf("Total do Estoque = %d\n", estoque);
  printf("Média de Valor do Estoque = %f \n item", estoque/quant);
  
  getchar();
  return 1;
  }