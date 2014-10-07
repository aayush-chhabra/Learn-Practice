# include <stdio.h>

void swap(int array[], int a, int b){
	array[a] = array[a]^array[b];
	array[b] = array[a]^array[b];
	array[a] = array[a]^array[b];
}

void selectionSort(int array[], int start, int length){
	int min = 10000, index = 0;
	if(length == start)
		return;
	for(int i=start	; i<length; i++){
		if(array[i] < min){
			//printf("%d\n", i);
			index = i;
			min = array[i];
		}
	}
	
	swap(array, index, start);
	
	selectionSort(array, start+1, length-1);
}

int main(){
	int array[] = {10,9,8,7,6,5,4,3,2,1};
	selectionSort(array, 0, 10);

	for(int i=0; i<10; i++){
		printf("%d\n", array[i]);
	}

	
}