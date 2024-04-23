#pragma once

#include <iostream>
#include <iomanip> // Include the <iomanip> header for formatting
#include <fstream> // Include the <fstream> header for file operations

#include "Node.h"
#include "List.h"
#include "Queue.h"
#include "DequeueResult.h"

#include "Teller.h"
#include "Customer.h"

using namespace std;

class Bank
{
private:
	List<Customer>* customersList;
	Queue<Customer>* customersQueue;
	List<Teller>* tellersList;

	int numberOfTellers;
	int numberOfCustomers;
	int totalWaitingTime;
	int totalServiceTime;
	float sumTotalAvgWait;
	bool sorted = false;

public:
	Bank(int numberOfTellers)
	{
		this->numberOfTellers = numberOfTellers;

		totalWaitingTime = 0;
		totalServiceTime = 0;
		sumTotalAvgWait = 0;

		customersList = new List<Customer>();
		customersQueue = new Queue<Customer>();

		tellersList = new List<Teller>();

		AddTellers();
	}

	void AddCustomer(Customer& newCustomer)
	{
		customersList->Add(newCustomer);
		numberOfCustomers++;
	}
	
	void DisplayReport() 
	{
		cout << "\n\t\t====================>>> Bank Queue Management System <<<===================== \n";
		cout << "\t\t============================================================================= \n\n";

		SimulateQueueSystem();
		DisplaycustomersSortedList();
		DisplayTellers();
		DisplaycustomersQueue();
	}

	void DisplayReportToFile(ofstream& outputFile)
	{
		if (!sorted)
		{
			SimulateQueueSystem();
		}

		if (outputFile.is_open())
		{
			outputFile << "\n\t\t====================>>> Bank Queue Management System <<<===================== \n";
			outputFile << "\t\t============================================================================= \n\n";

			//******************************************************************************************************

			outputFile << "\n\t\t\t      ==========>> Customers Sorted Queue <<========= \n\n ";

			outputFile << " ID \t Priority   Arrival-Time   Service-Duration   Waiting-Time   Start-Service-Time   Teller-ID   Leave-Time" << endl;
			outputFile << " --------------------------------------------------------------------------------------------------------------" << endl;

			Node<Customer>* currentCustomer = customersList->head;

			while (currentCustomer != nullptr && !customersList->IsEmpty())
			{
				outputFile << currentCustomer->data.ToString() << endl;
				currentCustomer = currentCustomer->next;
			}
			if (customersList->IsEmpty())
			{
				outputFile << "\t\t\t\t\t There are no customers in the sorted list ... " << endl;
			}
			outputFile << " --------------------------------------------------------------------------------------------------------------" << endl;
			outputFile << " Total (time unit) : " << "\t\t\t" << totalServiceTime << "\t\t   " <<totalWaitingTime << endl << endl;
			outputFile << " Average (time unit/customer) : " << "\t" << fixed << setprecision(2) << (float)totalServiceTime / numberOfCustomers << "\t\t   "
				<< (float)totalWaitingTime / numberOfCustomers << endl;
			outputFile << " --------------------------------------------------------------------------------------------------------------" << endl<<endl;

			//******************************************************************************************************

			outputFile << "\n\t\t\t\t    ==========>> Tellers List <<========= \n\n ";

			outputFile << " ID   State    Total-customers    start-service  Avg-Service   total-service-time    end-service   efficiency" << endl;
			outputFile << " --------------------------------------------------------------------------------------------------------------" << endl;

			Node<Teller>* currentTeller = tellersList->head;
			while (currentTeller != nullptr)
			{
				outputFile << currentTeller->data.ToString() << endl;
				currentTeller = currentTeller->next;
			}
			outputFile << " --------------------------------------------------------------------------------------------------------------" << endl;

			//******************************************************************************************************

			outputFile.close(); // Close the file when done
			cout << "\t\t\t\t   >>> All data had been written in the file <<< " << endl;
			cout << " --------------------------------------------------------------------------------------------------------------" << endl << endl;

		}
		else
		{
			cerr << "\t\t\t\t\t  Unable to open the file." << endl;
		}
	}

private:

