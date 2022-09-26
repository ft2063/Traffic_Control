#include <iostream>
#include <fstream>
#include <iomanip>
#include<sstream>
#include <cmath>
#include<ctime>
#include "TrafficLight.h" 
#include "Intersection.h"

using namespace std;          


int main(){
	
		TrafficLights Semaphore1, Semaphore2, Semaphore3, Semaphore4, Semaphore5;			//initialize 5 semaphores
		Intersection WashingtonRoad3;														//initialize intersection
		WashingtonRoad3.AddLight(Semaphore1);												//add semaphores to intersection
		WashingtonRoad3.AddLight(Semaphore2);
		WashingtonRoad3.AddLight(Semaphore3);
		WashingtonRoad3.AddLight(Semaphore4);
		WashingtonRoad3.AddLight(Semaphore5);
		cout << "number of Semaphores = " << WashingtonRoad3.getNumOfSemaphores() << endl;  //Print number of semaphores
		WashingtonRoad3.ReadTrafficData();													//read data from Traffic Information document
		WashingtonRoad3.CalculateGreenTime();												 //calculate and store time each semaphore remains green

		for (; 1==1;){																		//condition 1==1 is always satisfied, hence simulation does not end 
			WashingtonRoad3.run();															//call run function
		} 
		WashingtonRoad3.dropLight(Semaphore5.getID());
		WashingtonRoad3.getNumOfSemaphores();
		cout << "number of Semaphores = " << WashingtonRoad3.getNumOfSemaphores() << endl;

	return 0;
}
