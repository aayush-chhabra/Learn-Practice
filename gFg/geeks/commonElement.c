# include <stdio.h>

int max(int a, int b, int c){
	int max = a;
	if(max<b)
		max = b;
	if(max<c)
		max=c;
	return max;
}

int main(){
	int a[]={3,5,6,9,12,17,19,20};
	int b[]={3,6,7,10,11,13,16,19};
	int c[]={3,6,7,10,11,18,19,20};

	for(int i=0, j=0, k=0; (i<8)&&(j<8)&&(k<8); ){
		int z = max(a[i], b[j], c[k]);

		if(z > a[i])
			i++;
		if(z > b[j])
			j++;
		if(z > c[k])
			k++;

		if((z==a[i])&&(z==b[j])&&(z==c[k])){

			printf("%d\n",a[i] );
			i++;j++;k++;
		}



	}

}