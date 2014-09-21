# include <iostream>

class const1
{
private:
	int a;
public:
	const1():a(0){}
	
	const int& changeVal(){
		return a;
	}	

	void print(){
		std::cout<<this->a;
	}
};



int main(){

	const1 a1;
	a1.changeVal() = 10;
	a1.print();
	//*z = 10;
	//std::cout<<z;
}