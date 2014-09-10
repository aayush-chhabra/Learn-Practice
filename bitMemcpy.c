# include <stdio.h>

int traverse(int array[3][3], int row, int col, int* count){
	
	if((row == 0)&&(col==0)){
		*count = 1 + *count;
		return 0;
	}

	if(row>=1)
		return traverse(array, row-1, col, count);

	if(col>=1)
		return traverse(array, row, col-1, count);


}


int main(){
	int array[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	int row = 3, col = 3, count = 0;
	int z = traverse(array, row, col, &count);

	printf("%d\n", z);
}