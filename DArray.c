#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
struct DArray* CreateArray(int );
struct DArray
{
    int capacity,lastindex,*ptr;
};
struct DArray* CreateArray(int cap)
{
    struct DArray *arr;
    arr=(struct DArray*)malloc(sizeof(struct DArray));
    arr->capacity=cap;
    arr->lastindex=-1;
    arr->ptr=(int*)malloc(sizeof(int)*cap);
    return arr;
}
void doubleArray(struct DArray *arr)
{
    int *temp;
    temp=(int*)malloc(sizeof(int)*arr->capacity*2);
    for(int i=0;i<=arr->lastindex;i++)
        temp[i]=arr->ptr[i];
    free(arr->ptr);
    arr->ptr=temp;
    arr->capacity=arr->capacity*2;

}
void halfArray(struct DArray *arr)
{
    if(arr->capacity>1)
    {
        int *temp;
        temp=(int*)malloc(sizeof(int)*arr->capacity/2);
        for(int i=0;i<=arr->lastindex;i++)
            temp[i]=arr->ptr[i];
        free(arr->ptr);
        arr->ptr=temp;
        arr->capacity=arr->capacity/2;
    }
}
void append(struct DArray *arr,int data)
{
    if(arr->lastindex==arr->capacity-1)
        doubleArray(arr);
    arr->lastindex+=1;
    arr->ptr[arr->lastindex]=data;
}
void insert(struct DArray *arr,int index,int data)
{
    if(index<0 || index >arr->lastindex+1)
        printf("Invalid Index");
    else
    {
        if(arr->lastindex==arr->capacity-1)
            doubleArray(arr);
        for(int i=arr->lastindex;i>=index;i--)
            arr->ptr[i+1]=arr->ptr[i];
        arr->ptr[index]=data;
        arr->lastindex+=1;
    }
}
void del(struct DArray *arr,int index)
{
    if(index<0 || index >arr->lastindex)
        printf("Invalid Index");
    else
    {
        for(int i=index;i<arr->lastindex;i++)
            arr->ptr[i]=arr->ptr[i+1];
        arr->lastindex-=1;
        if(arr->lastindex+1<=arr->capacity/2)
            halfArray(arr);
    }
}
void view(struct DArray *arr)
{
    for(int i=0;i<=arr->lastindex;i++)
        printf("%d ",arr->ptr[i]);
}
int main()
{
    struct DArray *arr;
    arr=CreateArray(3);
    append(arr,1);
    append(arr,2);
    append(arr,3);
    append(arr,4);
    append(arr,5);
    view(arr);
    printf("\n");
    del(arr,2);
    del(arr,3);
    view(arr);
}


