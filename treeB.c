# include <stdio.h>
# include <stdlib.h>

struct node{
	int number;
	struct node* next;
}*root;


struct linkedList{
	struct node value;
};


int lengthOfQ = 0;

void push(int num){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->number = num;
	temp->next = NULL;

	if(lengthOfQ == 9)
		printf("POP\n");

	else{
		array[lengthOfQ] = temp;
		lengthOfQ++;
	}
}

struct node* pop(){
	struct node* temp = array[0];
	for(int i=1; i<lengthOfQ; i++){
		array[i-1] = array[i];
		lengthOfQ--;
	}
	return temp;
}


void print(){
	for(int i=0; i<lengthOfQ; i++){
		printf("%d\n", array[i]->number);
	}
}

int main(){
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	push(60);
	//print();
	struct node* temp = pop();
	pop();
	pop();
	pop();
	pop();
	print();
}
