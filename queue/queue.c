/* Author: Eric Goodwin
 * CS2750 Section E01 Assignment 5
 * Dr. Sanjiv Bhatia
 */


#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


//these functions are relatively standard for linked lists.  taken mostly from textbooks/online materials


void initializeQueue ( queue * q ) {
    q->front = NULL;
    q->rear  = NULL;

    q->numCust = 0;

    return;
}

//checks if any nodes are remaining the linked list
int queueEmpty ( queue * q ) {
    return ( (q->numCust == 0) ? 1 : 0 );
}

//used to keep track of the number of codes in the linked list
int queueSize ( queue * q ) {
    return q->numCust;
}

// Used to get  the arrival time of front customer
int getArrivalTime ( queue * q ) {
    if ( q->numCust > 0 )
        return q->front->customer->arrival;
    else
        return -1;
}
//adds customer to linked list
void EnQueue ( Customer_T * cust, queue * q ) {
    node * new_node;

    new_node = malloc( sizeof( node ) ); //allocates memory as new nodes are needed

    new_node->customer = cust;
    new_node->next     = NULL;

    if ( q->numCust == 0 )
        q->front = new_node;
    else
        q->rear->next = new_node;
   
    q->rear = new_node;
    q->numCust++;

    return;
}
// removes customer from linked list
// this function returns a Customer_T struct for purposes of transfering from the data queue to a checkout
// when its that customer's time.
Customer_T * DeQueue ( queue * q ) {
    if ( q->numCust == 0 ) {
        printf( "Queue is empty\n" );
        return NULL;
    }

    node   * node_temp;
    Customer_T * cust_temp;

    node_temp = q->front;
    cust_temp = node_temp->customer;

    // null if last in queue
    q->front = node_temp->next;

    q->numCust--;

    if ( q->numCust == 0 )
        q->rear == NULL;

    free( node_temp ); //releases the memory the temporary node was given

    return cust_temp;
}

