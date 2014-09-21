# include <iostream>


class Singelton{
private:
	int a1;
	
	Singelton():a1(18){

	}

	//Singelton a;
public:
	Singelton static getObject(){
		return Singelton();
	} 
};

int main(){

}