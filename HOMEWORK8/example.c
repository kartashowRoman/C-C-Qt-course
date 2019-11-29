#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct myT{
  int i;
  char c;
  int priority;
  struct myT * Next;
};
void handlerStructs
  (struct myT * Task,
   struct myT * Task2){

    Task->i = Task2->i /2;
    Task->c = ++Task2->c;
}

void initPriority(struct myT *Task){
  Task->priority = rand()%10;
}

void listLinker
  (struct myT * Task,
   struct myT * Task2){

  Task->Next = Task2;
}






int main(){
  srand(time(NULL));

  struct myT Task[10];
  Task[0].i = 9000;
  Task[0].c = 'A';



  for (int j=1; j <10; j++)
    handlerStructs
      (&Task[j], &Task[j-1]);

////////////////////////

  for (int j=0; j <10; j++)
    initPriority(&Task[j]);

  for (int j=1; j <10; j++){
    listLinker
      (&Task[j-1], &Task[j]);
  }
  Task[9].Next = 0;

  struct myT * currentTask;
  currentTask = &Task[0];
  do{
    printf("Current El: %d %c Priority: %d \n",
currentTask->i, currentTask->c,
currentTask->priority);      

    currentTask =
          currentTask->Next;
  }while(currentTask!=0);

  return 0;
}
