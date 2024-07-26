#include <stdio.h>
int scanarray(int array[20][20], int m1, int m2)
{
	for (int i = 0; i < m1; i++)
	{
		for (int j = 0; j < m2; j++)
		{
			printf("enter the [%d][%d] element of the array\n", i, j);
			scanf("%d", &array[i][j]);
		}
	}
	printf("\n");
}

int printarray(int array[20][20], int m1, int m2)
{
	for (int i = 0; i < m1; i++)
	{
		for (int j = 0; j < m2; j++)
		{
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
}

int main(int argc, char const *argv[])
{
	int M1, M2, m1, m2, met1[20][20], met2[20][20], res[20][20], sum = 0;

	printf("enter the rows and columns in the 1st matrix\n");
	scanf("%d %d", &M1, &M2);
	printf("rows=%d, columns=%d\n", M1, M2);
	printf("enter the elements of the array\n");
	scanarray(met1, M1, M2);
	printf("the array is\n");
	printarray(met1, M1, M2);

	printf("enter the rows and columns in the 2nd matrix\n");
	scanf("%d %d", &m1, &m2);
	printf("rows=%d, columns=%d\n", m1, m2);
	printf("enter the elements of the array\n");
	scanarray(met2, m1, m2);
	printf("the array is\n");
	printarray(met2, m1, m2);

	for (int i = 0; i < M1; i++)
	{
		for (int j = 0; j < m2; j++)
		{
			for (int k = 0; k < M2; k++)
			{
				sum += met1[i][k] * met2[k][j];
			}
			res[i][j]=sum;
			sum=0;
		}
	}
	printf("the multiple of these two metrix is \n");
	printarray(res,M2,m1);

	return 0;
}