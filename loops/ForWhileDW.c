#include <stdio.h>

int main(){
    int i = 0;
    int b = 0;
    int a = 0;
    for(; i < 3; i++){

        printf("We are in for-loop %d \n", i);

        int a;

	while(a < 3){

	printf("Now we are in while-loop %d \n", a);

        a++;

	    do {
	   
  	    printf("Now it is do-while ---------%d \n", b);

            b++;
	    
	    } while(b < 1);
	}
    }



    return 0;
}
