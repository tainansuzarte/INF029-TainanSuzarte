#include <stdio.h>
#include <stdio.h>


void comerbolo();

int main(){
  int bolo=10;
  comerbolo(bolo);


}

void comerbolo(int fatia){


  if (fatia==0){
  	printf("Comi a ultima fatia \n");
  	
  }else{
    printf("Comi 1 fatia \n");
  	fatia=fatia-1;
    comerbolo(fatia);
    
  }

	

}