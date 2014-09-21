# include <stdio.h>
# include <stdlib.h>



void merge(int a[10]){
	int l=0, r=5, absolute, totalAbsolute = 10000;
	while(l < r){
		absolute = a[l]+a[r];
		printf("Abs : %d\n", absolute );
		if(abs(absolute)<totalAbsolute)
			totalAbsolute = absolute;	
		if(absolute < 0){
			l++;
		}
		else if(absolute > 0){
			r--;
		}
		else{
			printf("%d, %d\n", a[l], a[r]);
		}

	}
	printf("%d\n", totalAbsolute);
}



int main(){
	int a[] = {-80, -10, 1, 60, 70, 85};
	merge(a);
	
}