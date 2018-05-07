/* Author: Eric Goodwin
 * CS2750 Section E01 - Assignment 5
 * Dr. Sanjiv Bhatia
 *
 * This program is to the simulate part 2 of the grocery store assignment.  This simulates the bakery store style linke
 */





#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


#define INCREMENT 1 //to increase idle time

// Function prototypes

void simulation_single ( queue, int );
void initClerks ( Clerk_T *, queue *, const int );
void calculateTotals ( Clerk_T *, Customer_T *, int );
void printReport_single ( Clerk_T *, queue *, const int);
int loadCustomers ( queue * );
int getArrivalTime ( queue *);

int main () {
    queue data;

    const int numLanes  = 10; //change this to create/reduce # of checkout lines


    //verifies file open correctly 
    
    if ( ! loadCustomers( &data ) ) {
        printf( "Error: File did not open correctly" );
        return 1;
    }

    // Run simulation
    simulation_single( data, numLanes );
    

    return 0;
}

void simulation_single ( queue data, int numLanes) {
    Customer_T * cust = NULL;
    Clerk_T  clerks[numLanes];
    queue lane;

    int Customer_in_line = 1;  // flag to control while loop.  program runs until out of customers in the data queue
    int index = 0; //used to step through through loops
    int timer = 0; //used to measure how many times the while loop runs and essentially becomes how long the store is open and it takes to check out all the customers in the queue.

    initClerks( clerks, &lane, numLanes);  // sets clerk struct member functions to 0

    // Loop runs until all customers in line have been served
    while ( Customer_in_line ) {
        timer += INCREMENT; //keep tracks of total time simulation is ran

        // Check all busy clerks to see if they are complete with their customers
        for ( index = 0; index < numLanes; index++ ) {
            if ( !(clerks[index].free) && (timer >= clerks[index].complete_time) )
                clerks[index].free = 1; //flag
            else if ( clerks[index].free ) //adds time to the clerks idle time if they are free
                clerks[index].total_idle += INCREMENT;  // increases clerk's idle time
        }

        // Check queue for next customer 
        while ( !queueEmpty( &data ) && timer >= getArrivalTime( &data ) ){
            EnQueue( DeQueue( &data ), &lane ); //moves customer data queue to clerk queue
	}

        // sends customer timing data to be calculated
        for ( index = 0; index < numLanes; index++ ) {
            if ( clerks[index].free && !(queueEmpty( &lane )) )
                calculateTotals( (clerks + index), DeQueue( &lane ), timer ); //dimisses customer from clerk queue
        }

        // Checks if any customers remaining to enter the queue
        Customer_in_line = !(queueEmpty( &data ) && queueEmpty( &lane ) );

        // Check if any clerk has met the service time and set to free
        if ( ! Customer_in_line ) {
            for ( index = 0; index < numLanes; index++ ) {
                if ( !(clerks[index].free) )
                    Customer_in_line = 1;
            }
        }
    }
    printReport_single( clerks, &lane, numLanes ); //reports data for simulation run


    return;
}
