#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 
#include <time.h>
#define GETPARSE "(54/12)+(88/12)"


enum Oper {ADD, SUB, MULT, DIV};

int getParse (char);



int rb (int min, int max)
{
  return rand() % (max - min + 1) + min;
}


int valid (char *s){
    int i = 0;
    int j = 0;
    
    for (i = 0; s[i]; i++){
        
        if (s[i] == '(' && s[i+1] == '/') return 0;
        if (s[i] == '/' && s[i+1] == ')') return 0;
        if (s[i] == ')' && s[i+1] == '(') return 0;
    }
    
    
}



struct frac {
       int n, d;
};


struct fracEq {
     frac f1, f2;
     //char oper;
     Oper op;
};


int walkAdd (char *s, int*i , char end){ //WHERE I IS INDEX OF FIRST VALID ELEMENT
    int n=0;
    for (;s[*i]!=end;(*i)++)
    {   
        printf ("%i\n",n);
        n*=10;
        n+=s[*i] - '0';
    }
    return n;
}

int parse (char *s){
    int i =0;
    int j = 0;
    int count = 0;
    fracEq eq1;
    Oper operand;
  
    for (i = 0; s[i]; i++){ // PARSES THE NUMERATOR AND STORES IT AS AN INT            
        if (s[i] == '(' && count == 0)
           {eq1.f1.n = walkAdd (s, &i, '/');
           count++;}
           
        else if (s[i] == '/' && count == 1)
             {eq1.f1.d = walkAdd (s, &i, ')');
             count++;}
             
        else if (s[i] == ')' && s[i+2]=='(')  
             {if (s[i] == '+') operand = ADD;
             if (s[i] == '-') operand = SUB;
             if (s[i] == '/') operand = DIV;
             if (s[i] == '*') operand = MULT;}
             
        else if (s[i] == '/' && count == 2)
             {eq1.f2.d = walkAdd (s, &i,')');
             count++;}
             
        else if (s[i] == '(' && count == 4)
             eq1.f2.n =  walkAdd (s, &i, '/');

    }
          
    printf ("%i/",eq1.f1.n);
    printf ("%i",eq1.f1.d);
    //printf ("%c",eq1.oper);
    printf (" %i/",eq1.f2.n);
    printf ("%i\n\n",eq1.f2.d);
          
//------------------------------------------------------------------------------------------------------------------------------ 
}

int main (){
//char s[80];
parse (GETPARSE);


 
 system ("PAUSE");   
}
