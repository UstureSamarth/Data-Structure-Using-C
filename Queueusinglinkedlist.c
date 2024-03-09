#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node
{
    int item;
    struct Node *next;
};
void push(struct Node **r,struct Node **f,int data)
{
    struct Node *n;
    n=(struct Node*)malloc(sizeof(struct Node));
    n->item=data;
    n->next=NULL;
    if(*r==NULL)
    {
        *f=n;
        *r=n;
    }
    else
    {
        (*r)->next=n;
        *r=n;
    }
}
void pop(struct Node **r,struct Node **f)
{
    if(*f==NULL)
    {
        printf("Empty");
        getch();
    }
    else
    {
        if(*f==*r)
        {
            free(*f);
            *f=NULL;
            *r=NULL;
        }
        else
        {
            struct Node *t;
            t=*f;
            *f=t->next;
            free(t);
        }
    }
}
void peek(struct Node *f)
{
    if(f==NULL)
    {
        printf("Empty");
    }
    else
        printf("%d",f->item);

}
int main()
{
    int ch,data;
    struct Node *rear=NULL,*front=NULL;
    while(1)
    {
        system("cls");
        peek(front);
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Exit\n");
        printf("Enter Your Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter Data:");
                scanf("%d",&data);
                push(&rear,&front,data);
                break;
            case 2:
                pop(&rear,&front);
                break;
            case 3:
                peek(front);
                break;
            case 4:
                exit(0);

        }
    }


}
