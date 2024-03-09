#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
struct Deque
{
    int capacity;
    int front,rear;
    int *ptr;
};
struct Deque* createdeque(int cap)
{
    struct Deque *d;
    d=(struct Deque*)malloc(sizeof(struct Deque));
    d->capacity=cap;
    d->front=-1;
    d->rear=-1;
    d->ptr=(int*)malloc(sizeof(int)*cap);
    return d;
}
void push1(struct Deque *d,int data)//insertion at front
{
    if((d->rear==d->capacity-1 && d->front==0) || d->rear+1==d->front)
    {
        printf("Overflow");
        getch();
    }
    else if(d->front==-1)
    {
        d->front+=1;
        d->rear+=1;
        d->ptr[d->front]=data;
    }
    else if(d->front==0)
    {
        d->front=d->capacity-1;
        d->ptr[d->front]=data;
    }
    else
    {
        d->front-=1;
        d->ptr[d->front]=data;
    }
}
void push2(struct Deque *d,int data)//insertion at rear
{
    if((d->rear==d->capacity-1 && d->front==0) || d->rear+1==d->front)
    {
        printf("Overflow");
        getch();
    }
    else if(d->rear==-1)
    {
        d->front+=1;
        d->rear+=1;
        d->ptr[d->rear]=data;
    }
    else if(d->rear==d->capacity-1)
    {
        d->rear=0;
        d->ptr[d->rear]=data;
    }
    else
    {
        d->rear+=1;
        d->ptr[d->rear]=data;
    }
}
void pop1(struct Deque *d)//deletion at front
{
    if(d->front==-1)
    {
        printf("Empty");
        getch();
    }
    else if(d->front==d->rear)
    {
        d->front-=1;
        d->rear-=1;
    }
    else if(d->front==d->capacity-1)
        d->front=0;
    else
        d->front+=1;
}
void pop2(struct Deque *d)//deletion at rear
{
    if(d->rear==-1)
    {
        printf("Empty");
        getch();
    }
    else if(d->front==d->rear)
    {
        d->front-=1;
        d->rear-=1;
    }
    else if(d->rear==0)
        d->rear=d->capacity-1;
    else
        d->rear-=1;
}
void peek1(struct Deque *d)//value at front
{
    if(d->front==-1)
        printf("Empty");
    else
        printf("%d",d->ptr[d->front]);
}
void peek2(struct Deque *d)//value at rear
{
    if(d->rear==-1)
        printf("Empty");
    else
        printf("%d",d->ptr[d->rear]);
}
int main()
{
    int cap,ch,data;
    struct Deque *d;
    printf("Enter Capacity:");
    scanf("%d",&cap);
    d=createdeque(cap);
    while(1)
    {
        system("cls");
        peek1(d);
        printf("\t\t");
        peek2(d);
        printf("\n1.Push1\n2.Push2\n3.Pop1\n4.Pop2\n5.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter Data:");
                scanf("%d",&data);
                push1(d,data);
                break;
            case 2:
                printf("Enter Data:");
                scanf("%d",&data);
                push2(d,data);
                break;
            case 3:
                pop1(d);
                break;
            case 4:
                pop2(d);
                break;
            case 5:
                exit(0);
        }
    }
}

