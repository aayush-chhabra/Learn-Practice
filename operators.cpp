# include <iostream>

class test{
	int count;

public:
	
	test(): count(0){

	}
	
	test(int c): count(c){

	}
	
	void operator += (int i){
		count+=i;
	}	

	int getCount(){
		return count;
	}
};

int main(){
	test t(10);
	t+=18;

	int z = t.getCount();

	printf("%d\n", z);
}