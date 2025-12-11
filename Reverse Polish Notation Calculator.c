#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define maxop 100
#define number '0'
#define maxval 100

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

int main(){
    int type;
    double op2;
    char s[maxop];
    
    while ((type = getop(s)) != EOF) {  // Changed from '\n' to EOF
        switch (type){
            case number:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)  // Fixed the condition
                    push(pop() / op2);
                else 
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

int sp = 0;
double val[maxval];

void push(double f){        
    if (sp < maxval)
        val[sp++] = f;
    else 
        printf("error: stack full\n");
}

double pop(void){
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int getop(char s[])
{
    int i, c;
    
    // Skip whitespace
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    
    // If not a digit or decimal point, return the character
    if (!isdigit(c) && c != '.')
        return c;
    
    i = 0;
    // Collect integer part
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    
    // Collect fraction part
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    
    s[i] = '\0';
    
    if (c != EOF)
        ungetch(c);
    
    return number;
}

int buf = EOF;

int getch(void) {
    int c;
    if (buf != EOF) { 
        c = buf; 
        buf = EOF; 
        return c; 
    }
    return getchar();
}

void ungetch(int c) {
    buf = c;
}