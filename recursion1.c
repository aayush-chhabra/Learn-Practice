# include <stdio.h>
#include <string.h>

char* reverse (char* str, int length){
	
	
	if(length > 0) {

		char temp;
		temp = str[0];		
		str[0] = str[length-1];
		str[length-1] = str[0];
		reverse(str + 1, length-2);

	}

	

//	return str;
}


int main(){
	char a []= {'a','a','y','u','s','h'};
	reverse(&a, 6);
	
}

