# include <iostream>
# include <string.h>

using namespace std;

class String{
	char *array;
	public:
		String():array(NULL){

		}
		String(char * string){
			array = (char *)malloc(strlen(string)*sizeof(char));
			strcpy(array, string);
		}

		~String(){
			cout<<"Feeing the memory too";
			free(array);
		}

		void operator = ( char * string){
			array = (char *)malloc(strlen(string)*sizeof(char));
			strcpy(array, string);
		}

		String operator + (char * str){
			char * tempArray = (char *)malloc(sizeof(array) + (strlen(str)*sizeof(char)) );
			strcpy(tempArray, array);
			strcat(tempArray, str);
			return tempArray;
		}

		int length(){
			return strlen(array);
		}

		void getString(){
			printf("%s\n", array);
		}

};


int main(){
	String a("Aayush");
	
	String s = a + " Chhabra";

	int z = s.length();
	printf("%d\n", z);
	s.getString();

}