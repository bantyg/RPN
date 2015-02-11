#include <stdio.h>
#include "rpn.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "expr_assert.h"

void test_to_convert_char_Number_to_int(){
	char* strNum = "1";
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

void test_to_evaluate_the_1_plus_2_operation_for_two_digits(){
	char* strExp = "11 22 +";
	Result result = evaluate(strExp);
	assertEqual(result.status,33);
}

void test_to_evaluate_the_3_minus_2_operation(){
	char* strExp = "2 3 -";
	Result result = evaluate(strExp);
	assertEqual(result.status,-1);
}

void test_to_evaluate_the_3_minus_2_operation_for_two_digits(){
	char* strExp = "22 33 -";
	Result result = evaluate(strExp);
	assertEqual(result.status,-11);
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
	char* strExp = "11 c + + 2";
	Result result = evaluate(strExp);
	assertEqual(result.error,1);
}

void test_to_convert_the_infix_expression_to_posfix_expression(){
	char* strExp = "1 + 2";
	char *posfix = "1 2 +";
	char* result = infixToPostfix(strExp);
	assertEqual(strcmp(result,posfix),0);
}

void test_to_convert_the_infix_expression_to_posfix_expression_for_2_operators(){
	char* strExp = "1 + 2 + 3";
	char *posfix = "1 2 + 3 +";
	char* result = infixToPostfix(strExp);
	assertEqual(strcmp(result,posfix),0);
} 

void test_to_convert_the_infix_expression_to_posfix_expression_for_2_operators_for_double_digit(){
	char* strExp = "11 + 32 + 33";
	char *posfix = "11 32 + 33 +";
	char* result = infixToPostfix(strExp);
	assertEqual(strcmp(result,posfix),0);
} 

void test_to_convert_the_infix_expression_to_posfix_expression_for_2_operators_for_four_digit(){
	char* strExp = "1145 + 3245 + 3345";
	char *posfix = "1145 3245 + 3345 +";
	char* result = infixToPostfix(strExp);
	assertEqual(strcmp(result,posfix),0);
} 

void test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function(){
	assertEqual(strcmp(infixToPostfix("2 + 3"), "2 3 +"), 0);  
}

void test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_multipleDigit(){
	assertEqual(strcmp(infixToPostfix("2234 + 3543"), "2234 3543 +"), 0);  
}

void test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_long(){
	assertEqual(strcmp(infixToPostfix("2 + 3 * 4"), "2 3 4 * +"), 0);  
}

void test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_long_multipleDigit(){
	assertEqual(strcmp(infixToPostfix("232 + 345 * 456"), "232 345 456 * +"), 0);  
}

void test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_long_for_with_presidence(){
	assertEqual(strcmp(infixToPostfix("2 * 3 + 4"), "2 3 * 4 +"), 0);  

}

void test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_long_for_with_multipleDigit_for_presidence(){
	assertEqual(strcmp(infixToPostfix("232 * 333 + 455"), "232 333 * 455 +"), 0);  
}

void test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_expression1(){
	assertEqual(strcmp(infixToPostfix("A - B + C"), "A B - C +"), 0);  
}

void test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_expression3(){
	assertEqual(strcmp(infixToPostfix("3 + 4 * 5 / 6"), "3 4 5 * 6 / +"), 0);  
}

void test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_long_for_ex(){
	assertEqual(strcmp(infixToPostfix("2.32 * 33.3 + 4.55"), "2.32 33.3 * 4.55 +"), 0);  
}

// void test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_brackets(){
// 	printf("---------------------%s\n",infixToPostfix("X + (Y - Z)") );
// 	assertEqual(strcmp(infixToPostfix("X + ( Y - Z )"), "X Y Z - +"), 0);  
// }