# include <stdio.h>

void swap(int array[], int a, int b){
	array[a] = array[a]^array[b];
	array[b] = array[a]^array[b];
	array[a] = array[a]^array[b];
}

void bubbleSort(int array[], int length){
	if(length == 0)
		return;
	for(int i=0; i<length; i++){
		if(i != length-1){
			if(array[i] > array[i+1]){
				swap(array, i, i+1);
			}
		}
	}
	bubbleSort(array, length-1);
}

int main(){

	int array[] = {10,9,8,7,6,5,4,3,2,1};
	bubbleSort(array, 10);
	for(int i=0; i<10; i++)
		printf("%d\n", array[i]);
}