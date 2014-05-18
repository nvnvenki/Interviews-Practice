struct node
{
        int key;
        struct node *link;
};

typedef struct node* node_t;

node_t addElement(node_t,int);
void display(node_t);
node_t reverseList(node_t);
node_t del(node_t,node_t);
node_t sortedAdd(node_t,int);
node_t clear(node_t);
int nthFromLast(node_t,int);
node_t makeUnique(node_t);
void displayRev(node_t);
int count(node_t,int);
int getNth(node_t,int);
node_t pop(node_t);
node_t insertAt(node_t,int,int);
node_t rotateBy(node_t,int);
node_t intersection(node_t,node_t,node_t);
node_t deleteNafterM(node_t,int,int);
void deleteNode(node_t);
int getLength(node_t);
node_t swapKth(node_t,int);
node_t sortZOT(node_t); // Sort a list of 0's 1's and 2's
node_t intersection(node_t,node_t,node_t);
node_t union_(node_t,node_t,node_t);
int isPresent(node_t,int);
node_t swap_every_two_nodes(node_t);
void splitNodes(node_t);
void mergeIntoAnotherAtAlternatePositions(node_t,node_t);
void swapPointers(node_t*,node_t*);
node_t add_two_lists(node_t,node_t,node_t);
node_t addSameSize(node_t,node_t,int*);
void addCarryToRemaining(node_t,node_t,int*,node_t*);
int getLength(node_t);
