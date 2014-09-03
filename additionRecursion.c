# include <stdio.h>

int addrecursion(int a, int b){
	if(b==0) return a;
	a+=1;
	a = addrecursion(a, b-1);	
	return a;
}


int main(){

	int a=10, b=5;

	int z = addrecursion(a,b);
	printf("%d", z);


}