/* Author: Eric Goodwin
 * CS2750 Section E01 Assignment 5
 * Dr. Sanjiv Bhatia
 */

/* Write a program to generate random numbers to be associated with the time of arrival and the
service time requirement for the customer. The time is a logical entity and can be expressed
as a float, instead of the usual HH:MM:SS format. The arrival time will increase linearly
with every customer (assuming that a customer arrives, on an average, every 50 seconds).
Each customer will require between 100 and 400 seconds of service time.
This program will generate a list of two fields (as specified above) and write them to a file
named customers.
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"

#define MAX 100

int main(){
	int MAX_SERVICE_TIME = 300;
	int MIN_SERVICE_TIME = 100;
	int AVERAGE_ARRIVAL = 50;

	srand(time(NULL));
	int service_random;
	int arrival = 0;
	int service;
	int index;

	FILE *fp;
	fp = fopen("customers", "wb");
	
	//calculates arrival time
	//for (index = 0; index <= 99; index++){
	while (index < MAX){
		arrival = arrival + (rand() % (AVERAGE_ARRIVAL+1));

//		arrival_random = rand() % 50 + 1;
//		arrival = (arrival + arrival_random);
	
	
	

	//calculate service time
		service_random = rand() % MAX_SERVICE_TIME + MIN_SERVICE_TIME; // creates random value between 100 and 400
		service = service_random;



// testing		printf("arrival time variable: ""%d\n", arrival);

// testing		printf("service time  variable:" "%d\n", service);



	fwrite(&arrival, sizeof(int), 1, fp);
	fwrite(&service, sizeof(int), 1, fp);
	
	index++;  

	}
	
	fclose(fp);

	return 0;
}

/*float ArrivalTimes(float){
	float r;
	float service_time_randomizer;
	CustomerTime customers_times[20];
	int index;

	for (index = 0; index < 21; index++){
		r = rand() % 300 + 100;
		customers_times[index].arrival_t = (0 + (ARRIVAL_AVG*index)+r);
	};*/
