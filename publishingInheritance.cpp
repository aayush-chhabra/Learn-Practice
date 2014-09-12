# include <iostream>
# include <string.h>
class publishing{
	protected:
		char title[100];
		float price;
	public:
		publishing(): title(""), price(0){

		}
		publishing(char t[100], float p):price(p){
			strcpy(title, t);
		}
		void getData(){
			printf("%s %f\n", title, price);
		}
};

class book: public publishing{
	private:
		int pageCount;
	public:
		book(): publishing(){

		}
		book(char t[100], float p, int c): publishing(t, p), pageCount(c){

		}
		void getData(){
			printf("Book: %s %f %d\n", title, price, pageCount);
		}
};


class tape: public publishing{
	private:
		int length;
	public:
		tape(): publishing(){

		}
		tape(char t[100], float f, int l): publishing(t, f), length(l){

		}
		void getData(){
			printf("Tape : %s %f %d \n", title, price, length);
		}
};

int main(){
	tape a("aayush", 10.5, 10);
	book b("aayush", 10.5, 10);
	a.getData();
	b.getData();
}