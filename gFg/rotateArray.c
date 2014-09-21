# include <stdio.h>

void rotateArray(int array[10], int rotationIndex){
	int temp;
	for(int j=0; j<rotationIndex;j++){
		temp = array[0];
		for(int i=0; i<8; i++){
			printf("%d\n", temp);
			array[i] = array[i+1];
		}
		array[8-j] = temp;
		printf("Here I am: %d\n", array[8-j]);	
	}
}

int main(){
	int array[] = {2,5,9,1,4,76,43,21,16};
	rotateArray(array, 3); 

	for (int i = 0; i < 9; ++i)
	{
		printf(" %d ",array[i]);
	}
}