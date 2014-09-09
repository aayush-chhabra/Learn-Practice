# include <stdio.h>
 
int main(){
	int a = 0, count = 0;
	a = ~a;
	//a = a & 1<<31;
	// while(a)
	// {
	// 	if(a&1){
	// 		a=a>>1;
	// 		count++;

	// 	}
	// 	a=a>>1;
	// }
	printf("%d\n", a);
}