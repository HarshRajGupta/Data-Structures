#include <stdio.h>
#define MAX 2000

void ScanArray(int* Arr, int n)
{
	for (int i=0; i<n; ++i)
		scanf("%d",Arr + i);
}

void PrintArray(int* Arr, int n)
{
	printf("\n========================================\n");
	for (int i=0; i<n; ++i)
		printf("%d ", *(Arr + i));
	printf("\n========================================\n");
}

void merge(int* mer, int* Arr1, int n1, int* Arr2, int n2)
{
	for (int i=0; i<n1; ++i)
	{
		*(mer + i) = *(Arr1 + i);
	}
	for (int i=n1; i<n1+n2; ++i)
	{
		*(mer + i) = *(Arr2 + (i-n1));
	}
}

int main(void)
{
	printf("Array size of 1st Array : ");
	int n1;
	scanf("%d", &n1);
	printf("Enter Elements of 1st Array\n");
	int Arr1[MAX] = {0};
	ScanArray(Arr1, n1);
	printf("Array size of 2nd Array : ");
	int n2;
	scanf("%d", &n2);
	printf("Enter Elements of 2nd Array\n");
	int Arr2[MAX] = {0};
	ScanArray(Arr2, n2);
	int result[MAX*2];
	merge(result, Arr1, n1, Arr2, n2);
	PrintArray(result, n1+n2);
	return 0;
}