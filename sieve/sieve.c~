/* Author: Eric Goodwin
 * CS2750 Section E01 Asssignment 5
 * Dr. Sanjiv Bhatia
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXBYTES 100000 
#define BITSIZE 8 
#define N 100000

void ClearBit(unsigned char [], unsigned int);
void SetBit(unsigned char [], unsigned int);
int  BitVal(unsigned char [], unsigned int);
void PrintPrimes(unsigned char[], unsigned long);
int  Sieve(unsigned char[], unsigned int, unsigned int);

int main(){  
   
    unsigned int maxsize = N;	
    unsigned int i;
    //Set Bit Array
    unsigned char BitArray[MAXBYTES];
    SetBit(BitArray, 0);
    SetBit(BitArray, 1);
    for (i = 2; i < maxsize;i++){

        if(Sieve(BitArray, i, maxsize)==0)
            break;
    }
    PrintPrimes(BitArray, maxsize-1);
    return 0;
}

void PrintPrimes(unsigned char BitArray[], unsigned long maxsize) {
    unsigned int i;
    for (i = 2; i < maxsize; i++)
        if (!BitVal(BitArray, i))
           printf("%ld ", i);
    printf("\n");
}

void SetBit(unsigned char BitArray[], unsigned int pos) {
    BitArray[pos / BITSIZE] |= 1 << (pos % BITSIZE);
}

void ClearBit(unsigned char BitArray[], unsigned int pos) {
    BitArray[pos / BITSIZE] &= ~(1 << (pos % BITSIZE));
}

int BitVal(unsigned char BitArray[], unsigned int pos) {
    return ((BitArray[pos / BITSIZE] & (1 << (pos % BITSIZE))) != 0);
}

int Sieve(unsigned char BitArray[], unsigned int p, unsigned int maxsize) {
    unsigned int i;
    unsigned int j;
    j = 0;
    for (i = 2 * p; i < maxsize; i += p) {
        SetBit(BitArray, i);
        j++;
    }
    return j;
}
