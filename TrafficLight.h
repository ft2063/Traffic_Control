#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include<sstream>
#include <cmath>
#include<ctime>

using namespace std;


class TrafficLights {              //create class to represent trafficlights
private:							//Private members cannot be accessed directly
	int ID;
	int state;						// 1=red, 2=yellow, 3=green
	double greentime;				// time for semaphore to remain green
	static int TLnumber;			// number of sempahores

public:								//Public members can be accessed directly
	TrafficLights() {				//default constructor
		ID = TLnumber;				//ID corresponds to semaphore number
		TLnumber++;					//number of semaphore is incremented each time a semaphore is created
		state = 1;                   //traffic light starts as red
		greentime = 0;
	}

	int getID() {					//getID(); getGreentime(); getNumOfTrafficlights() are accessors to private variables
		return (ID);
	}
	int getState() {
		return (state);
	}
	void setState(int color) {	//setState; setGreenTime are modifiers of private variables
		state = color;
	}
	double getGreentime() {
		return (greentime);
	}
	void setGreentime(double GreenTime) {
		greentime = GreenTime;
	}

	void PrintLightInfo() {						//PrintLightInfo() prints information about a specific trafficlight
		cout << "ID = " << ID << endl;
		cout << "state = " << state << endl;
		cout << "greentime = " << greentime << endl;
	}
	static int getNumOfTrafficlights() {
		return TLnumber;
	}
	void wait(double number_seconds) {		//wait() returns after the number of seconds given is elapsed
		clock_t startClock = clock();
		double SecondsWaited = number_seconds * CLOCKS_PER_SEC;   //CLOCKS_PER_SEC converts seconds to milliseconds
		while (clock() < startClock + SecondsWaited);
		return;
	}
};

int TrafficLights::TLnumber = 0;					//initial number of semaphores is zero
const double yellowtime = 3;						// time semaphore remains yellow = 3 seconds 
const double updategreentime = 60;				    //number seconds in 1 minutes, program will update information each minute
const int tMAX = 10;