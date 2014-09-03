# include <stdio.h>

int multiplyRecursive(int a, int b, int answer){
	
	if(b==0) return answer;
	answer = answer+a;
	answer = multiplyRecursive(a, b-1, answer);
	return answer;

}

int main(){
	int a=10, b=5;
	int z = multiplyRecursive(a,b,0);
	printf("%d\n", z);
}