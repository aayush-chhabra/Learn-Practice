# include <stdio.h>


int seriesSum(int value, int sum){
	if(value==0) return sum;
	if((value%3==0)||(value%5==0)) sum+=value;
	value = seriesSum(value-1, sum);
	return value;

}

int main(){
	int z = seriesSum(10, 0);
	printf("%d\n", z);
}