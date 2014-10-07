# include <stdio.h>

int checkChar(char i){
	if((i>='0')&&(i<='9')){
		return 1;
	}
	return 0;
}

int main(){
	
	char a[]="-123a";
	int ans = 0, sign = 0;
	if(a[0]=='-'){	
		sign = 1;
	}

	for(int i = sign; a[i]!='\0'; i++){
		if(checkChar(a[i])){
			ans = ans*10 + (a[i] - '0');
		}
		else{
			printf("Invalid character in the string....\n");
			break;
		}
	}
	printf("%d\n", ans);
}