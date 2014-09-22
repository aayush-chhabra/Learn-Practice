# include <iostream>

using namespace std;

class objects{
	
	protected:
		int number;

	public:
		
		objects():number(0){

		}
		
		objects(int n):number(n){

		}
		
		void getNumber(){
			printf("%d\n", number);
		}

		void incrementNumber(){
			++number;
		}
};


class fobjects: public objects{
	
	
	public:
		
		// fobjects():objects(){

		// }

		// fobjects(int n):objects(n){

		// }

		void decrement(){
			--number;
		}
};

int main(){
	fobjects o1(10);
	o1.getNumber();
	// fobjects o2(10);
	// o2.getNumber();
	// o2.decrement();
	// o2.getNumber();
	// o2.incrementNumber();
	// o2.getNumber();
}