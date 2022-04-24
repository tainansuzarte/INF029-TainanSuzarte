#include <stdio.h>
#include "TainanSuzarte-20212160033-T1.h" 
#include <stdlib.h>
#include <math.h>
#include <string.h>



DataQuebrada quebraData(char data[]){
  
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i;

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else 
		dq.valido = 0;
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else
		dq.valido = 0;
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else
		dq.valido = 0;

    dq.iDia = atoi(sDia);
    dq.iMes = atoi(sMes);
    dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
    return dq;
}
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[]){

    int datavalida = 1;
    DataQuebrada dq2;

    

    dq2 = quebraData(data);
    if (dq2.valido==0)
      return 0;
    else
      {

      if(dq2.iMes==1 || dq2.iMes==3 || dq2.iMes==5 || dq2.iMes==7 || dq2.iMes==8 || dq2.iMes==10 || dq2.iMes==12 ){
          if(dq2.iDia>0 && dq2.iDia<=31)
            datavalida=datavalida+1;
          else
            datavalida=0;
      }else if(dq2.iMes==4 || dq2.iMes==6 || dq2.iMes==9 || dq2.iMes==11){
        if(dq2.iDia>0 && dq2.iDia<31)
          datavalida=datavalida+1;
        else
          datavalida=0;
      }else if(dq2.iMes==2){
          if ( ( dq2.iAno % 4 == 0 && dq2.iAno%100 != 0 ) || dq2.iAno% 400 == 0 ){
            if(dq2.iDia>0 && dq2.iDia<30)
              datavalida=datavalida+1;
            else
              datavalida=0;
          
          }else{
            if(dq2.iDia>0 && dq2.iDia<29)
              datavalida=datavalida+1;
            else
              datavalida=0;
            }           
        
    
        }else{
          datavalida=0;
        }
        
      }
      

      
   printf("%s - ", data);

    if(datavalida>0){
        printf("Data Valida! \n");
        return 1;}
    else{
        printf("Data Invalida \n");
        return 0;}

}
int main(void){
 
  int resultado;
 // printf("Digite o primeiro valor:");
 // scanf("%d", &V1);
 // printf("Digite o segundo valor:");
  //scanf("%d", &V2);
  char str[11];
  
    strcpy(str,"29/02/2015");
    printf("%d\n",q1(str) == 0);
    strcpy(str,"29/02/2012");
    printf("%d\n",q1(str) == 1);
    strcpy(str,"9/13/2014");
    printf("%d\n",q1(str) == 0);
    strcpy(str,"45/4/2014");
    printf("%d\n",q1(str) == 0);
    strcpy(str,"12/1/15");
    printf("%d\n",q1(str) == 1);
    strcpy(str,"1/9/2016");
    printf("%d\n",q1(str) == 1);
    strcpy(str,"//2016");
    printf("%d\n",q1(str) == 0);
    strcpy(str,"1//20");
    printf("%d\n",q1(str) == 0);
    strcpy(str,"1/R/2016");
    printf("%d\n",q1(str) == 0);
    strcpy(str,"1/12/19");
    printf("%d\n",q1(str) == 1); 
 
  
  //printf("Resultado da Soma = %d\n", resultado);
  
  getchar();
  return 0;
  }