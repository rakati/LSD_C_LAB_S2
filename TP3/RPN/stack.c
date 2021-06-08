#include "stack.h"

t_stack* new_stack(int data){
    t_stack* P=(t_stack*)malloc(sizeof(t_stack));
    P->data=data;
    P->next=NULL;
    return P;
}

int is_empty(t_stack* head){
    if(head==NULL){
        return 1;
    }
    return 0;
}

void push(t_stack** head, int data){
    t_stack* P=new_stack(data);
    P->next=*head;
    *head=P;
    return;
}

int pop(t_stack** head){
    if(is_empty(*head)){
        return INT_MIN;
    }
    int data=(*head)->data;
    t_stack* L=*head;
    *head=(*head)->next;
    free(L);
    return data;
}

int stack_len(t_stack* head){
    t_stack* temp=head;
    int n=0;
    while(temp!=NULL){
        n++;
        temp=temp->next;
    }
    return n;
}

int peek_stack(t_stack* head){
    if(is_empty(head)){
        return INT_MIN;
    }
    return head->data;
}

void print_stack(t_stack* head){
    t_stack* temp=head;
    printf("[ ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("]\n");
    return;
}

void free_stack(t_stack* head){
    while(head!=NULL){
        t_stack* temp=head;
        head=head->next;
        free(temp);
    }
    return;
}