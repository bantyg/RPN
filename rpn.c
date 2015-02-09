#include "rpn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int toInt(char* ch){
	return atoi(ch);
}

int isOperator(char a){
	return (a=='+' || a=='-' || a=='*' || a=='/' || a=='^');
}

int performOperation(int num1,int num2,char op){
	int i,result = num2;
	switch(op){
		case '+':return num2+num1;
		case '-':return num2-num1;
		case '*':return num2*num1;
		case '/':return num2/num1;
		default:return 0;
	}
}

int isDigit(char c){
	return c!= ' ' && c>=48 && c<=57;
}

int getResult(Stack s1,char c){
	int j,num1,num2,ans;
	Result result;
	num1 =*(int*)pop(&s1);
	num2 =*(int*)pop(&s1);
	ans = performOperation(num1,num2,c);
	return ans;
}

void pushResultInStack(Stack* s1,char *op,int *opCount,int *result){
	if(s1->list->count > 1){
		*result = getResult(*s1,*op);
		push(s1,result);
		(*opCount)++;
	}
}

void pushDigitInStack(Stack* s1,char *c,int *operandCount,int *digit){
	if(isDigit(*c)){
		(digit)[++(*operandCount)] = atoi(c);
		push(s1,&((digit)[*operandCount]));
	}
}


Result evaluate(char *expression){
	int i,*digit,result;
	int operandCount=0,operatorCount=0;
	Stack stack = createStack();
	digit = malloc(strlen(expression)*sizeof(int));
	for (i = 0; i < strlen(expression); ++i){
		if(!isOperator(expression[i]) && expression[i] != ' '){
			pushDigitInStack(&stack,&expression[i],&operandCount,digit);
			while(expression[++i] != ' '){}
		}
		if(isOperator(expression[i])){
			if(stack.list->count <= 1) return (Result){1,0};
			pushResultInStack(&stack,&expression[i],&operatorCount,&result);
		}
	}
	return (operandCount != operatorCount+1)?(Result){1,0}:(Result){0,result};
}







