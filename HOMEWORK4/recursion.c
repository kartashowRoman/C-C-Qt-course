#include <stdio.h>


long int sum_date(long int date){	
	long int a = date % 10;
	long int result = 0;
	result = result + a;
	if (date - 1 < 0){
	return 0;
	} else {
	
	return result + sum_date(date / 10);
	
	}
	}

void main(){
	
	long int num = sum_date(19051996);
	printf("%li \n", num);

}
