#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct Node
{
    int item;
    struct Node *next;
};
void push(struct Node **s,int data)
{
    struct Node *n;
    n=(struct Node*)malloc(sizeof(struct Node));
    n->item=data;
    n->next=*s;
    *s=n;
}
void pop(struct Node **s)
{
    if(*s==NULL)
        {
            printf("Empty");
            getch();
        }
    else
    {
        struct Node *t;
        t=*s;
        *s=t->next;
        free(t);
    }
}
void peek(struct Node *s)
{
    if(s==NULL)
        printf("Empty");
    else
        printf("%d",s->item);
    getch();
}
int main()
{
    int ch,data;
    struct Node *stack=NULL;
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
                    push(&stack,data);
                    break;
            case 2:
                pop(&stack);
                break;
            case 3:
                peek(stack);
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
