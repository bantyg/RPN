#include "rpn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int toInt(char ch){
	char str[] = {ch,'\0'};
	return atoi(str);
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


Result evaluate(char *expression){
	int i,j,*digit,result,count;
	int operandCount=0,operatorCount=0;
	Stack stack = createStack();
	Result error = {1,0};
	digit = malloc(strlen(expression)*sizeof(int));
	for (i = 0; i < strlen(expression); ++i){
		if(isDigit(expression[i])){
			digit[++operandCount] = atoi(&expression[i]);
			push(&stack,&digit[operandCount]);
		}
		if(expression[i] != ' ' && isOperator(expression[i])){
			if(stack.list->count <= 1)return error;
			result = getResult(stack,expression[i]);
			push(&stack, &result);
			operatorCount++;
		}
	}
	if(operandCount != operatorCount+1) return error;		
	return (Result){0,result};
}







