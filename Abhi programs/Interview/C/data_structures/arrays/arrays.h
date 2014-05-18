struct pair
{
	int max;
	int min;
};



#define MAX 10000
void display(int* array, int n);
int find_odd_occurence(int* array, int n);
void find_union(int* a, int m, int* b, int n);
void find_intersection(int* a, int m, int* b, int n);
int find_max_difference(int* array, int n);
void separate_into_zeroes_ones(int* array,int n);
struct pair find_min_max(int* array, int n);
int is_majority(int* array, int n, int x);
static int majority_helper(int* array, int n, int index, int x);
void find_first_second_smallest(int* array,int n);
void find_leader(int* array, int n);
int find_largest_sum_contiguous(int* array,int n);
int find_missing_number(int* array, int n);
int find_element_in_rotated(int* array,int n, int searchElement);
static int find_pivot(int* array, int n);
int binary_search(int* array, int start, int end, int searchElement);
void reverse(int* array, int start, int end);
void rotate(int* array, int d, int n);
void make0rows0columns(int a[][3]);
void findTwoElementsTarget(int* sorted_array,int target_sum, int n);
void right_rotate(int* array, int d, int n);