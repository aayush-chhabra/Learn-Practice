# include <stdio.h>
# include <string.h>

int main(){

	char a[100]={"aaaabcccd"}, b=1;
	int length = strlen(a);

	for(int i=0; i<length; i++){
		if(a[i]==a[i+1]){
			b++;
		}
		else
		{
			printf("%c - %d", a[i], b);
			b=1;
		}
	}

	printf("%s\n", a);
}