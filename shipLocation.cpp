# include <iostream>

using namespace std;


class Angle{
	int lat, lang;
	public:
		
		Angle():lat(0), lang(0){
			cout<<"called";
		}

		Angle(int lat1, int lang1): lat(lat1), lang(lang1){

		}

		int getLat(){
			return lat;
		}

		int getLang(){
			return lang;
		}
};


class Ship{
	int shipNumber;
	char shipLocation[10];
	Angle ang;
	static int totalShips;
	
	public:
		Ship():shipNumber(++totalShips), ang(0,0){
		}

		Ship(char location[10], int lat, int lang):shipNumber(++totalShips), ang(lat,lang){
			strcpy(shipLocation, location);
		}

		int static getTotalShipNumbers(){
			return totalShips;
		}

		void getShipDetails(){
			printf("%d %s %d %d\n", shipNumber, shipLocation, ang.getLat(), ang.getLang() );
		}
};





int Ship::totalShips = 0; 

int main(){
	Ship s1("hawaii", 10, 20);
	Ship s2("New York", 20, 30);
	s1.getShipDetails();
	s2.getShipDetails();
	
}