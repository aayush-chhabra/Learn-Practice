# include <iostream>

class test{
	

public:
	test(){
		this(0,0);	
	}
	test(int a){
		this(a,0);
	}
	test(int a, int b){
		std::cout<<a<<b;
	}
};

int main(){
	test t;
}