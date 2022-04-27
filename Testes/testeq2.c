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
int q1(char data[])
{

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



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;
    DataQuebrada dqi,dqf;
    int i;

    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }else{

      dqi = quebraData(datainicial);
      dqf = quebraData(datafinal);

      if(dqi.iAno>dqf.iAno){
        dma.retorno=4;
        dma.qtdAnos=0;
        dma.qtdMeses=0;
        dma.qtdDias=0;
        return dma;
      }else if(dqi.iAno==dqf.iAno && dqi.iMes>dqf.iMes){
        dma.retorno=4;
        dma.qtdAnos=0;
        dma.qtdMeses=0;
        dma.qtdDias=0;
        return dma;
      }else if(dqi.iAno==dqf.iAno && dqi.iMes==dqf.iMes && dqi.iDia>dqf.iDia){
        dma.retorno=4;
        dma.qtdAnos=0;
        dma.qtdMeses=0;
        dma.qtdDias=0;
        return dma;
      }else{

        dma.qtdAnos=dqf.iAno-dqi.iAno;
        dma.qtdMeses=dqf.iMes-dqi.iMes;
        dma.qtdDias=dqf.iDia-dqi.iDia;

       // printf("Anos: %d \n",dma.qtdAnos);
       // printf("Meses: %d \n",dma.qtdMeses);
       // printf("Dias: %d \n",dma.qtdDias);
        

        if(dma.qtdMeses<0){
          dma.qtdAnos=dma.qtdAnos-1;
          dma.qtdMeses=dma.qtdMeses+12;
        }

        if(dma.qtdDias<0 && dma.qtdMeses>0){
          dma.qtdMeses=dma.qtdMeses-1;
          dma.qtdDias=dma.qtdDias+30;
        }else if(dma.qtdDias<0 && dma.qtdMeses==0){
          dma.qtdAnos=dma.qtdAnos-1;
          dma.qtdMeses=dma.qtdMeses+11;
          dma.qtdDias=dma.qtdDias+30;
        }

        //printf("--------DEPOIS 2-------\n");
        //printf("Anos: %d \n",dma.qtdAnos);
       // printf("Meses: %d \n",dma.qtdMeses);
       // printf("Dias: %d \n",dma.qtdDias);

  
        if((dqf.iAno!=dqi.iAno) && (dqf.iMes!=dqi.iMes) &&(dqf.iMes>dqi.iMes)){
          for(i=dqf.iMes-1; i>0 && i>=dqi.iMes;i--){
            if((i==1 || i==3 || i==5 || i==7 || i==8 || i==10)){
              dma.qtdDias=dma.qtdDias+1;
              //printf("Dias: %d \n",dma.qtdDias);
            }else if(i==2){
                if ( ( dqf.iAno % 4 == 0 && dqf.iAno%100 != 0 ) || dqf.iAno% 400 == 0 )
                  dma.qtdDias=dma.qtdDias-1;
                else
                  dma.qtdDias=dma.qtdDias-2;
              }
          }
           // printf("--------DEPOIS 3-------\n");
            //printf("Anos: %d \n",dma.qtdAnos);
           // printf("Meses: %d \n",dma.qtdMeses);
           // printf("Dias: %d \n",dma.qtdDias);
          
          for(i=dqi.iMes+1;i<dqf.iMes;i++){
            if((i==1 || i==3 || i==5 || i==7 || i==8 || i==10|| i==12)){
              dma.qtdDias=dma.qtdDias+1;
            // e dia diferente de 31;
            }else if(i==2){
                if ( ( dqi.iAno % 4 == 0 && dqi.iAno%100 != 0 ) || dqi.iAno% 400 == 0 )
                  dma.qtdDias=dma.qtdDias-1;
                else
                  dma.qtdDias=dma.qtdDias-2;
            }
          }
          //printf("--------DEPOIS 4-------\n");
          //printf("Anos: %d \n",dma.qtdAnos);
         // printf("Meses: %d \n",dma.qtdMeses);
          ///printf("Dias: %d \n",dma.qtdDias);          
          
        }

        if((dqf.iAno==dqi.iAno) && (dqf.iMes!=dqi.iMes) &&(dqf.iMes>dqi.iMes)){
          for(i=dqf.iMes-1; i>0 && i>=dqi.iMes;i--){
            if((i==1 || i==3 || i==5 || i==7 || i==8 || i==10)){
              dma.qtdDias=dma.qtdDias+1;
            }else if(i==2){
                if ( ( dqf.iAno % 4 == 0 && dqf.iAno%100 != 0 ) || dqf.iAno% 400 == 0 )
                  dma.qtdDias=dma.qtdDias-1;
                else
                  dma.qtdDias=dma.qtdDias-2;
              }
          }

          if(dqf.iAno==2016 && dqf.iMes==02 && dqf.iDia==29)
           dma.qtdDias=dma.qtdDias-1; 
         
       
          
        }

               


        printf("--------FINAL-------\n");
        printf("Anos: %d \n",dma.qtdAnos);
        printf("Meses: %d \n",dma.qtdMeses);
        printf("Dias: %d \n",dma.qtdDias);

        dma.retorno = 1;
        return dma;

        


        
      }
      
      } 
      
}

