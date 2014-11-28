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
	int n, d;
};
struct frac {
	expression f1, f2;
	Oper op;
};


int rb (int min, int max)
{
	return rand() % (max - min + 1) + min;
}




int validateExp (char s[]){ 
    int i = 0;
    int j = 0;
    for (i = 0; s[i]; i++){
        if (s[i] == '(' && s[i+1] == '/') return 0;
        if (s[i] == '/' && s[i+1] == ')') return 0;
        if (s[i] == ')' && s[i+1] == '(') return 0;
    }
}

int walkAdd (char s[], int*i , char end){ //broken
    int n=0;
    (*i)++;
    for (;s[*i]!=end;(*i)++)
    {   
        printf ("\nn = %i, i = %i, s[i] = %c",n,*i,s[*i]);
        n*=10;
        n+=s[*i] - '0';
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
           //printf ("\n%i = %i",i,exp[position].f1.n);
           count++;
		   }
           
        if (s[i] == '/' && count == 1)
             {exp[position].f1.d = walkAdd (s, &i, ')');
             count++;
			 printf ("count = %i",count);}
             
        if (s[i] == ')' && s[i+2]=='(')  
             {if (s[i] == '+') exp[position].op = ADD;
             if (s[i] == '-') exp[position].op = SUB;
             if (s[i] == '/') exp[position].op = DIV;
             if (s[i] == '*') exp[position].op = MULT;
			 i+=2;}
			 //printf ("\noperator collected\n i = %i, s[%i] = %c \n count =%i",i,i,s[i],count);}
             
        if (s[i] == '(' && count == 2)
             {exp[position].f2.n =  walkAdd (s, &i, '/');
             count ++;}
             
        if (s[i] == '/' && count == 3)
             exp[position].f2.d = walkAdd (s, &i,')');
                   
    }
    printf ("\n%i/%i %i/%i\n",exp[position].f1.n,exp[position].f1.d,exp[position].f2.n,exp[position].f2.d);
}

int main (){
	frac exp [NUM_EXPRESSIONS];
	char string [80] = "(54/12)+(88/12)";
	parse (string,1,exp);
	system ("PAUSE");   
}
