#include <stdio.h>
void main()
{
char vt[50][20],price[20][20];
int sm[20],em[20],i,count=0,end;
for(i=1;i<=20;i++)
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
