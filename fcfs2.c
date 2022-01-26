#include<stdio.h>
#include<stdlib.h>
struct process
{
    int pid;
    int at;
    int bt;
    int ct;
};
void swap(int a,int b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}
void sort(struct process* p,int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(p[i].at>p[j].at)
            {
                swap(p[i].at,p[j].at);
                swap(p[i].pid,p[j].pid);
                swap(p[i].bt,p[j].bt);
            }
        }
    }
}
void calc(struct process* p,int n)
{
    int i,total=0;
    for(i=0;i<n;i++)
    {
        total+=p[i].bt;
        p[i].ct=total;
    }
}
void display(struct process* p,int n)
{
    int i;
    printf("P\tAT\tBT\tCT\tWT\tTAT\n");
    for(i=0;i<n;i++)
    printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].ct-p[i].at-p[i].bt,p[i].ct-p[i].at);
}
int main()
{
    int n,i;
    printf("Enter the number of processes\n");
    scanf("%d",&n);
    struct process* p=(struct process*)malloc(sizeof(struct process));
    printf("PID\tAT\tBT\n");
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d",&p[i].pid,&p[i].at,&p[i].bt);
    }
    sort(p,n);
    calc(p,n);
    display(p,n);
    realloc(p,0);
    return 0;
}