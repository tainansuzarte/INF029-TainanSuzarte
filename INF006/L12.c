#include <stdio.h>
#include <stdio.h>


int main(void){
 
  int f, filhos=0, cont=1, pop=0, menor150=0;
  float s, salarios, maior=0, porc; 



  while(cont==1){
    printf("Digite o salário do morador:");
    scanf("%f", &s);
    getchar();
    printf("Digite a quantidade de filhos:");
    scanf("%d", &f);
    getchar();

    if(s>maior){
      maior=s;
    }

    if(s<150){
      menor150=menor150+1;
    }
    pop=pop+1;
    filhos=filhos+f; 
    salarios=salarios+s;

    printf("Deseja Continuar inserindo? (1- Sim, 0-Não):");
    scanf("%d", &cont);
    getchar();
    }
  
  porc=(menor150/pop)*100;
  
  printf("Média de Filhos = %d\n", filhos/pop);
  printf("Média de Salario = R$ %.2f /pessoa \n ", salarios/pop);
  printf("Maior Salario= R$ %.2f \n", maior);
  printf("%.2f %% da população tem salario menor de R$150,00",porc);
  
  getchar();
  return 1;
  }