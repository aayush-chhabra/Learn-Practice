# include <stdio.h>

int main(){
	int a[]={3,5,6,9,12,17,19};
	int b[]={3,6,7,10,11,13,16};

	for(int i=0, j=0; (i<7)&&(j<7); ){
		if(b[j]>a[i]){
			i++;
		}
		else if(b[j]<a[i]){
			printf("%d\n", b[j]);
			j++;
		}
		else
		{
			i++;j++;
		}
	}
}