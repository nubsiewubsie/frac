#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 
#include <time.h>

int reduce (int *n, int *d){

	int r = 0;

	int numerator = *n;
	int denominator = *d;
		//printf ("%i, %i",numerator,denominator);
	 	do
	    {
	        r = *n % *d;
	        if(r == 0)
	            break;
	        *n = *d;
	        *d = r;
	    }
   		while(true); //D IS NOW THE GCD
   		
   	*n = numerator/(*d);
   	*d = denominator/(*d); 	
}
int main (
)
{
	int n = 88;
	int d = 12;
	reduce (&n,&d);
	printf ("%i/%i\n",n,d);
}
