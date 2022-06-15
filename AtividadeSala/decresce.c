#include <stdio.h>
#include <stdio.h>


void decrescer();

int main(){
  int n=10;
  decrescer(n);


}

void decrescer(int nivel){


  if (nivel==0){
  	printf("Nível %d \n",nivel);
  	
  }else{
    printf("Nível %d \n",nivel);
  	nivel=nivel-1;
    decrescer(nivel);
    
  }

	

}