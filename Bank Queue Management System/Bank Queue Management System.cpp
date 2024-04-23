#include <iostream>
#include <fstream> // Include the <fstream> header for file operations


#include "Node.h"
#include "List.h"
#include "Queue.h"
#include "DequeueResult.h"

#include "Teller.h"
#include "Customer.h"
#include "Bank.h"

using namespace std;


// Function to convert string to Priority enum
Priority StringToPriority(const string& str) {
	if (str == "ordinary") {
		return Priority::ordinary;
	}
	else if (str == "special") {
		return Priority::special;
	}
	else {
		return Priority::ordinary; // Default to ordinary priority
	}
}

// Function to read customer data from a file
void ReadCustomerDataFromFile(const string& filename, Bank& bank) {
	std::ifstream file(filename);
	if (file.is_open()) {
		int id, arrivalTime, serviceTime;
		string priorityStr;
		while (file >> id >> arrivalTime >> serviceTime >> priorityStr) {
			Priority priority = StringToPriority(priorityStr);
			Customer* customer = new Customer(id, arrivalTime, serviceTime, priority);
			bank.AddCustomer(*customer);
		}
		file.close();
	}
	else {
		cerr << "Unable to open file: " << filename << endl;
	}
}

int main()
{
		#pragma region Testing generic List 
			//Node<int>* n1 = new Node<int>(3);

		//cout << n1->data << endl; 
		//if (n1->prev == nullptr) {
		//	cout << "null" << endl;

		//}

		//cout << n1->prev << endl; 
		//cout << n1->next << endl; 

		//Node<int>* n2 = new Node<int>();
		//cout << n2->data << endl; 
		//cout << n2->prev << endl; 
		//cout << n2->data << endl; 

		//List<int>* numbers = new List<int>(); 

		//numbers->Add(1);
		//numbers->Add(2);
		//numbers->Add(3);

		//numbers->Display();

		//cout << "\n------------\n";

		//numbers->Remove(3); 

		//numbers->Display();

		//cout << "\n------------\n";

		//numbers->Add(6);

		//numbers->Remove(1);

		//numbers->Display();

		//cout << "\n------------\n";

		//List<string>* names = new List<string>(); 

		//names->Add("Omar");
		//names->Add("Omasdfr");
		//names->Add("Oaasdmar");

		//names->Display();

		//Teller *t1 = new Teller();
		//t1->name = "Omar"; 
		//t1->age = 34; 
		//t1->id = 1; 

		//Teller* t2 = new Teller();
		//t2->name = "Ahmed";
		//t2->age = 23;
		//t2->id = 2;

		//List<Teller>* tellers = new List<Teller>();
		//tellers->Add(*t1);
		//tellers->Add(*t2);

		//tellers->Display();

		//Customer* c1 = new Customer();
		//c1->age = 23;
		//c1->id = 1;
		//c1->name = "asda";

		////cout<<c1->ToString();

		//Customer* c2 = new Customer();
		//c2->age = 443;
		//c2->id = 2;
		//c2->name = "dfgfd";

		//List<Customer>* customers = new List<Customer>();
		//customers->Add(*c1);
		//customers->Add(*c2);

		//customers->Display();

		//customers->Remove(*c1);

		//customers->Display();

		//customers->Add(*c1);

		//customers->Display();

		//=====================  
		#pragma endregion

		#pragma region Testing generic Queue
			//Queue<int>* q = new Queue<int>(); 

			//q->Enqueue(1);
			//q->Enqueue(2);
			//q->Enqueue(4);

			//DequeueResult<int> d1 = q->Dequeue();

			//if (d1.IsSuccess)
			//{
			//	cout << d1.Value << endl;
			//}
			//else {
			//	cout << "The Queue is empty ! " << endl;
			//}

			//DequeueResult<int> d2 = q->Dequeue();

			//if (d2.IsSuccess)
			//{
			//	cout << d2.Value << endl;
			//}
			//else {
			//	cout << "The Queue is empty ! " << endl; 
			//}


			//DequeueResult<int> d3 = q->Dequeue();

			//if (d3.IsSuccess)
			//{
			//	cout << d3.Value << endl;
			//}
			//else {
			//	cout << "The Queue is empty ! " << endl;
			//}

			//DequeueResult<int> d4 = q->Dequeue();

			//if (d4.IsSuccess)
			//{
			//	cout << d4.Value << endl;
			//}
			//else {
			//	cout << "The Queue is empty ! " << endl;
			//}

			////=================================

			//Customer* cc1 = new Customer();
			//cc1->name = "Ahmed"; 
			//cc1->age = 43; 
			//cc1->id = 1; 

			//Customer* cc2 = new Customer();
			//cc2->name = "Ali";
			//cc2->age = 23;
			//cc2->id = 2;

			//Queue<Customer>* customersQueue = new Queue<Customer>();

			//customersQueue->Enqueue(*cc1);
			//customersQueue->Enqueue(*cc2);

			//DequeueResult<Customer> r1 = customersQueue->Dequeue();

			//if (r1.IsSuccess) {
			//	cout << r1.Value.ToString() << endl; 
			//}
			//else {
			//	cout << "The Queue is empty !"; 
			//}


			//DequeueResult<Customer> r2 = customersQueue->Dequeue();

			//if (r2.IsSuccess) {
			//	cout << r2.Value.ToString() << endl;
			//}
			//else {
			//	cout << "The Queue is empty !";
			//}


			//DequeueResult<Customer> r3 = customersQueue->Dequeue();

			//if (r3.IsSuccess) {
			//	cout << r3.Value.ToString() << endl;
			//}
			//else {
			//	cout << " The Queue is empty ! \n" << endl ;
			//}

			// //===============================

			//customersQueue->Enqueue(*cc1);

			//DequeueResult<Customer> r4 = customersQueue->Dequeue();

			//if (r4.IsSuccess) {
			//	cout << r4.Value.ToString() << endl;
			//}
			//else {
			//	cout << " The Queue is empty !";
			//}

			//Queue<int> nums;

			//nums.Enqueue(1);
			//nums.Enqueue(2);
			//nums.Enqueue(3);

			//for (int i = 0; i < 3; i++) 
			//{
			//	DequeueResult<int> r = nums.Dequeue();
			//	if (r.IsSuccess)
			//		cout << r.Value << endl;

			//	else
			//		cout << "failed" << endl;
			//}


			/*customers->Enqueue(*c1);
				customers->Enqueue(*c2);
				customers->Enqueue(*c3);
				if (!customers->IsEmpty()) {
					cout << "not Empty \n";
				}
				for (int i = 0; i < 3; i++)
				{
					DequeueResult<Customer> r = customers->Dequeue();

					if (r.IsSuccess)
					{
						cout << r.Value.ToString() << endl;
					}
				}
				if (customers->IsEmpty()) {
					cout << "Empty \n";
				}*/


				//Queue<int> nums;

					//nums.Enqueue(1);
					//nums.Enqueue(2);
					//nums.Enqueue(3);

					//cout << nums.size << endl;
					//cout << nums.IsEmpty() << endl;

					//for (int i = 0; i < 3; i++)
					//{
					//	DequeueResult<int> result = nums.Dequeue();
					//	if (result.IsSuccess) {
					//		cout << result.Value << endl;
					//	}
					//	else {
					//		cout << "failed ... " << endl;
					//	}
					//}
					//cout << nums.IsEmpty() << endl;
				////===============================  
		#pragma endregion

		#pragma region testing enums
						/*	queue<int> myNums;

			myNums.push(1);
			myNums.push(2);
			myNums.push(3);

			cout << myNums.size() << endl;

			 myNums.pop();

			 cout << myNums.size() << endl;
			 myNums.pop();
			 myNums.pop();

			 if (myNums.empty()) {
				 cout << "empty" << endl;
			 }

			 cout << "=================\n";

			 Queue<int> numbers;

			 numbers.Enqueue(1);


			DequeueResult<int> x = numbers.Dequeue();

			if (x.IsSuccess) {
				cout << x.IsSuccess << endl;
			}

			DequeueResult<int> x2 = numbers.Dequeue();

			if (x2.IsSuccess) {
				cout << x2.IsSuccess << endl;
			}
			else {
				cout << "not valid";
			}*/


			/*	TellerState t;
				t = TellerState::busy;
				if (t == TellerState::available) {
					std::cout << "Available" << std::endl;
				}
				else {
					std::cout << "Busy" << std::endl;
				}*/


		#pragma endregion

		#pragma region test cases on priority and arrival time 
				//Queue<Customer>* q2 = new Queue<Customer>();
		//cout << q2->IsEmpty();
		//Customer* cc1 = new Customer();
		//q2->Enqueue(*cc1);
		//cout << q2->IsEmpty();


		//Bank* b1 = new Bank(3);

		/*Customer* c1 = new Customer(1, 15, 5, Priority::ordinary);
		Customer* c2 = new Customer(2, 5, 2, Priority::ordinary);
		Customer* c3 = new Customer(3, 5, 5, Priority::special);
		Customer* c4 = new Customer(4, 5, 4, Priority::special);*/


		/*b1->AddCustomer(*c1);
		b1->AddCustomer(*c2);
		b1->AddCustomer(*c3);
		b1->AddCustomer(*c4);

		b1->DisplaycustomersList();

		b1->SimulateQueueSystem();

		b1->DisplaycustomersQueue();*/

		//// Test case 1: Five customers arrive at the same time, all with ordinary priority
		//Customer* tc1_c1 = new Customer(1, 10, 5, Priority::ordinary);
		//Customer* tc1_c2 = new Customer(2, 10, 2, Priority::ordinary);
		//Customer* tc1_c3 = new Customer(3, 10, 4, Priority::ordinary);
		//Customer* tc1_c4 = new Customer(4, 10, 3, Priority::ordinary);
		//Customer* tc1_c5 = new Customer(5, 10, 1, Priority::ordinary);

		//// Add customers to the bank
		//b1->AddCustomer(*tc1_c1);
		//b1->AddCustomer(*tc1_c2);
		//b1->AddCustomer(*tc1_c3);
		//b1->AddCustomer(*tc1_c4);
		//b1->AddCustomer(*tc1_c5);

		//// Display the customer list
		//cout << "Customer List:" << endl;
		//b1->DisplaycustomersList();

		//// Simulate the queue system
		//b1->SimulateQueueSystem();

		//// Display the customers in the queue
		//cout << "Customers in Queue:" << endl;
		//b1->DisplaycustomersQueue();

		//// Test case 2: Five customers arrive at different times, all with special priority
		//Customer* tc2_c1 = new Customer(1, 5, 5, Priority::special);
		//Customer* tc2_c2 = new Customer(2, 7, 2, Priority::special);
		//Customer* tc2_c3 = new Customer(3, 9, 4, Priority::special);
		//Customer* tc2_c4 = new Customer(4, 11, 3, Priority::special);
		//Customer* tc2_c5 = new Customer(5, 13, 1, Priority::special);

		//// Add customers to the bank
		//b1->AddCustomer(*tc2_c1);
		//b1->AddCustomer(*tc2_c2);
		//b1->AddCustomer(*tc2_c3);
		//b1->AddCustomer(*tc2_c4);
		//b1->AddCustomer(*tc2_c5);

		//// Display the customer list
		//cout << "Customer List:" << endl;
		//b1->DisplaycustomersList();

		//// Simulate the queue system
		//b1->SimulateQueueSystem();

		//// Display the customers in the queue
		//cout << "Customers in Queue:" << endl;
		//b1->DisplaycustomersQueue();

		//// Test case 3: Five customers arrive at different times, with mixed priorities
		//Customer* tc3_c1 = new Customer(1, 5, 5, Priority::special);
		//Customer* tc3_c2 = new Customer(2, 6, 2, Priority::ordinary);
		//Customer* tc3_c3 = new Customer(3, 7, 4, Priority::special);
		//Customer* tc3_c4 = new Customer(4, 9, 3, Priority::ordinary);
		//Customer* tc3_c5 = new Customer(5, 12, 1, Priority::special);

		//// Add customers to the bank
		//b1->AddCustomer(*tc3_c1);
		//b1->AddCustomer(*tc3_c2);
		//b1->AddCustomer(*tc3_c3);
		//b1->AddCustomer(*tc3_c4);
		//b1->AddCustomer(*tc3_c5);

		//// Display the customer list
		//cout << "Customer List:" << endl;
		//b1->DisplaycustomersList();

		//// Simulate the queue system
		//b1->SimulateQueueSystem();

		//// Display the customers in the queue
		//cout << "Customers in Queue:" << endl;
		//b1->DisplaycustomersQueue();


		//Customer* tc4_c1 = new Customer(1, 5, 5, Priority::special);
		//Customer* tc4_c2 = new Customer(2, 6, 2, Priority::ordinary);
		//Customer* tc4_c3 = new Customer(3, 7, 4, Priority::special);
		//Customer* tc4_c4 = new Customer(4, 7, 3, Priority::special); // Same arrival time as c3
		//Customer* tc4_c5 = new Customer(5, 9, 1, Priority::ordinary);

		//// Add customers to the bank
		//b1->AddCustomer(*tc4_c1);
		//b1->AddCustomer(*tc4_c2);
		//b1->AddCustomer(*tc4_c3);
		//b1->AddCustomer(*tc4_c4);
		//b1->AddCustomer(*tc4_c5);

		//// Display the customer list
		//cout << "Customer List:" << endl;
		//b1->DisplaycustomersList();

		//// Simulate the queue system
		//b1->SimulateQueueSystem();

		//// Display the customers in the queue
		//cout << "Customers in Queue:" << endl;
		//b1->DisplaycustomersQueue();

		//Customer* tc5_c1 = new Customer(1, 5, 5, Priority::ordinary);
		//Customer* tc5_c2 = new Customer(2, 7, 2, Priority::ordinary);
		//Customer* tc5_c3 = new Customer(3, 8, 4, Priority::ordinary);
		//Customer* tc5_c4 = new Customer(4, 8, 3, Priority::special); // Same arrival time as c3
		//Customer* tc5_c5 = new Customer(5, 8, 1, Priority::ordinary);
		//Customer* tc5_c6 = new Customer(6, 5, 1, Priority::special);

		//// Add customers to the bank
		//b1->AddCustomer(*tc5_c1);
		//b1->AddCustomer(*tc5_c2);
		//b1->AddCustomer(*tc5_c3);
		//b1->AddCustomer(*tc5_c4);
		//b1->AddCustomer(*tc5_c5);
		//b1->AddCustomer(*tc5_c6);

		//// Display the customer list
		//b1->DisplaycustomersList();

		//// Simulate the queue system
		//b1->SimulateQueueSystem();

		//// Display the customers in the queue
		//b1->DisplaycustomersQueue();  

		//===============================

		//Bank* b2 = new Bank(3);

		//Customer* c1 = new Customer(1 , 5 , 10 , Priority::ordinary);
		//Customer* c2 = new Customer(2 , 6 , 5 , Priority::ordinary);
		//Customer* c3 = new Customer(3 , 7 , 10 , Priority::ordinary);
		//Customer* c4 = new Customer(4 , 11, 5 , Priority::ordinary);
		//Customer* c5 = new Customer(5 , 12, 5 , Priority::ordinary);
		//Customer* c6 = new Customer(6 , 13, 5 , Priority::ordinary);

		//b2->AddCustomer(*c1);
		//b2->AddCustomer(*c2);
		//b2->AddCustomer(*c3);
		//b2->AddCustomer(*c4);
		//b2->AddCustomer(*c5);
		//b2->AddCustomer(*c6);

		//b2->DisplayTellers();

		//b2->DisplaycustomersList();

		//b2->DisplaycustomersQueue();

		////-----------------------
		//b2->SimulateQueueSystem();
		////-----------------------

		//b2->DisplayTellers();

		//b2->DisplaycustomersSortedList();

		//b2->DisplaycustomersQueue();

		//===============================
		//    
		//    // test case 2 :
		   //Bank* b2 = new Bank(3);

		   //Customer* c1 = new Customer(1, 5, 8, Priority::ordinary); // Arrival: 9, Service: 8
		   //Customer* c2 = new Customer(2, 6, 9, Priority::ordinary); // Arrival: 12, Service: 6
		   //Customer* c3 = new Customer(3, 7, 10, Priority::ordinary); // Arrival: 15, Service: 10
		   //Customer* c4 = new Customer(4, 10, 8, Priority::ordinary); // Arrival: 17, Service: 5
		   //Customer* c5 = new Customer(5, 19, 9, Priority::ordinary); // Arrival: 19, Service: 7
		   //Customer* c6 = new Customer(6, 21, 9, Priority::ordinary); // Arrival: 21, Service: 9

		   //b2->AddCustomer(*c1);
		   //b2->AddCustomer(*c2);
		   //b2->AddCustomer(*c3);
		   //b2->AddCustomer(*c4);

		   //b2->AddCustomer(*c5);
		   //b2->AddCustomer(*c6);

		   //b2->DisplayTellers();
		   //b2->DisplaycustomersList();
		   //b2->DisplaycustomersQueue();

		   ////-----------------------
		   //b2->SimulateQueueSystem();
		   ////-----------------------

		   //b2->DisplayTellers();
		   //b2->DisplaycustomersSortedList();
		   //b2->DisplaycustomersQueue();

		   //// Clean up memory
		   //delete b2;
		   //delete c1;
		   //delete c2;
		   //delete c3;
		   //delete c4;
		   //delete c5;
		   //delete c6;


			   //// Test case 3:
			   //Bank* b3 = new Bank(2);

			   //Customer* c1 = new Customer(1, 20, 5, Priority::ordinary); // Arrival: 8, Service: 5
			   //Customer* c2 = new Customer(2, 7, 7, Priority::ordinary); // Arrival: 10, Service: 7
			   //Customer* c3 = new Customer(3, 12, 8, Priority::ordinary); // Arrival: 12, Service: 8
			   //Customer* c4 = new Customer(4, 7, 6, Priority::special); // Arrival: 14, Service: 6
			   //Customer* c5 = new Customer(5, 10, 9, Priority::ordinary); // Arrival: 15, Service: 9
			   //Customer* c6 = new Customer(6, 17, 7, Priority::special); // Arrival: 17, Service: 7
			   //Customer* c7 = new Customer(7, 5,15, Priority::ordinary); // Arrival: 17, Service: 7

			   //b3->AddCustomer(*c1);
			   //b3->AddCustomer(*c2);
			   //b3->AddCustomer(*c3);
			   //b3->AddCustomer(*c4);
			   //b3->AddCustomer(*c5);
			   //b3->AddCustomer(*c6);
			   //b3->AddCustomer(*c7);

			   ////b3->DisplayTellers();
			   ///*b3->DisplaycustomersList();
			   //b3->DisplaycustomersQueue();*/

			   ////-----------------------
			   //b3->SimulateQueueSystem();
			   ////-----------------------

			   //b3->DisplaycustomersSortedList();
			   //b3->DisplayTellers();
			   //b3->DisplaycustomersQueue();

			   //// Clean up memory
			   //delete b3;
			   //delete c1;
			   //delete c2;
			   //delete c3;
			   //delete c4;
			   //delete c5;
			   //delete c6;


			   //// Test case 4:
			   //Bank* b4 = new Bank(3);

			   //Customer* c1 = new Customer(1, 20, 6, Priority::ordinary); // Arrival: 20, Service: 6
			   //Customer* c2 = new Customer(2, 12, 8, Priority::ordinary); // Arrival: 12, Service: 8
			   //Customer* c3 = new Customer(3, 18, 7, Priority::ordinary); // Arrival: 18, Service: 7
			   //Customer* c4 = new Customer(4, 10, 5, Priority::special); // Arrival: 10, Service: 5
			   //Customer* c5 = new Customer(5, 20, 9, Priority::ordinary); // Arrival: 20, Service: 9
			   //Customer* c6 = new Customer(6, 17, 6, Priority::special); // Arrival: 17, Service: 6
			   //Customer* c7 = new Customer(7, 14, 7, Priority::ordinary); // Arrival: 14, Service: 7
			   //Customer* c8 = new Customer(8, 8, 9, Priority::special); // Arrival: 8, Service: 9
			   //Customer* c9 = new Customer(9, 10, 6, Priority::ordinary); // Arrival: 10, Service: 6
			   //Customer* c10 = new Customer(10, 22, 7, Priority::ordinary); // Arrival: 22, Service: 7
			   //Customer* c11 = new Customer(11, 25, 8, Priority::ordinary); // Arrival: 25, Service: 8
			   //Customer* c12 = new Customer(12, 28, 6, Priority::ordinary); // Arrival: 28, Service: 6
			   //Customer* c13 = new Customer(13, 32, 7, Priority::special); // Arrival: 32, Service: 7
			   //Customer* c14 = new Customer(14, 35, 5, Priority::ordinary); // Arrival: 35, Service: 5
			   //Customer* c15 = new Customer(15, 37, 9, Priority::ordinary); // Arrival: 37, Service: 9
			   //Customer* c16 = new Customer(16, 40, 6, Priority::ordinary); // Arrival: 40, Service: 6
			   //Customer* c17 = new Customer(17, 42, 7, Priority::ordinary); // Arrival: 42, Service: 7
			   //Customer* c18 = new Customer(18, 45, 8, Priority::special); // Arrival: 45, Service: 8
			   //Customer* c19 = new Customer(19, 48, 6, Priority::ordinary); // Arrival: 48, Service: 6
			   //Customer* c20 = new Customer(20, 50, 7, Priority::ordinary); // Arrival: 50, Service: 7

			   //b4->AddCustomer(*c1);
			   //b4->AddCustomer(*c2);
			   //b4->AddCustomer(*c3);
			   //b4->AddCustomer(*c4);
			   //b4->AddCustomer(*c5);
			   //b4->AddCustomer(*c6);
			   //b4->AddCustomer(*c7);
			   //b4->AddCustomer(*c8);
			   //b4->AddCustomer(*c9);
			   //b4->AddCustomer(*c10);
			   //b4->AddCustomer(*c11);
			   //b4->AddCustomer(*c12);
			   //b4->AddCustomer(*c13);
			   //b4->AddCustomer(*c14);
			   //b4->AddCustomer(*c15);
			   //b4->AddCustomer(*c16);
			   //b4->AddCustomer(*c17);
			   //b4->AddCustomer(*c18);
			   //b4->AddCustomer(*c19);
			   //b4->AddCustomer(*c20);


			   ////b4->DisplayTellers();
			   ///*b4->DisplaycustomersList();
			   //b4->DisplaycustomersQueue();*/

			   ////-----------------------
			   //b4->SimulateQueueSystem();
			   ////-----------------------

			   //b4->DisplayTellers();
			   //b4->DisplaycustomersSortedList();
			   //b4->DisplaycustomersQueue();


			   //// Clean up memory
			   //delete b4;
			   //delete c1;
			   //delete c2;
			   //delete c3;
			   //delete c4;
			   //delete c5;
			   //delete c6;
			   //delete c7;
			   //delete c8;
			   //delete c9;
			   //delete c10;
			   //delete c11;
			   //delete c12;
			   //delete c13;
			   //delete c14;
			   //delete c15;
			   //delete c16;
			   //delete c17;
			   //delete c18;
			   //delete c19;
			   //delete c20;

		#pragma endregion

	//******************************************************************************************

    // test case 1 : 
	Bank* b1 = new Bank(3);

	ReadCustomerDataFromFile("00-Test cases/Test Case 1.txt", *b1);
	ofstream outputFile1("01-Reports/Report 1.txt"); // Open a file named "output.txt" for writing

	b1->DisplayReport();

	b1->DisplayReportToFile(outputFile1);

	// Clean up memory
	delete b1;

	//******************************************************************************************


	// test case 2 : 
	Bank* b2 = new Bank(3);

	ReadCustomerDataFromFile("00-Test cases/Test Case 2.txt", *b2);
	ofstream outputFile2("01-Reports/Report 2.txt"); // Open a file named "output.txt" for writing

	b2->DisplayReport();

	b2->DisplayReportToFile(outputFile2);

	// Clean up memory
	delete b2;

	//******************************************************************************************

}