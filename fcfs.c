#include<stdio.h>
int main()
{
    int n,i,j,at[10],bt[10],ct[10],temp[10],count=0,minat,minpos,total=0;
    printf("Enter the number of processes\n");
    scanf("%d",&n);
    printf("Enter the Arrival Time and Burst Time\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\n",i+1);
        scanf("%d %d",&at[i],&bt[i]);
        temp[i]=at[i];
    }
    minat=99;
    minpos=-1;
    while(count!=n)
    {
        for(i=0;i<n;i++)
        {
            if(at[i]<minat)
            {
                minat=at[i];
                minpos=i;
            }
        }
        total+=bt[minpos];
        at[minpos]=99;
        ct[minpos]=total;
        count++;
        minat=99;
    }
    printf("P\tAT\tBT\tCT\tWT\tTAT\n");
    for(i=0;i<n;i++)
    {
       printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,temp[i],bt[i],ct[i],ct[i]-temp[i]-bt[i],ct[i]-temp[i]);
    }
    return 0;
    }
