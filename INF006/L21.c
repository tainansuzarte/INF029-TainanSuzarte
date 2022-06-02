#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int multiplica(int v[], int u[]){
  int r[8];
  int j, i, num, num2, num3, resto, ln;
  char tam[10], d1;
  int pot;

      j=0;
      for (i=3;i>=0; i--){
      pot=pow(10.0,i);
      v[j]=v[j]*pot;
      j=j+1;
    }
  
    num=0;
    for(i=0;i<4;i++){
      num=num+v[i];
    }
  
    j=0;
    for (i=3;i>=0;i--){
      pot=pow(10.0,i);
      u[j]=u[j]*pot;
      j=j+1;
    }
  
    num2=0;
    for(i=0;i<4;i++){
      num2=num2+u[i];
    }  

  num3=num2*num;


    sprintf(tam, "%d", num3);
    ln = strlen(tam);

    d1=ln;
     
    resto=num3;
    if(ln>1)
      ln=ln-1;
  
    for(i=0;ln>0;i++){

      if(ln>1){
        pot=pow(10.0,ln);
        r[i]=resto/pot;
        resto=resto%pot;
      }else if(ln==1 && d1==1){
        r[i]=resto;        
      }else{
        pot=pow(10.0,ln);
        r[i]=resto/pot;
        r[i+1]=resto%pot;
      }

        ln=ln-1;
      
    }

  return r;
}

int main(void){
 
  int u[4], v[4], uv[8];
  int i;

  printf("Digite os Digitos do 1 número:  ");
  for(i=0;i<4;i++){
    printf("Digite o %d Digito do Primeiro Numero:",i+1);
    scanf("%d", &u[i]);
  }

    printf("Digite os Digitos do 2 número:  ");
  for(i=0;i<4;i++){
    printf("Digite o %d Digito do Segundo Numero:",i+1);
    scanf("%d", &v[i]);
  }
  
  
  uv = multiplica(u,v);
  
  printf("Resultado da Multiplicação :");
    for(i=0;i<8;i++){
    printf("%d -",i);
  }
  
  getchar();
  return 0;
  }