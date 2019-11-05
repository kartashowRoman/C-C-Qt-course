#include <stdio.h>
#include <stdlib.h>
#include <math.h>



void main(){

	srand(time(NULL));	
	long int numbers = rand();
	long int count[1000];
	int k;
	for (k = 0; k <1001; k++) {
		count[k] = numbers;
	}
	


	FILE *fp;
	for (int i; i < 11; i++){
	fp = fopen(i+"randnum.txt", "w");
	
	for(int j = 0; j < 100; j++) fprintf(fp, "%li", count[1000]);
	
	fclose(fp);
	}
	

}


