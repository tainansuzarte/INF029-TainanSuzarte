#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void teste(int numerobusca, int numerobase){

    int qtdOcorrencias;
    int vetorbase[10], vetorbusca[10];
    size_t ln, ln2;
    float d1, d2;
    int pos, fila,cont;
    int resto, resto1, i, j ,pot;
    char tam1[10],tam2[10];
  

    sprintf(tam2, "%d", numerobase);
    sprintf(tam1, "%d", numerobusca);
    ln = strlen(tam1);
    ln2 = strlen(tam2);

    d1=ln;
    d2=ln2;
     
    resto=numerobase;
    resto1=numerobusca;
    ln2=ln2-1;
    ln=ln-1;
  
    for(i=0;ln2>0;i++){

      if(ln2>1){
        pot=pow(10.0,ln2);
        vetorbase[i]=resto/pot;
        resto=resto%pot;
      }else{
        pot=pow(10.0,ln2);
        vetorbase[i]=resto/pot;
        vetorbase[i+1]=resto%pot;
      }
      
      ln2=ln2-1;
      
    }
    
    for(i=0;ln>0;i++){

      if(ln>1){
        pot=pow(10.0,ln);
        vetorbusca[i]=resto1/pot;
        resto1=resto1%pot;
      }else{
        pot=pow(10.0,ln);
        vetorbusca[i]=resto1/pot;
        vetorbusca[i+1]=resto1%pot;
      }
      
      ln=ln-1;
      
    }

  
    qtdOcorrencias=0;
    for(i=0;i<d2;i++){
      pos=0;
      cont=0;
      if(vetorbusca[pos]==vetorbase[i]){
        cont=1;
        for(j=i+1;j<i+d1;j++){
          if(vetorbusca[pos+1]==vetorbase[j]){
            cont=cont+1;
          }else break;
          pos++;
        }
        if(cont==d1){
          qtdOcorrencias=qtdOcorrencias+1;
        }
      }
    }

  printf("Foram encontradas %d Ocorrencias \n",qtdOcorrencias);

  
    printf("\n------\n");
  
    for(i=0;i<=d2-1;i++){
      printf("%d-",vetorbase[i]);
    }
    printf("\n------\n");
    for(i=0;i<=d1-1;i++){
      printf("%d-",vetorbusca[i]);
    }  
}

int main(void){
 
  //int V1, V2, resultado;
 // printf("Digite o primeiro valor:");
 // scanf("%d", &V1);
 // printf("Digite o segundo valor:");
  //scanf("%d", &V2);
  
 
  teste(23,222222);
  
  //printf("Resultado da Soma = %d\n", resultado);
  
  getchar();
  return 0;
  }