# include <stdio.h>

int main(){
	int a[] = {2,3,7,8,8,12}, aL = sizeof(a)/sizeof(int);
	int b[] = {7,8}, bL = sizeof(b)/sizeof(int);
	int i, j, k;

	int c[20];

	for(i=0, j=0, k=0 ;			 ; ++k){
		
		if((i >= aL-1)&&(j >= bL-1))
			break;
		else if(j >= bL-1){
			c[k] = a[i];
			i++;
			continue;
		}
		else if(i >= aL-1){
			c[k] = b[j];
			j++;
			continue;	
		}

		if(a[i]<b[j]){
			c[k] = a[i];
			i++;
		}
		else if(a[i] > b[j]){
			c[k] = b[j];
			j++;
		}

		else{
			c[k] = b[j];
			c[++k] = b[j];
			j++;i++;	
		}
	}

	for(i=0; i<=k; i++){
		printf("%d ",c[i]);
	}
}