#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct Node
{
    struct Node *left;
    int item;
    struct Node *right;
};
void insertion(struct Node **r,int data)
{
    struct Node *n;
    n=(struct Node*)malloc(sizeof(struct Node));
    n->item=data;
    n->left=NULL;
    n->right=NULL;
    if(*r==NULL)
        *r=n;
    else
    {
        struct Node *t;
        t=*r;
        while(1)
        {
            if(t->item==data)
            {
                printf("Same data is not allowed");
                free(t);
                break;
            }
            else if(t->item < data)
            {
                if(t->right==NULL)
                {
                    t->right=n;
                    break;
                }
                else
                    t=t->right;
            }
            else
            {
                if(t->left==NULL)
                {
                    t->left=n;
                    break;
                }
                else
                    t=t->left;
            }
        }

    }
}
/*void deletion(struct Node **r,int data)
{
     struct Node *ptr,*parptr=NULL;
     ptr=*r;
    if(*r)
    {
        while(ptr)
        {
            if(ptr->item==data)
                break;
            else if(ptr->item < data)
            {
                parptr=ptr;
                ptr=ptr->right;
            }
            else
            {
                parptr=ptr;
                ptr=ptr->left;
            }
        }
    }
        if(ptr)
        {
            if(parptr->right==ptr)
            {
                if(ptr->left==NULL && ptr->right==NULL)
                {
                    parptr->right=NULL;
                    free(ptr);
                }
                else if(ptr->left==NULL || ptr->right==NULL)
                {
                    if(ptr->right!=NULL)
                    {
                        parptr->right=ptr->right;
                        free(ptr);
                    }
                    else
                    {
                        parptr->right=ptr->left;
                        free(ptr);
                    }
                }
                else
                {
                    struct Node *suc,*parsuc;
                    suc=ptr->right;
                    parsuc=ptr;
                    while(suc->left)
                    {
                        parsuc=suc;
                        suc=suc->left;
                    }
                    ptr->item=suc->item;
                    if(parsuc->left==suc)
                    {
                        if(suc->right==NULL)
                        {
                            parsuc->left=NULL;
                            free(suc);
                        }
                        else
                        {
                            parsuc->left=suc->right;
                            free(suc);
                        }
                    }
                    else
                    {
                        if(suc->right==NULL)
                        {
                            parsuc->right=NULL;
                            free(suc);
                        }
                        else
                        {
                            parsuc->right=suc->right;
                            free(suc);
                        }
                    }
                }
            }
            else
            {
                if(ptr->left==NULL && ptr->right==NULL)
                {
                    parptr->left=NULL;
                    free(ptr);
                }
                else if(ptr->left==NULL || ptr->right==NULL)
                {
                    if(ptr->right!=NULL)
                    {
                        parptr->left=ptr->right;
                        free(ptr);
                    }
                    else
                    {
                        parptr->left=ptr->left;
                        free(ptr);
                    }
                }
                else
                {
                    struct Node *suc,*parsuc;
                    suc=ptr->right;
                    parsuc=ptr;
                    while(suc->left)
                    {
                        parsuc=suc;
                        suc=suc->left;
                    }
                    ptr->item=suc->item;
                    if(parsuc->left==suc)
                    {
                        if(suc->right==NULL)
                        {
                            parsuc->left=NULL;
                            free(suc);
                        }
                        else
                        {
                            parsuc->left=suc->right;
                            free(suc);
                        }
                    }
                    else
                    {
                        if(suc->right==NULL)
                        {
                            parsuc->right=NULL;
                            free(suc);
                        }
                        else
                        {
                            parsuc->right=suc->right;
                            free(suc);
                        }
                    }
                }
            }
        }
    }*/

void preorder(struct Node *r)
{
    if(r)
    {
        printf("%d ",r->item);
        preorder(r->left);
        preorder(r->right);
    }
}
void inorder(struct Node *r)
{
    if(r)
    {
        inorder(r->left);
        printf("%d ",r->item);
        inorder(r->right);
    }
}
void postorder(struct Node *r)
{
    if(r)
    {
        postorder(r->left);
        postorder(r->right);
        printf("%d ",r->item);
    }
}
int main()
{
    int ch,data,a=1;
    struct Node *root=NULL;
    while(1)
    {
        system("cls");
        printf("1.Insertion\n2.Deletion\n3.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter Data:");
                scanf("%d",&data);
                insertion(&root,data);
                break;
            case 2:
                printf("Enter Data:");
                scanf("%d",&data);
                del(&root,data);
                break;
            case 3:
                a=0;

        }
        if(a==0)
            break;
    }
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    getch();
}
void del(struct Node **r,int data)
{
    struct Node *ptr,*parptr=NULL;
    ptr=*r;
    if(*r)
    {
        while(ptr)
        {
            if(ptr->item==data)
                break;
            else if(ptr->item < data)
            {
                parptr=ptr;
                ptr=ptr->right;
            }
            else
            {
                parptr=ptr;
                ptr=ptr->left;
            }
        }
    }
    //traverse
    if(ptr && parptr==NULL)
    {
        if(ptr->right==NULL && ptr->left==NULL)
        {
            *r=NULL;
            free(ptr);
        }
        else if(ptr->right==NULL || ptr->left==NULL)
        {
            if(ptr->left!=NULL)
                *r=ptr->left;
            else
                *r=ptr->right;
            free(ptr);
        }
        else
        {
            struct Node *suc,*parsuc;
            suc=ptr->right;
            parsuc=ptr;
            while(suc->left)
            {
                parsuc=suc;
                suc=suc->left;
            }
            ptr->item=suc->item;
            if(suc->right!=NULL)
            {
                if(parsuc->left==suc)
                    parsuc->left=suc->right;
                else
                    parsuc->right=suc->right;
                free(suc);
            }
            else
            {
                if(parsuc->left==suc)
                    parsuc->left=NULL;
                else
                    parsuc->right=NULL;
                free(suc);
            }
        }
    }
    else if(ptr){
                if(ptr->right==NULL && ptr->left==NULL)
                {
                    if(parptr->left==ptr)
                        parptr->left=NULL;
                    else
                        parptr->right=NULL;
                    free(ptr);
                }
                else if(ptr->right==NULL || ptr->left==NULL)
                {
                    if(parptr->left==ptr)
                    {
                        if(ptr->left!=NULL)
                            parptr->left=ptr->left;
                        else
                            parptr->left=ptr->right;
                        free(ptr);
                    }
                    else
                    {
                        if(ptr->left!=NULL)
                            parptr->right=ptr->left;
                        else
                            parptr->right=ptr->right;
                        free(ptr);
                    }
                }
                else
                {
                    struct Node *suc,*parsuc;
                    suc=ptr->right;
                    parsuc=ptr;
                    while(suc->left)
                    {
                        parsuc=suc;
                        suc=suc->left;
                    }
                    ptr->item=suc->item;
                    if(suc->right!=NULL)
                    {
                        if(parsuc->left==suc)
                            parsuc->left=suc->right;
                        else
                            parsuc->right=suc->right;
                        free(suc);
                    }
                    else
                    {
                        if(parsuc->left==suc)
                            parsuc->left=NULL;
                        else
                            parsuc->right=NULL;
                        free(suc);
                    }
                }
    }
}
