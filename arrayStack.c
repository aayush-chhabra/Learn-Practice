# include <stdio.h>
# define MAX_LENGTH 30


int push(int* array, int* length, int max_length, int number, int* min_array, int* min_array_length){
	if(*length!=MAX_LENGTH){
		array[*length] = number;
		(*length)++;
		if(number < min_array[*min_array_length]){
			//printf(" Number less than the list  : %d\n",number);
			++(*min_array_length);
			min_array[*min_array_length] = number;
			printf("Here: I add the numbers to the stack: %d %d\n", min_array[*min_array_length], *min_array_length);
		}
	}
	else
		printf("pehle pop kar chutiye");

	return 0;
}

int pop(int* array, int* length, int* min_array, int* min_array_length){
	int z;
	if(*length!=0){
		z = array[*length];
		if(z==min_array[*min_array_length]){
			min_array[*min_array_length]=0;
			--(*min_array_length);
		}
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
	for(int i=0; i<=*length; i++){
		printf("%d\t", array[i]);
	}
}


int printMin(int *array, int* length){
	//find minimum in O(1)
	return 0;
}


int main()
{
	int array[MAX_LENGTH], length=0;
	int min_array[MAX_LENGTH], min_array_length=0;
	min_array[min_array_length] = 1000;

	push(array, &length, MAX_LENGTH, 10, min_array, &min_array_length);
	push(array, &length, MAX_LENGTH, 11, min_array, &min_array_length);
	push(array, &length, MAX_LENGTH, 12, min_array, &min_array_length);
	push(array, &length, MAX_LENGTH, 13, min_array, &min_array_length);
	push(array, &length, MAX_LENGTH, 14, min_array, &min_array_length);
	push(array, &length, MAX_LENGTH, 8, min_array, &min_array_length);


	printStack(min_array, &min_array_length);



	//one array three stacks
	// int* array1,* array2,* array3;
	// int l1=0, l2=0, l3=0;

	// array1 = (array+0);
	// array2 = (array + (MAX_LENGTH/3));
	// array3 = (array + 2*(MAX_LENGTH/3));

	// push(array1, &l1, MAX_LENGTH/3 , 14);
	// push(array2, &l2, MAX_LENGTH/3 , 14);
	// push(array3, &l3, MAX_LENGTH/3 , 14);
	// printStack(array1, &l1);
	// printStack(array1, &l1);
	// printStack(array1, &l1);
	// printStack(array2, &l2);
	// printStack(array3, &l3);
	//printf("%d %d %d\n", l1, l2, l3);

}