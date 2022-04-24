#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void teste(int num){

    int vetornum[100], vetorinvertido[100];
    size_t ln;
    float d1;
    int resto,i,j,pot, num1;
    char tam[10];
  

    sprintf(tam, "%d", num);
    ln = strlen(tam);

    d1=ln;
     
    resto=num;
    ln=ln-1;
  
    for(i=0;ln>0;i++){

      if(ln>1){
        pot=pow(10.0,ln);
        vetornum[i]=resto/pot;
        resto=resto%pot;
      }else{
        pot=pow(10.0,ln);
        vetornum[i]=resto/pot;
        vetornum[i+1]=resto%pot;
      }
      
      ln=ln-1;
      
    }
    j=0;
    ln=d1-1;
    for (i=d1-1;i>=0;i--){
      pot=pow(10.0,ln);
      vetorinvertido[j]=vetornum[i]*pot;
      ln=ln-1;
      j=j+1;
    }
    
    
    num=0;
    for(i=0;i<d1;i++){
      num=num+vetorinvertido[i];
    }

    printf("Numero Invertido: %d",num);

}

int main(void){
 
  //int V1, V2, resultado;
 // printf("Digite o primeiro valor:");
 // scanf("%d", &V1);
 // printf("Digite o segundo valor:");
  //scanf("%d", &V2);
  
 
  teste(3000);
  
  //printf("Resultado da Soma = %d\n", resultado);
  
  getchar();
  return 0;
  }