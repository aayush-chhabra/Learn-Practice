# include <iostream>

class Time{
	private:
		int hours, minutes, seconds;
	public:
		
		Time(): hours(0), minutes(0), seconds(0){

		}

		Time(int h, int m, int s): hours(h), minutes(m), seconds(s){

		} 

		void setTime(int h, int m, int s){
			hours = h;
			minutes = m;
			seconds = s;
		}

		void getTime(){
			printf("%d:%d:%d\n",hours, minutes, seconds);
		}

		Time addTime(Time t1, Time t2){
			Time temp;
			
			this->hours = t1.hours + t2.hours;
			this->minutes = t1.minutes + t2.minutes;
			this->seconds = t1.seconds + t2.seconds;

			return temp;
		}


};

int main(){
	
	Time t1(10, 2, 5), t2(11, 12, 50), t3;

	t1.getTime();
	t2.getTime();

	t3.addTime(t1, t2);

	t3.getTime();

}