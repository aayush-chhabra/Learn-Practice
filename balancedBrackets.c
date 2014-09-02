#include <stdio.h>

void push(char *a, int length, char pushingElement);
void balanced_brackets(char *s);
int pop(char *a, int length);
void print(char *a, int length);

void print(char *a, int length){
	for(int i=0; i<length; i++){
		printf("%c", a[i]);
	}
	printf("\n");
}

void push(char *a, int length, char pushingElement){
	int i;
	for(i=0; a[i]!='.'; i++);
	a[i]=pushingElement;
}

int pop(char *a, int length){
	int i, temp;
	for(i=0; a[i]!='.'; i++);
	if(i==length){
		temp=a[length-1];
		a[length-1]='.';
	}
	else if(i!=0){
		temp=a[i-1];
		a[i-1]='.';	
	}
	else{
		printf("fuck you!!");
	}
	return temp;
}

void balanced_brackets(char *s) {
    // Write your code here
    // To print results to the standard output you can use printf()
    // Example: printf("%s", "Hello world!");
    char a[10];
    for(int i=0; i<10; i++){
    	a[i]='.';
    }

    // push(a, 10, 'a');
    // push(a, 10, 'b');
    // push(a, 10, 'c');
    // push(a, 10, 'd');
    // print(a, 10);
    // pop(a,10);
    // print(a, 10);
    // pop(a,10);
    // print(a, 10);
    // pop(a,10);
    // print(a, 10);

    for(int i=0; i<(sizeof(s)/sizeof(s[0])); i++){
    	if(s[i]=='(') push(a, 10, '(');
    	if(s[i]==')') pop(a,10);
    }

    print(a, 10);

    if(a[0]!='.') printf("unbalanced");
    else printf("balanced");

}



int main(){
	char a[]={'(','(',')','(',')','(',')',')'};
	balanced_brackets(a);
}