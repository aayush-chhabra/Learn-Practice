# include <iostream>
using namespace std;


class node{
	
	int number[10];
	public:
	node(){
		cout<<"In the First Constructor\n\n";
	}
	
	node(int a){
		cout<<"In the Second Constructor"<<a;
	}

	int& operator [](int n){
		return number[n];
	}

	void print(){
		cout<<number[0]<<endl;
		cout<<number[1]<<endl;
		cout<<number[2]<<endl;
		cout<<number[3]<<endl;
		cout<<number[4]<<endl;
	}

};

int main(){
	node a;
	a[0] = 10;
	a[1] = 20;
	a[2] = 30;
	a.print();
}