#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Queue
{
    int capacity;
    int rear;
    int front;
    int *ptr;
};
struct Queue* createqueue(int cap)
{
    struct Queue *q;
    q=(struct Queue*)malloc(sizeof(struct Queue));
    q->capacity=cap;
    q->rear=-1;
    q->front=-1;
    q->ptr=(int*)malloc(sizeof(int)*cap);
    return q;
}
void push(struct Queue *q,int data)
{
    if((q->rear==q->capacity-1 && q->front==0) || (q->rear+1==q->front))
    {
            printf("overflow");
            getch();
    }
    else if(q->rear==-1)
    {
        q->rear+=1;
        q->front+=1;
        q->ptr[q->rear]=data;
    }
    else if(q->rear==q->capacity-1)
    {
        q->rear=0;
        q->ptr[q->rear]=data;
    }
    else
    {
        q->rear+=1;
        q->ptr[q->rear]=data;
    }
}
void pop(struct Queue *q)
{
    if(q->front==-1)
    {
            printf("Empty");
            getch();
    }
    else if(q->front==q->rear)
    {
        q->front=-1;
        q->rear=-1;
    }
    else if(q->front==q->capacity-1)
        q->front=0;
    else
        q->front+=1;
}
void peek(struct Queue *q)
{
    if(q->rear==-1 && q->front==-1)
        printf("Empty");
    else
        printf("%d",q->ptr[q->front]);
    getch();
}
int main()
{
    int cap,ch,data;
    struct Queue *q;
    printf("Capacity:");
    scanf("%d",&cap);
    q=createqueue(cap);
    while(1)
    {
        system("cls");
        printf("1.Push\n2.Pop\n3.Peek\n4.Exit\n\t");
        printf("Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Data:");
                scanf("%d",&data);
                push(q,data);
                break;
            case 2:
                pop(q);
                break;
            case 3:
                peek(q);
                break;
            case 4:
                exit(0);

        }
    }
}
