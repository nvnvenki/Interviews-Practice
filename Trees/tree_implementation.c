#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "tree.h"


tree_t insert(tree_t root, int key)
{


        tree_t temp = (tree_t)malloc(sizeof(struct tree));
        temp -> key = key;
        temp -> rlink = NULL;
        temp -> llink = NULL;

        if(root == NULL)
        {
                root = temp;
        }
        else if(key > root -> key)
        {
                root -> rlink = insert(root -> rlink, key);
        }
        else if(key < root -> key)
        {
                root -> llink = insert(root -> llink, key);
        }

        return root;
}


void display(tree_t root)
{
        if(root != NULL)
        {
                display(root -> llink);
                printf("%d\n", root -> key);
                display(root -> rlink);

        }
}

tree_t getNode(int key)
{
        tree_t temp = (tree_t)malloc(sizeof(struct tree));
        temp -> key = key;
        temp -> rlink = NULL;
        temp -> llink = NULL;

        return temp;
}

void pre_traversal(tree_t root)
{
        if(root != NULL)
        {
                printf("%d\n", root -> key);
                display(root -> llink);
                display(root -> rlink);
        }


}


void post_traversal(tree_t root)
{
        if(root != NULL)
        {
                display(root -> llink);
                display(root -> rlink);
                printf("%d\n", root -> key);
        }
}

int count(tree_t root)
{
        if(root != NULL)
        {
                return (1 + count(root -> llink) + count(root -> rlink));
        }
        else
        {
                return 0;
        }

}

int count_leaf(tree_t root)
{
        if(root != NULL)
        {
                if(root -> llink == NULL && root -> rlink == NULL)
                {
                        return 1;
                }
                else
                {
                        return count_leaf(root -> llink) + count_leaf(root -> rlink);
                }

        }
        else
        {
                return 0;
        }

}

int max(int a, int b)
{
        return a > b? a: b;
}

int height(tree_t root)
{
        if(root == NULL)
        {
                return 0;
        }
        else
        {
                return 1 + max(height(root -> llink), height(root -> rlink));
        }
}

int max_of_tree(tree_t root)
{
        tree_t temp = root;
        while(temp -> rlink!= NULL)
        {
                temp = temp -> rlink;
        }
        return temp -> key;
}


int least_of_tree(tree_t root)
{
        tree_t temp = root;
        while(temp -> llink != NULL)
        {
                temp = temp -> llink;
        }
        return temp -> key;
}

void verticalSumArray(tree_t root,int *vertical_sum,int hd)
{
        if(root == NULL)
        {
                return;
        }

        verticalSumArray(root -> llink,vertical_sum,hd - 1);
        int prevSum = (vertical_sum[hd] == 0? 0 : vertical_sum[hd]);
        vertical_sum[hd] = prevSum + root -> key;
//      printf("### %d\n",vertical_sum[hd]);
        verticalSumArray(root -> rlink,vertical_sum,hd + 1);
}

tree_t mirror_tree(tree_t root)
{
        tree_t temp;
        if(root != NULL)
        {
                temp = root -> llink;
                root -> llink = root -> rlink;
                root -> rlink = temp;
                root -> llink = mirror_tree(root -> llink);
                root -> rlink = mirror_tree(root -> rlink);
        }
        return root;
}

int RLMirrors(tree_t root)
{
        tree_t mirrored_root = mirror_tree(root);
        printf("%d\n", isMirrorsLR(root,mirrored_root));
        return 1;
        // return isMirrorsLR(root,mirrored_root)? 1 : 0;

}

int isMirrorsLR(tree_t root1,tree_t root2)
{
        if(root1 == NULL && root2 == NULL)
        {
                return 1;
        }
        if(root1 == NULL || root2 == NULL)
        {
                return 0;
        }

        return isMirrorsLR(root1 -> llink, root2 -> rlink) && isMirrorsLR(root1 -> rlink, root2 -> llink);
}

#if 0
tree_t largestSumSubtree(tree_t root)
{
#if 0
        if(root == NULL)
        {
                return root;
        }
        int max = 0;
        tree_t largest = NULL;
        max = maxSum(root,&largest,&max);
        printf("%d\n",max);
#endif
        return largest;
}
#endif
tree_t search(tree_t root,int key)
{
        while(root != NULL && key != root -> key)
        {
                root = (key < root -> key) ? root -> llink:root -> rlink;
        }

        return root;
}


