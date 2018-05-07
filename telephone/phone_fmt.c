//Author: Eric Goodwin
//Assignment 5 CS 2750 Spring 2016
//Dr. Sanjiv Bhatia


#include<stdio.h>
#include<stdlib.h>
#include "phone_fmt.h"

char input;
void phone_fmt(char *input){
	int number;
	int index1;
	int index2=0;
	char newArray[10]; 

//	debug
//	printf("before for loop:%s", input); 

	while (index2 < 10){   //stops the loop once 9 digits have been found
	  for (index1 = 0; input[index1]!='\0';){  //searches until null character in input string
		if (isdigit(input[index1])){	//if a digit is found, stores that digiit in NewArray. 
			newArray[index2]=input[index1];
			index1++;  // steps to next element in input string
			index2++; // steps to next element in NewArray
		}
		else if (!(isdigit(input[index1]))){ //if no digit found, steps to next element in input string
		index1++;
		}
	  } 
	}
//	debug
//	printf("newarray:\n");
//	printf("%c\n", newArray[0]);
//	printf("%c\n", newArray[1]);
//	printf("%c\n", newArray[9]);

	//display in format (XXX) XXX-XXXX
	
	printf("(%c%c%c)%c%c%c-%c%c%c%c\n", newArray[0], newArray[1], newArray[2], newArray[3], newArray[4], newArray[5], newArray[6], newArray[7], newArray[8], newArray[9]);
			
}

	//***PREVIOUS ATTEMPT = COULDN'T HANDLE WHITE SPACES****
	//while (*input){
	//	if (isdigit(*input)){
	//		val = strtol(input, &input, 10);
	//		printf("val before displanum function: %d\n", val);
	//	 }
	//	else{
	//	    	input++;
	//	}
	//}

//	displayNum(val);
	

	
//this function was to be used in a previous attempt that took a long int and seperated using divions and modulo.  while this function operated, the function that passed the long int could not handle white spaces.  leaving this in in case I need to refer back to how to use modulo and division to sperate out digits from a long int
//void displayNum(long val){
//	printf("val after passed to functin: %d\n", val);
//
//	int AreaCode;
//	AreaCode = val/10000000;
//	printf("Areacode: (%d)\n", AreaCode);
//
//	int SevenDigitNum;
//	SevenDigitNum = val % 100000000;
//	printf("Seven digitnum: %d\n", SevenDigitNum);
//
//	int Prefix;
//	Prefix = SevenDigitNum/100000;
//	printf("prefix: %d\n", Prefix);
//
//	int Suffix;
//	Suffix = SevenDigitNum % 10000;
//	printf("suffix: %d\n", Suffix);
//	
//	//printf("(%d) " "%d-""%d\n", AreaCode, Prefix, Suffix);
//}


