#include <stdio.h>



int main(){
	int i= 0;
again: ;
	
	i++;
	printf("%d \n", i);
	if (i < 100)
	{
	goto again;
	}
	



return 0; 
}
