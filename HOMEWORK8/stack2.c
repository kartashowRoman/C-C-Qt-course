#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


typedef struct Task 
{
	char name;
	int time;
	int priority;
	struct Task *next;
} Task;
int CharCount = 65;
int priority = 1;

//для стека
Task *top;


char name;// сделать ручной ввод с переключением на автоматический




//функции стека
void push()
{
	name = CharCount;
	
	Task *NewTask;
	NewTask = (Task *) malloc (sizeof(Task));
	
	NewTask->name = name;
	NewTask->time = rand() % 5 + 1;
	NewTask->priority =+ priority;
	NewTask->next = top;
	
	top = NewTask;
	CharCount++;
	priority++;
    printf("Task %c has been added\n", NewTask->name);
	
}

int isEmpty()
{
	return top == NULL;
}



int peek()
{
	if (!isEmpty())
	{
		printf("The task on the top: %c\n", top->name);
	} else {
		printf("Stack if empty");
		
	}
	return ExecutionStack();
}

void display()
{
	Task *temp;
	if (top == NULL)
	{
		printf("Stack if empty");
	} else {
		printf("The stack has following tasks: \n");
		temp = top;
		while(temp != NULL)
		{
			printf("Task name: %c\n", temp->name);
			temp = temp->next;
		}
	}
}

void pop()
{
	Task *temp;
	if (top == NULL)
	{
		printf("The stack is empty");
	} else {
		sleep(top->time);
		printf("Task %c has been successfully executed (Time: %d sec)\n", top->name, top->time);
		temp = top;
		top = top->next;
		temp->next = NULL;
		free(temp);

	}

}

//для очереди
typedef struct Queue
{
	Task *front, *rear;
} Queue;

Queue *q;

//создать пустой список
void createQueue()
{
	q = (Queue *)malloc(sizeof(Queue));
	q->front = q->rear = NULL;
}
// если список пуст
int QueueEmpty()
{
	return q->front == NULL;
}

// добавить элемент в список
int Qpriority = 1;
void addQueue()
{
	name = CharCount;

	Task *temp = (Task *)malloc(sizeof(Task));

	temp->name = name;
	temp->time = rand() % 5 + 1;
	temp->priority =+ Qpriority;
	CharCount++;
	Qpriority++;
	if (q->rear == NULL) 
	{
		q->front = temp;
		q->rear = temp; 
	}
	q->rear->next = temp;
	q->rear = temp;
	printf("Task %c has been added\n", temp->name);
	printf("%d", temp->priority);

}
// Удалить элемент из списка
void delQueue()
{
	if (q->front == NULL)
	{
	
		printf("The queue is empty!\n");
		
	}
	sleep(q->front->time);
	printf("Task %c has been successfully executed (%d sec)\n", q->front->name, q->front->time);

	Task *temp = q->front;
	free(temp);
	q->front = q->front->next;

	if (q->front == NULL)
	{
		q->rear = NULL;
		printf("The queue is empty!\n");
	}
}
// Посмотреть первый элемент из списка
int peekQueue()
{
	if(q->front == NULL)
	{
		printf("The queue is empty!");
		
	} else {
		printf("The first task is: %c\n", q->front->name);
		
	}
}




//выполнение 
void menu(){
	
	printf("Choose your mode (enter number): \n 1.Stack\n 2.Queue\n");	

	int ModeOption = 0;
	scanf("%d", &ModeOption);
	
	if(ModeOption == 1)
	{
		return GenerateTasksStack();	
	
	} else if (ModeOption == 2)
	{
		return GenerateTasksQueue();

	} else 
	{
		printf("Enter either 1 or 2 !!!\n");
		return menu();

	}
	

}

// Генерируем задачи для стека
void GenerateTasksStack()
{
	printf("Generate the number of tasks automatically or manually? \n 1.Automatically\n 2.Manually\n");
	int Option = 0;
	scanf("%d", &Option);
	
	int NumTask = 0;

	if (Option == 1)
	{
		NumTask = rand() % 5 + 1;
		for (int i = 0; i < NumTask; i++)
		{
			push();
		}
		return ExecutionStack();
	} else if (Option == 2)
	{
		printf("How many tasks to push?\n");
		scanf("%d", &NumTask);
		for (int i = 0; i < NumTask; i++)
		{
			push();
		}
		return ExecutionStack();
	} else
		printf("Enter either 1 or 2 !!!\n");
		return GenerateTasksStack();

}
// Генерируем задачи для списка
void GenerateTasksQueue()
{
	printf("Generate the number of tasks automatically or manually? \n 1.Automatically\n 2.Manually\n");
	int Option = 0;
	scanf("%d", &Option);
	
	createQueue();
	
	int NumTask = 0;
	
	if (Option == 1)
	{
		NumTask = rand() % 5 + 1;
		for (int i = 0; i < NumTask; i++)
		{
			addQueue();
		}
		
	} else if (Option == 2)
	{
		printf("How many tasks to push?\n");
		scanf("%d", &NumTask);
		for (int i = 0; i < NumTask; i++)
		{
			addQueue();
		}
		
	} else
	{
		printf("Enter either 1 or 2 !!!\n");
		return GenerateTasksQueue;
	}
	return ExecutionQueue();
}


// Выполнение задач стека

void ExecutionStack()
{
	printf("Peek or execute?\n1.Peek\n2.Execute\n");
	int choice = 0;
	scanf("%d", &choice);
	if( choice == 1)
	{
		return peek();
	} else if (choice == 2)
	{		
		printf("\nTasks are being executed\n\n");
		for (int i = 0; !isEmpty(); i++)
			pop();
		printf("No more tasks to be executed!\n");
		return menu();
	} else 
	{
		printf("Enter either 1 or 2 !!!");
		return ExecutionStack();
	}
	
}

// Выполнение задач очереди

void ExecutionQueue()
{
	printf("Peek or execute?\n1.Peek\n2.Execute\n");
	int choice = 0;
	scanf("%d", &choice);
	
	if( choice == 1)
	{
		peekQueue();
		return ExecutionQueue();
	} else if (choice == 2)
	{		
		int count = 0;
		count = q->rear->priority;	
		
		printf("\nTasks are being executed\n\n");
		for (int i = 0; i < count; i++)
		{ 
			delQueue();
			
		}
		return menu();
	} else 
	{
		printf("Enter either 1 or 2 !!!");
		return ExecutionQueue();
	}
}



int main(){
	srand(time(NULL));
	
	
	menu();
	
	return 0;
}
