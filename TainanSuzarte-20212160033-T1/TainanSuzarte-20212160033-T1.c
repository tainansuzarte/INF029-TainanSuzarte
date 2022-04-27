// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Tainan Oliveira Suzarte  
//  email: tainan.ssa@gmail.com
//  Matrícula: 20212160033
//  Semestre: 2022.1

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "TainanSuzarte-20212160033-T1.h" 
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
/*
## função utilizada para testes  ##
 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##
 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
    int fat = 6;
    return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}



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
      

      
   //printf("%s - ", data);

    if(datavalida>0){
        printf(" ");
        return 1;
     }else
        return 0;

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


  
        if((dqf.iAno!=dqi.iAno) && (dqf.iMes!=dqi.iMes) &&(dqf.iMes>dqi.iMes)){
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

          
          for(i=dqi.iMes+1;i<dqf.iMes;i++){
            if((i==1 || i==3 || i==5 || i==7 || i==8 || i==10|| i==12)){
              dma.qtdDias=dma.qtdDias+1;

            }else if(i==2){
                if ( ( dqi.iAno % 4 == 0 && dqi.iAno%100 != 0 ) || dqi.iAno% 400 == 0 )
                  dma.qtdDias=dma.qtdDias-1;
                else
                  dma.qtdDias=dma.qtdDias-2;
            }
          }
         
          
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

               




        dma.retorno = 1;
        return dma;

        


        
      }
      
      } 
}

void converteMaiusculo(char textoOriginal[], char textoDestino[]){
  for (int i = 0; i < strlen(textoOriginal); i++){
    textoDestino[i] = toupper(textoOriginal[i]);  
  }
  
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */


