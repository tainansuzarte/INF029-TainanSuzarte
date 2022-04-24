#include <stdio.h>
#include <stdio.h>

int idademinima(int ano){
  int result;
  int *idade;

  *idade=2022-ano;
  printf("Idade do Colaborador: %d",*idade);
  
  if(*idade>65){
    
    return 1;
  }else{
    return 0;
  }

}

int temposervico(int ano){

  int *tempo;

  *tempo=2022-ano;
  printf("Tempo de Serviço: %d",*tempo);
  if(*tempo>=30){
    
    return 1;
  }else{
    return 0;
  }

}

int casoesp(int *idade, int *tempo){

  int **id, **temp;
  
  id=&idade;
  temp=&tempo;

  if(**id>=60 && **temp>=25){
    return 1;
  }else{
    return 0;
  }
  
}

void impressao(int result){

  if(result>0){
    printf("Requerer Aposentadoria");
  }else{
    printf("Não requerer aposentadoria");
  }
}

int main(void){
 
  int cod, anonasc, anoing;
  int resultado;
  
  printf("Digite o seu código de empregado:");
  scanf("%d", &cod);
  printf("Digite o Ano de seu nascimento:");
  scanf("%d", &anonasc);
  printf("Digite o Ano de seu nascimento:");
  scanf("%d", &anoing);
  
  
  resultado=idademinima(anonasc)+temposervico( anoing)+casoesp(*idade, *tempo);

  
  
  impressao(resultado);
  
  getchar();
  return 0;
  }