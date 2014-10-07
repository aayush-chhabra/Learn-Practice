# include <stdio.h>

struct node{
	int a;
	
};

int main(){
	for(int i=1; i<=20; i++){
		if((i%3==0)&&(i%5==0)){
			printf("FizzBuzz\n");
			continue;
		}
		if(i%3==0)
			printf("Fizz\n");
		else if(i%5==0)
			printf("Buzz\n");
		else
			printf("%d\n", i);
	}
}