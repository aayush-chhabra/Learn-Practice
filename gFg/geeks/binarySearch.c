# include <stdio.h>

int binarySearch(int array[], int num, int front, int rear){
	int mid = (front+rear)/2;
	if(num > array[mid])
		return binarySearch(array, num, mid+1, rear);
	else if(num < array[mid])
		return binarySearch(array, num, front, mid-1);
	else{
		return mid;
	}
}

int main(){
	int array[] = {1,2,3,4,5,6,7,8,9,10};
	int z = binarySearch(array, 3, 0, 9);
	printf("%d\n", z);
}