# include <stdio.h>

void swap(char array[], int a, int b){
	array[a] = array[a] ^ array[b];
	array[b] = array[a] ^ array[b];
	array[a] = array[a] ^ array[b];
}

int reverse(char a[], int len){
	if(a[len] == '\0'){
		//printf("%d\n", len);
		return 0;
	}

	int z = reverse(a, len+1);
	//printf("%d %d\n", z, len);
	if(z >= len){
		return ++z;
	}
	swap(a, z, len);
	return ++z;
}

int main(){
	char a[]="aayush";
	//swap(a,0,6);
	reverse(a,0);
	printf("%s\n", a);
}