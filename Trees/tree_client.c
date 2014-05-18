#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include <pthread.h>



int main()
{

#if 0
        int a[] = {2, 4, 1, 8, 3, 5, 9, 6, 7};
        tree_t root = NULL;

        for(int i = 0; i < 9; ++i)
        {
                root = insert(root,a[i]);
        }

        display(root);

        printf("----------------------\n");
#endif
#if 0
        printf("In-order traversal \n");
        display(root);

        printf("No of nodes: %d\n", count(root));

        printf("----------------------\n");
        printf("No of leaf nodes: %d\n",count_leaf(root));

        printf("----------------------\n");
        printf("Pre-order traversal\n");
        post_traversal(root);
        printf("----------------------\n");
        printf("Post-order traversal\n");
        pre_traversal(root);
        printf("----------------------\n");

        printf("Height of the tree is: %d\n", height(root));
        printf("Least value in tree is: %d\n", least_of_tree(root));
        printf("Max value of tree is: %d\n", max_of_tree(root));

        int height_ = height(root);
        int vertical_sum[10000];
        for(int i = 0; i < 10000; ++i)
        {
                vertical_sum[i] = 0;
        }
        /*
                I assumed Vertical sum for root is 1... :P if there are more no of nodes on the
                left subtree of the root..they we cant implement this using arrays in c..as negative indices is not possible
        */

        verticalSumArray(root,vertical_sum,1);
        for(int i = 0;vertical_sum[i] != 0 ; ++i)
        {
                printf("%d : %d \n",i,vertical_sum[i]);
        }

        // tree_t mirrored_root = mirror_tree(root);
        printf("----------------------\n");
        // display(mirrored_root);
        //printf("%d\n", RLMirrors(root));
        //inorder(root);

        tree_t largest = largestSumSubtree(root);
        printf("%d\n",largest -> key);

        int key = 1;
        if(search(root,key) != NULL)
        {
                printf("%d is present\n",key);
        }
        else
        {
                printf("%d is absent\n",key);
        }

        iterativeInorder(root);

        printf("----------------------\n");

        iterativePreorder(root);


        printf("----------------------\n");
        iterativePostorder(root);

        levelorder(root);

        int height = 0;
        printf("the diameter of the tree: %d\n",diameter(root));

        int key = 9;
        printAncestorsI(root,key);

        int k = 3;
        printKdistance(root,k);

        int sum = 36;
        if(hasSumPath(root,sum) == 1)
        {
                printf("Yes\n");
        }
        else
        {
                printf("No\n");
        }

        root  = getNode(10);
        root -> llink = getNode(8);
        root -> rlink = getNode(2);
        root -> llink -> llink = getNode(3);
        root -> llink -> rlink = getNode(5);
        root -> rlink ->rlink = getNode(2);

        display(root);
        printf("----------------------\n");
        if(isSum(root))
        {
                printf("Yes\n");
        }
        else
        {
                printf("No\n");
        }

        root  = getNode(20);
        root -> llink = getNode(8);
        root -> rlink = getNode(22);
        root -> llink -> llink = getNode(4);
        root -> llink -> rlink = getNode(12);
        root -> llink -> rlink -> rlink = getNode(14);
        root -> llink -> rlink -> llink = getNode(10);

        int n1 = 4;
        int n2 = 14;
        printf("Least common ancestor of %d & %d is %d \n", n1,n2,lowestCommonAncestor(root,n1,n2));
        printf("\n");
#endif
        // printPaths(root);
#if 0
        int num = 4;
        printf("The no of bst for %d keys is %d\n", num,countTrees(num));i
#endif
#if 0
        root = getNode(20);
        root -> llink = getNode(8);
        root -> rlink = getNode(22);
        root -> llink -> llink = getNode(4);
        root -> llink -> rlink = getNode(12);
        root -> llink -> rlink -> llink = getNode(10);
        root -> llink -> rlink -> rlink = getNode(14);

        tree_t successor = inorderSuccessor(root,root -> llink);
        if(successor != NULL)
        {
                printf("thei inorder successor is %d\n",successor -> key);
        }
#endif
#if 0
        root = getNode(20);
        root -> llink = getNode(8);
        root -> rlink = getNode(22);
        root -> llink -> llink = getNode(100);
        if(checkAllLeavesSameLevel(root) == 1)
        {
                printf("All the leaves are in the same level\n");
        }
#endif
#if 0
        display(root);
        printf("-------------------------------------\n");
        replaceNodeWithSum(root,0);
        display(root);
int getSum(tree_t root)
{
        if(root == NULL)
        {
                return 0;
        }
        else
        {
                return root -> key + getSum(root -> rlink);
        }
}
#endif
        // printf("%d\n",countTrees(3));
#if 0
        root = getNode(10);
        root->llink = getNode(20);
        root->rlink = getNode(30);



        if(isBalanced(root) == 1)
        {
                printf("The tree is balanced\n");
        }
        else
        {
                printf("Ther tree is unbalanced\n");
        }
#endif
#if 0
        tree_t root = NULL;
        int array[] = {1,2,3,4,5,6,7,8,9};
        int n = 9;
        root = createMinimalBST(root,array,n);
        display(root);
#endif
//        tree_t root = NULL;
#if 0
        root = getNode(20);
        root -> llink = getNode(8);
        root -> rlink = getNode(22);
        root -> llink -> llink = getNode(4);
        root -> llink -> rlink = getNode(12);
        root -> llink -> rlink -> llink = getNode(10);
        root -> llink -> rlink -> rlink = getNode(14);

        // printPathWithSum(root,40);

        // levelorderRecursive(root);
        // rightView(root);
#endif
#if 0
        int inorder[] = {4, 2, 5, 1, 6, 3};
        int preorder[] = {1, 2, 4, 5, 3, 6};

        int n = 6;
        // int preIndex = 0;
        // root = buildTreeWithInorderAndPreOrder(inorder,preorder,0,n - 1,&preIndex);
        // display(root);

        int index = 0;
        printPostOrder(inorder,preorder,0,n - 1,&index);
#endif
#if 0
        /*
                        10
                    -2      7
                 8      -4

        */
        tree_t root = NULL;
        root = getNode(10);
        root->llink = getNode(-2);
        root->rlink = getNode(7);
        root->llink->llink = getNode(8);
        root->llink->rlink = getNode(-4);
 //       printf("Sum: %d\n",maxSumPath(root));

        pre_traversal(root);
        printf("----------------------------------");
        display(root);
#endif

        return 0;
}

