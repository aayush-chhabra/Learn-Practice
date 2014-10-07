# include <stdio.h>
#include <string.h>

int main(){
	char a1[100] = "Aayush Chhabra";
	char *a = a1;
	char *b;
	b=a;
	//memcpy(b,a,10);
	//strcpy(b,a);
	printf("%s\n",b	);
}