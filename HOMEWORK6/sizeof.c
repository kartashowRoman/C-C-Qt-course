#include <stdio.h>



int main(){
	char text[100000];
	FILE *fp;
	
	if((fp=fopen("txt.txt", "r"))==NULL)
	{

	printf("Cannot open file.\n");

	} else { 
		fgets(text, 100000, fp);
		fclose(fp);
	};
	printf("Считанные данные: \n");
	
	int num_sym = 0;
	for( int j = 0; text[j] != '\0'; j++)
	{
    	printf("%c", text[j]);
		++num_sym;
	}
	char actual_sym[num_sym];
	
	size_t size_text = sizeof(actual_sym);

	printf("Размер считанных данных: \n");
	printf("%lu байт(а) \n", size_text);

return 0;
}
