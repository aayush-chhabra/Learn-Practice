# include <stdio.h>
# include <stdlib.h>

struct node{
	int number;
	struct node * next;
} *root, *newRoot ;


void addNode(struct node ** root, int number){
	if(*root == NULL){
		struct node *temp = (struct node *)malloc(sizeof(struct node));
		temp -> number = number;
		temp -> next = NULL;
		*root = temp; 
		return;
	}
	addNode(&(*root)->next, number);
}

void print(struct node * root){
	struct node * temp = root;
	while(temp != NULL){
		printf("%d\n",temp->number);
		temp = temp->next;
	}
}

struct node * reverse(struct node** root){
	
	if((*root)->next == NULL){
		newRoot = *root;
		return *root;
	}
	struct node * temp = reverse(&(*root)->next);
	temp->next = (*root);
	(*root) -> next = NULL;
	return *root;
}

int main(){
	root = NULL;
	addNode(&root, 10);
	addNode(&root, 20);
	addNode(&root, 30);
	addNode(&root, 40);
	reverse(&root);
	print(newRoot);
	//printf("%d\n", newRoot->number);
}