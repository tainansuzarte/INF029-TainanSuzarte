#include <stdio.h>
#include <stdio.h>

int n;

int funcao1(int n){
  int i;
  int resul=0;
  


  for(i=0; i<=n; i++){
    resul=i+resul;
  }

  return resul;
  }

int funcao2(int n){
  int resul=0;
  

  resul=(n*(n+1))/2;

  return resul;
  }
  
  
  

int main(void){

  int r1,r2;

  printf("Digite o numero que deseja calcular:");
  scanf("%d", &n);
   
  r1=funcao1(n);
  r2=funcao2(n);

  if(r1==r2){
    printf("Os resultados das funções para o número são iguais."); 
  }else{
       printf("Os resultados das funções para o número são diferentes."); 
  }

  getchar();
  return 0;
  }