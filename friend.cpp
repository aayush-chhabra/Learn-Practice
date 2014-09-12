# include <iostream>

using namespace std;

class beta;

class alpha{
	int aplhaCount;
	public:
		alpha(): aplhaCount(0){

		}
		alpha(int a): aplhaCount(a){

		}
		void show(){
			cout<<aplhaCount;
		}
		friend int addTwoClasses(alpha a, beta b);
};

class beta{
	int betaCount;
	public:
		beta(): betaCount(0){
			
		}
		beta(int a): betaCount(a){

		}
		void show(){
			cout<<betaCount;
		}
		friend int addTwoClasses(alpha a, beta b);	
};

int addTwoClasses(alpha a, beta b){
	return a.aplhaCount + b.betaCount;
}

int main(){
	alpha a(10);
	beta b(20);

	int z = addTwoClasses(a, b);

	cout<<z;

}