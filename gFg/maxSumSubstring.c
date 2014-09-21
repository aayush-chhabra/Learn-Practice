# include <stdio.h>

int max(int x, int y){
	return (x > y)?x:y;
}


int main(){
	int array[] = {-2,-3,4,-1,-2,1,5,-3};
	int maxCurrent = array[0], maxSoFar = array[0];
	for(int i=1; i<8; i++){
		maxCurrent = max(array[i], maxCurrent + array[i]);
		maxSoFar = max(maxSoFar, maxCurrent);
	}
	printf("%d\n", maxSoFar);
}