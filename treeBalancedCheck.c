# include <stdio.h>
# include <stdlib.h>
# include <math.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* addNode(struct node * root, int data){
	
	if(root==NULL){
		struct node* temp; 
		temp = (struct node *)malloc(sizeof(struct node));
		temp->data = data;
		temp->left=NULL;
		temp->right=NULL;
		return temp;
	}

	if(data>root->data){
		root->right = addNode(root->right, data);
	}

	else if(data<root->data){
		root->left = addNode(root->left, data);
	}

	return root;
}

void printInorder(struct node* root){
	if(root == NULL){
		return;
	}
	printInorder(root->left);
	printf("%d\n",root->data );
	printInorder(root->right);
}


struct node* FindMin(struct node *root)
{
    if(root==NULL)
    {
            return NULL;
    }
    if(root->left)
	    return FindMin(root->left);
	else 
		return root;
}

struct node* deleteNode(struct node* root, int data){
	if(root == NULL){
		return NULL;
	}

	if(data > root->data){
		root->right = deleteNode(root->right, data);
	}

	else if(data < root->data){
		root->left = deleteNode(root->left, data);
	}

	else{
		if((root->left)&&(root->right)){
			struct node * temp = FindMin(root->right);
			root -> data = temp -> data;
			root->right = deleteNode(root->right, temp->data);
		}
		else{
			if(root->left == NULL){
				root = root->right;
			}
			else if(root->right == NULL){
				root = root->left;
			}
		}
	}
	return root;
}


// int balancedTree( struct node * root, int* minLength, int* maxLength, int length){
// 	struct node* temp = root;

// 	if((root->left == NULL )&&(root->right == NULL)){
// 		if(*minLength>length) *minLength = length;
// 		else if(*maxLength<length) *maxLength = length;
// 		printf("%d\n", length);
// 		return 0;
// 	}
// 	if(root->left != NULL){
// 		length+=1;
// 		balancedTree(root, minLength, maxLength, length);
// 		printf("root value : %d  - %d\n", root->data, length);	
// 	}
// 	if(root->right != NULL){
// 		length+=1;
// 		balancedTree(root, minLength, maxLength, length);
// 	}

// }

int calculateMin(int a, int b){
	return (a>b) ? b : a;
}

int calculateMax(int a, int b){
	return (a>b) ? a : b;
}

int calculateMinDepth(struct node* root){
	if(root == NULL)
		return 0;
	return 1+ calculateMin(calculateMinDepth(root->left),calculateMinDepth(root->right));
}

int calculateMaxDepth(struct node* root){
	if(root == NULL)
		return 0;
	return 1+ calculateMax(calculateMaxDepth(root->left),calculateMaxDepth(root->right));
}

int main(){
	struct node* root;
	int min=100, max=0;
	root = NULL;
	root = addNode(root, 10);
	root = addNode(root, 20);
	root = addNode(root, 4);
	root = addNode(root, 13);
	root = addNode(root, 8);
	root = addNode(root, 54);
	root = addNode(root, 27);
	root = addNode(root, 7);
	root = addNode(root, 2);
	int z = calculateMinDepth(root);
	int y = calculateMaxDepth(root);
	printf("%d\n", (y-z));
	//printInorder(root);
	
}