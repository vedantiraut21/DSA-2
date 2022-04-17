#include<stdio.h>
#include"bst.h"

void main(){
	
	int choice, d, data, level;
	char* n;
	bst t;
	
	do{
		
		printf("\n\n1. Initialize BST\n2. Insert Node\n3. Delete Node\n4. Search\n5. PostOrder Traversal\n6. Display Level\n7. Destory Tree\n8. Exit");
		
		printf("\n\n Enter your choice: ");
		scanf("%d",&choice);
		
		switch(choice){
			
			case 1: 
				initBST(&t);
				break;
				
			case 2:
				printf("\n Enter MIS: ");
				scanf("%d", &d);
				
				printf("\n Enter name: ");
				scanf("%ms", &n);
				node* nn = newNode(d, n);
				insertNode(&t, nn);
				break;
				
			case 3:
				printf("\n Enter MIS: ");
				scanf("%d",&data);
				removeNode(&t, data);
				break;
			
			case 4:
				printf("\n Enter data to search: ");
				scanf("%d", &data);
				search(t, data);
				break;
			
			case 5:
				postorder(&t);
				break;
			
			case 6:
				printf("\n Enter the level you want to print: ");
				scanf("%d", &level);
				display_Level(t, level);
				break;
			
			case 7:
				destroyTree(&t);
				printf("\n All nodes deleted...\n");
				break;
			
			default:
				printf("\nInvalid choice\n");
				break;
		}
		
	}while(choice<8 && choice>0);
	
}
