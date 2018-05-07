/* Author: Eric Goodwin
 * Class: CS2750 Section E01 Assingment 5
 * Dr Sanjiv Bhatia
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// Reads all the customers in file into a queue
// Returns 1 if failed to open file
// used by both bakery and grocery sims
int loadCustomers ( queue * data ) {
    FILE   * file   = NULL;
    Customer_T * cust = NULL;

    initializeQueue( data ); //creates a linked list to hold all customer data from file

    if ( (file = fopen( "customers", "rb" )) == NULL )
        return 0;

    while (!feof(file)){
        cust = malloc(sizeof(Customer_T));
        fread(cust, sizeof( Customer_T), 1, file ); //reads from file
        if (!feof(file)) //read until end of file
            EnQueue( cust, data );  // adds data from file into the linked list.  creates new nodes as neccesary
    }

    fclose( file );

    return 1;
}


//creates the report to be displayed at end of processing
//seperate function for single and multi queues.  
void printReport_single ( Clerk_T * clerks, queue * lane, int numLanes) {
    int index = 0; //used to control loop
    int total_served = 0;
    int total_wait = 0;
    int total_serv = 0;
    int total_idle = 0;
	
//loops through the registers to calculate times
    for ( index = 0; index < numLanes; index++ ) {
        total_served += clerks[index].total_customers;
        if ( clerks[index].total_customers != 0 ) {
            total_wait += clerks[index].total_wait_time;
            total_serv += (clerks[index].total_service_time + clerks[index].total_wait_time);
        }
        
        total_idle += clerks[index].total_idle;
    }


    printf( "****Performance Report*****\n" );

//display averages
//per conversation and email with Dr. Bhatia, ints are acceptable for the assignment
//these could have been type casted to floats in order to get floats.
    printf( "Total customers served: %d\n", total_served );
    printf( "Average wait time: %d\n", total_wait / total_served );
    printf( "Average service time: %d\n", total_serv / total_served );
    printf( "Avgerage idle time: %d\n", total_idle / numLanes );

}

void printReport_multi (Clerk_T * clerks, queue * lanes, int numLanes){

    int index = 0;
    int total_served = 0;
    int total_wait = 0;
    int total_serv = 0;
    int total_idle = 0;

//loops through the registers to calculate times
    for ( index = 0; index < numLanes; index++ ) {
        total_served += clerks[index].total_customers;
        if ( clerks[index].total_customers != 0 ) {
            total_wait += clerks[index].total_wait_time;
            total_serv += (clerks[index].total_service_time + clerks[index].total_wait_time);
        }
        
        total_idle += clerks[index].total_idle;
    }


    printf( "****Performance Report*****\n" );

//display averages
//per conversation and email with Dr. Bhatia, ints are acceptable for the assignment.
//these could have been type casted to floats
    printf( "Total customers served: %d\n", total_served );
    printf( "Average wait time: %d\n", total_wait / total_served );
    printf( "Average service time: %d\n", total_serv / total_served );
    printf( "Average idle time: %d\n", total_idle / numLanes );

}
    // keeps track of times as program runs
void calculateTotals ( Clerk_T  * clerks, Customer_T * cust, int timer  ) {
    clerks->complete_time = (timer + cust->service);
    clerks->total_wait_time += (timer - cust->arrival);
    clerks->total_service_time += cust->service;
    clerks->total_customers++;
    clerks->free = 0;
    free(cust); 
}


//following finctions sets of values clerk struct to 0.  Slightly different for single queue checkout
// and multiqueue
void initClerks ( Clerk_T * clerks, queue * lane, int numLanes  ) {
    int index = 0;

    initializeQueue( lane );

    for ( index = 0; index < numLanes; index++ ) {
        clerks[index].complete_time = 0;
        clerks[index].total_wait_time = 0;
	clerks[index].total_service_time = 0;
	clerks[index].total_idle = 0;
        clerks[index].total_customers = 0;
        clerks[index].free   = 1; // flag
    }

}


void initClerks_multi ( Clerk_T * clerks, queue * lanes, int numLanes  ) {
    int index = 0;


    for ( index = 0; index < numLanes; index++ ) {
	initializeQueue( lanes + index );
    	
	clerks[index].complete_time = 0;
        clerks[index].total_wait_time = 0;
	clerks[index].total_service_time = 0;
	clerks[index].total_idle = 0;
        clerks[index].total_customers = 0;
        clerks[index].free   = 1; // flag
    }

}
