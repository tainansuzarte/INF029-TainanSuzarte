#include <stdio.h>
#include <stdio.h>


void crescer();

int main(){
  int n=10;
  crescer(n);


}

void crescer(int nivel){

 int n=0;
  if (nivel==n){
  	printf("Nível %d \n",n);
  	
  }else{
    printf("Nível %d \n",n);
  	n=n+1;
    crescer(n);
    
  }

	

}