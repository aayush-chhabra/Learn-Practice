# include <iostream>
# define MAXLENGTH 100;

class CoordinateStack{
	private:
		int coordinate[MAXLENGTH];
		int top;
	public:
		
		CoordinateStack():top(-1){

		}

		void push(int x, int y){
			coordinate[++top] = x;
			coordinate[++top] = y;
		}

		void pop(){
			printf("(%d,%d)\n", coordinate[top-1], coordinate[top]);
			top = top - 2;
		}

		void getStack(){
			for(int i=0; i<=top; i+=2){
				printf("(%d,%d)\n", coordinate[i], coordinate[i+1]);
			}
		}
};

class CoordinateStackRestricted: public CoordinateStack{

	public:
		CoordinateStackRestricted(): CoordinateStack(){

		}

		void push(int x, int y){
			if(top>=MAXLENGTH){
				printf("stack out of bounds!!\n");
				exit(1);
			}
			CoordinateStack::push(x, y);
		}
};

int main(){

	CoordinateStack o;
	o.push(1,3);
	o.push(2,4);
	o.push(5,7);
	o.push(8,2);

	o.getStack();
	o.pop();
	o.getStack();
}