#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARR_SIZE 25

int a[ARR_SIZE];

int compare(const int *i, const int *j);
int compare(const int *i, const int *j)
{
	return *i - *j;
}



int main(){
	srand(time(NULL));

	for(int i=0; i < ARR_SIZE; i++)
	{
		a[i]= rand()%25;
	}
	qsort(a, ARR_SIZE, sizeof(int), (int(*) (const void *, const void*))compare);
	
	
	for(int i = 0; i < 25; i++)
	{
		printf("%d \n", a[i]);
	}

								




return 0; 
}
