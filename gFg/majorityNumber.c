# include <stdio.h>
# include <stdlib.h>

struct node{
	int number;
	int count;
	struct node * left;
	struct node * right;
} *root;

int searchNode(struct node* root, int number);
void addNode(struct node** root, int number);
void printTree(struct node * root);
void incrementCount(struct node** root, int number);

void incrementCount(struct node** root, int number){
	if(root == NULL)
		return;

	if((*root)->number == number){
		//printf("%d %d\n", (*root)->number, (*root)->count);
		(*root)->count+=1;

		//printf("MC\t");
		return;
	}



	if(number < (*root)->number)
		incrementCount(&(*root)->left, number);

	if(number > (*root)->number)
		incrementCount(&(*root)->right, number);
}


int searchNode(struct node* root, int number){
	//This function would tell us if the node is already existing in the BST.
	if(root == NULL)
		return 0;

	if(number == root->number)
		return 1;


	if(number < root->number)
		searchNode(root->left, number);
	else
		searchNode(root->right, number);

	return 0;

}


void addNode(struct node** root, int number){

	if(searchNode(*root, number)){
		//printf("BC\t");
		incrementCount(root, number);
	}

	else{

		if(*root == NULL){
			struct node* temp = (struct node * )malloc(sizeof(struct node));
			temp -> number = number;

			//check first, okay ??
			temp -> count = 1;


			temp -> left = NULL;
			temp -> right = NULL;
			*root = temp;
			return;
		}

		else{
			if(number < (*root)->number)
				addNode(&(*root)->left, number);
			else
				addNode(&(*root)->right, number);
		}	
	}
}

void printTree(struct node * root){
	if(root == NULL)
		return;
	printTree(root->left);
	printf("Number: %d Count: %d\n", root->number, root->count);
	printTree(root->right);
}






int main(){
	
	root = NULL;
	//1 1 2 3 4 1 6 1 7 1 1
	addNode(&root, 1);
	addNode(&root, 1);
	addNode(&root, 2);
	addNode(&root, 3);
	addNode(&root, 4);
	addNode(&root, 1);
	addNode(&root, 1);
	addNode(&root, 6);
	addNode(&root, 1);
	addNode(&root, 7);
	addNode(&root, 1);
	addNode(&root, 1);
	// addNode(&root, 17);
	// addNode(&root, 29);
	// addNode(&root, 15);
	// addNode(&root, 1);
	// addNode(&root, 0);
	// addNode(&root, 2);

	printTree(root);
}