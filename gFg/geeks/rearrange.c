# include <stdio.h>

int main(){
	int a[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
	int negative = 0, positive = 0;

	for(int i=0; i<10; i++){
		if(a[i] > 0){
			positive = i;
			break;
		}
	}

	for(int i=0; i<10; i++){
		if(a[i] < 0){
			negative = i;
			break;
		}
	}

	for(int i=0 ; i<10; i++){
		if(a[i] < 0){
			if(negative!=i){
				
			}
		}
	}
}