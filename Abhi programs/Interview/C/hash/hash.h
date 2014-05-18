#define NO_PAGES  1024
#define LRU_SIZE  5
#define HASH_LENGTH  128

struct node
{
	int ele;
	struct node* link;
};

typedef struct node* node_t;
node_t add_front(node_t head, int ele);
node_t add_end(node_t head, int ele);
node_t delete_rear(node_t head);
void display(node_t head);
void initialise_hash(node_t* hash_array);
int hash_function(int page_number);
node_t insert_in_table(node_t head, int ele);
int search(int page_number, node_t head);
node_t create_cache();
node_t reference_page(node_t* hash,node_t head , int page_number);
static node_t remove_and_bring_front(node_t head, int page_number);