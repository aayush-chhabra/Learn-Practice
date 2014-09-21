// program to find the inversions in an array.

# include <stdio.h>


void countInversions(int array[10]){
	int count = 0;
	for(int i=0; i<5; i++){
		for(int j=i+1; j<5; j++){
			if(array[i] > array[j]){
				count++;
				printf("(%d, %d)\n",array[i], array[j]);
			}

		}
	}
	//printf("%d\n", count);
}

int main(){
	int array[]= {2, 4, 1, 3, 5};
	countInversions(array);
}