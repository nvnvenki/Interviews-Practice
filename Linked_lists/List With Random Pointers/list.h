struct node
{
        int key;
        struct node* link;
        struct node* random;
};

typedef struct node* node_t;

node_t addNode(node_t,node_t);
void display(node_t);
node_t clone(node_t,node_t*);
int count(node_t);
node_t getNode(int);
