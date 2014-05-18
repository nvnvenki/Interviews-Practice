struct node
{
        int key;
        struct node *link;
        struct node *child;
};

typedef struct node* node_t;

node_t createList(int*,int);
void display(node_t);
node_t createMultiLevelList(void);
node_t flattenList(node_t);
