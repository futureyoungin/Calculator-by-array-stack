#pragma once
#include "ArrayStack.h"
#include "Pop.h"
#include "Top.h"
#include "Push.h"
#include "CheckEquation.h"
#include "CreateStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int Calculator(int operand1, char op, int operand2) {
	int Result = 0;

	if (op == '*')
		Result = operand1 * operand2;
	else if (op == '/')
		Result = operand1 / operand2;
	else if( op == '+')
		Result = operand1 + operand2;
	else if (op == '-')
		Result = operand1 - operand2;

	return Result;
}

int Calculations(Stack *OperatorStack, int_Stack *DigitStack, char *FirstToken) {
	


	while (*FirstToken != NULL) {
		if (isdigit(*FirstToken)) {
			int_Push(DigitStack, atoi(FirstToken));
			while (isdigit(*FirstToken))
				++FirstToken;
		}

		else {
			if (*FirstToken == ')') {				
				while (Top(OperatorStack) != '(') {
					int_Push(DigitStack, Calculator(int_Pop(DigitStack), Pop(OperatorStack), int_Pop(DigitStack)));
				}
				Pop(OperatorStack);
				++FirstToken;
			}
			else if ((*FirstToken == '+') || (*FirstToken == '-')) {
				if (Top(OperatorStack) == '*' || Top(OperatorStack) == '/' || Top(OperatorStack) == '+' || Top(OperatorStack) == '-') {
					int_Push(DigitStack, Calculator(int_Pop(DigitStack), Pop(OperatorStack), int_Pop(DigitStack)));
					Push(OperatorStack, *FirstToken);
					++FirstToken;
				}
				else {
					Push(OperatorStack, *FirstToken);
					++FirstToken;
				}
			}
			else if ((*FirstToken == '*') || (*FirstToken == '/')) {
				if (Top(OperatorStack) == '+' || Top(OperatorStack) == '-') {
					Push(OperatorStack, *FirstToken);
					++FirstToken;
				}
				else if (Top(OperatorStack) == '*' || Top(OperatorStack) == '/') {
					int_Push(DigitStack, Calculator(int_Pop(DigitStack), Pop(OperatorStack), int_Pop(DigitStack)));
					Push(OperatorStack, *FirstToken);
					++FirstToken;
				}
				else {
					Push(OperatorStack, *FirstToken);
					++FirstToken;
				}
			}
			else if (*FirstToken == '(') {
				Push(OperatorStack, *FirstToken);
				++FirstToken;
			}

		}
	}//°è»ê

	while(DigitStack->top != -1 && OperatorStack->top != -1)
		int_Push(DigitStack, Calculator(int_Pop(DigitStack), Pop(OperatorStack), int_Pop(DigitStack)));
	

	return int_Pop(DigitStack);
}