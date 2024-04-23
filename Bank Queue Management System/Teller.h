#pragma once

#include <sstream> // for std::stringstream
#include <string>
#include <iomanip> // Include the <iomanip> header for formatting

#include<iostream>

#include"Customer.h"

using namespace std;

enum State
{
	available = 0, busy = 1
};

class Teller
{
public:
	 int id ;

	State state;

	int startServiceTime; 
	int nextAvialableTime;

	int freeTime;
	int endServiceTime;
	int totalServiceTime;
	int totalWaitingTime;
	int nextCustomerExpectedWaiting;
	float avgServiceTime;
	float efficiency;

	Queue<Customer>* assignedCustomers;

	Teller()
	{
		assignedCustomers = new Queue<Customer>();
		state = available;

		 startServiceTime =  0 ;
		 nextAvialableTime = 0 ;

		 freeTime = 0 ;
		 endServiceTime = 0 ;
		 totalServiceTime = 0 ;
		 totalWaitingTime = 0;
		 nextCustomerExpectedWaiting = 0;
		 efficiency = 0.0;
	}

	string StateToString(State s)
	{
		switch (s)
		{
		case available:
			return "available";
			break;

		case busy:
			return "busy";
			break;

		default:
			return "unknown state !";
			break;
		}
	}

	string ToString()
	{
		stringstream ss;

		ss << "  " << id << "    " << StateToString(state) << " \t\t" <<
			assignedCustomers->size << "\t\t " <<
			startServiceTime << "\t    " <<
			fixed << setprecision(2) << avgServiceTime << "\t\t" <<
			totalServiceTime << "\t\t  " <<
			endServiceTime << "\t\t" <<
			fixed << setprecision(2)<<efficiency <<" %"<<
			endl;

		return ss.str();
	}

	bool operator==(Teller other)
	{
		return id == other.id;
	}

};