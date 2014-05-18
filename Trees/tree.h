struct tree
{
        int key;
        struct tree* rlink;
        struct tree* llink;
};
typedef struct tree* tree_t;


tree_t insert(tree_t,int);
void display(tree_t);
void post_traversal(tree_t);
void pre_traversal(tree_t);
int count(tree_t);
void display_list(tree_t);
void fixPrevPtr(tree_t root);
int count_leaf(tree_t);
int height(tree_t);
int max(int,int);
int least_of_tree(tree_t);
int max_of_tree(tree_t);
void verticalSumArray(tree_t,int *,int);
tree_t mirror_tree(tree_t);
int RLMirrors(tree_t);
int isMirrorsLR(tree_t,tree_t);
void iterativeInorder(tree_t);
void iterativePreorder(tree_t);
void iterativePostorder(tree_t);
tree_t largestSumSubtree(tree_t);
int maxSum(tree_t,tree_t*,int*);
tree_t search(tree_t,int);
void levelorder(tree_t);
int diameter(tree_t);
int printAncestors(tree_t,int);
void printAncestorsI(tree_t,int);
void printKdistance(tree_t,int);
int hasSumPath(tree_t,int);
tree_t getNode(int);
int isSum(tree_t);
int lowestCommonAncestor(tree_t,int,int);
void printPaths(tree_t);
void printPathsRec(tree_t,int *,int);
void printArray(int *,int);
int countTrees(int);
tree_t inorderSuccessor(tree_t,tree_t);
int checkAllLeavesSameLevel(tree_t);
int checkAllLeavesSame(tree_t,int,int*);
void replaceNodeWithSum(tree_t,int);
int maxDepth(tree_t);
int minDepth(tree_t);
int isBalanced(tree_t);
tree_t createMinimalBST(tree_t,int*,int); // Given a sorted array create a BST with minimal height
tree_t addToMinimalBST(int*,int,int);
void printPathWithSum(tree_t,int);
void pathWithSum(tree_t,int*,int,int);
void levelorderRecursive(tree_t);
void printLevel(tree_t,int);
void leftView(tree_t);
void leftViewRec(tree_t,int,int*);
void rightView(tree_t);
void rightViewRec(tree_t,int,int*);
tree_t buildTreeWithInorderAndPreOrder(int*,int*,int,int,int*);
int searchKeyInTraversal(int*,int,int,int);
void printPostOrder(int*,int*,int,int,int*);
int maxSumPath(tree_t);
void getTargetLeaf(tree_t,int*,int,tree_t*);
int printPath(tree_t,tree_t);
