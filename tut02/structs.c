struct node {
    int data;
    char *string;
    struct node *prev; 
    struct node *next;
};

struct treeNode {
    int data;
    struct node *left;
    struct node *right;
};