	void BubbleSortCustomersByPriority() {
		//int iterations = 0;
		bool sorted = false;

		do {
			sorted = true;
			Node<Customer>* current = customersList->head;
			Node<Customer>* previous = nullptr;

			while (current != nullptr && current->next != nullptr) {
				if (current->data.arrivalTime == current->next->data.arrivalTime
					&& current->data.priority == ordinary
					&& current->next->data.priority == special)
				{
					// Swap data
					Swap(current->data, current->next->data);
					sorted = false;
				}
				previous = current;
				current = current->next;
			}
			//iterations++;
		} while (!sorted);
		//cout << "Number of iterations for Bubble Sort: " << iterations << endl;
	}

	void BubbleSortCustomersByArrivalTime() {
		//int iterations = 0;
		bool sorted = false;

		do {
			sorted = true;
			Node<Customer>* current = customersList->head;
			Node<Customer>* previous = nullptr;

			while (current != nullptr && current->next != nullptr) {
				if (current->data.arrivalTime > current->next->data.arrivalTime) {
					// Swap data
					Swap(current->data, current->next->data);
					sorted = false;
				}
				previous = current;
				current = current->next;
			}
			//iterations++;
		} while (!sorted);
		//cout << "Number of iterations for Bubble Sort: " << iterations << endl;
	}

	template<typename T>
	void Swap(T& N1, T& N2)
	{
		T TempData = N1;
		N1 = N2;
		N2 = TempData;
	}

	void AddTellers()
	{
		for (int i = 1; i <= numberOfTellers; i++)
		{
			Node<Teller>* newTeller = new Node<Teller>();
			newTeller->data.id = i;
			tellersList->Add(newTeller->data);
		}
	}

