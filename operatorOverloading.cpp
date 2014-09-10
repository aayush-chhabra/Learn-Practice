# include <iostream>


class binaryOperator{
	private:
		int count;
	public:
		binaryOperator(): count(0){

		}
		binaryOperator(int c): count(c){

		}
		binaryOperator operator + (binaryOperator b){
			return binaryOperator(count + b.count);
		}
		void get(){
			printf("%d\n", count);
		}
};

int main(){
	binaryOperator b1(5), b2(10);
	b1 = b1 + b2;
	b1.get();
}



// class operatorOverload{
// 	private:
// 		int count;
// 	public:
// 		operatorOverload(): count(0){

// 		}

// 		operatorOverload operator ++(int){
// 			++count;
// 			operatorOverload temp;
// 			temp.count = count;
// 			return temp;
// 		}

// 		void get(){
// 			printf("%d\n", count);
// 		}
// };

// int main(){

// 	operatorOverload o;
// 	o = o++;
// 	o.get();
// 	return 0;
// }



// class operatorOverloadTest{
// 	private:
// 		int count;
// 	public:
// 		operatorOverloadTest():count(0){

// 		}

// 		void operator ++ (){
// 			++count;
// 		}

// 		void get(){
// 			printf("%d\n", count);
// 		}
// };

// int main(){
// 	operatorOverloadTest obj1;
// 	++obj1;
// 	++obj1;
// 	++obj1;
// 	++obj1;

// 	obj1.get();

// }