# include <stdio.h>

int main(){
	int array[] = {2,5,9,1,4,76,43,21,16}, array1[10], length = 0;
	int size = sizeof(array)/sizeof(int);
	int max = array[size-1];
	array1[length] = max;
	length++;
	for(int i = size-1; i>=0; i--){
		if(array[i] > max){
			printf("here: %d\n",array[i]);
			max = array[i];
			array1[length] = array[i];
			length++;
		}
	}

	for (int i = 0; i < length; ++i)
	{
		/* code */
		printf("%d\n",array1[i]);
	}
	
}