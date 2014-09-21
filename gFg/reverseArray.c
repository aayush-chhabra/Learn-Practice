# include <stdio.h>

void reverse(int array[10], int start, int end){
	
	if(start >= end)
		return;

	array[start] = array[start] ^ array[end];
	array[end] = array[start] ^ array[end];
	array[start] = array[start] ^ array[end];

	reverse(array, start+1, end-1);
}


int main(){
	int array[]={2,5,9,1,4,76,43,21,16};

	reverse(array, 0, 8);

	for(int i=0; i<9; i++)
		printf("%d\n", array[i]);

}