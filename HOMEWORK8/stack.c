#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Task {
	char name[MAX_SIZE];
	int time; 
	int priority;
	struct Task *next;
} Task;

void push(Task **top, int number){
	Task *NewTask;
	NewTask = malloc(NewTask);
	//strncpy(NewTask->name, TaskName, MAX_SIZE);
	NewTask->priority = number;
	if (top == NULL) {
		*top = NewTask;
	}
	else
	{
		NewTask->next=*top;
		*top = NewTask;			
	}

}

void peek(Task *top){
	Task *NewTask = top;
	while(NewTask){
		printf("%d", NewTask->priority);
		NewTask = NewTask->next;

	}


}
/*void pop(Task **top, int N){
	Task *q = *top;
	Task *prev = NULL;
	
	while(q != NULL) {
		if(q->



}*/




int main(){
	//srand(time(NULL));
	
	Task *top = NULL;
	push(&top, 1);
	push(&top, 2);
	push(&top, 3);

	//peek(top);



	return 0; 
}
