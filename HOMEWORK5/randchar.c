#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(){
	srand(time(NULL));
	unsigned char RANDsymbols[1000];
	unsigned int k;
	unsigned int e;

	for (k = 0; k < 1000; k++)
	{
		RANDsymbols[k] = rand() % (122 - 97 +1 ) + 97;
	}

	for(e = 0; e < 1000; e++)
	{
		printf("%c", RANDsymbols[e]);
	}
}