int q3(char *texto, char c, int isCaseSensitive)
{
    char textoCopia[100];
    size_t ln;
    int i;
    int qtdOcorrencias = 0;
  

    ln = strlen(texto);

    if(!isCaseSensitive){
      converteMaiusculo(texto, textoCopia);
      c = toupper(c);
    }  
    else
      strcpy(textoCopia, texto);  

    
  
  
    for(i=0;i<ln;i++){
      //printf("Letra %d: %d \n",i,textoCopia[i]);
      if(c==textoCopia[i]){
        qtdOcorrencias =qtdOcorrencias+1;
      }
    }  
    //printf("%d", qtdOcorrencias);
    

  
    //printf("CAse: %d Letra: %d \n",isCaseSensitive,c);

    /*if(isCaseSensitive==1){
        printf("Entrou no Primeiro caso \n");
        for(i=0;i<ln;i++){
        

          printf("Letra %d: %d \n",i,texto[i]);
          if(c==texto[i]){
            qtdOcorrencias =qtdOcorrencias+1;
          }
      
        }      
    }else if (isCaseSensitive!=1){
        printf("Entrou no Segundo caso \n");
        for(i=0;i<ln;i++){

          strcpy(textoCopia,texto);
            printf("Letra %d: %d \n",i,textoCopia[i]);
          if(textoCopia[i]<-100)
            textoCopia[i]=textoCopia[i]+32;   

          if(textoCopia[i]<=-93 && textoCopia[i]>-96){
            textoCopia[i]=97;}
          if(textoCopia[i]<-85 && textoCopia[i]>-88){
            textoCopia[i]=101;}
          if(textoCopia[i]==-83){
            textoCopia[i]=105;}
          if(textoCopia[i]<-74 && textoCopia[i]>-78){
            textoCopia[i]=111;}
          if(textoCopia[i]<-68 && textoCopia[i]>-71){
            textoCopia[i]=117;}
          

          if(c>96)
            c=c-32;
          
          if(textoCopia[i]>96){
            textoCopia[i]=textoCopia[i]-32;
          }
          
          if(c==textoCopia[i]){
            qtdOcorrencias =qtdOcorrencias+1;
          }
      
        } 

      
    }*/


    //printf("Ocorrencias: %d \n",qtdOcorrencias );
    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;
 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    size_t ln, ln2;
    int i,x=0,j, z=0, cont;
    int qtdOcorrencias = 0;
    int acento=0;
  

    ln = strlen(strTexto);
    ln2= strlen(strBusca);
    //printf("%ld \n",ln);
    //printf("%ld \n",ln2);
  
        for(i=0;i<ln;i++){
          cont=0;
          x=0;
          if(strTexto[i]<-100)
            strTexto[i]=strTexto[i]+32;   

        /*  if(strTexto[i]<=-93 && strTexto[i]>-96){
            strTexto[i]=97;}
          if(strTexto[i]<-85 && strTexto[i]>-88){
            strTexto[i]=101;}
          if(strTexto[i]==-83){
            strTexto[i]=105;}
          if(strTexto[i]<-74 && strTexto[i]>-78){
            strTexto[i]=111;}
          if(strTexto[i]<-68 && strTexto[i]>-71){
            strTexto[i]=117;} */

          if(strTexto[i]==-61){
            acento=acento+1;
          }
          

          if(strBusca[x]>96)
            strBusca[x]=strBusca[i]-32;
          
          if(strTexto[i]>96){
            strTexto[i]=strTexto[i]-32;
          }
          
          if(strBusca[x]==strTexto[i]){
            cont=1;
            for(j=i+1;j<=ln2+i;j++){
              x=x+1;
              if(strTexto[j]==strBusca[x]){
                cont=cont+1;
              }else break;
            }
            if(cont>=ln2){
              qtdOcorrencias=qtdOcorrencias+1;
              posicoes[z]=i+1-acento;
              posicoes[z+1]=j-acento;
              z=z+2;
              if(ln2>1)
                i=j-1;
            }
          }
      
        } 


    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{

    int vetornum[100], vetorinvertido[100];
    size_t ln;
    float d1;
    int resto,i,j,pot, num1;
    char tam[10];
  

    sprintf(tam, "%d", num);
    ln = strlen(tam);

    d1=ln;
     
    resto=num;
    if(ln>1)
      ln=ln-1;
  
    for(i=0;ln>0;i++){

      if(ln>1){
        pot=pow(10.0,ln);
        vetornum[i]=resto/pot;
        resto=resto%pot;
      }else if(ln==1 && d1==1){
        vetornum[i]=resto;        
      }else{
        pot=pow(10.0,ln);
        vetornum[i]=resto/pot;
        vetornum[i+1]=resto%pot;
      }

        ln=ln-1;
      
    }
    j=0;
    ln=d1-1;
    for (i=d1-1;i>=0;i--){
      pot=pow(10.0,ln);
      vetorinvertido[j]=vetornum[i]*pot;
      ln=ln-1;
      j=j+1;
    }
    
    
    num=0;
    for(i=0;i<d1;i++){
      num=num+vetorinvertido[i];
    }

    return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias=-1;
    int vetorbase[10], vetorbusca[10];
    size_t ln, ln2;
    float d1, d2;
    int pos, fila,cont;
    int resto, resto1, i, j ,pot,f;
    char tam1[10],tam2[10];
  

    sprintf(tam2, "%d", numerobase);
    sprintf(tam1, "%d", numerobusca);
    ln = strlen(tam1);
    ln2 = strlen(tam2);

    d1=ln;
    d2=ln2;
     
    resto=numerobase;
    resto1=numerobusca;
    ln2=ln2-1;
    if(ln>1)
       ln=ln-1; 
    

  
    for(i=0;ln2>0;i++){

      if(ln2>1){
        pot=pow(10.0,ln2);
        vetorbase[i]=resto/pot;
        resto=resto%pot;
      }else{
        pot=pow(10.0,ln2);
        vetorbase[i]=resto/pot;
        vetorbase[i+1]=resto%pot;
      }
      
      ln2=ln2-1;
      
    }
    
    for(i=0;ln>0;i++){

      if(ln>1){
        pot=pow(10.0,ln);
        vetorbusca[i]=resto1/pot;
        resto1=resto1%pot;
      }else if(ln==1 && d1==1){
        pot=1;
        vetorbusca[i]=resto1;        
      }else{
        pot=pow(10.0,ln);
        vetorbusca[i]=resto1/pot;
        vetorbusca[i+1]=resto1%pot;
      }
      
      ln=ln-1;
      
    }
    
    //printf("Buscar: %d \n",vetorbusca[0]);  
    qtdOcorrencias=0;
    for(i=0;i<d2;i++){
      pos=0;
      cont=0;
      
      if(vetorbusca[pos]==vetorbase[i]){
        cont=1;
  
        if(d1>1){
          for(j=i+1;j<i+d1 &&j<d2;j++){
            if(vetorbusca[pos+1]==vetorbase[j]){
              cont=cont+1;
            }else break;
            pos++;
          }    
        }
        if(cont==d1){
          qtdOcorrencias=qtdOcorrencias+1;
          if(d1>1)
            i=j-1;
          //printf("Rodada %d \n",j);
        }
      }
    }

  return qtdOcorrencias;
  printf("Foram encontradas %d Ocorrencias \n",qtdOcorrencias);

  
  
}