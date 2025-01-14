#include <iostream>

#define MEMORY_MAX 1048576


int memory_left = MEMORY_MAX;
int memory_used = 0;
int number_partition = 1;
char *memory_allocated = new char[MEMORY_MAX];
struct partition{
	char *partition = NULL;
	long int size;
	int number;
};
partition all_partitions[10];

int AddPartition();
int ShowPartitions();
int DelPartition();
int MergePartitions();
int CheckMemory();
//Меню программы
int Menu()
{
	std::cout<<"\n\n1.Добавить раздел\n2.Удалить раздел\n3.Объединить разделы\n";
	int option = 0;
	std::cin>>option;
	switch (option) {
		case 1:
			return AddPartition();
			break;
		case 2:
			return DelPartition();
			break;
		case 3:
			return MergePartitions();
			break;
	}
}

//Добавление раздела
int AddPartition()
{
    
	CheckMemory();
	int memory_input = 0;
	std::cout<<"Введите размер раздела (минимум 1024 и максимум "<<memory_left<<")\n";
    std::cin>>memory_input;
		
	int check = 0;

	if(memory_input<1024 || memory_input>memory_left)
	{
		std::cout<<"Введите допустимый размер!!!\n";
		return AddPartition();
	}
		
		
		
	memory_left -= memory_input;
	memory_used += memory_input;

	std::cout<<"Раздел "<<number_partition<<" размером "<<memory_input<<" байт успешно добавлен\n";
	std::cout<<"Памяти занято: "<<memory_used<<", Свободно: "<<memory_left<<'\n';

	for(int i = 0; check != 1; i++)
	{
		if(all_partitions[i].partition == NULL && check != 1)
		{
			all_partitions[i].partition = new (memory_allocated) char[memory_input];
			for(int j = 0; j < memory_input; j++)
			{
				all_partitions[i].partition[j] = 'a';
			}
			check++;
			all_partitions[i].size = memory_input;
			if(all_partitions[i].number == 0)
			{
				all_partitions[i].number = number_partition++;
			}
		}
			
	}
		
	check = 0;
		
		

	
		
	
	ShowPartitions();
	
	return Menu();
}
//проверка памяти 
int CheckMemory()
{
	if(memory_left > 0)
	{
		return 0;
	} else 
	{
		std::cout<<"Свободной памяти не осталось\n";
		return Menu();
	}
}
//проверка указателя разделa

//Показать разделы 
int ShowPartitions(){
	std::cout<<"На данный момент имеются следующие разделы\n";
	for(int i = 0; i < number_partition; i++)
	{
		if(all_partitions[i].partition != NULL)
		{
			std::cout<<"Раздел "<<all_partitions[i].number<<", размер = "<< all_partitions[i].size<<'\n';	
		}
	}
	
	return 0;

}
//Удаление разделов

int DelPartition(){
	ShowPartitions();
	std::cout<<"Что удаляем?(Укажите номер раздела)\n";
	int option = 0;
	std::cin>>option;

	all_partitions[option-1].partition=NULL;

	std::cout<<"Раздел "<<all_partitions[option-1].number<<" успешно удалён\n";

	memory_left += all_partitions[option-1].size;
	memory_used -= all_partitions[option-1].size;

	all_partitions[option-1].size = 0;
	

	for(int i = 0; i < all_partitions[option-1].size; i++)
	{
		memory_allocated[i]=' ';
	}
	
	
	
	ShowPartitions();
	return Menu();

}
//Объединение разделов
int MergePartitions()
{
	ShowPartitions();
	std::cout<<"Что объединяем?(Укажите номер разделов)\n";
	int option1 = 0;
	int option2 = 0;
	
	std::cin>>option1;
	std::cout<<"Раздел "<<option1<<" и... \n";
	std::cin>>option2;
	
		
	for(int i = option1; i < option2; i++)
	{
		all_partitions[option1-1].size = all_partitions[option1-1].size + all_partitions[i].size;
		
		all_partitions[option1-1].partition = new (memory_allocated) char[all_partitions[option1-1].size + all_partitions[i].size];

		for(int j = 0; j < all_partitions[i].size; j++)
		{

			all_partitions[i].partition[j] = ' ';

		}

		

		for(int j = 0; j < all_partitions[option1-1].size; j++)
		{

			all_partitions[option1-1].partition[j] = 'a';

		}
		
		all_partitions[i].partition = NULL;
		all_partitions[i].size = 0;
		
		
	} 
	
	
	ShowPartitions();
	return Menu();
}





int main()
{
	

	Menu();

	
    return 0;

}
	

