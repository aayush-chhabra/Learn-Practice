# include <iostream>

using namespace std;

void pushStack(int array[10], char chara, int* length);
int pop(int array[10], int *length);

int main(){
	char a[] = {'2','1','+','3','*'};
	int arr[10];
	int length = 0, sum = 0;
	int lengthOfCharArray = sizeof(a)/sizeof(char);
	//printf("%d\n", lengthOfCharArray);
	for(int i=0; i<lengthOfCharArray; i++){
		int z = a[i] - '0';
		if((z>=0)&&(z<=9)){
			pushStack(arr, a[i], &length);
		}
		else{
			int a1 = pop(arr, &length);
			int b = pop(arr, &length);
			printf("%d %c %d\n",a1 - '0', a[i], b - '0');
		}

	}
}


int pop(int array[10], int *length){
	if(*length >= 0){

		int z = array[*length-1];
		array[*length] = -1;
		(*length)--;
		return z;
	}
	else{
		printf("Hadd ho gayi hai lund, chutiyapa ki\n");
	}
}


void pushStack(int array[10], char chara, int* length){
	if(*length <= 9){
		array[*length] = chara;
		(*length)++;	
	}
	else
	{
		printf("Fuck you !!\n");
	}
}
