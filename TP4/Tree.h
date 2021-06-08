#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct TreeNode {
    int data;
    struct TreeNode * left;
    struct TreeNode * right;
} Tree ;

#define N 200

typedef struct Tree_stack
{
    Tree* head[N];
    unsigned length;
} Tree_stack;


//Tree functions
Tree* treeNull();
bool testNull(Tree*); /*Test if a tree is NULL*/
int root(Tree*); /*Extract the root of the tree*/
Tree* left(Tree*);/*Extract the left sub-tree*/
Tree* right(Tree*); /*Extract the right sub-tree*/
Tree* buildTree(int, Tree*,Tree*); /* Build a tree with a root data and two trees left and right*/
void fixData(int, Tree **); /*Modify the root of the tree*/
void fixLeft(Tree*, Tree **); /*Modify the left sub-tree*/
void fixRight(Tree*, Tree **); /*Modify the right sub-tree*/
void freeTree(Tree **); /*free the allocated memory for the tree*/

//Tree_stack functions
bool testNullTS(Tree_stack P);
void push(Tree* T,Tree_stack* P);
Tree* pop(Tree_stack* P);

#endif