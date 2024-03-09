#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Array
{
    int *ptr,lastindex,capacity;
};
struct Array* CreateArray(int capacity)
{
    struct Array *arr;
    arr=(struct Array*)malloc(sizeof(struct Array));
    arr->capacity=capacity;
    arr->lastindex=-1;
    arr->ptr=(int*)malloc(sizeof(int)*capacity);
    return arr;
}
void append(struct Array *arr,int value)
{
    if(arr->lastindex==arr->capacity-1)
    {
        printf("Overflow");
    }
    else
    {
        arr->lastindex+=1;
        arr->ptr[arr->lastindex]=value;
    }
}
void insert(struct Array *arr,int index,int value)
{
    if(arr->lastindex==arr->capacity-1)
        printf("Overflow");
    else if(index<0 || index >arr->lastindex+1)
        printf("Invalid Index");
    else
    {
            int i;
            for(i=arr->lastindex;i>=index;i--)
                arr->ptr[i+1]=arr->ptr[i];
            arr->ptr[index]=value;
            arr->lastindex+=1;
    }
}
void edit(struct Array *arr,int index,int value)
{
    if(index<0 || index > arr->lastindex)
        printf("Invalid Index");
    else
        arr->ptr[index]=value;
}
void del(struct Array *arr,int index)
{
    int i;
    if(index<0 || index > arr->lastindex)
        printf("Invalid Index or Empty Array");
    else
    {
        for(i=index;i<arr->lastindex;i++)
            arr->ptr[i]=arr->ptr[i+1];
        arr->lastindex-=1;
    }
}
void view(struct Array *arr)
{
    int i;
    for(i=0;i<=arr->lastindex;i++)
        printf("%d ",arr->ptr[i]);
}
int main()
{
    int cap,ch,val,index;
    struct Array *arr;
    printf("Enter Capacity of Array:");
    scanf("%d",&cap);
    arr=CreateArray(cap);
   while(1)
   {
       system("cls");
       view(arr);
       printf("\n1.Append\n2.Insert\n3.Delete\n4.Edit\n5.Exit\n");
       printf("Enter Your Choice:");
       scanf("%d",&ch);
       switch(ch)
       {
        case 1:
            printf("Enter Data to Append:");
            scanf("%d",&val);
            append(arr,val);
            break;
        case 2:
            printf("Enter index to which Value is entered:");
            scanf("%d",&index);
            printf("Enter Value:");
            scanf("%d",&val);
            insert(arr,index,val);
            break;
        case 3:
            printf("Enter Index of value to delete:");
            scanf("%d",&index);
            del(arr,index);
            break;
        case 4:
            printf("Enter Index to Edit:");
            scanf("%d",&index);
            printf("Enter Value:");
            scanf("%d",&val);
            edit(arr,index,val);
            break;
        case 5:
            printf("Enter any key to exit");
            getch();
            exit(0);
            break;
        default:
            printf("Enter Valid Choice\n");
            printf("Press any key to continue");
            getch();
       }

   }

}
