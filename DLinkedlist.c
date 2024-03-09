 #include<stdio.h>
#include<stdlib.h>
struct Node
{
    struct Node *prev;
    int item;
    struct Node *next;
};
void insertatfirst(struct Node **s,int data)
{
    struct Node *n;
    n=(struct Node*)malloc(sizeof(struct Node));
    n->item=data;
    n->prev=NULL;
    n->next=*s;
    if(( *s)!=NULL)
        (*s)->prev=n;
    *s=n;
}
void insertatlast(struct Node **s,int data)
{
    struct Node *n;
    n=(struct Node*)malloc(sizeof(struct Node));
    n->item=data;
    n->next=NULL;
    if(*s==NULL)
    {
        n->prev=NULL;
        *s=n;
    }
    else
    {
        struct Node *t;
        t=*s;
        while(t->next!=NULL)
            t=t->next;
        n->prev=t;
        t->next=n;
    }


}
void insertafter(struct Node *t,int data)
{
    struct Node *n;
    n=(struct Node*)malloc(sizeof(struct Node));
    n->item=data;
    n->prev=t;
    n->next=t->next;
    if(t->next!=NULL)
        t->next->prev=n;
    t->next=n;
}
void deletefirst(struct Node **s)
{
    if(*s==NULL)
        printf("List is Empty");
    else
    {
        struct Node *t;
        t=*s;
        if(t->next!=NULL)
            t->next->prev=NULL;
        *s=t->next;
        free(t);
        /*
            *s=t->next;
            if(*s!=NULL)
                (*s)->prev=NULL;
            free(t);
        */
    }
}
void deletelast(struct Node **s)
{
    if(*s==NULL)
        printf("List is Empty");
    else
    {
        struct Node *t;
        t=*s;
        while(t->next!=NULL)
            t=t->next;
        if(t->prev!=NULL)
            t->prev->next=NULL;
        else
            *s=NULL;
        free(t);
    }
}
void deleteparticular(struct Node **s,struct Node *t)
{

            if(t->next!=NULL)
                t->next->prev=t->prev;
            if(t->prev!=NULL)
                t->prev->next=t->next;
            else
                *s=t->next;
            free(t);
}
struct Node* search(struct Node *s,int data)
{
    while(s)
    {
        if(s->item==data)
            return s;
        s=s->next;
    }
    return NULL;
}
void view(struct Node *s)
{
    struct Node *t;
    t=s;
    while(t->next!=NULL)
    {
        printf("%d  ",t->item);
        t=t->next;
    }
    printf("%d",t->item);
}
void aview(struct Node *s)
{
    struct Node *t;
    t=s;
    while(t->next!=NULL)
        t=t->next;
    while(t->prev!=NULL)
    {
        printf("%d  ",t->item);
        t=t->prev;
    }
    printf("%d  ",t->item);
}

int main()
{
    struct Node *start=NULL;
    insertatfirst(&start,10);
    insertatfirst(&start,20);
    insertatfirst(&start,30);
    insertatfirst(&start,40);
    insertatlast(&start,50);
    deletefirst(&start);
    view(start);
    printf("\n");
    aview(start);
    printf("\n");

}
