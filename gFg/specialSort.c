# include <stdio.h>


void swap(int *array, int a, int b){
	array[a] = array[a]^array[b];
	array[b] = array[a]^array[b];
	array[a] = array[a]^array[b];
}


int main(){
	int array[] = {1,2,3,4,5,0,-1,-2,-3,-4,-5}, aL = 11;
	int countOfNegative = 0;

	for(int i=0; i<aL; i++){
		if((array[i] < 0)&&(i!=0)){
			int z = i;
			for(int j=i-1; j>=countOfNegative; j--){
				swap(array, z, j);
				z--;
			}
			countOfNegative++;
		}
	}

	for(int i=0; i<aL; i++)
		printf("%d\n",array[i]);
}