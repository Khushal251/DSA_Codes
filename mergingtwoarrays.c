#include <stdio.h>

int main(int argc, char const *argv[])
{
	int i, j, n1, n2, n, arr[100], arr2[100], arr3[100], sum = 0;
	printf("enter the number of elements in an array 1\n");
	scanf("%d", &n1);
	for (int i = 0; i < n1; i++)
	{
		printf("enter the element number %d\n", i);
		scanf("%d", &arr[i]);
	}
	printf("the array is \n");
	for (int i = 0; i < n1; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\nenter the number of elements in an array 2\n");
	scanf("%d", &n2);
	for (int i = 0; i < n2; i++)
	{
		printf("enter the element number %d\n", i);
		scanf("%d", &arr2[i]);
	}
	printf("the array is \n");
	for (int i = 0; i < n2; i++)
	{
		printf("%d ", arr2[i]);
	}
	n = n1 + n2;
	for (i = 0; i < n1; i++)
	{
		arr3[i] = arr[i];
	}
	for (j = 0; j < n2; j++)
	{
		arr3[i] = arr2[j];
		i++;
	}

	printf("\nthe new array is\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr3[i]);
	}

	return 0;
}