# include <iostream>

using namespace std;

class TollBooth{
	private:
		int carCount;
		double totalAmount;	
	public:
		TollBooth(): carCount(0), totalAmount(0){

		}

		void payingCar(double amt){
			totalAmount += amt;
			carCount++;
		}
		
		void nonPayingCar(){
			carCount++;
		}

		void getCarAndCollectionCount(){
			printf("%d %f\n", carCount, totalAmount);
		}
};

int main(){
	TollBooth T1;
	T1.payingCar(10.23);
	T1.nonPayingCar();
	T1.getCarAndCollectionCount();

}