# include <stdio.h>
# include <stdlib.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
};

void addNode(struct node** root, int data){
	
	if(*root == NULL){
		struct node* temp;
		temp = (struct node*)malloc(sizeof(struct node));
		temp -> data = data;
		temp -> left = NULL;
		temp -> right = NULL;
		*root=temp;
	}
	if(data >(*root)->data)
    {
        addNode((*root)->right,data);
    }
    else if(data < (*root)->data)
    {
        addNode((*root)->left,data);
    }
}

void printInorder(struct node* root){
	if(root == NULL){
		return;
	}
	printInorder(root->left);
	printf(" %d ", root->data);
	printInorder(root->right);
}


int main(){
	struct node* root = NULL;
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	breakArray(&root, array, 9);
	printInorder(root);
}

int breakArray(struct node** root, int array[], int length){
	if(length == 1)
		return array[0];
	int data;
	data = array[(length/2)];
	addNode(root, data);
	breakArray(root, array, (length/2));
	breakArray(root, array+(length/2), (length/2));
}