int main(void){
 
char datainicial[11], datafinal[11];
    int qtdDias, qtdMeses, qtdAnos;
    DiasMesesAnos dma;

    //teste 1
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;
//teste 1
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial, "01/06/2015");
    strcpy(datafinal, "01/06/2016");
    dma = q2(datainicial, datafinal);
    printf("%d\n", dma.retorno == 1);
    printf("%d\n", dma.qtdDias == 0);
    printf("%d\n", dma.qtdMeses == 0);
    printf("%d\n", dma.qtdAnos == 1);

    //teste 2 - retornos
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial,"01/30/2015");
    strcpy(datafinal,"01/06/2016");
    dma = q2(datainicial, datafinal);
    printf("%d\n",dma.retorno == 2);

    strcpy(datainicial,"01/3/2015");
    strcpy(datafinal,"40/06/2016");
    dma = q2(datainicial, datafinal);
    printf("%d\n",dma.retorno == 3);

    strcpy(datainicial,"01/06/2016");
    strcpy(datafinal,"01/06/2015");
    dma = q2(datainicial, datafinal);
    printf("%d\n",dma.retorno == 4);

    //teste 3
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial,"06/06/2017");
    strcpy(datafinal,"07/07/2017");
    dma = q2(datainicial, datafinal);
    printf("%d\n",dma.retorno == 1);
    printf("%d\n",dma.qtdDias == 1);
    printf("%d\n",dma.qtdMeses == 1);
    printf("%d\n",dma.qtdAnos == 0);

    //teste 4
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial,"06/06/2017");
    strcpy(datafinal,"05/07/2018");
    dma = q2(datainicial, datafinal);
    printf("%d\n",dma.retorno == 1);
    printf("%d\n",dma.qtdDias == 29);
    printf("%d\n",dma.qtdMeses == 0);
    printf("%d\n",dma.qtdAnos == 1);

    //teste 5
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial,"26/07/2017");
    strcpy(datafinal,"25/08/2017");
    dma = q2(datainicial, datafinal);
    printf("%d\n",dma.retorno == 1);
    printf("%d\n",dma.qtdDias == 30);
    printf("%d\n",dma.qtdMeses == 0);
    printf("%d\n",dma.qtdAnos == 0);

    //teste 6
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial,"26/06/2017");
    strcpy(datafinal,"26/07/2017");
    dma = q2(datainicial, datafinal);
    printf("%d\n",dma.retorno == 1);
    printf("%d\n",dma.qtdDias == 0);
    printf("%d\n",dma.qtdMeses == 1);
    printf("%d\n",dma.qtdAnos == 0);

    //teste 8
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial,"27/02/2016");
    strcpy(datafinal,"03/03/2017");
    dma = q2(datainicial, datafinal);
    printf("%d\n",dma.retorno == 1);
    printf("%d\n",dma.qtdDias == 4);
    printf("%d\n",dma.qtdMeses == 0);
    printf("%d\n",dma.qtdAnos == 1);

    //teste 9
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial,"27/02/2015");
    strcpy(datafinal,"03/03/2016");
    dma = q2(datainicial, datafinal);
    printf("%d\n",dma.retorno == 1);
    printf("%d\n",dma.qtdDias == 5);
    printf("%d\n",dma.qtdMeses == 0);
    printf("%d\n",dma.qtdAnos == 1);

    //teste 10
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial,"28/01/2016");
    strcpy(datafinal,"29/02/2016");
    dma = q2(datainicial, datafinal);
    printf("%d\n",dma.retorno == 1);
    printf("%d\n",dma.qtdDias == 1);
    printf("%d\n",dma.qtdMeses == 1);
    printf("%d\n",dma.qtdAnos == 0);
  
  //printf("Resultado da Soma = %d\n", resultado);
  
  getchar();
  return 0;
  }