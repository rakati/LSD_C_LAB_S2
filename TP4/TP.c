#include "Tree.h"

void print_tree(Tree* T){
    if(T==NULL){
        printf("[ ]\n");
        return ;
    }
    printf("[ ");
    Tree_stack P={NULL,0};
    Tree* temp=T;
    unsigned s = 0;
    while(testNullTS(P)==0 || temp!=NULL)
    {
        if(temp!=NULL)
        {
            push(temp,&P);
            temp=temp->left;
        }
        else
        {
            temp=pop(&P);
            printf("%d ",temp->data);
            temp=temp->right;
        }
    }
    printf("]\n");
    return;
}

//Ex1

int max(int x, int y){
    if(x>y)
        return x;
    return y;
}

int max_nodes(Tree* T){
    if(testNull(T)){
        return 0;
    }
    int lmax = max_nodes(left(T));
    int rmax = max_nodes(right(T));
    return max(lmax , rmax) + 1 ;
}

int tree_depth(Tree* T){
    return max_nodes(T) - 1 ;
}

int tree_diameter(Tree* T){
    if(testNull(T))
        return 0;
    int ltree = tree_diameter(left(T));
    int rtree = tree_diameter(right(T));
    return max(max_nodes(left(T)) + max_nodes(right(T)) + 1, max(ltree,rtree));
}

int leaf_sum(Tree* T){
    if(T==NULL)
        return 0;
    Tree_stack P={NULL,0};
    Tree* temp=T;
    unsigned s = 0;
    while(testNullTS(P)==0 || temp!=NULL)
    {
        if(temp!=NULL)
        {
            push(temp,&P);
            temp=temp->left;
        }
        else
        {
            temp=pop(&P);
            if(testNull(left(temp)) && testNull(right(temp)))
                s+=temp->data;
            temp=temp->right;
        }
    }
    return s;
}

int leaf_sum_2(Tree* T){
    if(testNull(T))
        return 0;
    if(testNull(left(T)) && testNull(right(T)))
        return T->data;
    return leaf_sum_2(left(T)) + leaf_sum_2(right(T));
}

//Ex2

void insert_node(int x,Tree* T){
    if(testNull(T)){
        buildTree(x,NULL,NULL);
        return;
    }
    Tree* temp = T;
    while(!(testNull(left(temp))) || !(testNull(right(temp)))){
        if(x<temp->data){
            if(!testNull(left(temp)))
                temp = temp->left;
            else 
                break;
        }
        else{
            if(x>temp->data){
                if(!testNull(right(temp)))
                    temp = temp->right;
                else 
                    break;
            }
            else
                return;
        }
    }
    Tree* P=buildTree(x,NULL,NULL);
    if(x<temp->data){
        fixLeft(P,&temp);
        return;
    }
    else{
        if(x>temp->data){
            fixRight(P,&temp);
            return;
        }
        else{
            return;
        }
    }
}

void search_Tree_IN(int x,Tree* T){
    if(testNull(T)){
        printf("The value %d doesn't exist\n",T->data);
        return;
    }
    if(T->data == x){
        printf("The value %d exists\n",T->data);
        return;
    }
    if(T->data < x){
        return search_Tree_IN(x,right(T));
    }
    if(T->data > x){
        return search_Tree_IN(x,left(T));
    }
}

int max_depth(Tree* T){
    return tree_depth(T);
}

int tree_size(Tree* T){
    if(testNull(T))
        return 0;
    return 1 + tree_size(left(T)) + tree_size(right(T));
}

int main(){
    Tree* T1=NULL;
    Tree* T2=NULL;
    T1=buildTree(3,NULL,NULL);
    T2=buildTree(7,NULL,NULL);
    Tree* T=buildTree(5,T1,T2);
    Tree* T3=NULL;
    Tree* T4=NULL;
    Tree* T5=buildTree(11,NULL,NULL);
    Tree* T6=buildTree(15,NULL,NULL);
    Tree* T7=buildTree(13,T5,T6);
    T3=buildTree(0,NULL,T);
    T4=buildTree(10,T3,T7);
    printf("\n\n");
    print_tree(T4);
    //Ex1 
    printf("The depth of the tree is %d\n",tree_depth(T4));
    printf("The diameter of the tree is %d\n",tree_diameter(T4));
    printf("The sum of the leaves in the tree is %d\n",leaf_sum_2(T4));
    //Ex2
    insert_node(4,T4);
    print_tree(T4);
    search_Tree_IN(15,T4);
    printf("The tree size is %d\n",tree_size(T4));
    return 0;
}