void iterativeInorder(tree_t root)
{
        int n = count(root);
        tree_t stack[n];
        for(int i = 0; i < n; ++i)
        {
                stack[i] = NULL;
        }
        int top = 0;
        tree_t cur = root;
        while(cur != NULL)
        {
                while(cur != NULL)
                {
                        if(cur -> rlink != NULL)
                        {
                                stack[top++] = cur -> rlink;
                        }
                        stack[top++] = cur;
                        cur = cur -> llink;
                }

                cur = stack[--top];

                while(top != 0 && cur -> rlink == NULL)
                {
                        printf("%d\t",cur -> key);
                        cur = stack[--top];
                }

                printf("%d\t",cur -> key);
                cur = (top != 0) ? stack[--top]:NULL;
        }
        printf("\n");
}

void iterativePreorder(tree_t root)
{
        int n = count(root);
        tree_t stack[n];
        int top = 0;
        if(root == NULL)
        {
                return;
        }
        tree_t cur = root;

        stack[top++] = cur;
        while(top != 0)
        {
                cur = stack[--top];
                printf("%d\t",cur -> key);
                if(cur -> rlink != NULL)
                {
                        stack[top++] = cur -> rlink;
                }
                if(cur -> llink != NULL)
                {
                        stack[top++] = cur -> llink;
                }
        }
        printf("\n");
}

void iterativePostorder(tree_t root)
{
       // :P
}

void levelorder(tree_t root)
{
        int n = count(root);
        tree_t queue[n];
        for(int i = 0; i < n; ++i)
        {
                queue[i] = NULL;
        }
        int size = 0;
        int q = 0;
        tree_t cur = root;

        while(cur != NULL)
        {
                printf("%d\t",cur -> key);
                if(cur -> llink != NULL)
                {
                        queue[size++] = cur -> llink;

                }

                if(cur -> rlink != NULL)
                {
                        queue[size++] = cur -> rlink;
                }

                cur = queue[q++];
        }

        printf("\n");
}

int diameter(tree_t root)
{
        if(root == NULL)
        {
                return 0;
        }
        // Get the height of left and right sub trees
        int lheight = height(root -> llink);
        int rheight = height(root -> rlink);

        // get the diameter of right and left sub tree
        int ldiameter = diameter(root -> llink);
        int rdiameter = diameter(root -> rlink);

        // return the max of ldiametere , r diameter , height of lsubtree + r subtree + 1

        return max(lheight + rheight + 1, max(ldiameter,rdiameter));

}


int printAncestors(tree_t root,int key)
{
        if(root == NULL)
        {
                return 0;
        }
        if(root -> key == key)
        {
                return 1;
        }

        if(printAncestors(root -> llink,key) || printAncestors(root -> rlink,key))
        {
                printf("%d\t",root -> key);
                return 1;
        }
        return 0;
}

void printAncestorsI(tree_t root,int key)
{
        if(root == NULL)
        {
                return;
        }
        tree_t stack[count(root)];
        int top = -1;
        tree_t cur = root;
        while(1)
        {
                /*
                        Traverse the left side while traversing , push the nodes into the stack
                        so that their right can be traversed later
                */
                while(cur && cur -> key != key)
                {

                        stack[++top] = cur;
                        cur = cur -> llink;
                }

                /*
                        If the node whose ancestors are to be printed is found then break loop
                */
                if(cur && cur -> key == key)
                {
                        break;
                }
                // Check if right sub teee exists for the node at top
                // if not then pop that node because we dnt need this
                if(stack[top] -> rlink == NULL)
                {
                        cur = stack[top--];

                        while(top != -1 && stack[top] -> rlink == cur)
                        {
                                cur = stack[top--];
                        }
                }
                cur = top == -1 ? NULL : stack[top] -> rlink;
        }

        while(top != -1)
        {
                printf("%d\t",stack[top--] -> key);
        }
}

void printKdistance(tree_t root, int k)
{
        if(root == NULL)
        {
                return;
        }
        if(k == 0)
        {
                printf("%d\t", root -> key);
                return;
        }
        else
        {
                printKdistance(root -> llink,k - 1);
                printKdistance(root -> rlink,k - 1);
        }
}

int hasSumPath(tree_t root,int sum)
{
        if(root == NULL)
        {
                return sum == 0;
        }
        else
        {
                int temp = sum - root -> key;
                if((temp == 0) && (root -> llink == NULL) && (root -> rlink == NULL))
                {
                        return 1;
                }

                return ((hasSumPath(root -> llink,temp)) || (hasSumPath(root -> rlink,temp)));
        }
}

int isSum(tree_t root)
{
        int left = 0;
        int right = 0;

        if(root == NULL || (root -> llink == NULL && root -> rlink == NULL))
        {
                return 1;
        }

        if(root -> llink != NULL)
        {
                left = root -> llink -> key;
        }
        if(root -> rlink != NULL)
        {
                right = root -> rlink -> key;
        }

        if((root -> key == (right + left)) && isSum(root -> llink) && isSum(root -> rlink))
        {
                return 1;
        }
        else
        {
                return 0;
        }
}

