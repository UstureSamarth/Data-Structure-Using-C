 #include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node
{
    int item;
    struct Node *next;
};
void insertatfirst(struct Node **s,int data)
{
    struct Node *n;
    n=(struct Node*)malloc(sizeof(struct Node));
    n->item=data;
    n->next=*s;
    *s=n;
}
void insertatlast(struct Node **s,int data)
{
    struct Node *n;
    n=(struct Node*)malloc(sizeof(struct Node));
    n->item=data;
    n->next=NULL;
    if(*s==NULL)
        *s=n;
    else
    {
        struct Node *t;
        t=*s;
        while(t->next!=NULL)
            t=t->next;
        t->next=n;
    }
}
void insertafter(struct Node *t,int data)
{
    struct Node *n;
    n=(struct Node*)malloc(sizeof(struct Node));
    n->item=data;
    n->next=NULL;
    if(t->next==NULL)
        t->next=n;
    else
    {
        n->next=t->next;
        t->next=n;
    }
}
struct Node* search(struct Node **s,int data)
{
    struct Node *t;
    t=*s;
    while(t)
    {
        if(t->item==data)
            break;
        else
            t=t->next;
    }
    return t;
}
void deleteatlast(struct Node **s)
{
    if(*s==NULL)
        printf("List is Empty");
    else
    {
            struct Node *t,*d=NULL;
            t=*s;
             while(t->next!=NULL)
                {
                    d=t;
                    t=t->next;
                }
                if((*s)->next==NULL)
                    *s=NULL;
                else
                    d->next=NULL;
                free(t);
                /*
                    free(t);
                    if(d==NULL)
                        *s=NULL;
                    else
                        d->next=NULL;


                */


    }
}
void deleteatfirst(struct Node **s)
{
    if(*s==NULL)
        printf("List is Empty");
    else
    {
            struct Node *t;
            t=*s;
            *s=t->next;
            free(t);
    }
}
void deleteparticular(struct Node **s,struct Node *t)
{
    struct Node *d;
    d=*s;
    if(d==t)
    {
        *s=d->next;
        free(t);
    }
    else
    {
        while(d->next!=t)
            d=d->next;
        d->next=t->next;
        free(t);
    }
}
/*
    struct Node* search(struct Node *start,int data)
    {
        while(start)
        {
            if(start->item==data)
                return start;
            start=start->next;
        }
        return NULL;
    }
*/
void view(struct Node **s)
{
    struct Node *t;
    t=*s;
    while(t->next!=NULL)
    {
        printf("%d  ",t->item);
        t=t->next;
    }
    printf("%d",t->item);
}
int main()
{
    struct Node *start=NULL;
    insertatfirst(&start,1);
    insertatfirst(&start,2);
    insertatfirst(&start,3);
    insertatfirst(&start,4);
    insertatfirst(&start,5);
    insertatfirst(&start,6);
    insertafter(search(&start,6),15);
    view(&start);
    insertatlast(&start,7);
    insertatlast(&start,8);
    insertatlast(&start,9);
    insertatlast(&start,10);
    printf("\n");
    view(&start);
    deleteatlast(&start);
    deleteatlast(&start);
    deleteatlast(&start);
    printf("\n");
    view(&start);
    deleteatfirst(&start);
    deleteatfirst(&start);
    printf("\n");
    view(&start);

}
