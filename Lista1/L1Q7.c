#include <stdio.h>
#include <string.h>

typedef struct lista_palavras
  {
    char pala1[12];
    char pala2[12];
    char pala3[12];
  } palavras; 

palavras ler3palavras(void){
  size_t ln;
  palavras lista;

  printf("Digite a primeira palavra:");
  fgets(lista.pala1, 13, stdin);
    ln = strlen(lista.pala1) - 1;
    if (lista.pala1[ln] == '\n')
        lista.pala1[ln] = '\0';
    fflush(stdin);
  
  printf("Digite a segunda palavra:");
  fgets(lista.pala2, 13, stdin);
    ln = strlen(lista.pala2) - 1;
    if (lista.pala2[ln] == '\n')
        lista.pala2[ln] = '\0';
    fflush(stdin);
  
  printf("Digite a terceira palavra:");
  fgets(lista.pala3, 13, stdin);
    ln = strlen(lista.pala3) - 1;
    if (lista.pala3[ln] == '\n')
        lista.pala3[ln] = '\0';
    fflush(stdin);


  return (lista);
}

int main(void){

  palavras listamain;
   
  listamain = ler3palavras();

  printf("A primeira palavra foi %s \n",listamain.pala1);
  printf("A segunda palavra foi %s \n",listamain.pala2);
  printf("A terceira palavra foi %s \n",listamain.pala3);
  
    
  getchar();
  return 0;
  }