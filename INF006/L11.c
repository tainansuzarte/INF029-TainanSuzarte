#include <stdio.h>
#include <stdio.h>


int main(void){
 
  int x, quant=0, cont=1;
  float y, estoque; 

;
  estoque=0;

  while(cont==1){
    printf("Digite a quantidade de itens do produto:");
    scanf("%d", &x);
    getchar();
    printf("Digite o preço unitario do produto:");
    scanf("%f", &y);
    getchar();

    estoque=estoque+(x*y);
    quant=quant+x;
    printf("Deseja Continuar inserindo? (1- Sim, 0-Não):");
    scanf("%d", &cont);
    getchar();
    }
  printf("Total do Estoque = R$ %.2f\n", estoque);
  printf("Média de Valor do Estoque = R$ %.2f /und \n ", estoque/quant);
  
  getchar();
  return 1;
  }