# include <stdio.h>

int push(int array[][20], int* row, int* col, int number){
	if((*row == 9)&&(*col == 19)){
		printf("Bahut Maa chuda li tune, bus kar le ab");
	}
	if(*col == 19){
		++(*row);
		(*col) = 0;
	}
	array[*row][*col] = number;
	(*col)++;
	return 0;
}

int pop(int array[][20], int* row, int* col){
	if((*row == 0)&&(*col == 0)){
		printf("Kitna chutiya hai yaar tu :D\n");
	}
	int z = array[*row][*col];
	array[*row][*col] = 0;
	if(*col != 0){
		--(*col);
	}
	else{
		--(*row);
		*col = 19;
	}
	//array[row][col] = number;
	return 0;
}

void printStack(int array[][20], int row, int col){
	for(int i=0; i<=row; i++){
		for(int j=0; j<=19; j++){
			printf("%d\t",array[i][j]);
		}
		printf("\n");
	}
}




int main(){
	int array[10][20];
	int r=0, c=0;
	push(array, &r, &c, 1);
	push(array, &r, &c, 2);
	push(array, &r, &c, 3);
	push(array, &r, &c, 4);
	push(array, &r, &c, 5);
	push(array, &r, &c, 6);
	push(array, &r, &c, 7);
	push(array, &r, &c, 8);
	push(array, &r, &c, 9);
	push(array, &r, &c, 10);
	push(array, &r, &c, 14);
	push(array, &r, &c, 15);
	push(array, &r, &c, 10);
	push(array, &r, &c, 11);
	push(array, &r, &c, 12);
	push(array, &r, &c, 13);
	push(array, &r, &c, 14);
	push(array, &r, &c, 15);
	push(array, &r, &c, 10);
	push(array, &r, &c, 11);
	push(array, &r, &c, 12);
	push(array, &r, &c, 13);
	push(array, &r, &c, 14);
	push(array, &r, &c, 15);

	printStack(array, r, c);
}