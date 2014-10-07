# include <iostream>
using namespace std;

class node {
	char * a;
	public:
		node(){
			a=NULL;
		}
		node(char a1[]){
			int size = sizeof(a1)/sizeof(char);
			a = new char[size];
			strcpy(a, a1);
		}

		~node(){
			delete [] a;
		}

		void print(){
			cout<<a;
		}
};

void helll(node a){
	node b(a);
}

int main(){
	node a("Hello");
	helll(a);
	a.print();
}