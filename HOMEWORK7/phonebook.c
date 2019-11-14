#include <stdio.h>
#include <string.h>

struct namenum {
	char name[20];
	long int number;
} Phonebook[10];

//добавление контакта
int count = 0;
char inName[20];
long int inNumber;

int push(){
	
	printf("\nВведите имя, которое вы хотите добавить(макс. 20 букв): \n");
	scanf("%s", inName);
	strncpy(Phonebook[count].name, inName, 20);

	
	printf("Введите номер телефона: \n");
	scanf("%li", &inNumber);
	Phonebook[count].number = inNumber;
	
	
	FILE *fp;
	fp=fopen("phonebook.txt", "r+");
	fprintf(fp, "%s %li", Phonebook[count].name, Phonebook[count].number);
	fclose(fp);

	printf("Контакт %s и соответствующий номер телефона (%li) записаны!\n\n\n", inName, inNumber);
	count++;
	return menu();
	}	

//вывести все контакты
int showAll(){
	for(int i = 0; i != count; i++)
		printf("Ваши контакты: %s %li\n\n", Phonebook[i].name, Phonebook[i].number);	
	
	return menu();
}
//поиск контактов
char inSearch[20];
int matchCount[20];
int match;

int search(){
	printf("Введите имя (только буквы) \n");
	scanf("%s", inSearch);
	for(int j = 0; j != count; j++)
	{
		for( int i = 0; i < strlen (inSearch); i++)
		{
			if(inSearch[i] == Phonebook[j].name[i])
			{
				matchCount[j]++;
			}
			
			
			
		}
		if(matchCount[j] > 3)
			{	
				printf("Номер: %li\n", Phonebook[j].number);
			}
		
	}
	for(int j = 0; j !=count; j++)
	{
		matchCount[j] = 0;
	}
	

	return menu();
}
//меню программы


int menu(){

	printf("Телефонный справочник\nВыберите одно из действий(укажите цифру)\n1.Добавить контакт\n2.Вывести все контакты\n3.Поиск номера телефона по имени\n");

	// управление меню программы
	int decision;
	scanf("%d", &decision);
	switch (decision){
		case 1: 
			push();
			break;
		case 2:
			showAll();
			break;
		case 3:
			search();
			break;
		default:
			printf("Нет такой команды!\n");
	}

	return 0;
}


int main(){

	menu();
	

	return 0;

}