	void SimulateQueueSystem()
	{
		BubbleSortCustomersByArrivalTime();

		BubbleSortCustomersByPriority();

		Enqueue();

		Node<Teller>* currentTeller = tellersList->head;
		Node<Customer>* currentCustomer = customersList->head;

		int globalTime;
		int count = 1;
		int minExpectedWaiting = 0;
		int minExpectedWaitingTellerID = 0;

		bool isFirstCustomer = true;
		bool allBusy;

		while (currentTeller != nullptr && !customersQueue->IsEmpty())
		{
			allBusy = true;

			if (currentCustomer->data.arrivalTime >= currentTeller->data.nextAvialableTime)
			{
				DequeueResult<Customer> dequedCustomer = customersQueue->Dequeue();

				if (dequedCustomer.IsSuccess)
				{
					if (isFirstCustomer)
					{
						globalTime = dequedCustomer.Value.arrivalTime;

						isFirstCustomer = false;
					}

					currentTeller->data.assignedCustomers->Enqueue(dequedCustomer.Value);

					currentTeller->data.state = busy;

					currentTeller->data.nextCustomerExpectedWaiting = 0;

					sumTotalAvgWait += currentTeller->data.avgServiceTime;

					//==========================================================================================================
				   // here I am updating the data in the Queue but I can't display it later because the Queue would be empty ...

					dequedCustomer.Value.waitingTime = 0;

					dequedCustomer.Value.startServiceTime = dequedCustomer.Value.arrivalTime;

					dequedCustomer.Value.leaveTime = dequedCustomer.Value.arrivalTime + dequedCustomer.Value.serviceTime;

					dequedCustomer.Value.assignedTellerID = count;

					currentTeller->data.nextAvialableTime = dequedCustomer.Value.leaveTime;

					currentTeller->data.totalServiceTime += dequedCustomer.Value.serviceTime;

					currentTeller->data.endServiceTime = dequedCustomer.Value.leaveTime;

					totalServiceTime += dequedCustomer.Value.serviceTime;

					if (currentTeller->data.assignedCustomers->IsFirstNode())
					{
						currentTeller->data.startServiceTime = dequedCustomer.Value.startServiceTime;
					}

					//========================================================================
				   // So I have to update the list with these data so I can Display it later ...

					currentCustomer->data.waitingTime = dequedCustomer.Value.waitingTime;

					currentCustomer->data.startServiceTime = dequedCustomer.Value.startServiceTime;

					currentCustomer->data.leaveTime = dequedCustomer.Value.leaveTime;

					currentCustomer->data.assignedTellerID = dequedCustomer.Value.assignedTellerID;

					//========================================================================

					count++;
					currentCustomer = currentCustomer->next;
					currentTeller = currentTeller->next;
				}
				else
				{
					cout << "\n\t\t\t\t failed to dequeu from customer queue ...\n" << endl;
				}
			}
			else
			{
				Node<Teller>* tempTeller = tellersList->head;
				Node<Teller>* minWaitingTeller = nullptr;
				minExpectedWaitingTellerID = count;

				minExpectedWaiting = currentTeller->data.nextAvialableTime - currentCustomer->data.arrivalTime;

				int i = 1;

				while (tempTeller != nullptr)
				{
					if (currentCustomer->data.arrivalTime >= tempTeller->data.nextAvialableTime)
					{
						allBusy = false;
					}
					else
					{
						tempTeller->data.nextCustomerExpectedWaiting = tempTeller->data.nextAvialableTime - currentCustomer->data.arrivalTime;

						if (tempTeller->data.nextCustomerExpectedWaiting <= minExpectedWaiting)
						{
							minExpectedWaiting = tempTeller->data.nextCustomerExpectedWaiting;

							minWaitingTeller = tempTeller;

							minExpectedWaitingTellerID = i;
						}
					}
					i++;
					tempTeller = tempTeller->next;
				}

				if (allBusy)
				{
					DequeueResult<Customer> dequedWaitingCustomer = customersQueue->Dequeue();

					if (dequedWaitingCustomer.IsSuccess)
					{
						currentTeller = minWaitingTeller;
						count = minExpectedWaitingTellerID;

						currentTeller->data.assignedCustomers->Enqueue(dequedWaitingCustomer.Value);

						currentTeller->data.state = busy;


						//currentTeller->data.nextCustomerExpectedWaiting = 0 ;

						//==========================================================================================================
					   // here I am updating the data in the Queue but I can't display it later because the Queue would be empty ...

						dequedWaitingCustomer.Value.waitingTime = currentTeller->data.nextAvialableTime - dequedWaitingCustomer.Value.arrivalTime;

						dequedWaitingCustomer.Value.startServiceTime = currentTeller->data.nextAvialableTime;

						dequedWaitingCustomer.Value.leaveTime = dequedWaitingCustomer.Value.startServiceTime + dequedWaitingCustomer.Value.serviceTime;

						dequedWaitingCustomer.Value.assignedTellerID = count;

						currentTeller->data.nextAvialableTime = dequedWaitingCustomer.Value.leaveTime;

						currentTeller->data.totalServiceTime += dequedWaitingCustomer.Value.serviceTime;

						currentTeller->data.totalWaitingTime += minExpectedWaiting;

						currentTeller->data.endServiceTime = dequedWaitingCustomer.Value.leaveTime;

						sumTotalAvgWait += currentTeller->data.avgServiceTime;

						totalServiceTime += dequedWaitingCustomer.Value.serviceTime;

						totalWaitingTime += minExpectedWaiting;

						if (currentTeller->data.assignedCustomers->IsFirstNode())
						{
							currentTeller->data.startServiceTime = dequedWaitingCustomer.Value.startServiceTime;
						}

						//========================================================================
					   // So I have to update the list with these data so I can Display it later ...

						currentCustomer->data.waitingTime = dequedWaitingCustomer.Value.waitingTime;

						currentCustomer->data.startServiceTime = dequedWaitingCustomer.Value.startServiceTime;

						currentCustomer->data.leaveTime = dequedWaitingCustomer.Value.leaveTime;

						currentCustomer->data.assignedTellerID = dequedWaitingCustomer.Value.assignedTellerID;

						//========================================================================

						count++;
						currentCustomer = currentCustomer->next;
						currentTeller = currentTeller->next;
					}
					else
					{
						cout << "\n\t\t\t\t failed to dequeu from customer queue ...\n" << endl;
					}
				}
				else
				{
					currentTeller = currentTeller->next;
					count++;
				}
			}
			if (!customersQueue->IsEmpty() && currentTeller == nullptr)
			{
				currentTeller = tellersList->head;
				count = 1;
			}
		}

		setTellerEfficiency();

		sorted = true;
	}

