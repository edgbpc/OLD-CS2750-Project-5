/*Author: Eric Goodwin
 * CS2750 Section E01 - Assignment 5
 * Dr. Sanjiv Bhatia
 *
 * Ths program is the multi queue version of the bakery_sim.  Instead of queue feeding 10 clerks from a single queue, it has ten seperate queues for each clerk.  Most of the functions are the same with a few modifications to account for the array of queues.  
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define INCREMENT 1 //to increase idle time

// Function prototypes

void simulation_multi ( queue, int );
void initClerks_multi ( Clerk_T *, queue *, int );
void calculateTotals ( Clerk_T *, Customer_T *, int );
void printReport_multi ( Clerk_T *, queue *, int );
int find_a_lane ( Clerk_T *, queue *, int );
int loadCustomers( queue * );

int main () {
    queue data;

    int numLanes = 10; //change to create/reduce # of checkout lanes

    //verifised file open correctly
    
    if (!loadCustomers(&data)){
        printf( "Error openning file." );
        return 1;
    }

    // Run simulation
    simulation_multi( data, numLanes );

    return 0;
}

void simulation_multi ( queue data, int numLanes ) {
    Customer_T* cust = NULL;
    Clerk_T clerks[numLanes];
    queue lanes[numLanes];

    int Customer_in_line  = 1;  // flag to control while loop.  program continues to loop until all customers have made it through the clerk queues.
    int index = 0; // used to control most of the loops
    int lane_index = 0; // catches the lane assignment for the shortest clerk Queue
    int timer = 0; // used to measure how many times the while loop runs and essentially becomes how long the store is open and it takes to check out all the customers in the queue.

    initClerks_multi( clerks, lanes, numLanes );

    //Loop runs until all customers in line have been served
    while ( Customer_in_line ) {
        timer += INCREMENT; //keeps track of total time the simulation is ran

        // Check all busy clerks to see if they are complete with their customer
        for ( index = 0; index < numLanes; index++ ) {
            if ( !(clerks[index].free) && (timer >= clerks[index].complete_time) ) {
                clerks[index].free = 1; //flag
                clerks[index].complete_time = 0;
            }
            else if ( clerks[index].free ) //adds time to the clerks idle time if they are free
                clerks[index].total_idle += INCREMENT; //increases clerk's idle time
        }

        // Check queue for next customer
        while ( !queueEmpty( &data ) && timer >= getArrivalTime(&data)){
            lane_index = find_a_lane(clerks, lanes, numLanes); //function call determines the best lane for the client to use

            EnQueue(DeQueue(&data), (lanes + lane_index)); //dismisses the client from the original linked list into one of the queues in the array. 
        }

        // sends customer timing data to be calculated 
        for ( index = 0; index < numLanes; index++ ) {
            if ( clerks[index].free && !(queueEmpty( lanes + index )) )
                calculateTotals( (clerks + index), DeQueue( lanes + index ), timer ); //dimisses customer from clerk queue
        }

        // Check if any customers remaining to enter the queue
        Customer_in_line = !(queueEmpty( &data ));

        // Checks if any clerk has met the service time and set to free
        if ( ! Customer_in_line ) {
            for ( index = 0; index < numLanes; index++ ) {
                if ( !queueEmpty( lanes + index) || !(clerks[index].free) )
                    Customer_in_line = 1;
            }
        }
    }

    printReport_multi( clerks, lanes, numLanes ); //reports data for simulation run

    return;
}

//used to select the best lane for the customer to check out at
//this function is only used in the multi queue sim.
int find_a_lane (Clerk_T * clerks, queue * lanes, int numLanes ) {
    int index = 0;
    int lane_index = 0;
    int temp_index = 0;
    int next_index = 0;

    // adds 1 if clerk has customer 
    lane_index = queueSize(lanes) + !clerks[0].free;

    if ( lane_index != 0 ) { // steps through each lane to find the shortest
        for ( index = 1; index < numLanes; index++ ) {
            temp_index = queueSize( lanes + index ) + !clerks[index].free;

            if ( temp_index == 0 ) {
                next_index = index;
		break; //jumps to return next_index
            }
            else if ( temp_index < lane_index ) {
                lane_index = temp_index;
                next_index = index;
            }
        }
    }

    return next_index;
}

