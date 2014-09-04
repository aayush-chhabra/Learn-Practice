# include <stdio.h>
# include <string.h>

int main(){
	
	char a[]="aayyuusshh";
	int sum=0;
	int length = strlen(a);
	//printf("%d\n", length);

	for(int i=0; i<length; i++){
		sum = sum^a[i];
	}

	printf("%d\n", sum);
}