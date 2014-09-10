# include <iostream>

class countBase{
	protected:
		int count;
	public:
		countBase(): count(0){

		}
		countBase(int c): count(c){

		}
		void getCount(){
			printf("%d\n", count);
		}
		void operator ++(){
			count++;
		}
};

class countDerived : public countBase{
	public:
		countDerived(): countBase(0){

		}
		countDerived(int c): countBase(c){

		}
		void operator --(int){
			count--;
		}
};

int main(){

	countDerived o(18);
	o.getCount();
	++o;
	o.getCount();
	o--;
	o.getCount();
}