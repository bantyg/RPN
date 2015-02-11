#include "rpn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int i;
	char *expr  = "2 * 3 + 4";
	Stack operands = createStack();
	Stack operators = createStack();
	for (i = 0; i < strlen(expr); i++){
		if(!isOperator(expr[i])){
			push(&operands,&expr[i]);
		}
		else
		if(isOperator(expr[i])){
			push(&operators,&expr[i++]);
		}
	}



	return 0;
}