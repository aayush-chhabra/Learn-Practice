# include <stdio.h>
# include <stdlib.h>

struct node{

	int number;
	struct node * left;
	struct node * right;

}*root;

void addNode(int number){
	if(root == NULL){
		struct node* temp = (struct node*)malloc(sizeof(struct node));
		temp -> number = number;
		temp -> left = NULL;
		temp -> right = NULL;
		root = temp;
	}
	else{
		struct node * parent, *temp;
		temp = root;
		while(temp!=NULL){
			if(temp->number > number){
				parent = temp;
				temp = temp->right;
			}
			else{
				parent = temp;
				temp = temp->right;
			}
		}

		struct node* temp1 = (struct node*) malloc(sizeof(struct node));
		temp1 -> number = number;
		temp1 -> left = NULL;
		temp1 -> right = NULL;
		
		if(number > parent->number){
			parent->right = temp1;
		}
		else
			parent->left = temp1;
	}
}

void print(){

}


int main(){
	root = NULL;
	addNode(10);
	addNode(20);
	addNode(3);
	addNode(5);
	addNode(1);

	printf("%d %d %d", root->number, (root->left)->number, (root->right)->number);

}