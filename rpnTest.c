#include <stdio.h>
#include "rpn.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "expr_assert.h"

void test_to_convert_char_Number_to_int(){
	char strNum = '1';
	assertEqual(toInt(strNum),1);
}

void test_to_check_the_input_is_operator_or_not(){
	char op = '+';
	assertEqual(isOperator(op),1);
}

void test_to_check_the_input_is_operator_or_not_if_input_is_numChar(){
	char op = '1';
	assertEqual(isOperator(op),0);
}

void test_to_check_the_input_in_the_range_of_0_to_9_or_not(){
	char op = '1';
	assertEqual(isDigit(op),1);
}


void test_to_check_the_input_in_the_range_of_0_to_9_or_not_for_char(){
	char op = 'w';
	assertEqual(isDigit(op),0);
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

void test_to_evaluate_the_3_minus_2_operation_will_show_error_1(){
	char* strExp = "2 3 - 3";
	Result result = evaluate(strExp);
	assertEqual(result.error,1);
}

void test_to_evaluate_the_1_plus_2_operation_gives_error(){
	char* strExp = "1 2 + +";
	Result result = evaluate(strExp);
	assertEqual(result.error,1);
}


void test_to_evaluate_gives_error_if_there_is_no_operator(){
	char* strExp = "1 2 3 4";
	Result result = evaluate(strExp);
	assertEqual(result.error,1);
}

void test_to_evaluate_gives_error_if_there_is_no_operand(){
	char* strExp = "+ - + +";
	Result result = evaluate(strExp);
	assertEqual(result.error,1);
}

void test_to_evaluate_gives_error_if_there_is_any_character_present_in_the_expression(){
	char* strExp = "1 c + +";
	Result result = evaluate(strExp);
	assertEqual(result.error,1);
}
