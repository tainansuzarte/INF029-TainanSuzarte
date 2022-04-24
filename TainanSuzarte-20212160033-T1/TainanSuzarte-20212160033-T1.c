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

    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 2;
      return dma;
    }else{
      //verifique se a data final não é menor que a data inicial
      
      //calcule a distancia entre as datas


      //se tudo der certo
      dma.retorno = 1;
      return dma;
      
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

    size_t ln;
    int i;
    int qtdOcorrencias = 0;
  

    ln = strlen(texto);
  

    if(isCaseSensitive==1){
      
        for(i=0;i<ln;i++){
        

          if(texto[i]<-124 && texto[i]>-128){
            texto[i]=65;}
          if(texto[i]<-117 && texto[i]>-120){
            texto[i]=69;}
          if(texto[i]==-115){
            texto[i]=73;}
          if(texto[i]<-106 && texto[i]>-110){
            texto[i]=79;}
          if(texto[i]<-100 && texto[i]>-103){
            texto[i]=85;}

          if(c==texto[i]){
            qtdOcorrencias =qtdOcorrencias+1;
          }
      
        }      
    }else{
        for(i=0;i<ln;i++){

          

          if(texto[i]<-100)
            texto[i]=texto[i]+32;   

          if(texto[i]<=-93 && texto[i]>-96){
            texto[i]=97;}
          if(texto[i]<-85 && texto[i]>-88){
            texto[i]=101;}
          if(texto[i]==-83){
            texto[i]=105;}
          if(texto[i]<-74 && texto[i]>-78){
            texto[i]=111;}
          if(texto[i]<-68 && texto[i]>-71){
            texto[i]=117;}
          

          if(c>96)
            c=c-32;
          
          if(texto[i]>96){
            texto[i]=texto[i]-32;
          }
          
          if(c==texto[i]){
            qtdOcorrencias =qtdOcorrencias+1;
          }
      
        } 

      
    }



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
    printf("%ld \n",ln);
    printf("%ld \n",ln2);
  
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
    ln=ln-1;
  
    for(i=0;ln>0;i++){

      if(ln>1){
        pot=pow(10.0,ln);
        vetornum[i]=resto/pot;
        resto=resto%pot;
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
    int qtdOcorrencias;
    int vetorbase[10], vetorbusca[10];
    size_t ln, ln2;
    float d1, d2;
    int pos, fila,cont;
    int resto, resto1, i, j ,pot;
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
      }else{
        pot=pow(10.0,ln);
        vetorbusca[i]=resto1/pot;
        vetorbusca[i+1]=resto1%pot;
      }
      
      ln=ln-1;
      
    }

  
    qtdOcorrencias=0;
    for(i=0;i<d2;i++){
      pos=0;
      cont=0;
      if(vetorbusca[pos]==vetorbase[i]){
        cont=1;
        for(j=i+1;j<i+d1;j++){
          if(vetorbusca[pos+1]==vetorbase[j]){
            cont=cont+1;
          }else break;
          pos++;
        }
        if(cont==d1){
          qtdOcorrencias=qtdOcorrencias+1;
        }
      }
    }

  return qtdOcorrencias;
  printf("Foram encontradas %d Ocorrencias \n",qtdOcorrencias);

  
  
}