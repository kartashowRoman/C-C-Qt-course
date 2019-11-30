#include <stdio.h>
#include <time.h>
#include <string.h>
#define MAX_ARR 100000 


int arr1[MAX_ARR], arr2[MAX_ARR], arr3[MAX_ARR];


//Быстрая сортировка

int Compare(const void *p, const void *q)
{
	int x = *(const int *)p;
	int y = *(const int *)q;
	
	if(x<y)
		return -1;
	else if (x>y)
		return 1;
	return 0;


}

void QuickSort(int *a, size_t n)
{
	qsort(a, n, sizeof(int), Compare);
}

//Сортировка пузырьком

void BubbleSort(int *arr,int n)
{
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = 0; j < n - i - 1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;

			}
			
		}
	}
}
// Сортировка слиянием

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    
    int L[n1], R[n2]; 
  
    
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    
    i = 0; 
    j = 0;  
    k = l;  
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        
        int m = l+(r-l)/2; 
  
         
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
// Сравнение времени работы алгоритмов
void Comparison()
{
	printf("Сравниваем время работы 3х алгоритмов сортировки (быстрая сортировка, сортировка пузырьком и сортировка слиянием)\n");
	for(int i = 0; i < MAX_ARR; i++)
	{
		arr1[i] = rand() % 100000;
	}
	clock_t t;
	t = clock();
	QuickSort(arr1, MAX_ARR);
	t = clock() - t;
	printf("Быстрая сортировка: %f сек.\n", ((double)t)/CLOCKS_PER_SEC);
	for(int i = 0; i < MAX_ARR; i++)
	{
		arr2[i] = rand() % 100000;
	}
	
	t = clock();
	BubbleSort(arr2, MAX_ARR);
	t = clock() - t;
	printf("Cортировка пузырьком: %f сек.\n", ((double)t)/CLOCKS_PER_SEC);
	for(int i = 0; i < MAX_ARR; i++)
	{
		arr3[i] = rand() % 100000;
	}
	
	t = clock();
	mergeSort(arr3, 0, MAX_ARR - 1);
	t = clock() - t;
	printf("Cортировка слияние: %f сек.\n", ((double)t)/CLOCKS_PER_SEC);

}


int main()
{
	srand(time(NULL));
	
	
	
	
	Comparison();

	return 0;
	
}
