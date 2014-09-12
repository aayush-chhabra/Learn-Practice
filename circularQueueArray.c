# include <stdio.h>
# define MAXLENGTH 10

int addToQ(int circularQ[MAXLENGTH], int* front, int* rear, int number){
	//printf("%d", *rear);
	if(*rear >= MAXLENGTH){
		printf("fuck you!!");
		return 0;
	}

	if(*rear == MAXLENGTH-2){
		
		*rear = *rear + 1;
		circularQ[*rear] = number;
		*rear = *rear + 1;
		return 0;
	}

	if((*front == 0)&&(*rear == -1)){
		*rear = *rear + 1;
		circularQ[*rear] = number;
		return 0;
	}
	*rear = *rear + 1;
	circularQ[*rear] = number;	
	return 0;
}


void pop(int circularQ[MAXLENGTH], int* front, int* rear){
	
	if(*front!=*rear){
		//printf("%d", circularQ[*front]);
		for(int i=0; i<*rear; i++){
			circularQ[i]=circularQ[i+1];
		}
		(*rear)--;
	}

	if(*front==*rear){
		printf("%d\n", circularQ[*front]);
		*front = 0;
		*rear = -1;
	}
	


}

void print(int circularQ[MAXLENGTH], int front, int rear){
	for(int i = front; i< rear; i++){
		printf("%d\n", circularQ[i]);
	}
}


int main(){
	int circularQ[MAXLENGTH];
	int front, rear;
	front = 0; 
	rear = -1;

	addToQ(circularQ, &front, &rear, 10);
	addToQ(circularQ, &front, &rear, 20);
	addToQ(circularQ, &front, &rear, 30);
	addToQ(circularQ, &front, &rear, 40);
	addToQ(circularQ, &front, &rear, 50);
	addToQ(circularQ, &front, &rear, 60);
	addToQ(circularQ, &front, &rear, 70);
	addToQ(circularQ, &front, &rear, 80);
	addToQ(circularQ, &front, &rear, 90);
	addToQ(circularQ, &front, &rear, 100);
	print(circularQ, front, rear);
	pop(circularQ, &front, &rear);
	pop(circularQ, &front, &rear);
	pop(circularQ, &front, &rear);
	pop(circularQ, &front, &rear);
	pop(circularQ, &front, &rear);
	pop(circularQ, &front, &rear);
	pop(circularQ, &front, &rear);
	pop(circularQ, &front, &rear);
	pop(circularQ, &front, &rear);
	pop(circularQ, &front, &rear);
	printf("\n");
	print(circularQ, front, rear);


}