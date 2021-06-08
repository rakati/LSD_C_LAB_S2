#include "Tree.h"

Tree*  treeNull()
{
    Tree*  T=NULL;
    return T;
}

bool testNull(Tree*  T)
{
    if(T==NULL)
        return true;
    return false;
}

 int root(Tree*  T)
{
    if(testNull(T))
       exit(EXIT_FAILURE);
    return T->data;
}

Tree* left(Tree*  T)
{
    if(testNull(T))
        return NULL;
    return T->left;
}

Tree* right(Tree*  T)
{
    if(testNull(T))
        return NULL;
    return T->right;
}

Tree*  buildTree(int x,Tree*  T_1,Tree*  T_2)
{
    Tree*  T=(Tree* )malloc(sizeof(Tree));
    T->data=x;
    T->left=T_1;
    T->right=T_2;
    return T;
}

void fixData(int x,Tree ** P)
{
    if(testNull(*P))
        exit(EXIT_FAILURE);
    else
    {
        (*P)->data=x;
    }
}

void fixLeft(Tree * G, Tree ** P)
{
    if(testNull(*P))
        exit(EXIT_FAILURE);
    else
    {
        (*P)->left=G;
    }
}

void fixRight(Tree * D, Tree ** P)
{
    if(testNull(*P))
        exit(EXIT_FAILURE);
    else
    {
        (*P)->right=D;
    }
}

void freeTree(Tree ** T)
{
    Tree* temp=*T;
    if(temp==NULL)
        return;
    if(temp->left!=NULL)
        freeTree(&temp->left);
    if(temp->right!=NULL)
        freeTree(&temp->right);
    free(temp);
    *T=NULL;
}

bool testNullTS(Tree_stack P)
{
    if (P.length ==0)
        return true;
    return false;
}

void push(Tree* T,Tree_stack * P)
{
    if(P->length==N)
    {
        printf("Stack is empty.\n");
        return;
    }
    P->head[P->length]=T;
    P->length+=1;
}

Tree* pop(Tree_stack * P)
{
    if(testNullTS(*P))
        return NULL;
    Tree* T=P->head[P->length-1];
    P->length-=1;
    return T;
}