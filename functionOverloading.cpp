# include <iostream>

int add(int a, int b){
	return a+b;
}

int add(int a, int b, int c){
	return a+b+c;
}


int main(){
	int z = add(10, 15);
	printf("%d\n", z);
	z = add(10, 15, 25);
	printf("%d\n", z);
}