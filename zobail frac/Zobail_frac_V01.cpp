#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 
#include <time.h>

#define GETPARSE "(54/12)+(88/12)"
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
    for (;s[*i]!=end;(*i)++)
    {   
        printf ("%i\n",n);
        n*=10;
        n+=s[*i] - '0';
    }
    return n;
}

int parse (char s[],int position,frac *exp){
    int i =0;
    int j = 0;
    int count = 0;
  
    for (i = 0; s[i]; i++){ // PARSES THE NUMERATOR AND STORES IT AS AN INT            
        if (s[i] == '(' && count == 0)
           {exp[position].f1.n = walkAdd (s, &i, '/');
           count++;}
           
        else if (s[i] == '/' && count == 1)
             {exp[position].f1.d = walkAdd (s, &i, ')');
             count++;}
             
        else if (s[i] == ')' && s[i+2]=='(')  
             {if (s[i] == '+') exp[position].op = ADD;
             if (s[i] == '-') exp[position].op = SUB;
             if (s[i] == '/') exp[position].op = DIV;
             if (s[i] == '*') exp[position].op = MULT;}
             
        else if (s[i] == '(' && count == 2)
             exp[position].f2.n =  walkAdd (s, &i, '/');
             
        else if (s[i] == '/' && count == 3)
             {exp[position].f2.d = walkAdd (s, &i,')');
             count++;}             
    }
    printf ("%i/",exp[position].f1.n);
    printf ("%i",exp[position].f1.d);
    printf (" %i/",exp[position].f2.n);
    printf ("%i\n\n",exp[position].f2.d);
}

int main (){
	frac exp [NUM_EXPRESSIONS];
	parse (GETPARSE,1,exp);
	system ("PAUSE");   
}
