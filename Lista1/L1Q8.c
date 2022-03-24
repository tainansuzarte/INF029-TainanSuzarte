#include <stdio.h>
#include <string.h>

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct ficha_cliente
  {
    char nome[30];
    Data dataNascimento;
    char sexo;
    char cpf[12];
  } clientes; 

clientes cadastrarCliente(void){
  size_t ln;
  clientes consumer;

  
  
  printf("Nome do Cliente:");
  fgets(consumer.nome, 31, stdin);
    ln = strlen(consumer.nome) - 1;
    if (consumer.nome[ln] == '\n')
        consumer.nome[ln] = '\0';
    fflush(stdin);
  
  printf("Digite o CPF:");
  fgets(consumer.cpf, 13, stdin);
    ln = strlen(consumer.cpf) - 1;
    if (consumer.cpf[ln] == '\n')
        consumer.cpf[ln] = '\0';
    fflush(stdin);
  
  
  printf("Data de nascimento\n");

    printf("Dia: ");
    scanf("%d", &consumer.dataNascimento.dia);
    fflush(stdin);

    printf("Mes: ");
    scanf("%d", &consumer.dataNascimento.mes);
    fflush(stdin);

    printf("Ano: ");
    scanf("%d", &consumer.dataNascimento.ano);
    fflush(stdin);
    getchar();

    printf("Sexo (M ou F): ");
    scanf("%c", &consumer.sexo);
    fflush(stdin);
    


  return (consumer);
}

int main(void){

  clientes novocliente;
   
  novocliente = cadastrarCliente();

  printf("Cliente Cadastrado com sucesso! \n");
  printf("Nome do Cliente: %s \n",novocliente.nome);
  printf("Data de Nascimento: %d / %d / %d \n",novocliente.dataNascimento.dia,novocliente.dataNascimento.mes,novocliente.dataNascimento.ano);
  printf("Sexo: %c \n",novocliente.sexo);
  printf("CPF: %s \n",novocliente.cpf);
    
  getchar();
  return 0;
  }