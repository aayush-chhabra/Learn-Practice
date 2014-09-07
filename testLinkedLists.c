# include <stdio.h>
# include <stdlib.h>

struct node{

	int value;
	struct node * next;

}* root;

void addNode(struct node ** root, int value){
	
	struct node * temp = (struct node *)malloc(sizeof(struct node *));
	temp->value = value;
	temp->next = NULL;

	if(*root == NULL){
		*root = temp;
	}
	else{
		struct node * runner = *root;
		while(runner->next!=NULL)
			runner = runner->next;
	 	
	 	runner->next = temp;
	}
}

void printNode(struct node* root){
	struct node * runner = root; 
	while(runner!=NULL){
		printf("%d\n", runner->value);
		runner = runner->next;
	}
}	

int main(){
	
	root = NULL;
	addNode(&root, 10);
	addNode(&root, 20);
	addNode(&root, 30);
	addNode(&root, 40);
	printNode(root);

	//addNode(&root, 50);
	//printNode(root);

}






//updating the root every time a function call returns

// struct node{
// 	int value;
// 	struct node * next;
// }* root;

// struct node * addnode(struct node* root, int value){

// 	struct node* temp = (struct node*)malloc(sizeof(struct node *));
// 	temp -> value = value;
// 	temp -> next = NULL;

// 	if(root == NULL){
// 		root = temp;
// 		return root;
// 	}

// 	struct node * runner = root;
// 	while(runner->next!=NULL)
// 		runner=runner->next;
// 	runner->next = temp;
// 	return root;
	
// }

// void print(struct node* root){
// 	struct node* runner;
// 	runner = root;

// 	while(runner!=NULL){
// 		printf(" %d\n ", runner->value);
// 		runner = runner->next;
// 	}
// }

// int main(){
// 	root = NULL;

// 	root = addnode(root, 10);	
// 	root = addnode(root, 20);
// 	root = addnode(root, 30);
// 	root = addnode(root, 40);
// 	print(root);

// }



