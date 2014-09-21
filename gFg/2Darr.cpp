# include <iostream>

int main(){
	int* array[10];
	
	array[0] = new int[10];
	*(array[0]) = 0;
	*(array[0]+1) = 10;
	*(array[0]+2) = 12;


	printf("%d\n", *(array[0]+1));
}