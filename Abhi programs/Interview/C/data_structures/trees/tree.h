struct node
{
	int ele;
	struct node* llink;
	struct node* rlink;
};


typedef struct node* node_t;


node_t insert_node(node_t root, int ele);
void pre_order(node_t root);
void post_order(node_t root);
void in_order(node_t root);
void search(node_t root, int ele, int* flag);
node_t delete_tree(node_t root);
node_t create_exact_copy(node_t root);
int find_whether_identical(node_t first, node_t second);
node_t create_mirror_copy(node_t root);
void print_path_rootToLeaves(node_t root, int* path, int pathlen);
static void print_array(int* array, int n);
int height(node_t root);
static int max(int a, int b);
void print_level_order(node_t root);
static void print_each_level(node_t root, int level);
int isBST(node_t root);
void print_level_order_spirally(node_t root);
static void print_each_level_spirally(node_t root, int level, int rtol);
int check_children_sum_property(node_t root);
void convert_to_children_sum(node_t root);
static void increment(node_t root, int difference);
int find_diameter(node_t root);
int my_isBst(node_t root);