	void DisplayTellers()
	{
		cout << "\n\t\t\t\t    ==========>> Tellers List <<========= \n\n ";

		cout << " ID   State    Total-customers    start-service  Avg-Service   total-service-time    end-service   efficiency" << endl;
		cout << " --------------------------------------------------------------------------------------------------------------" << endl;

		Node<Teller>* current = tellersList->head;
		while (current != nullptr)
		{
			cout << current->data.ToString() << endl;
			current = current->next;
		}
		cout << " --------------------------------------------------------------------------------------------------------------" << endl;
	}

	void DisplaycustomersList()
	{
		cout << "\t\t\t==========>> Customers List <<========= \n\n ";

		cout << " ID \t Priority   Arrival-Time   Service-Duration   Waiting-Time   Start-Service-Time   Teller-ID   Leave-Time" << endl;
		cout << " --------------------------------------------------------------------------------------------------------------" << endl;

		Node<Customer>* current = customersList->head;

		while (current != nullptr && !customersList->IsEmpty())
		{
			cout << current->data.ToString() << endl;
			current = current->next;
		}
		if (customersList->IsEmpty())
		{
			cout << "\t\t\t\t\t There are no customers in the list ... " << endl;
		}
		cout << " --------------------------------------------------------------------------------------------------------------n\\n" << endl;
	}

	void DisplaycustomersSortedList()
	{
		BubbleSortCustomersByArrivalTime();
		BubbleSortCustomersByPriority();

		cout << "\n\t\t\t      ==========>> Customers Sorted Queue <<========= \n\n ";

		cout << " ID \t Priority   Arrival-Time   Service-Duration   Waiting-Time   Start-Service-Time   Teller-ID   Leave-Time" << endl;
		cout << " --------------------------------------------------------------------------------------------------------------" << endl;

		Node<Customer>* current = customersList->head;

		while (current != nullptr && !customersList->IsEmpty())
		{
			cout << current->data.ToString() << endl;
			current = current->next;
		}
		if (customersList->IsEmpty())
		{
			cout << "\t\t\t\t\t There are no customers in the sorted list ... " << endl;
		}
		cout << " --------------------------------------------------------------------------------------------------------------" << endl;
		cout << " Total (time unit) : " << "\t\t\t" << totalServiceTime << "\t\t   " << totalWaitingTime << endl << endl;
		cout << " Average (time unit/customer) : " << "\t" << fixed << setprecision(2) << (float)totalServiceTime / numberOfCustomers << "\t\t   "
			<< (float)totalWaitingTime / numberOfCustomers << endl;
		cout << " --------------------------------------------------------------------------------------------------------------\n\n" << endl;
	}

	void DisplaycustomersQueue()
	{
		cout << "\n\n\t\t\t\t ==========>> Customers Sorted Queue <<========= \n\n ";
		cout << " ID \t Priority   Arrival-Time   Service-Duration   Waiting-Time   Start-Service-Time   Teller-ID   Leave-Time" << endl;
		cout << " --------------------------------------------------------------------------------------------------------------" << endl;

		if (customersQueue->IsEmpty())
		{
			cout << "\t\t\t\t\t The cutomers Queue is now Empty ..." << endl;
		}
		while (!customersQueue->IsEmpty())
		{
			DequeueResult<Customer> result = customersQueue->Dequeue();

			if (result.IsSuccess)
			{
				cout << result.Value.ToString() << endl;
			}
			else
			{
				cout << "Failed to dequeue customer." << endl;
			}
		}
		cout << " --------------------------------------------------------------------------------------------------------------\n\n" << endl;
	}

	void ChangeTellersState()
	{
		Node<Teller>* currentTeller = tellersList->head;
		while (currentTeller != nullptr)
		{
			currentTeller->data.state = busy;
			currentTeller = currentTeller->next;
		}
	}

	void Enqueue()
	{
		Node<Customer>* current = customersList->head;

		while (current != nullptr)
		{
			customersQueue->Enqueue(current->data);

			current = current->next;
		}
	}

	void setTellerEfficiency() 
	{
		Node<Teller>* current = tellersList->head; 
		while (current) 
		{
			current->data.avgServiceTime = (float)current->data.totalServiceTime / current->data.assignedCustomers->size;
			current->data.efficiency = (1- current->data.avgServiceTime / totalServiceTime) * 100 ;

			current = current->next;
		}

		current = tellersList->head; 
		while (current)
		{

			current = current->next;
		}
	}

};
