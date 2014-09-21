# include <stdio.h>

int main(){
	char a[] = {'e','n','g','g','n','e'};
	int b = 0;
	int size = sizeof(a)/sizeof(char);

	for(int i=0; i<size-1; i++){
		b = b^a[i];
	}
	printf("%d\n", b);
}