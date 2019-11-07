#include <stdio.h>



void main(){
	int numberUpper[26];
	int numberLower[26];
	//создаём массив английских букв верхнего регистра
	char UpCaseAlphabet[26];
	char uppercase = 65;
	int i;
	for( i = 0; i < 26; i++)
	{
		UpCaseAlphabet[i] = uppercase;
		uppercase++;
	};
	i = 0;

	//создаём массив английских букв нижнего регистра
	char LowCaseAlphabet[26];
	char lowercase = 97;
	for( i = 0; i < 26; i++)
	{
		LowCaseAlphabet[i] = lowercase;
		lowercase++;
	};
	
	//открываем файл txt.txt для считывания символов
	char sym[10000];
	
	FILE *fp;

	if((fp=fopen("txt.txt", "r+"))==NULL)
	{

	printf ("Cannot open file.\n");

	} else { // собираем символы
	
    fgets(sym, 10000, fp);
	fclose(fp);
	};
	int z;
	for(z = 0; sym[z] != '\0'; z++)
	{
		printf("%c", sym[z]);

	}
	int x;
	int t;
	
	// считаем символы
	while(1){
		for(t = 0; sym[t] != '\0'; t++)
		{
			for(x = 0; x <= 26; x++){

			if(UpCaseAlphabet[t] == sym[x]) 
			{	
						
				numberUpper[t]++;
				
		
			} else if(LowCaseAlphabet[t] == sym[x])
			{	 
			
				numberLower[t]++; 
				
			
			} 
	
		}
	}
	break;	
	}
	int y;
	for(int y = 0; y < 26; y++)
	{
	printf("%c: %d \n", UpCaseAlphabet[y], numberUpper[y]);
	printf("%c: %d \n", LowCaseAlphabet[y], numberLower[y]);
	};



	
}
