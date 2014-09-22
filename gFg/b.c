# include <stdio.h>

int main(){
	int a[]= {1,2,3,4,5,6,7,8,9,1};
	int count = 0;

	for(int i=0; i<10; i++){
		if(!(count & (1<<a[i]))){
			count = count | (1<<a[i]);
		}
		else
		{
			printf(" Duplicate : %d %d\n", a[i], i);
		}
	}
}
