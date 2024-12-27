#include<stdio.h>
#include<stdlib.h>
int main()
{
int RQ[100],i,n,TotalHeadMovements=0,initial;
printf("enter no of requests\n");
scanf("%d"&n);
printf("enter request sequence\n");
for(i=0;i<n;i++)
scanf("%d",&RQ[i]);
printf("enter the initial position \n");
scanf("%d",&initial);

for(i=0;i<n;i++)
{
TotalHeadMovements=TotalHeadMovements+abs(RQ[i]-initial);
initial=RQ[i];
}

printf("Total Head movements is %d",TotalHeadMovements);
return 0;
}
