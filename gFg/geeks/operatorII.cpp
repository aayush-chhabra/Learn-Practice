# include <iostream>

using namespace std;

class node{
	int number;
	public:
		node():number(0){
			cout<<"here";
		}
		node(int a): number(a){
			cout<<"here1";
		}

		node operator +(node a){
			node temp;
			temp.number = number + a.number;
			return temp;
		}

		void print(){
			cout<<number;
		}
};


int main(){
	node a(10), b(20), c;
	c = a+b;
	c.print();
}