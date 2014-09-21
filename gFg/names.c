#include <stdio.h>
#include <string.h>

void sort_names(char **names, int names_length) {
    // Write your code here
    // To print results to the standard output you can use printf()
    // Example: printf("%s", "Hello world!");
    int i;
    // for(i=0; i<names_length; i++){
    //     printf("%s", names[i]);        
    // }
}

int main(){
	char names[][100] = {"Ashley Yards", "Melissa Banks", "Martin Stove", "Erika Johnson", "Robert Jones"};
	char **namess;
	namess = names;
	printf("%s\n", namess[0]);
	//printf("%s\n", names[0]);

	//sort_names(names, 5);
	return 0;
}