# include <stdio.h>
# include <stdlib.h>

struct node{
	int a;
	struct node* next;
}*root, *root1;

void addNode(int n){
	
	if(root == NULL){
		struct node* temp = (struct node*) malloc(sizeof(struct node));
		temp->a = n;
		temp->next = NULL;
		root=temp;
		return;
	}
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	temp->a = n;
	temp->next = NULL;
	struct node* temp1 = root;
	while(temp1->next!=NULL){
		temp1=temp1->next;
	}
	temp1->next = temp;
}

void print(){
	struct node* temp;
	temp = root1;
	while( temp != NULL ){
		printf("%d\n", temp->a);
		temp=temp->next;
	}
}


struct node* reverse(struct node* root){
	struct node* temp = root;
	if(temp->next==NULL){
		root1 = temp;
		return temp;
	}
	//printf("%d", temp->a);
	struct node* t1 = reverse(temp->next);
	t1->next = temp;
	temp->next = NULL;
	return temp;

}

int main(){
	root = NULL;
	addNode(10);
	addNode(3);
	addNode(5);
	addNode(8);
	addNode(2);
	addNode(1);

	reverse(root);

	//printf("%d\n", (root->next)->a);

	print();

}