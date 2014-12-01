#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 
#include <time.h>

#define NUM_EXPRESSIONS 30



enum Oper {ADD, SUB, MULT, DIV};

int deleteExp (int);
int getExp (int);

struct expression {
	int n, d, value;
};
struct frac {
	expression f1, f2;
	Oper op;
};


void deleteFrac (frac *a, int deletePosition, int n){
	
	int i = 0;
	
	for (i = deletePosition; i < n+1; i++)a[i] = a[i+1];
		
}


void reduce (frac *exp,int position){
	int r = 0;
	int numerator = exp[position].f1.n;
	int denominator = exp[position].f1.d;
		//printf ("%i, %i",numerator,denominator);
	 	do
	    {
	        r = exp[position].f1.n % exp[position].f1.d;
	        if(r == 0)
	            break;
	        exp[position].f1.n = exp[position].f1.d;
	        exp[position].f1.d = r;
	    }
   		while(true);
   		
   	exp[position].f1.n = numerator/exp[position].f1.d;
   	exp[position].f1.d = denominator/exp[position].f1.d; 	
	 
	r = 0;   
	numerator = exp[position].f2.n;
	denominator = exp[position].f2.d;
		//printf ("%i, %i",numerator,denominator);
	 	do
	    {
	        r = exp[position].f2.n % exp[position].f2.d;
	        if(r == 0)
	            break;
	        exp[position].f2.n = exp[position].f2.d;
	        exp[position].f2.d = r;
	    }
   		while(true); 
   		
   	exp[position].f2.n = numerator/exp[position].f2.d;
   	exp[position].f2.d = denominator/exp[position].f2.d; 
		
   	printf ("\n%i/%i %i/%i\n",exp[position].f1.n,exp[position].f1.d,exp[position].f2.n,exp[position].f2.d);
}

int rb (int min, int max)
{
	return rand() % (max - min + 1) + min;
}

/*int validateExp (char s[]){ 
    int i = 0;
    int j = 0;
    for (i = 0; s[i]; i++){
        if (s[i] == '(' && s[i+1] == '/') return 0;
        if (s[i] == '/' && s[i+1] == ')') return 0;
        if (s[i] == ')' && s[i+1] == '(') return 0;
    }*/
 
int walkAdd (char s[], int*i , char end){ //broken
    int n=0;
    int neg = 0;
    (*i)++;
    for (;s[*i]!=end;(*i)++)
    {   
    	if (s[*i]=='-')
    	{
			neg = 1;
			(*i)++;
		}
        printf ("\nn = %i, i = %i, s[i] = %c",n,*i,s[*i]);
        n*=10;
        n+=s[*i] - '0';
    }
    if (neg == 1)
    {
    	printf ("hi");
    	n*=-1;    	
	}
    printf ("\n n = %i",n);
    return n;
}

int parse (char s[],int position,frac *exp){
    int i =0;
    int j = 0;
    int count = 0;
  	printf ("%s\n",s);
  	
    for (i = 0; s[i]; i++){ 
		
        if (s[i] == '(' && count == 0)
        	{exp[position].f1.n = walkAdd (s, &i, '/');
        	count++;}
        if (s[i] == '/' && count == 1)
             {exp[position].f1.d = walkAdd (s, &i, ')');
             count++;}
        if (s[i] == ')' && s[i+2]=='(')  
             {if (s[i] == '+') exp[position].op = ADD;
             if (s[i] == '-') exp[position].op = SUB;
             if (s[i] == '/') exp[position].op = DIV;
             if (s[i] == '*') exp[position].op = MULT;
			 i+=2;}             
        if (s[i] == '(' && count == 2)
             {exp[position].f2.n =  walkAdd (s, &i, '/');
             count ++;}             
        if (s[i] == '/' && count == 3)
             exp[position].f2.d = walkAdd (s, &i,')');
    }
    printf ("\n%i/%i %i/%i\n",exp[position].f1.n,exp[position].f1.d,exp[position].f2.n,exp[position].f2.d);
}

void sortVal (int numExp, frac * exp){
	int i;
	for (i=numExp;i>numExp;i++)
	{
		reduce (exp,i);
	}
}

int main (){
	frac exp [NUM_EXPRESSIONS];
	int numExp =1;
	char string [80] = "(54/-54)+(88/-1)";
	parse (string,1,exp);
	reduce (exp,1);
	system ("PAUSE");   
}
