struct node
{
	int value;
	struct node* link;
};

typedef struct node* node_t;


node_t add_front(node_t head, int ele);
node_t add_end(node_t head, int ele);
node_t delete_front(node_t head);
node_t delete_rear(node_t head);
node_t insert_in_order(node_t head, int ele);
node_t merge_ordered_lists(node_t first, node_t second);
node_t delete_with_info(node_t head, int ele);
node_t delete_with_pos(node_t head, int ele);
node_t reverse(node_t head);
void delete_node_given_pointer(node_t node_pointer);
void print_middle(node_t head);
int search(node_t head , int ele);
void display(node_t head);
void print_nth_last(node_t head, int n);
static int count_nodes(node_t head);
node_t delete_list(node_t head);
int find_cycle(node_t head);
int is_palindrome(node_t* left, node_t right);
int find_intersection(node_t first, node_t second);
static int get_intersection(int d, node_t first, node_t second);
void print_reverse_recursively(node_t head);
void remove_duplicates(node_t head);
node_t move_last_to_first(node_t head);
node_t pairwise_reverse(node_t head);
static void swap(int* a, int* b);
void find_common_recursively(node_t first, node_t second);
static void __find_common_recursively_utility(node_t temp1, node_t temp2, node_t temp3);
node_t delete_alternate(node_t head);
void alternating_split(node_t head);
node_t delete_node_when_neigbour_higher(node_t head);
node_t separate_into_even_odd(node_t head);
static void remove_loop(node_t loop_node, node_t head);
node_t add_two_lists(node_t first,node_t second);
node_t rotate_by_k(node_t head, int k);
node_t separate_into_zeroes_ones(node_t head);
node_t retain_m_delte_n(node_t head, int m, int n);
void alternating_split_v2(node_t head);
node_t separate_into_even_odd_v2(node_t head);



