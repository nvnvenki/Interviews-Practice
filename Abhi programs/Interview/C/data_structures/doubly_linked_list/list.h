struct node
{
	int ele;
	struct node* llink;
	struct node* rlink;
};

typedef struct node* node_t;

node_t add_front(node_t head, int ele);
node_t add_end(node_t head, int ele);
node_t delete_front(node_t head);
node_t delete_rear(node_t head);
void display(node_t head);
