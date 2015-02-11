#include "rpn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int toInt(char* ch){
	return atoi(ch);
}

int isOperator(char a){
	return (a=='+' || a=='-' || a=='*' || a=='/' || a=='^' || a=='(' || a==')');
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

int handleOperator(char operator){
	switch(operator){
		case '+':return 1;
		case '-':return 1;
		case '*':return 2;
		case '/':return 2;
		case '(':return 3;
		case ')':return 4;
		default:return 0;
	}
}

Stack *handlePrececednce(Stack *operands,Stack *operators,char *temp){
	char *space = " ";
	char brace = '(';
	int i,index;
	if(handleOperator((*(char*)(*operators->top)->data))==1 && handleOperator(*temp)>= 1){
		push(operands,deleteElementAt(operators->list,operators->list->count-2));
		push(operands,space);
	}
	if(handleOperator((*(char*)(*operators->top)->data)) ==2 &&  handleOperator(*temp)>= 2){
		push(operands,deleteElementAt(operators->list,operators->list->count-2));
		push(operands,space);
	}
	return operands;
}

// Stack handleBrace(Stack *operands,Stack *operators,char *temp,int index){
// 	char *space = " ";
// 	if(handleOperator((*(char*)(*operators->top)->data)) ==2 &&  handleOperator(*temp)>= 2){
// 		push(operands,deleteElementAt(operators->list,operators->list->count-2));
// 		push(operands,space);
// 	}

// } 

char * infixToPostfix(char * expression){
	int i,j,k,operatorCount,operandCount,index;
	char *ch,*result,temp=0,*brace;
	Stack operands = createStack();
	Stack operators = createStack();
	result = calloc(strlen(expression) + 1,sizeof(char));
	for (i = 0; i < strlen(expression); i++){
		if(!isOperator(expression[i])){
			push(&operands,&expression[i]);
		}
		else{
			if(isOperator(expression[i])){
				if(operators.list->count >= 1){
					temp = *(char*)(*operators.top)->data;
				}
				push(&operators,&expression[i]);
				handlePrececednce(&operands, &operators,&temp);
				i++;
			}
		}
	}
	operandCount = operands.list->count;
	operatorCount = operators.list->count * 2;
	for (j = 0; j< operandCount; ++j){
		result[j] = *(char*)deleteElementAt(operands.list,0);
	}
	for (k = operandCount; k < operandCount+operatorCount - 1; k++){
		result[k] = ' ';
		result[++k] = *(char*)pop(&operators);
	}
	return result;
}




