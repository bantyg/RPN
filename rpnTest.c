#include <stdio.h>
#include "rpn.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "expr_assert.h"

void test_to_convert_char_Number_to_int(){
	char* strNum = "1";
	assertEqual(atoi(strNum),1);
}

void test_to_evaluate_the_1_plus_2_operation(){
	char* strExp = "1 2 +";
	Result result = evaluate(strExp);
	assertEqual(result.status,3);
}

void test_to_evaluate_the_3_minus_2_operation(){
	char* strExp = "2 3 -";
	Result result = evaluate(strExp);
	assertEqual(result.status,-1);
}

void test_to_evaluate_the_3_multiply_2_operation(){
	char* strExp = "3 2 *";
	Result result = evaluate(strExp);
	assertEqual(result.status,6);
}

void test_to_evaluate_the_8_devision_4_operation(){
	char* strExp = "4 8 /";
	Result result = evaluate(strExp);
	assertEqual(result.status,0);
}


void test_to_evaluate_for_addition_of_3_operands(){
	char* strExp = "4 8 2 + +";
	Result result = evaluate(strExp);
	assertEqual(result.status,14);
}

void test_to_evaluate_the_8_4_3_plus_minus_(){
	char* strExp = "4 8 2 + -";
	Result result = evaluate(strExp);
	assertEqual(result.status,-6);
}


void test_to_evaluate_the_operation_which_has_operator_in_between(){
	char* strExp = "2 8 4 - 4 + - ";
	Result result = evaluate(strExp);
	assertEqual(result.status,-6);
}

void test_to_evaluate_the_operation_which_has_operator_in_between_with_parenthisis(){
	char* strExp = "5 1 2 + 4 * + 3 -";
	Result result = evaluate(strExp);
	assertEqual(result.status,14);
}


