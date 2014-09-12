# include <stdio.h>
# include <stdlib.h>

struct node{
	int number;
	struct node* next;
}* front, * rear;


int add(struct node ** front, struct node ** rear, int number){
	struct node * temp = (struct node *)malloc(sizeof(struct node));
	temp -> number = number;
	temp -> next = NULL;
	if((*front == NULL)&&(*rear == NULL)){
		*front = *rear = temp;
		temp->next = temp;
		return 1;
	}
	(*rear)->next = temp;
	temp->next = *front;
	(*rear) = (*rear)->next;
	return 1;
}


int pop(struct node ** front, struct node ** rear){
	
	if((*front==NULL)&&(*rear==NULL)){
		printf("Error, Queue empty");
		return 0;
	}
	
	if(*front == *rear){
		free(*rear);
		*front = *rear = NULL;
		return 0;
	}

	struct node *temp = *front;
	while(temp->next != *rear){
		temp = temp -> next;
	}

	free(*rear);
	*rear = temp;
	(*rear)->next = *front;

	return 0;
}


void print(struct node* front, struct node* rear){
	struct node* temp = front;
	do{
		printf(" %d ", temp->number);
		temp=temp->next;
	}while(temp!=rear);
	printf(" %d ", temp->number);
	temp=temp->next;
	printf(" %d ", temp->number);
}

int main(){
	front = rear = NULL;
	add(&front, &rear, 10);
	add(&front, &rear, 20);
	add(&front, &rear, 30);
	add(&front, &rear, 40);
	print(front, rear);
	pop(&front, &rear);
	pop(&front, &rear);
	pop(&front, &rear);
	printf("\n");
	print(front, rear);
	pop(&front, &rear);
	pop(&front, &rear);
	
	
	//printf("%d %d\n", front->number ,(front->next)->number);
	
}