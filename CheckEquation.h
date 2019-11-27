#pragma once
#include "ArrayStack.h"
#include "Push.h"
#include "Pop.h"
#include "IsEmptyStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define Operator1 '*'
#define Operator2 '/'
#define Operator3 '+'
#define Operator4 '-'



//괄호가 잘 닫혀있는지
bool CheckPar(char *MathString, Stack *pStack) {
	while (*(MathString) != NULL) {
		if (*(MathString) == '(') 
			Push(pStack, *(MathString));
		else if (*(MathString) == ')') {
			if (IsEmptyStack(pStack)) {
				printf("Error : Parenthesis is not matched\n");
				return false;
			}

			else
				Pop(pStack);
		}
		(++MathString);
	}
	if (pStack->top != -1) {
		printf("Error : Parenthesis not matched\n");
		return false;
	}
	else
		return true;
}



//연산자 뒤에 숫자 또는 '('가 오는지.
bool CheckOperator(char *MathString) {
	while (*MathString != NULL) {
		if (*MathString == Operator1 || *MathString == Operator2 || *MathString == Operator3 || *MathString == Operator4) {
			(++MathString);
			if (*MathString == Operator1 || *MathString == Operator2 || *MathString == Operator3 || *MathString == Operator4) {
				printf("Operator ERROR\n");
				return false;
			}
			else if (*MathString == ')') {
				printf("Operator ERROR\n");
				return false;
			}
		}
		(++MathString);
	}
	
	return true;
} 


//숫자 뒤에 '('가 오면 안되고 ')' 뒤에 숫자가 오면 안된다.그리고 '(' 뒤에는 바로 ')'가 오면 안된다.
bool CheckEquationOrder(char *MathString) {
	while (*MathString != NULL) {
		if (isdigit(*MathString)) {
			(++MathString);
			if (*MathString == '(') {
				printf("ERROR : EquationOrder Error \n");
				return false;
			}
		}
		if (*MathString == ')') {
			(++MathString);
			if (isdigit(*MathString)) {
				printf("ERROR : EquationOrder Error \n");
				return false;
			}
		}
		if (*MathString == '(') {
			(++MathString);
			if (*MathString == ')') {
				printf("ERROR : EquationOrder Error \n");
				return false;
			}
		}
		(++MathString);
	}

	return true;
}

bool CheckAll(char *MathString) {
	while (*MathString != '\0') {
		if (*MathString != '+' && *MathString != '-' && *MathString != '*' && *MathString != '/' && *MathString != '(' && *MathString != ')' && *MathString != '0' && *MathString != '1' && *MathString != '2' && *MathString != '3' && *MathString != '4' && *MathString != '5' && *MathString != '6' && *MathString != '7' && *MathString != '8' && *MathString != '9') {
			printf("ERROR : 헤아릴 수 없는 문자가 있습니다\n");
			return false;
		}
		++MathString;
	}
	return true;
}


