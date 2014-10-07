# include <stdio.h>

int main(){
	int a[]= {1,2,3,4,5,6,8,9,10};
	int count = 1;
	for(int i=0; i<9; i++){
		if(count < a[i]){
			printf("%d\n", count);
			break;
		}
		count++;
	}
}