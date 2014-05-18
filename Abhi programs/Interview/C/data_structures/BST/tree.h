struct node
{
	int ele;
	struct node* llink;
	struct node* rlink;
};


typedef struct node* node_t;

node_t insert(node_t root, int ele);
void display(node_t root);
node_t search(node_t root, int ele);
node_t find_highest(node_t root);
node_t find_lowest(node_t root);
int find_height(node_t root);
static int max(int a, int b);
void find_count(node_t root, int* count);
void find_leaves(node_t root, int* count);
node_t delete(node_t root, int ele);
int find_lca(node_t root, int value1, int value2);