/* Author: ERic Goodwin
 * Class: CS2750 Section E01 Assignment 5
 * Dr. Sanjiv Bhatia
 */

#ifndef QUEUE_H
#define QUEUE_H

typedef struct Customer_T{
	int arrival;
	int service;
} Customer_T;

typedef struct Clerk_T{
	int complete_time;
	int total_idle;
	int total_wait_time;
	int total_service_time;
	int total_customers;

	int free ;
} Clerk_T;

typedef struct node {
    Customer_T * customer;   
    struct node * next;
} node;

typedef struct queue {
    node * front;
    node * rear;


    int numCust; // Number of customers in queue
} queue;




void initializeQueue ( queue * );
int queueEmpty ( queue * );
int queueSize ( queue * );
// Used to get the arrival time of front customer
int getArrivalTime( queue * );
void EnQueue ( Customer_T *, queue * );
Customer_T * DeQueue ( queue * );

#endif