int lowestCommonAncestor(tree_t root,int n1,int n2)
{

        if(root == NULL || root -> key == n1 || root -> key == n2)
        {

                return -1;
        }


        if((root -> rlink != NULL) && (root -> rlink -> key == n1 || root -> rlink -> key == n2))
        {
                return root -> key;
        }

        if((root -> llink != NULL) && (root -> llink -> key == n1 || root -> llink -> key == n2))
        {
                return root -> key;
        }

        if(root -> key > n1 && root -> key < n2) // n1 < n < n2
        {
                return root -> key;
        }

        if(root -> key > n1 && root -> key > n2)
        {
                return lowestCommonAncestor(root -> llink,n1,n2);
        }
        if(root -> key < n1 && root -> key < n2)
        {
               return lowestCommonAncestor(root -> rlink,n1,n2);
        }
}

void printArray(int *a,int n)
{
        for(int i = 0; i < n ; ++i)
        {
                printf("%d\t",a[i]);
        }
        printf("\n");
}

void printPaths(tree_t root)
{
        int path[count(root)];
        printPathsRec(root,path,0);
}

void printPathsRec(tree_t root,int *path,int len)
{
        if(root == NULL)
        {
                return;
        }

        path[len++] = root -> key;

        if(root -> llink == NULL && root -> rlink == NULL)
        {
                printArray(path,len);
        }
        else
        {
                printPathsRec(root -> llink,path,len);
                printPathsRec(root -> rlink,path,len);
        }
}

int countTrees(int n)
{
        if(n <= 1)
        {
                return 1;
        }
        else
        {
                int total = 0;
                int left;
                int right;
                int root;
                for(root = 1; root <= n; ++root)
                {
                        left = countTrees(root - 1);
                        right = countTrees(n - root);

                        total += left * right;
                }
                return total;
        }
}

tree_t inorderSuccessor(tree_t root,tree_t node)
{
        if(node -> rlink != NULL)
        {
                return getNode(least_of_tree(node -> rlink));
        }
        tree_t successor = NULL;
        tree_t cur = root;
        while(cur != NULL)
        {
                if(node -> key < cur -> key)
                {
                        successor = cur;
                        cur = cur -> llink;
                }
                else if(node -> key > cur -> key)
                {
                        cur = cur -> rlink;
                }
                else
                {
                        break;
                }
        }
        return successor;
}

int checkAllLeavesSame(tree_t root,int level,int *leafLevel)
{
        if(root == NULL)
        {
                return 1;
        }
        if(root -> llink == NULL && root -> rlink == NULL)
        {
                // If the leaf node is found for the first time
                if(*leafLevel == 0)
                {
                        *leafLevel = level;
                        return 1;
                }

                // If this is not the first leaf node
                return (level == (*leafLevel));
        }

        return checkAllLeavesSame(root -> llink, level + 1, leafLevel) && checkAllLeavesSame(root -> rlink, level + 1, leafLevel);

}


int checkAllLeavesSameLevel(tree_t root)
{
        int level = 0;
        int leafLevel = 0;
        return checkAllLeavesSame(root,level,&leafLevel);
}

void replaceNodeWithSum(tree_t root,int sum)
{
        if(root == NULL)
        {
                return;
        }

        replaceNodeWithSum(root -> rlink,sum);
        sum = sum + root -> key;
        root -> key = sum + root -> key;
        replaceNodeWithSum(root -> llink,sum);
}

int min(int a,int b)
{
        return a < b? a : b;
}

int maxDepth(tree_t root)
{
        if(root == NULL)
        {
                return 0;
        }
        else
        {
                return 1 + max(maxDepth(root->llink), maxDepth(root->rlink));
        }
}

int minDepth(tree_t root)
{
        if(root == NULL)
        {
                return 0;
        }
        else
        {
                return 1 + min(minDepth(root->llink) , minDepth(root->rlink));
        }
}


int isBalanced(tree_t root)
{
        return ((maxDepth(root) - minDepth(root)) <= 1);
}

tree_t addToMinimalBST(int* a,int start,int end)
{
        if(end < start)
        {
                return NULL;
        }

        int mid = (start + end) / 2;
        tree_t temp = getNode(a[mid]);
        temp->llink = addToMinimalBST(a,start,mid - 1);
        temp->rlink = addToMinimalBST(a,mid + 1,end);
        return temp;
}

tree_t createMinimalBST(tree_t root,int* array,int n)
{
        return addToMinimalBST(array,0,n - 1);
}


