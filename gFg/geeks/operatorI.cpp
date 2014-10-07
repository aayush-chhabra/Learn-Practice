# include <iostream>

using namespace std;

class node{
	int number;
	public:
		node():number(0){
			cout<<"constructor 1\n";
		}
		node(int a): number(a){
			cout<<"constructor 2\n";	
		}
		int operator < (node b){
			return (number < b.number);
		}
};

int main(){
	node a(10), b(20);
	int z = a<b;
	cout<<a<b;
}