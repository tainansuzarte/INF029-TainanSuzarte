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
    char nome[20];
    Data dataNascimento;
    char sexo;
    char cpf[12];
    int erros;
  } clientes; 

int validarNome(int tamnome){

  
  if (tamnome>20){
    printf("Erro: Quantidade de Caracteres do Nome acima de 20 caracteres \n");
    
    return 1;
  }
  else
    return 0;
    
  
}

int validarCpf(int tamcpf){

  if (tamcpf!=12){
    printf("Erro! CPF inválido! \n");
    return 1;
  }
  else
    return 0;
    getchar();
}

int validarSexo(char sex){
  
  if((sex!='M') && (sex!='F') ){
    printf("Erro! Sexo inválido! \n");
    return 1;
  }
   else
    return 0;
  getchar();
}

int validarData(int dia, int mes, int ano){
  if(ano<2023){
    if(mes>0 && mes<13){
      if(mes==02 || mes==2) {
        if(dia>0 && dia<29){
          return 0;
        }else{
          printf("Dia inválido! \n");
          return 1;
        }
       if(mes==07 || mes==7){
        if(dia>0 && dia<32){
          return 0;
        }else{
          printf("Dia inválido! \n");         
         } 
       }
        
       if(mes!=07 && mes!=02 && mes%2!=0){
        if(dia>0 && dia<32){
          return 0;
        }else{
          printf("Dia inválido! \n");         
         }
         
       if(mes!=07 && mes!=02 && mes%2==0){
        if(dia>0 && dia<31){
          return 0;
        }else{
          printf("Dia inválido! \n");         
       }          
    }else{
      printf("Mês inválido! \n");
      return 1;
    }
  }else{
    printf("Ano inválido! \n" );
      return 1;
    }
  }
 }
}
}


clientes cadastrarCliente(void){
  size_t ln;
  clientes consumer;

  
  
  printf("Nome do Cliente:");
  fgets(consumer.nome, 21, stdin);
    ln = strlen(consumer.nome);
    consumer.erros=consumer.erros+validarNome(ln);
    if (consumer.nome[ln] == '\n')
        consumer.nome[ln] = '\0';
    fflush(stdin);
  
  
  printf("Digite o CPF:");
  fgets(consumer.cpf, 13, stdin);
    ln = strlen(consumer.cpf);
    consumer.erros=consumer.erros+validarCpf(ln);
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
    consumer.erros=consumer.erros+validarData(consumer.dataNascimento.dia, consumer.dataNascimento.mes, consumer.dataNascimento.ano);
    fflush(stdin);

    printf("Sexo (M ou F): ");
    scanf("%c", &consumer.sexo);
    consumer.erros=consumer.erros+validarSexo(consumer.sexo);
    fflush(stdin);
    


  return (consumer);
}

int main(void){

  clientes novocliente;
   
  novocliente = cadastrarCliente();
  if(novocliente.erros==0){
  printf("Cliente Cadastrado com sucesso! \n");
  printf("Nome do Cliente: %s \n",novocliente.nome);
  printf("Data de Nascimento: %d / %d / %d \n",novocliente.dataNascimento.dia,novocliente.dataNascimento.mes,novocliente.dataNascimento.ano);
  printf("Sexo: %c \n",novocliente.sexo);
  printf("CPF: %s \n",novocliente.cpf); 
  }
  else{
    printf("Cadastro Não realizado! Tente Novamente");
  }
  
    
  getchar();
  return 0;
  }