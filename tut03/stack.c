#include "stack.h"

struct node *createNode(int data) {
    struct node *new = malloc(sizeof(struct node));
    if (new == NULL) {
        return NULL;
    } 
    new->data = data;
    new->next = NULL;
    return new;
}

struct node *stackPush(struct s_rep *stack, int data) {
    if (stack == NULL) {
        return NULL;
    } else if (stack->head == NULL || stack->tail == NULL) {
        struct node *new = createNode(data);
        if (new == NULL) {
            return NULL;
        }
        stack->head = new;
        stack->tail = new;
        return new;
    } else {
        struct node *new = createNode(data);
        if (new == NULL) {
            return NULL;
        }
        new->next = stack->head;
        stack->head = new;
        return new;
    }
}

struct node *stackPop(struct s_rep *stack) {
    if (stack == NULL) {
        return NULL;
    } else if (stack->head == NULL || stack->tail == NULL) {
        return NULL;
    } else {
        struct node *top = stack->head;
        struct node *new_head = stack->head->next;
        stack->head = new_head;
        return top;
    }
}

int stackTop(struct s_rep *stack) {
    if (stack == NULL) {
        return 0;
    } else if (stack->head == NULL || stack->tail == NULL) {
        return 0;
    } else {
        return stack->head->data;
    }
}

unsigned int stackSize(struct s_rep *stack) {
    if (stack == NULL) {
        return 0;
    }
    unsigned int counter = 0;
    struct node *curr = stack->head;
    while (curr != NULL) {
        counter = counter + 1;
        curr = curr->next;
    }
    return counter;
}

int is_empty(struct s_rep *stack) {
    if (stack == NULL) {
        return TRUE; // 1
    } else if (stack->head == NULL || stack->tail == NULL) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void free_stack(struct s_rep *stack) {
    if (stack == NULL || is_empty(stack)) {
        return;
    } else {
        struct node *curr = stack->head;
        struct node *prev = NULL;
        while (curr != NULL) {
            prev = curr;
            curr = curr->next;
            free(prev);
        }   
        stack->head = NULL;
        stack->tail = NULL;
        return;
    }
}

void free_stackR(struct s_rep *stack) {
    if (stack == NULL) {
        return;
    } else if (stack->head == NULL || stack->tail == NULL) {
        return;
    } else {
        struct node *old_head = stack->head;
        struct node *new_head = stack->head->next;
        free(old_head);
        stack->head = new_head;
        free_stackR(stack);
        stack->head = NULL;
        stack->tail = NULL;
    }
}

void printStack(struct s_rep *stack) {
    if (stack == NULL || is_empty(stack)) {
        printf("(empty)\n");
        return;
    }
    printf("[");
    struct node *curr = stack->head;
    while (curr != NULL) {
        printf("%d", curr->data);
        if (curr->next != NULL) {
            printf(", ");
        }
        curr = curr->next;
    }
    printf("]\n");
}