struct node
{
	int ele;
	struct node* link;
};

typedef struct node* node_t;


node_t add_front(node_t last, int ele);
node_t add_last(node_t last, int ele);
node_t delete_front(node_t last);
node_t delete_last(node_t last);
void split_into_two(node_t last);
void display(node_t last);
node_t insert_in_sorted_order(node_t last, int ele);