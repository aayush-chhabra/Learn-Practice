# include <stdio.h>
# include <stdlib.h>


struct node{
	int number;
	struct node* left;
	struct node* right;
} *root;


int ifBalanced(struct node* root, int level, int* maxLevel){
	if(root == NULL){
		if((level != *maxLevel)&&(*maxLevel != 0)){
			return 0;
		}
		*maxLevel = level;
		return 1;
	}

	level++;
	
	int left = ifBalanced(root->left, level, maxLevel);
	int right = ifBalanced(root->right, level, maxLevel);

	if(left && right)
		return 1;
	else
		return 0;




}

void addBST(struct node ** root, int number){
	if(*root == NULL){
		struct node* temp = (struct node*)malloc(sizeof(struct node));
		temp -> number = number;
		temp -> left = NULL;
		temp -> right = NULL;
		*root = temp;
	}
	if(number < (*root)->number){
		addBST(&(*root)->left, number);
	}
	if(number > (*root)->number){
		addBST(&(*root)->right, number);
	}
}

void print(struct node* root){
	if(root != NULL){
		print(root->left);
		//printf("%d\n", root->number);
		printf("%lu\n", sizeof(root->number));
		print(root->right);
	}	
}





void addHeap(struct node** root, int number){
	int z = 0;
	if(*root == NULL){
		struct node* temp = (struct node*)malloc(sizeof(struct node));
		temp -> number = number;
		temp -> left = NULL;
		temp -> right = NULL;
		*root = temp;
		return;
	}

	if((*root)->left == NULL)
		addHeap(&(*root)->left, number);
	else if((*root)->right == NULL)
		addHeap(&(*root)->right, number);
	else{
		if((ifBalanced((*root)->left,0,&z))&&(ifBalanced((*root)->right,0,&z))){
			//printf("%d\n",(*root)->number);
			addHeap(&(*root)->left, number);
		}
		else if((ifBalanced((*root)->left,0,&z))&&!(ifBalanced((*root)->right,0,&z))){
			addHeap(&(*root)->right, number);	
		}
		else if(!ifBalanced((*root)->left,0,&z)){
			addHeap(&(*root)->left, number);	
		}
	}
}

void trickleUp(struct node* root){
	
}

void heapify(struct node** root){
	


	// if((*root)->left){
	// 	if((*root)->number < ((*root)->left)->number){
	// 		int temp = 	((*root)->left)->number;
	// 		((*root)->left)->number = (*root)->number;
	// 		(*root)->number = temp;
	// 		heapify(&(*root)->left);

	// 	}
	// }


}

int main(){
	root = NULL;
	addHeap(&root, '+');
	//printf("%d\n", root->number);
	addHeap(&root, '+');
	addHeap(&root, '+');
	addHeap(&root, 2);
	addHeap(&root, 4);
	addHeap(&root, 11);
	addHeap(&root, 23);
	heapify(&root);
	//printf("%d\n", ((root->left)->right)->number);
	print(root);
}