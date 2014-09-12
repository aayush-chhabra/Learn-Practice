# include <iostream>

using namespace std;

class Base
{
protected:
	int count;
public:
	Base():count(0){
		printf("Called\n");
	}
	~Base(){
		cout<<"Destructing";
	}

	virtual void print() = 0;
	
};

class Derived: public Base
{
private:
	int countD;
public:
	Derived():countD(10){

	}
	// void print(){
	// 	printf("%d\n", countD);
	// }
	
};

class Derived1: public Base
{
private:
	int countD1;
public:
	Derived1():countD1(20){

	}
	void print(){
		printf("%d\n", countD1);
	}
	
};


int main(){
	Derived d1;
	Derived1 d2;
	
	Base *b ;
	
	// b = &d1;
	// b->print();
	// b = &d2;
	// b->print();
}