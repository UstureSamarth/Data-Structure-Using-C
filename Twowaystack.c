#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct TWstack
{
    int capacity;
    int top1,top2;
    int *ptr;

};
struct TWstack* createtwstack(int cap)
{
    struct TWstack *s;
    s=(struct TWstack*)malloc(sizeof(struct TWstack));
    s->capacity=cap;
    s->top1=-1;
    s->top2=cap;
    s->ptr=(int*)malloc(sizeof(int)*cap);
    return s;
}
void push1(struct TWstack *s,int data)
{
    if(s->top1==s->capacity-1 || s->top2==0 || s->top1+1==s->top2)
    {
        printf("overflow");
        getch();
    }
    else
    {
        s->top1+=1;
        s->ptr[s->top1]=data;
    }
}
void push2(struct TWstack *s,int data)
{
    if(s->top1==s->capacity-1 || s->top2==0 || s->top1+1==s->top2)
    {
        printf("overflow");
        getch();
    }
    else
    {
        s->top2-=1;
        s->ptr[s->top2]=data;
    }
}
void pop1(struct TWstack *s)
{
    if(s->top1==-1 && s->top2==s->capacity)
    {
        printf("Empty");
        getch();
    }
    else
        s->top1-=1;
}
void pop2(struct TWstack *s)
{
    if(s->top1==-1 && s->top2==s->capacity)
    {
        printf("Empty");
        getch();
    }
    else
        s->top2+=1;
}
void peek1(struct TWstack *s)
{
    if(s->top1==-1)
        printf("Empty");
    else
        printf("%d",s->ptr[s->top1]);

}
void peek2(struct TWstack *s)
{
    if(s->top2==s->capacity)
        printf("Empty");
    else
        printf("%d",s->ptr[s->top2]);
}
int main()
{
    int cap,ch,data;
    struct TWstack *s;
    printf("Enter Capacity:");
    scanf("%d",&cap);
    s=createtwstack(cap);
    while(1)
    {
        system("cls");
        peek1(s);
        printf("\t\t");
        peek2(s);
        printf("\n1.Push1\n2.Push2\n3.Pop1\n4.Pop2\n5.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter Data:");
                scanf("%d",&data);
                push1(s,data);
                break;
            case 2:
                printf("Enter Data:");
                scanf("%d",&data);
                push2(s,data);
                break;
            case 3:
                pop1(s);
                break;
            case 4:
                pop2(s);
                break;
            case 5:
                exit(0);
        }
    }
}
