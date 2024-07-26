#include <stdio.h>
int scanarray(int arr[50][50], int n1, int n2)
{
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n2; j++)
		{
			printf("enter the value of [%d][%d] element\n", i, j);
			scanf("%d", &arr[i][j]);
		}
	}
}
int printarray(int arr[50][50], int n1, int n2)
{
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n2; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	int arr[50][50], arr2[50][50], arr3[50][50], n1, n2;
	printf("enter the number of rows in the matrix \n");
	scanf("%d", &n1);
	printf("enter the number of columns in the matrix \n");
	scanf("%d", &n2);

	scanarray(arr, n1, n2);
	printf("the 1st matrix is\n");
	printarray(arr, n1, n2);


	// the second array


	scanarray(arr2,n1,n2);
	printf("the 2nd matrix is\n");
	printarray(arr2,n1,n2);


	// addition of metrix
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n2; j++)
		{
			arr3[i][j] = arr2[i][j] + arr[i][j];
		}
	}
	printf("the addition of two metrix is");
 	printarray(arr3,n1,n2);


	return 0;
}
