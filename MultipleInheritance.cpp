# include <iostream>

using namespace std;

class Base{
public:
	void show(){
		cout<<"Base\n";
	}
};

class D1: virtual public Base{

};

class D2: virtual public Base{

};

class GC: public D1, public D2{
public:
	// void show(){
	// 	cout<<"GC\n";
	// }
};

int main(){

	GC a;
	a.show();



}