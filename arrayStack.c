# include <stdio.h>
# define MAX_LENGTH 30

int push(int* array, int* length, int , int number);
int pop(int* array, int* length);
void printStack(int* array, int* length);

int push(int* array, int* length, int max_length, int number){
	if(*length!=MAX_LENGTH){
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

	return 0;
}

void printStack(int* array, int* length){
	for(int i=0; i<*length; i++){
		printf("%d\t", array[i]);
	}
}

int main()
{
	int array[MAX_LENGTH], length=0;

	push(array, &length, MAX_LENGTH, 10);
	push(array, &length, MAX_LENGTH, 11);
	push(array, &length, MAX_LENGTH, 12);
	push(array, &length, MAX_LENGTH, 13);
	push(array, &length, MAX_LENGTH, 14);
	printStack(array, &length);



	int* array1,* array2,* array3;

	array1 = (array+0);
	array2 = (array + (MAX_LENGTH/3));
	array3 = (array + 2*(MAX_LENGTH/3));

	

}