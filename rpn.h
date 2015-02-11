#include "stack.h"
struct Result{
	int error;
	int status;
};

typedef struct Result Result;
Result evaluate(char *expression);
int toInt(char* ch);
int isOperator(char a);
int isDigit(char c);
char * infixToPostfix(char * expression);



