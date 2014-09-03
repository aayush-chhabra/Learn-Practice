# include <stdio.h>

int fibonacciSlave(int a, int b, int n)
 { if(n <= 1) return b;
   /*else*/
   return fibonacciSlave(b, a+b, n-1);
 }

int fibonacci(int n)
 { return fibonacciSlave(0, 1, n); }

/* O(n) time Fibonacci Function */


int main(){
	int z = fibonacci(20);
	printf("%d\n", z);
}