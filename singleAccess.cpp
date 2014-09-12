# include <iostream>

using namespace std;

class test{
	private:
	int array[10];



	public:

		test(){
			for(int i=0; i<10; i++){
				array[i] = i;
			}
		}

		int& operator [](int n){
			if((n<0)||(n>9))
				printf("Fuck you !!\n");

			return array[n];
		}

		void print(){
			for(int i=0; i<10; i++){
				cout<<array[i];
			}	
		}

};

int main(){
		test t1;

		t1[0] = 56;


		t1.print();

}