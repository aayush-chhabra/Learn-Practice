# include <stdio.h>
# include <string.h>

int main(){
	char str[]={"Aayush"};
	//printf("%s\n",str);
	int length=strlen(str);
	for(int i=0, j=length-1; i<length/2; i++, j--){
		str[i]=str[i]^str[j];
		str[j]=str[i]^str[j];
		str[i]=str[i]^str[j];
	}
	printf("%s\n",str);
}