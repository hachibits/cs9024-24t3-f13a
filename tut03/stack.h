#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

struct node {
    int data;
    struct node *next;
};

struct s_rep {
    struct node *head;
    struct node *tail;
};

struct node *createNode(int data);
struct node *stackPush(struct s_rep *stack, int data);
struct node *stackPop(struct s_rep *stack);

int stackTop(struct s_rep *stack);
unsigned int stackSize(struct s_rep *stack);
int is_empty(struct s_rep *stack);

void free_stack(struct s_rep *stack);
void free_stackR(struct s_rep *stack);

void printStack(struct s_rep *stack);

#endif