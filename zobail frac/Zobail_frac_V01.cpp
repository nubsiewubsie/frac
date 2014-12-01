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
	int n, d, value;};
struct frac {
	expression f1, f2;
	Oper op;};

void deleteFrac (frac *a, int deletePosition, int n){
	int i = 0;
	for (i = deletePosition; i < n+1; i++)a[i] = a[i+1];}

void ranFrac (frac *a, int n){
     srand((unsigned)time(NULL));   // seeds random # generator  
     int i = n;
     int temp = 0;     
     temp = rb (0,3);
     if (temp == 0) a[i].op = ADD;
     else if (temp == 1) a[i].op = SUB;
     else if (temp == 2) a[i].op = DIV;
     else if (temp == 3) a[i].op = MULT;
     
     a[i].f1.n = rb (-99, 99);
     a[i].f1.d = rb (MIN_NUM, MAX_NUM);
     a[i].f2.n = rb (MIN_NUM, MAX_NUM);
     a[i].f2.d = rb (MIN_NUM, MAX_NUM);
     
     //printf ("\n random fraction is:  %i/%i %c %i/%i  \n",a[i].f1.n, a[i].f1.d, a[i].op, a[i].f1.n,a[i].f1.d);
}

void reduce (frac *exp,int position){
	int r = 0;
	frac *c = exp;
	int *p = &position;
	int numerator = c[*p].f1.n;
	int denominator = c[*p].f1.d;
	 	do
	    {
	        r = c[*p].f1.n % c[*p].f1.d;
	        if(r == 0)
	            break;
	        c[*p].f1.n = c[*p].f1.d;
	        c[*p].f1.d = r;
	    }while(true);
   		
   	c[*p].f1.n = numerator/c[*p].f1.d;
   	c[*p].f1.d = denominator/c[*p].f1.d; 	
	 
	r = 0;   
	numerator = c[*p].f2.n;
	denominator = c[*p].f2.d;
	 	do
	    {
	        r = c[*p].f2.n % c[*p].f2.d;
	        if(r == 0)
	            break;
	        c[*p].f2.n = c[*p].f2.d;
	        c[*p].f2.d = r;
	    }
   		while(true); 
   		
   	c[*p].f2.n = numerator/c[*p].f2.d;
   	c[*p].f2.d = denominator/c[*p].f2.d; 
		
   	printf ("\n%i/%i %i/%i\n",c[*p].f1.n,c[*p].f1.d,c[*p].f2.n,c[*p].f2.d);
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
	}
}*/
 
int walkAdd (char s[], int*i , char end){
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
  	frac *c = exp;
  	int *p = &position;
  	
    for (i = 0; s[i]; i++){ 
		
        if (s[i] == '(' && count == 0)
        	{c[*p].f1.n = walkAdd (s, &i, '/');
        	count++;}
        if (s[i] == '/' && count == 1)
             {c[*p].f1.d = walkAdd (s, &i, ')');
             count++;}
        if (s[i] == ')' && s[i+2]=='(')  
             {if (s[i] == '+') c[*p].op = ADD;
             if (s[i] == '-') c[*p].op = SUB;
             if (s[i] == '/') c[*p].op = DIV;
             if (s[i] == '*') c[*p].op = MULT;
			 i+=2;}             
        if (s[i] == '(' && count == 2)
             {c[*p].f2.n =  walkAdd (s, &i, '/');
             count ++;}             
        if (s[i] == '/' && count == 3)
             c[*p].f2.d = walkAdd (s, &i,')');
    }
    printf ("\n%i/%i %i/%i\n",c[*p].f1.n,c[*p].f1.d,c[*p].f2.n,c[*p].f2.d);
}

void sortVal (int numExp, frac * exp){
	int i;
	for (i=numExp;i>numExp;i++)
	{
		//reduce (exp,i);
	}
}

int main (){
	frac exp [NUM_EXPRESSIONS];
	int numExp =1;
	int leave = 0;
	char choice;
	char string [80] = "(54/-54)+(88/-1)";
	//parse (string,1,exp);
	//reduce (exp,1);
	printf ("Fraction program\nChoose an operation\na - exit\t\tb - sort by value\nc - sort by operator\td - sort by answer\n");
	printf ("e - enter expression\tf - get random expression\ng - view expressions\th - view answers\ni - delete expression\n");
	do
	{
		fflush (stdin);
		scanf ("%c",&choice);
		switch (choice)
		{
		case 'a' :
			printf ("Good bye\n");
			leave = 1;
			break;
		case 'b' :
			printf ("Sorting by Value\n");
			break;
		case 'c' :
			printf ("Sorting by operator\n");
			break;
		case 'd' :
			printf ("Getting random expression\n");
			break;
		case 'e' :
			printf ("Printing expressions\n");
			break;
		case 'f' :
			printf ("Get random expression\n");
			break;
		case 'g' :
			printf ("View expression\n");
			break ;
		case 'h' :
			printf ("Displaying expressions");
			break; 
		default :
			printf ("Incorrect input\n");
			printf ("Fraction program\nChoose an operation\na - exit\t\tb - sort by value\nc - sort by operator\td - sort by answer\n");
			printf ("e - enter expression\tf - get random expression\ng - view expressions\th - reduce fractions\ni - delete expression\n");
			break;
		}
	}while (leave==0);
	//system ("PAUSE");   
}




