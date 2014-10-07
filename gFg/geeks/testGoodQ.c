# include <stdio.h>

int max(int a, int b){
	return (a>b)?a:b;
}

int array(int a1[], int a2[], int i, int j){
	
	int Smax = 0;

	if((i>=8)||(j>=8))
		return Smax;

	for( ; (i<8)&&(j<8) ; ){
		if(a1[i] < a2[j]){
			printf("%d %d\n",i,j);
			i++;
		}
		else if(a1[i] > a2[j]){
			j++;
		}
		else{
			Smax += max(array(a1, a2, i+1, j+1),array(a2, a1, j+1, i+1));
		}
	}
	return Smax;
}

int main(){
	int ar1[]  = {2, 3, 7, 10, 12, 15, 30, 34};
    int ar2[] =  {1, 5, 7, 8, 10, 15, 16, 19};

    int z = array(ar1, ar2, 0, 0);

    printf("%d\n", z);




}