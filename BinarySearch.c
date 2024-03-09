#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int Binarysearch(int a[],int sindex,int eindex,int data)
{
    if(eindex >= sindex)
    {
        int m;
        m=sindex+(eindex-sindex)/2;
        if(a[m]==data)
            return m;
        else if(a[m] > data)
            return Binarysearch(a,sindex,m-1,data);
        else if (a[m]< data)
            return Binarysearch(a,m+1,eindex,data);
    }
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
        printf("%d\n",Binarysearch(a,0,9,i));
    }
}
