#include<stdio.h>
#include<stdlib.h>
struct Node
{
    struct Node *prev;
    int item;
    struct Node *next;
};
void insertfirst(struct Node **s,int data)
{
    struct Node *n;
    n=(struct Node*)malloc(sizeof(struct Node));
    n->item=data;
    if(*s==NULL)
    {
        n->next=n;
        n->prev=n;
        *s=n;
    }
    else
    {
        n->next=*s;
        n->prev=(*s)->prev;
        (*s)->prev->next=n;
        *s=n;
    }
}
void insertlast(struct Node **s,int data)
{
    struct Node *n;
    n=(struct Node*)malloc(sizeof(struct Node));
    n->item=data;
    if(*s==NULL)
    {
        n->next=n;
        n->prev=n;
        *s=n;
    }
    else
    {
        n->prev=(*s)->prev;
        n->next=*s;
        (*s)->prev->next=n;
        (*s)->prev=n;
    }
}
void deletefirst(struct Node **s)
{
    if(*s==NULL)
        printf("List is Empty");
    else
    {
        if(*s==(*s)->next)
        {
            free(*s);
            *s=NULL;
        }
        else
        {
            struct Node *t;
            t=*s;
            t->next->prev=t->prev;
            t->prev->next=t->next;
            *s=t->next;
            free(t);
        }

    }
}
void deletelast(struct Node **s)
{
    if(*s==NULL)
        printf("List is Empty");
    else
    {
        if(*s==(*s)->next)
        {
            free(*s);
            *s=NULL;
        }
        else
        {
            struct Node *t;
            t=(*s)->prev;
            t->prev->next=t->next;
            t->next->prev=t->prev;
            free(t);
        }

    }
}
void view(struct Node *s)
{
    struct Node *t;
    t=s;
    while(t->next!=s)
    {
        printf("%d  ",t->item);
        t=t->next;
    }
    printf("%d",t->item);
}
void aview(struct Node *s)
{
    struct Node *t;
    t=s->prev;
    while(t->prev!=s->prev)
    {
        printf("%d  ",t->item);
        t=t->prev;
    }
    printf("%d",t->item);
}
int main()
{
    struct Node *start=NULL;
    insertfirst(&start,1);
    insertfirst(&start,4);
    insertfirst(&start,9);
    insertfirst(&start,16);
    insertfirst(&start,25);
    view(start);
    deletefirst(&start);
    deletefirst(&start);
    printf("\n");
    view(start);
    deletelast(&start);
    deletelast(&start);
    printf("\n");
    view(start);

}
