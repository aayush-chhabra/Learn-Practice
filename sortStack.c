# include <stdio.h>
# define MAX_LENGTH 20




int push(int* array, int* length, int max_length, int number){
	if(*length!=MAX_LENGTH-1){
		array[*length] = number;
		(*length)++;
	}
	else
		printf("pehle pop kar chutiye");

	return 0;
}

int pop(int* array, int* length){
	int z;
	if(*length!=0){
		z = array[*length];
		array[*length] = 0;
		(*length)--;
	}
	else
	{
		printf("Pehle kuch daal to chutiye");
	}

	return z;
}

void printStack(int* array, int* length){
	for(int i=0; i<*length; i++){
		printf("%d\t", array[i]);
	}
}

int sort(int* array, int length){
	int n;
	if(length==0) return array[length];
	n=pop(array, &length);
	int z = sort(array+1, length-1);
	if(n>z){
		int x = pop(array, &length);
		push(array, &length, MAX_LENGTH,n);
		sort(array, length);
	}
	push(array, &length, MAX_LENGTH, z);
	return n;
}


int main(){

	int array[MAX_LENGTH], length=0;

	push(array, &length, MAX_LENGTH, 10);
	push(array, &length, MAX_LENGTH, 12);
	push(array, &length, MAX_LENGTH, 11);
	push(array, &length, MAX_LENGTH, 15);
	push(array, &length, MAX_LENGTH, 3);
	push(array, &length, MAX_LENGTH, 8);


	printStack(array, &length);

	sort(array, length);

}