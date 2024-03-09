#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int item;
    struct Node *next;
};
void insertatfirst(struct Node **l,int data)
{
    struct Node *n;
    n=(struct Node*)malloc(sizeof(struct Node));
    n->item=data;
    if(*l==NULL)
    {
        *l=n;
        n->next=n;
    }
    else
    {
        n->next=(*l)->next;
        (*l)->next=n;
    }
}
void insertatlast(struct Node **l,int data)
{
    struct Node *n;
    n=(struct Node*)malloc(sizeof(struct Node));
    n->item=data;
    if(*l==NULL)
    {
        *l=n;
        n->next=n;
    }
    else
    {
        n->next=(*l)->next;
        (*l)->next=n;
        *l=n;
    }
}
void deletefirst(struct Node **l)
{
    struct Node *t;
    t=(*l)->next;
    if(t->next==t)
        *l=NULL;
    else
        (*l)->next=t->next;
    free(t);
}
void deletelast(struct Node **l)
{
    struct Node *t;
    t=(*l)->next;
    if(t==t->next)
    {
        free(*l);
        *l=NULL;
    }
    else
    {
        while(t->next!=(*l))
            t=t->next;
        t->next=(*l)->next;
        free(*l);
        *l=t;
    }
}
void view(struct Node *l)
{
    struct Node *t;
    t=l->next;
    while(t->next!=l->next)
    {
        printf("%d ",t->item);
        t=t->next;
    }
    printf("%d",t->item);
}
struct Node* search(struct Node *last,int data)
{
    if(last==NULL)
        return NULL;
    struct Node *t;
    t=last->next;
    while(t->next!=last->next)
    {
        if(t->item==data)
            return t;
        t=t->next;
    }
    return NULL;
    /*
     t=last;
     do
     {
         if(t->item==data)
                return t;
            t=t->next;
     }while(t!=last);
    */
}
void insertafter(struct Node **l,struct Node *t,int data)
{
    struct Node *n;
    n=(struct Node*)malloc(sizeof(struct Node));
    n->item=data;
    n->next=t->next;
    t->next=n;
    if(t==*l)
        *l=n;
}
void deleteparticular(struct Node **l,struct Node *t)
{
    if(*l==t && t->next==t)
    {
        free(t);
        *l=NULL;
    }
    else
    {
        struct Node *r;
        r=(*l)->next;
        while(r->next!=t)
            r=r->next;
        r->next=t->next;
        if(*l==t)
            *l=r;
        free(t);
    }
}
int main()
{
    struct Node *last=NULL;
    insertatfirst(&last,10);
    insertatfirst(&last,20);
    insertatfirst(&last,30);
    view(last);
    printf("\n");
    insertatlast(&last,40);
    insertatlast(&last,50);
    insertatlast(&last,60);
    view(last);
    deletelast(&last);
    deletelast(&last);
    printf("\n");
    view(last);
    insertafter(&last,search(last,10),15);
    insertafter(&last,search(last,15),25);
    printf("\n");
    view(last);
    deleteparticular(&last,search(last,10));
    deleteparticular(&last,search(last,15));
    printf("\n");
    view(last);

}
