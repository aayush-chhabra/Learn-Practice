# include <iostream>

using namespace std;

class base{
	int a;
	public:	
		base():a(0){
			cout<<"Base 0";
		}
		base(int a1): a(a1){
			cout<<"Base 1";
		}
		virtual int helo(){

		}
};

class derived : public base {
	int b;
	public:
		derived():b(0){
			cout<<"Derived 0";
		}
		derived(int b1):b(b1), base(b1){
			cout<<"Derived 1";
		}
};

bool isDerived(base * unknown){
	derived * d;
	if( d = dynamic_cast<derived *>(unknown) ){
		cout<<typeid(*unknown).name();
		return true;
	}
	return false;
}

int main(){
	derived a(10);
	base * b1 = &a;
	cout<<"\nHello this is the result"<<isDerived(b1);
}