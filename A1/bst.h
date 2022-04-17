
typedef struct node{
	int MIS;
	char* name;
	struct node* left;
	struct node* right;
	struct node* parent;
}node;

typedef struct stack{

	node* n;
	struct stack* next;
}stack;

typedef node* bst;

void initBST(bst* t);   // to initialize the tree.

node* newNode(int d, char* n);

void insertNode(bst* t,node* n);   //Recursive Insertion

node* findMin(node* temp);

void removeNode(bst* t, int d);

void search(bst t, int key);

void postorder(bst* t);  // Non-recursive

void push(node* r);

node* pop();

int stack_empty();

void display_Level(bst t,int level);

void destroyTree(bst* t);


