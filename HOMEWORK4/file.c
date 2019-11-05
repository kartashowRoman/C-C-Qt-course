#include <stdio.h>
#include <stdlib.h>
#include <math.h>



void main(){
	srand(time(NULL));
		
	long int numbers = rand();
	

	
	FILE *fp;
	for (int i; i < 11; i++){
	fp = fopen(i+"randnum.txt", "w");
	
	
	for(int j = 0; j < 10000; j++) fprintf(fp, "%li", numbers);
	
	fclose(fp);
	}
	

}



