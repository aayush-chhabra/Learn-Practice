# include <stdio.h>
# include <stdlib.h>

void sqrtz(int number){
	int z = number, flag, absolute, previous = 10000, prevAbsolute;

	do{
		flag = z / 2;
		//printf("%d\n", flag);
		absolute = abs(flag*flag - number);
		//printf("%d\n", absolute);
		prevAbsolute = abs(previous*previous - number);
		//printf("%d\n", prevAbsolute);
		if(prevAbsolute > absolute){
			//continue;
		}
		else{
			break;
		}
		previous = flag;
		z = z/2;
	}while(1);

	printf("%d\n", previous);
}

int main(){
	sqrtz(65);
	return 0;
}