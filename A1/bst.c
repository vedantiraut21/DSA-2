#include<stdio.h>
#include<stdlib.h>
#include"bst.h"

stack* top = NULL;

void push(node* r)
{
    stack* n = malloc(sizeof(stack));
    n->n = r;
    n->next = NULL;
    if(top==NULL)
    {
        top=n;
        return ;
    }
    n->next = top;
    top = n;
    return ;
}

node* pop()
{
    stack* temp = top;
    top = top->next;
    return temp->n;
}

int stack_empty()
{
    if(top==NULL)
        return 1;
    else
        return 0;
}

void initBST(bst* t){

	*t = NULL;
	printf("...");
	return;
}

node* newNode(int d, char* n){
	node* nn = (node*)malloc(sizeof(node));
	
	nn->MIS = d;
	nn->name = n;
	nn->left = nn->right = nn->parent = NULL;
	
	return nn;
} 

void insertNode(bst* t, node* nn){

	if(*t == NULL){
		*t = nn;
		return;
	}
	
	node* temp = *t;
	
	if(temp->MIS == nn->MIS){
		free(nn);
		printf("\nInsertion can't be performed, data already exists..\n");
		return;
	}
	else if(temp->MIS < nn->MIS){       //INSERTION AT RIGHT
		printf(" right ");
		insertNode(&(temp->right), nn);
		/*if(temp->right == NULL){
			temp->right = nn;
			nn->parent = temp;
			return;
		}
		else if(temp->right->MIS == nn->MIS){
			free(nn);
			return;
		}
		else
			insertNode(&(temp->right), nn);*/
	}
	else if(temp->MIS > nn->MIS){       //INSERTION AT LEFT
		printf(" left ");
		insertNode(&(temp->left), nn);
		/*if(temp->left == NULL){
			temp->left == nn;
			nn->parent = temp;
			return;
		}
		else if(temp->left->MIS == nn->MIS)
			{
				free(nn);
				return;
			}
		else
			insertNode(&(temp->left), nn);*/
	}
}

node* findMin(node* temp){
    node* curr = temp;
    
    while(curr && curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}

void removeNode(bst *t, int d){

	if(*t==NULL){
		return;
	}
	
	node* temp = *t;
	
	if(temp->MIS > d)
		removeNode(&(temp->left), d);
	else if(temp->MIS < d)
		removeNode(&(temp->right), d);
	else{
		//Case 1: No child
		if(temp->left == NULL && temp->right == NULL){
			free(temp);
			temp = NULL;
			return;
		}
		//Case 2: One child either left or right
		else if(temp->left == NULL){
			node* tp = temp;
			temp = temp->right;
			free(tp);
			return;
		}
		else if(temp->right == NULL){
			node* tp = temp;
			temp = temp->left;
			free(tp);
			return;
		}
		//Case 3: 2 children
		else{
			node* tp = findMin(temp->right);
			temp->MIS = tp->MIS;
			temp->name = tp->name;
			removeNode(&(temp->right), tp->MIS);
			return;
		}
	}
}

void search(bst t, int key){
	if(t == NULL){
		printf("\n Not Found..\n");
		return;
	}
	if (t->MIS == key){
		printf("\n Found..\n");
		return;
	}
	if(t->MIS > key)
		search(t->left,key);
	else
		search(t->right,key);
}

void postorder(bst* t){
	node* temp = *t;
	node* previous = NULL;
	
	if(temp==NULL){
		printf("Tree is empty\n");
        	return;
	}
	
	previous = *t;
	while(1){
		while(temp->left != NULL){
			push(temp);
			temp = temp->left;
		}
		
		while(temp->right == NULL || temp->right == previous){
			printf("\n MIS = %d", temp->MIS);
			printf("\n NAME = %s\n", temp->name);
			previous = temp;
			if(stack_empty())
				return;
			temp = pop();
		}
		push(temp);
		temp = temp->right;
	}
	printf("\n");
}

void display_Level(bst t, int level){
	if(t==NULL)
		return;

	if(level==1){
		printf("\n MIS = %d ", t->MIS);
		printf("\n Name = %s \n", t->name);
	}
	else if (level>1){
		display_Level(t->left , level-1);
		display_Level(t->right, level-1);
	}
}

void destroyTree(bst* t){
	node* temp = *t;
	if(temp==NULL)
		return;
	
	//first delete both subtrees
	destroyTree(&(temp->left));
	destroyTree(&(temp->right));
	
	//delete the node
	printf("\n Deleting node: %d", temp->MIS);
    	free(temp);
}

