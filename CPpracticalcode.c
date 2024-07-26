//naveen code sent through email to mam
#include <stdio.h>
void main()
{
char vt[50][20],price[20][20];
int sm[20],em[20],i,count=0,end;
for(i=1;i<=4;i++)
{
printf("If you want end process than type -999 else 0:");
scanf("%d",&end);
if(end==-999)
break;
printf("Enter vehicle type:");
scanf("%s",vt[i]);
printf("Enter the starting and ending months of sales\n");
scanf("%d %d",&sm[i],&em[i]);
printf("Enter price:");
scanf("%s",price[i]);
count++;
}
printf("Vehicle Type   Month of sale   Price\n");
printf("------------------------------------\n");
for(i=1;i<=count;i++)
{
printf("%-12s     %4d/%d   %10s",vt[i],sm[i],em[i],price[i]);
putchar('\n');
}
}










// // code which is in pdf
// #include <stdio.h>
// #include <conio.h>
// #define MAX 10
// void main()
// {
// 	char Veh[MAX][MAX] = {""};
// 	char Vehicle[MAX];
// 	int St_Mon[MAX],
// 		En_Mon[MAX],
// 		StMon, EnMon;
// 	long int Price[MAX];
// 	int n, i;
// 	clrscr();
// 	printf("How Entries U Want to Enter\n");
// 	scanf("%d", &n);
// 	printf("Enter Vehcle Type,Starting Month, Ending Month & Price:--\n");
// 	for (i = 0; i < n; i++)
// 	{
// 		scanf("%s", Veh[i]);
// 		scanf("%d", &St_Mon[i]);
// 		scanf("%d", &En_Mon[i]);
// 		scanf("%ld", &Price[i]);
// 	}
// 	clrscr();
// 	printf("Vehicle TypeMonth of SalesPrice\n");
// 	for (i = 0; i < n; i++)
// 	{
// 		printf("%s0%d / 0%d%ld\n", Veh[i], St_Mon[i], En_Mon[i], Price[i]);
// 	}

// 	printf("Enter The Type of Vehicle\n");
// 	scanf("%s", Vehicle);
// 	printf("Enter the Starting & Ending Month\n");
// 	scanf("%d %d", &StMon, &EnMon);
// 	for (i = 0; i < n; i++)
// 	{
// 		if ((strcmp(Veh[i], Vehicle) == 0))
// 		{
// 			if (St_Mon[i] >= StMon)
// 			{
// 				if (En_Mon[i] <= EnMon)
// 				{
// 					printf("Vehicle Type%s is Sold During Period0%d/0%d\n", Vehicle, StMon, EnMon);
// 					getch();
// 					exit(0);
// 				}
// 			}
// 		}
// 	}
// 	printf("Vehicle Type%s Not Sold During Period 0%d/0%d\n", Vehicle, StMon, EnMon);
// 	getch();
// }

