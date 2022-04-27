#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int q3(char *texto, char c, int isCaseSensitive){

    size_t ln;
    int i;
    int qtdOcorrencias = 0;
  

    ln = strlen(texto);
  

    if(isCaseSensitive==1){

      printf("Letra: %d \n",c);
        for(i=0;i<ln;i++){
          
         /* 
          if(texto[i]<-124 && texto[i]>-128){
            texto[i]=65;}
          if(texto[i]<-117 && texto[i]>-120){
            texto[i]=69;}
          if(texto[i]==-115){
            texto[i]=73;}
          if(texto[i]<-106 && texto[i]>-110){
            texto[i]=79;}
          if(texto[i]<-100 && texto[i]>-103){
            texto[i]=85;} */

          printf("%d \n",texto[i]);

          if(c==texto[i]){
            qtdOcorrencias =qtdOcorrencias+1;
          }
      
        }      
    }else{
        for(i=0;i<ln;i++){

          
        
          if(texto[i]<-100)
            texto[i]=texto[i]+32;   

          if(texto[i]<=-93 && texto[i]>-96){
            texto[i]=97;}
          if(texto[i]<-85 && texto[i]>-88){
            texto[i]=101;}
          if(texto[i]==-83){
            texto[i]=105;}
          if(texto[i]<-74 && texto[i]>-78){
            texto[i]=111;}
          if(texto[i]<-68 && texto[i]>-71){
            texto[i]=117;}
          

          if(c>96)
            c=c-32;
          
          if(texto[i]>96){
            texto[i]=texto[i]-32;
          }
          
          if(c==texto[i]){
            qtdOcorrencias =qtdOcorrencias+1;
          }
      
        } 

      
    }


    printf("Quantidade de Ocorrencias  : %d\n",qtdOcorrencias);
  return qtdOcorrencias;

}

int main(void){
 
  char str[250];
    strcpy(str,"Letícia signifiCa fEliCIdADE");
    printf("%d\n",q3(str, 'S', 1) == 0);
    //printf("%d\n",q3(str, 'C', 0) == 3);
   // printf("%d\n",q3(str, 'c', 1) == 1);
   // printf("%d\n",q3(str, 'C', 1) == 2);
   // printf("%d\n",q3(str, 'R', 0) == 0);
   // printf("%d\n",q3(str, 'e', 0) == 3);
   // printf("%d\n",q3(str, 'E', 1) == 2);
   // printf("%d\n",q3(str, 'S', 1) == 0);
  
  
  getchar();
  return 0;
  }

