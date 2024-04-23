# Bank-Queue-Management-system (BQMS)
My Bank Queue Management System streamlines bank operations by managing queues, reducing wait times, and enhancing staff efficiency. Features include queue management, ticketing, staff dashboards, and analytics. It improves customer satisfaction, operational efficiency, and decision-making.

## Objective
The objective of the Bank Queue Management System (BQMS) project is to develop a console-based application in C++ that efficiently manages customer queues in a bank. The system aims to assign customers to tellers for service while minimizing wait times.

## Core Features
1. **Customer Queue Management:** Implement a Queue data structure to manage customers waiting for service. Basic operations such as enqueue (customer arrival), dequeue (customer served), and display (current queue status) should be supported.
2. **Teller Assignment:** Simulate multiple tellers in the bank, each capable of serving customers. Use an Array or Linked List data structure to manage tellers, with each teller being either available or busy.
3. **Service Time Simulation:** Randomly assign a service time to each customer-teller interaction to simulate real-world variability. Manage teller availability and update it as customers are served.
4. **Priority Queue Option:** Introduce a priority queue for certain customers, such as those with special needs, elderly customers, or premium account holders, to ensure they are served more quickly.
5. **Waiting Time Analysis:** Calculate and display metrics such as average waiting time, average service time, and teller utilization rates to evaluate the efficiency of the queue system.

## Data Structures Used
- **Generic Queue:** For managing customers waiting for service.
- **Generic Linked List:** For handling multiple tellers.

