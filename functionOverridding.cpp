# include <iostream>

class Stack{
	protected:
		int stack[10];
		int top;
	public:
		Stack():top(-1){

		}
		void push(int num){
			stack[++top] = num;
		}
		void pop(){
			--top;
		}
};

class StackImproved: private Stack{
	public:
		void push(int num){
			if(top>=10){
				printf("Stack full\n");
				exit(1);
			}
			Stack::push(num);
		}

};

int main(){
	StackImproved o;
	o.pop();

}