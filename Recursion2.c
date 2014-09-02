// Given a string, compute recursively a new string where identical chars that are adjacent 
//in the original string are separated from each other by a "*". 

// pairStar("hello") → "hel*lo"
// pairStar("xxyy") → "x*xy*y"
// pairStar("aaaa") → "a*a*a*a"



#include <stdio.h>
#include <string.h>

char* allStar(char* str){
	int len = strlen(str);

	if(len==0) return "";

	if(len>=2){
		if(str[0] == str[1]){
			strcat(str[0] + "*");
			return strcat allStar(str+1);
		}
 	}

 	return str[0] + allStar(str+1);

}

int main(){
	char a[]= {'h','e','l','l','o'};
	allStar(a);
}