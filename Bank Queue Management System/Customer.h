#pragma once

#include <sstream> // for std::stringstream
#include <fstream> // Include the <fstream> header for file operations
#include <string>

#include<iostream>

using namespace std;

enum CustomerState
{
	waiting = 0, served = 1
};

enum Priority
{
	ordinary = 0, special = 1
};

class Customer
{
public:
	int id;

	int arrivalTime;
	int serviceTime;

	int waitingTime;
	int startServiceTime;
	int leaveTime;

	Priority priority;
	CustomerState state;

	bool isEnqued;
	int assignedTellerID;

	Customer(int id, int arrivalTime, int serviceTime, Priority priority) 
	{
		this->id = id;
		this->arrivalTime = arrivalTime;
		this->serviceTime = serviceTime;
		this->priority = priority;

		state = waiting;
		isEnqued = false;

		waitingTime = 0;
		startServiceTime = 0;
		leaveTime = 0;
		assignedTellerID = 0;
	}

	Customer()
	{
		state = waiting;
		isEnqued = false;

		waitingTime = 0;
		startServiceTime = 0;
		leaveTime = 0;
		assignedTellerID = 0;
	}

	string priorityToString(Priority p) {
		switch (p) {
		case ordinary:
			return "Regular";
			break;

		case special:
			return "VIP    ";
			break;

		default:
			return "unknown";
			break;
		}
	}
	string CustomerStateToString(CustomerState s) {
		switch (s) {
		case waiting:
			return "waiting";
			break;

		case special:
			return "served";
			break;

		default:
			return "unknown state !";
			break;
		}
	}
	string ToString()
	{
		stringstream ss;
		ss << "  " << id << "  \t " << priorityToString(priority) << "  \t" << arrivalTime <<" \t\t " << serviceTime << "\t\t   " << waitingTime << "\t\t    " << startServiceTime << "\t\t      " << assignedTellerID << "\t\t   " <<   leaveTime << endl;
		return ss.str();
	}

	bool operator==(Customer other)
	{
		return id == other.id && arrivalTime == other.arrivalTime && serviceTime == other.serviceTime && priority == other.priority;
	}
};
