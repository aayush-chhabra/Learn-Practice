# include <stdio.h>
# include <stdlib.h>

struct node{
	int value;
	struct node* next;
}*ptr;

int delete1(int value);
int insertIntoLL(struct node *temp);
void printLL();
int calculateLength();


int calculateLength(){
	struct node *runner = ptr;
	//printf(" %d --> ", runner->value);
	int count=0;
	while(runner!=NULL){
		count++;
		runner=runner->next;
	}
	return count;
}


int delete1(int value){
	struct node* runner = ptr;
	int count = 0;
	while(runner!=NULL){
		count+=1;
		if(runner->value == value){
			break;
		}
		runner=runner->next;
	}
	runner=ptr;
	// printf("This is the position of the element : %d\n", count);
	for(int i=1; i<(count-1); i++){
		runner=runner->next;
	}
	runner->next = runner->next->next;
}

int insertIntoLL(struct node *temp){
	if(ptr==NULL){
		ptr=temp;
		return 1;
	}
	struct node *runner = ptr;
	while(runner->next!=NULL)
		runner=runner->next;
	runner->next = temp;
	temp->next=NULL;
	return 1;
}

void printLL(){
	struct node *runner = ptr;
	//printf(" %d --> ", runner->value);
	while(runner!=NULL){
		printf(" %d --> ", runner->value);
		runner=runner->next;
	}
}

int main(){
	// struct node *ptr1;
	
	ptr = NULL;

	for(int i=1; i<=10; i++){
		struct node *temp = (struct node*)malloc(sizeof(struct node*));
		temp -> value=i;
		temp -> next=NULL;
		insertIntoLL(temp);
	}

	struct node *temp = (struct node*)malloc(sizeof(struct node*));
	temp -> value=4;
	temp -> next=NULL;
	insertIntoLL(temp);

	struct node *temp1 = (struct node*)malloc(sizeof(struct node*));
	temp1 -> value=11;
	temp1 -> next=NULL;
	insertIntoLL(temp1);
	
	
	// struct node *runner1, *runner2;
	// runner1 = runner2 = ptr;

	// while(runner1!=NULL){
	// 	runner2 = runner1->next;
	// 	while(runner2!=NULL){
	// 		if(runner1->value==runner2->value){
	// 			delete1(runner2->value);
	// 			runner2=runner2->next;
	// 		}
	// 		runner2=runner2->next;
	// 	}
	// 	runner1=runner1->next;
	// }
	struct node * runner = ptr;
	int length = calculateLength();
	
	int k = 4;

	length = length-k+1;

	// printf("Lenght : %d", length);
	// printLL();

	while(length!=0){
		runner = runner->next;
		length-=1;
	}

	printf("%d\n", runner->value);
	printLL();
}