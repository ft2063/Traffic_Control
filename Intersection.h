#pragma once
#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include<sstream>
#include <cmath>
#include<ctime>
#include "TrafficLight.h"

class Intersection {								//create class to represent Intersection		
private:											//Private members of the class
	TrafficLights trafficlights[tMAX];				//define array of trafficlights which has a maximum of tMax elements
	double CycleLength;
	double TotalTrafficFlow;
	double TrafficFlows[tMAX];						//array of double values which stores TrafficFlows values read from document provided
	double GreenTime[tMAX];							//array of double values which stored green time values for each semaphore reported in document
	int TLnumber;									//number of semaphores

public:												//Public membersof the class
	Intersection() {								//default costructor sets 0 as value of all private variables
		TLnumber = 0;
		CycleLength = 0;
		TotalTrafficFlow = 0;
		for (int i = 0; i < tMAX; i++) {
			TrafficFlows[i] = 0;
			GreenTime[i] = 0;
		}
	}

	void AddLight(TrafficLights aLight) {			//Adds a given Trafficlight to private array trafficlights
		if (TLnumber < tMAX) {					//if the trafficlight number is less than the maximum number of trafficlights
			trafficlights[TLnumber] = aLight;
			TLnumber++;							//increments number of Trafficlights in Intersection
		}
		else
			cout << "Can't add more traffic lights, full capacity" << endl;
	}
	void dropLight(int TLightID) {					//Excludes a given Trafficlight from intersection given its ID
		bool isFound = false;

		for (int i = 0; i < TLnumber; i++)
		{
			if (TLightID == trafficlights[i].getID())
			{
				cout << "The trafficlight to be removed is found" << endl;
				for (int j = i; j < TLnumber; j++)
				{
					trafficlights[j] = trafficlights[j + 1];
				}
				TLnumber--;							//decrease number of trafficlights in intersection
				isFound = true;
			}
		}

		if (!isFound)
			cout << "Can't find the traffic light to drop" << endl;
	}

	int getNumOfSemaphores() {						//returns number of semaphores added to intersection
		return TLnumber;
	}


	void ReadTrafficData() {								//function to store traffic information from file to respective variables
		ifstream infile;								//creates buffer
		infile.open("Traffic_Information.txt", ios::in); //open file 
		if (infile.fail()) {							//check correct opening of file
			cerr << "error in opening file";
			exit(-1);
		}
		string trash;									//the following lines are used to skip words in the file and store information into respective variables
		getline(infile, trash, '=');
		infile >> CycleLength;
		cout << "CycleLength = " << CycleLength << endl;
		getline(infile, trash, '=');
		infile >> TotalTrafficFlow;
		cout << "TotalTrafficFlow = " << TotalTrafficFlow << endl;

		for (int i = 0; i < TLnumber; i++) {			//stores all traffic flow values TrafficFlows[i]
			if (infile.eof()) break;
			getline(infile, trash, '=');
			infile >> TrafficFlows[i];
			cout << "traffic Flow for semaphore" << i << " = " << TrafficFlows[i] << endl;  //Displays traffic flow values TrafficFlows[i] for instructing user and debugging purposes

		}
		infile.close();															//closes input file
	}
	void CalculateGreenTime() {														//calculates greentime for each semaphore given the information stored in the file
		for (int i = 0; i < TLnumber; i++) {
			double greentime = (TrafficFlows[i]) * (CycleLength / TotalTrafficFlow); //uses formula d = q/qt *C
			GreenTime[i] = greentime;												//stores calculated values of green time into array  GreenTime
			cout << "Computed Green Time for semaphore " << i << " = " << greentime << " s" << endl;		//displays green time for each semaphore for instructing user and debugging purposes
			trafficlights[i].setGreentime(GreenTime[i]);							//sets the green time for each semaphore
			cout << "Updated Green Time for semaphore " << i << " is now set to = " << trafficlights[i].getGreentime() << endl;
			cout << "Updated information of semaphore " << i << " as follows: " << endl;
			trafficlights[i].PrintLightInfo();										//displays updated information of each trafficlight for user's knowledge and debugging purposes
			cout << endl;
		}
	}
	void run() {																	//this function manages the simulation
		double TimeSimulation = 0;													//set total time of simulation as zero
		cout << "Simulation starts" << endl << endl;
		for (; 1 == 1;) {															//loop is always satisfied hence simulation does not stop
			double start = 0;
			double endCycle = 0;
			double TimeOneCycle = 0;
			start = clock(); //start timer											//start timer
			for (int i = 0; i < TLnumber; i++) {									//for each semaphore
				cout << "Cycle of Semaphore " << i << endl << endl;					//display its name
				trafficlights[i].setState(1);										//assure semaphore is red
				trafficlights[i].setState(3);										//becomes green
				if (trafficlights[i].getState() != 3)									//move to next semaphore if this does not turn green
					continue;
				else {
					trafficlights[i].PrintLightInfo();								//display semaphore's information when green
					trafficlights[i].wait(trafficlights[i].getGreentime());			//green time elapses
					trafficlights[i].setState(2);									//set semaphore to yellow
					trafficlights[i].PrintLightInfo();								//display semaphore's information when yellow
					trafficlights[i].wait(yellowtime);								//yellow time elapses
					trafficlights[i].setState(1);									 //trafficlight becomes red
					trafficlights[i].PrintLightInfo();								//display semaphore's information when red
					cout << endl;
				}
			}
			endCycle = clock();														//end timer
			TimeOneCycle = endCycle - start;										//time of one cycle of simulation
			TimeSimulation += TimeOneCycle;											//total time elapsed
			if ((TimeSimulation) > (updategreentime * CLOCKS_PER_SEC)) {			//when total time elapsed is greater than time to update traffic values
				UpdateTiming();														//update times
				TimeSimulation = 0;													//resets total simulation time to zero
			}

		}
	}

	void UpdateTiming() {					//update green time for each semaphore
		ReadTrafficData();				//by reading again from given file
		CalculateGreenTime();			//calculating again green time for each semaphore
	}
};

