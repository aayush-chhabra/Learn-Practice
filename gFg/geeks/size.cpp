# include <iostream>
using namespace std;


class a{
	int a;
	public:
		virtual int fun(){
			
		}
};

class c: public a{
	int fun(){
		printf("Hello\n");
	}
};

int main(){
	a b;
	c d;
	cout<<sizeof(b)<<sizeof(d);
}