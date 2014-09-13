# include <stdio.h>
# include <stdlib.h>

struct treeNode{
	int number;
	struct treeNode* next;
}*front, *rear;


void push(int num){
	struct treeNode* temp = (struct treeNode*)malloc(sizeof(struct treeNode));
	temp->number = num;
	temp->next = NULL;


	if((front == NULL)&&(rear == NULL)){
		front = rear = temp;
		return;
	}

	rear->next = temp;
	rear = rear->next;
}

struct treeNode* pop(){
	struct treeNode * temp;
	if(front==NULL){
		printf("Nuthing to pop..\n");
		return NULL;
	}

	if(front == rear)
	{
		temp = front;
		front = rear = NULL;
		return temp;
	}

	temp = front;
	front = front -> next;
	return temp;

}


void print(){
	struct treeNode* temp = front;
	while(temp != rear){
		printf("%d\n", temp->number);
		temp = temp->next;
	}
	//printf("%d\n", temp->number);
}

int main(){
	front = rear = NULL;
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	push(60);
	//print();
	struct treeNode* temp = pop();
	printf("%d\n",temp->number);
	struct treeNode* temp1 = pop();
	printf("%d\n",temp1->number);
	struct treeNode* temp2 = pop();
	printf("%d\n",temp2->number);
	struct treeNode* temp3 = pop();
	printf("%d\n",temp3->number);
	struct treeNode* temp4 = pop();
	printf("%d\n",temp4->number);
	struct treeNode* temp5 = pop();
	printf("%d\n",temp5->number);
}
