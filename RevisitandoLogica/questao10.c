#include <stdio.h>
#include <stdio.h>

  typedef struct ficha_de_pessoa
  {
    char nome[40];
    int idade;
    char sexo;
    int cpf;
  } ficha;

int main(){

  int cont;
  char nomes[5], sexos[5];
  int idades[5], cpfs[5];
  ficha pessoa;


  cont =1;

  
  while(cont<2){
    printf("Digite o nome da %d ª pessoa: \n",cont);
    fflush(stdin);
    fgets(pessoa.nome, 40, stdin);

    printf("Digite a idade da %d ª pessoa: \n",cont);
    scanf("%d",&pessoa.idade);

    printf("Digite o sexo da %d ª pessoa(M- Masc / F - Fem): \n",cont);
    scanf("%s",&pessoa.sexo);

    printf("Digite o cpf da %d ª pessoa:\n",cont);
    scanf("%d",&pessoa.cpf);

    nomes[cont]=pessoa.nome;
    idades[cont]=pessoa.idade;
    sexos[cont]=pessoa.sexo;
    cpfs[cont]=pessoa.cpf;

    cont=cont+1;
    
  }

  cont=1;
  printf("----------Dados do Sistema------------ \n");
  
  while(cont<6){
    printf("Dados da %d pessoa \n",cont);
    printf("Nome: %s \n",nomes[cont]);
    printf("Idade: %d \n",idades[cont]);
    printf("Sexo: %s \n",sexos[cont]);
    printf("CPF: %d \n",cpfs[cont]);

    cont=cont+1;
    
  }
  
  
 
    
  }