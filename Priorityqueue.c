#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
struct Node
{
    int priority;
    int item;
    struct Node *next;
};
void push(struct Node **s,int data,int p)
{
    struct Node *n;
    n=(struct Node*)malloc(sizeof(struct Node));
    n->item=data;
    n->priority=p;
    if(*s==NULL)
    {
        n->next=NULL;
        *s=n;
    }
    else
    {
        struct Node *t,*d;
        t=*s;
        if(n->priority > t->priority)
        {
            n->next=t;
            *s=n;
        }
        else
        {
            while(n->priority <= t->priority)
            {
                d=t;
                if(t->next!=NULL)
                    t=t->next;
                else
                    break;
            }
            if(t->next==NULL && t->priority >= n->priority)
            {
                n->next=NULL;
                t->next=n;
            }
            else
            {
                n->next=d->next;
                d->next=n;
            }
        }
    }
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
        struct Node*t;
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
}
int main()
{
    int p,data,ch;
    struct Node *start=NULL;
    while(1)
    {
        system("cls");
        peek(start);
        printf("\n1.Push\n2.Pop\n3.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Priority:");
                scanf("%d",&p);
                printf("Data:");
                scanf("%d",&data);
                push(&start,data,p);
                break;
            case 2:
                pop(&start);
                break;
            case 3:
                    exit(0);
        }
    }
}
