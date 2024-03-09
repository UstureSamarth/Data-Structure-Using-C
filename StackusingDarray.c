#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct Stack
{
    int capacity;
    int top;
    int *ptr;
};
struct Stack* createstack(int cap)
{
    struct Stack *s;
    s=(struct Stack*)malloc(sizeof(struct Stack));
    s->capacity=cap;
    s->top=-1;
    s->ptr=(int*)malloc(sizeof(int)*cap);
    return s;
}
void push(struct Stack *s,int data)
{
    if(s->top==s->capacity-1)
        doublearray(s);
    s->top+=1;
    s->ptr[s->top]=data;

}
void pop(struct Stack *s)
{
    if(s->top==-1)
        printf("Empty");
    else
        s->top-=1;
    if(s->top<=s->capacity/2)
        halfarray(s);
}
void doublearray(struct Stack *s)
{
    int *temp;
    temp=(int*)malloc(sizeof(int)*s->capacity*2);
    for(int i=0;i<=s->top;i++)
        temp[i]=s->ptr[i];
    free(s->ptr);
    s->ptr=temp;
    s->capacity*=2;
}
void halfarray(struct Stack *s)
{
    int *temp;
    temp=(int*)malloc(sizeof(int)*s->capacity/2);
    for(int i=0;i<=s->top;i++)
        temp[i]=s->ptr[i];
    free(s->ptr);
    s->ptr=temp;
    s->capacity/=2;
}
void peek(struct Stack *s)
{
    if(s->top==-1)
        printf("Empty");
    else
        printf("%d",s->ptr[s->top]);
}
int main()
{
    int cap,ch,data;
    struct Stack *s;
    printf("Enter Capacity of Stack:");
    scanf("%d",&cap);
    s=createstack(cap);
    while(1)
    {
        system("cls");
        printf("1.PUSH\n2.POP\n3.PEEK\n4.EXIT\n");
        printf("Enter Your Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    printf("Enter Data to add:");
                    scanf("%d",&data);
                    push(s,data);
                    break;
            case 2:
                pop(s);
                break;
            case 3:
                peek(s);
                getch();
                break;
            case 4:
                getch();
                exit(0);
                break;
            default:
                printf("Enter Valid Choice");
        }
    }

}