void pathWithSum(tree_t root,int* path,int sum,int index)
{
        if(root == NULL)
        {
                return;
        }
        if(sum == 0)
        {
                printArray(path,index);
                return;
        }
        else
        {
                path[index++] = root->key;

                int curSum = sum - root->key;
                if(curSum == 0 && (root->llink == NULL && root->rlink == NULL))
                {
                        printArray(path,index);
                }

                if(root->llink != NULL)
                {
                        pathWithSum(root->llink,path,curSum,index);
                }
                if(root->rlink != NULL)
                {
                        pathWithSum(root->rlink,path,curSum,index);
                }
        }
}

void printPathWithSum(tree_t root,int sum)
{
        int path[1000];
        pathWithSum(root,path,sum,0);
}

void levelorderRecursive(tree_t root)
{
        int height_ = height(root);
        for(int i = 1; i <= height_; ++i)
        {
                printLevel(root,i);
        }
}


void printLevel(tree_t root,int level)
{
        if(root == NULL)
        {
                return;
        }
        if(level == 1)
        {
                printf("%d\t",root->key);
        }
        printLevel(root->llink,level - 1);
        printLevel(root->rlink,level - 1);
}

void leftViewRec(tree_t root,int level,int* max_level)
{
        if(root == NULL)
        {
                return;
        }
        if(level > (*max_level))
        {
                printf("%d\t", root->key);
                (*max_level) = level;
        }
        leftViewRec(root->llink,level + 1,max_level);
        leftViewRec(root->rlink, level + 1,max_level);
}

void leftView(tree_t root)
{
        int max = 0;
        leftViewRec(root,1,&max);

}


void rightViewRec(tree_t root,int level,int* max_level)
{
        if(root == NULL)
        {
                return;
        }
        if(level > (*max_level))
        {
                printf("%d\t", root->key);
                (*max_level) = level;
        }
        rightViewRec(root->rlink,level + 1,max_level);
        rightViewRec(root->llink, level + 1,max_level);
}

void rightView(tree_t root)
{
        int max = 0;
        rightViewRec(root,1,&max);
}

int searchKeyInTraversal(int* array,int start,int end,int key)
{
        for(int i = start; i <= end; ++i)
        {
                if(array[i] == key)
                {
                        return i;
                }
        }
        return -1;
}

tree_t buildTreeWithInorderAndPreOrder(int* inorder,int* preorder,int start,int end,int* preIndex)
{
        if(start > end)
        {
                return NULL;
        }

        tree_t temp = getNode(preorder[(*preIndex)++]);

        // if the tree has only one node in the given traversal
        if(start == end)
        {
                return temp;
        }
        int index = searchKeyInTraversal(inorder,start,end,temp->key);

        temp->llink = buildTreeWithInorderAndPreOrder(inorder,preorder,start,index - 1,preIndex);
        temp->rlink = buildTreeWithInorderAndPreOrder(inorder,preorder,index + 1,end,preIndex);

        return temp;
}

void printPostOrder(int* inorder,int* preorder,int start,int end,int* index)
{
        if(start > end)
        {
                return;
        }

        // first element in pre order is always the root search it in the inorder traversal
        int root = searchKeyInTraversal(inorder,start,end,preorder[*index]);
        (*index)++;
        printPostOrder(inorder,preorder,start,root - 1,index);
        printPostOrder(inorder,preorder,root + 1,end,index);
        printf("%d\t",inorder[root]);
}

void getTargetLeaf(tree_t root,int *max_sum,int cur_sum,tree_t* targetLeaf)
{
        if(root == NULL)
        {
                return;
        }

        cur_sum += root->key;

        if(root->llink == NULL && root->rlink == NULL)
        {
                if(cur_sum > *max_sum)
                {
                        *max_sum = cur_sum;
                        *targetLeaf = root;
                }
        }

        getTargetLeaf(root->llink,max_sum,cur_sum,targetLeaf);
        getTargetLeaf(root->rlink,max_sum,cur_sum,targetLeaf);

}

int printPath(tree_t root,tree_t target_leaf)
{
        if(root == NULL)
        {
                return 0;
        }
        if(root == target_leaf || printPath(root->llink,target_leaf) || printPath(root->rlink,target_leaf))
        {
                printf("%d\t",root->key);
                return 1;
        }

}


int maxSumPath(tree_t root)
{
        if(root == NULL)
        {
                return 0;
        }

        tree_t target_leaf;
        int max_sum = INT_MIN;
        getTargetLeaf(root,&max_sum,0,&target_leaf);
        printPath(root,target_leaf);

        return max_sum;
}
