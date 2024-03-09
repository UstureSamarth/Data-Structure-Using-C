#include<stdio.h>
#include<stdlib.h>
int linearsearch(int a[],int size,int data)
{
    for(int i=0;i<size;i++)
        if(a[i]==data)
            return i;
    return -1;
}

void display(int a[],int size)
{
    for(int i=0;i<size;i++)
        printf("%d ",a[i]);
}
int main()
{
    int a[10]={1,2,3,4,5,6,6,17,18,20};
    int i;
    display(a,10);
    while(1)
    {
        printf("\nEnter Item To Search:");
        scanf("%d",&i);
        if(i==0)
            exit(0);
        else
        printf("%d\n",linearsearch(a,10,i));
    }
}
