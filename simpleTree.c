# include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct tree{
	struct tree* left;
	int value;
	struct tree* right;
}* root;

int addNode(struct tree* root, struct tree* temp){

	

	if(root == NULL){
		root = temp;
		//printf("%d", root->value);
	}
	else{
		if(root->value > temp->value)	addNode(root->right, temp);
		else if(root->value < temp->value) addNode(root->left, temp);
	}
	return 0;
}

int printTree(struct tree * root){

	if(root!=NULL){
		printf(" %d ", root->value);
		if(root->left != NULL)printTree(root->left);
		if(root->right != NULL)printTree(root->right);
	}
	return 0;
}


int main(){
	
	root = NULL;

	struct tree * temp = (struct tree*)malloc(sizeof(struct tree *));
	temp->left = NULL;
	temp->right = NULL;
	temp->value = 10;

	
	

	addNode(root, temp);
	printf("%d\n", root->value);


	//printTree(root);
}