#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void teste(char *strTexto, char *strBusca, int posicoes[30]){

    size_t ln, ln2;
    int i,x=0,j, z=0, cont;
    int qtdOcorrencias = 0;
    int acento=0;
  

    ln = strlen(strTexto);
    ln2= strlen(strBusca);
    printf("%ld \n",ln);
    printf("%ld \n",ln2);
  
        for(i=0;i<ln;i++){
          cont=0;
          x=0;
          if(strTexto[i]<-100)
            strTexto[i]=strTexto[i]+32;   

        /*  if(strTexto[i]<=-93 && strTexto[i]>-96){
            strTexto[i]=97;}
          if(strTexto[i]<-85 && strTexto[i]>-88){
            strTexto[i]=101;}
          if(strTexto[i]==-83){
            strTexto[i]=105;}
          if(strTexto[i]<-74 && strTexto[i]>-78){
            strTexto[i]=111;}
          if(strTexto[i]<-68 && strTexto[i]>-71){
            strTexto[i]=117;} */

          printf("Posição %d - Valor:%d \n",i,strTexto[i]);

          if(strTexto[i]==-61){
            acento=acento+1;
          }
          

          if(strBusca[x]>96)
            strBusca[x]=strBusca[i]-32;
          
          if(strTexto[i]>96){
            strTexto[i]=strTexto[i]-32;
          }
          
          if(strBusca[x]==strTexto[i]){
            cont=1;
            for(j=i+1;j<=ln2+i;j++){
              x=x+1;
              if(strTexto[j]==strBusca[x]){
                cont=cont+1;
              }else break;
            }
            if(cont>=ln2){
              qtdOcorrencias=qtdOcorrencias+1;
              posicoes[z]=i+1-acento;
              posicoes[z+1]=j-acento;
              z=z+2;
            }
          }
      
        } 

      //size_t ln3 = sizeof(posicoes)/sizeof(posicoes[0]);


       printf("Quantidade de acentos : %d \n",acento);  

    printf("Quantidade de Ocorrencias : %d \n",qtdOcorrencias);
    for(i=0;posicoes[i]>0 && posicoes[i]<ln;i++){
      printf("%d Posição da Ocorrencia: %d \n",i,posicoes[i]);
    }

}

int main(void){
 
    char strTexto[250];
    char strBusca[50];
    int posicoes[30];
    int i;
    for (i = 0; i < 30; i++)
    {
        //posicoes[i] = -1;
    }
    strcpy(strTexto, "Olá, o mundo é muito grande. Tem muitas pessoas, e muitos problemas");
    strcpy(strBusca, "ola");
    teste(strTexto, strBusca, posicoes);
  
  
  getchar();
  return 0;
  }

