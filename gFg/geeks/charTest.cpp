# include <iostream>

using namespace std;

int main(){
	char a[]={'9','a'};
	cout<<(int)a[0];
	if(a[0]<66)
		cout<<"its and alpha";
	else
		cout<<"less than an alpha";
}