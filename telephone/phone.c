//Author: Eric Goodwin
//Assignment 5 CS 2750 Spring 2016
//Dr. Sanjiv Bhatia



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phone_fmt.h"


int main(){
      char input[20];

      printf("Enter your phone number. Maximum of 20 characters:\n");
      fgets(input, 20, stdin);

//    debug 
//    printf("Before extractNum: %s", input);
//    printf("%c", input[0]);

    phone_fmt(input);

return 0;
}

