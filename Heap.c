#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct Heap
{
    int capacity;
    int lastindex;
    int *ptr;
};
struct Heap* createheap(int cap)
{
    struct Heap *h;
    h=(struct Heap*)malloc(sizeof(struct Heap));
    h->capacity=cap;
    h->lastindex=-1;
    h->ptr=(int*)malloc(sizeof(int)*cap);
    return h;
}
void insertion(struct Heap *h,int data)
{
    if(h->lastindex==h->capacity-1)
        printf("Overflow");
    else if(h->lastindex==-1)
    {
        h->lastindex+=1;
        h->ptr[h->lastindex]=data;
    }
    else
    {
        int c,p;
        h->lastindex+=1;
        c=h->lastindex;
        while(c > 0)
        {
            p=(c-1)/2;
            if(data > h->ptr[p])
            {
                h->ptr[c]=h->ptr[p];
                c=p;
            }
            else
                break;
        }
        h->ptr[c]=data;

    }
}

void showheap(struct Heap *h)
{
    if(h->lastindex!=-1)
    {
        for(int i=0;i<=h->lastindex;i++)
            printf("%d ",h->ptr[i]);
    }
}
void deletion(struct Heap *h)
{
    int c,p,data;
    p=0;
    c=2*p+1;
    data=h->ptr[h->lastindex];
    h->lastindex-=1;
    while(c+1 <= h->lastindex)
    {
        if(data >= h->ptr[c] && data >= h->ptr[c+1])
            break;
        if(h->ptr[c] >= h->ptr[c+1])
        {
            h->ptr[p]=h->ptr[c];
            p=c;
        }
        else
        {
            h->ptr[p]=h->ptr[c+1];
            p=c+1;
        }
        c=2*p+1;
    }
    if(c==h->lastindex && data < h->ptr[c])
    {
        h->ptr[p]=h->ptr[c];
        p=c;
    }
    h->ptr[p]=data;
}
int* heapsort(struct Heap *h)
{
    int *arr;
    int i=h->capacity-1;
    arr=(int*)malloc(sizeof(h->capacity));
    while(h->lastindex+1)
    {
        arr[i]=h->ptr[0];
        deletion(h);
        i--;
    }
    return arr;
}
void showarray(int *arr,int size)
{
        for(int i=0;i<size;i++)
            printf("%d ",arr[i]);
}
int main()
{
    int cap,ch,data,a=1;
    struct Heap *h;
    printf("Enter Capacity:");
    scanf("%d",&cap);
    h=createheap(cap);
    while(1)
    {
        system("cls");
        showheap(h);
        printf("\n1.Insertion\n2.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter Data:");
                scanf("%d",&data);
                insertion(h,data);
                break;
            case 2:
                a=0;
        }
        if(a==0)
            break;
    }
    showarray(heapsort(h),cap);
    getch();
}

