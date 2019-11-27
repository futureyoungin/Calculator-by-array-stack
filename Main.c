#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Push.h"
#include "CreateStack.h"
#include "ArrayStack.h"
#include "Pop.h"
#include "Top.h"
#include "DestroyStack.h"
#include "IsEmptyStack.h"
#include "IsFullStack.h"
#include "CountStackItem.h"
#include "ClearStack.h"
#include "CheckEquation.h"
#include "Calculator.h"



int main(void) {
	char Math[5000] = { 0 };
	char MathString[5000] = { 0 };	
	char *FirstToken; // ' '없애기.
	char diameter[] = " ";
	
	
	Stack *pStack = CreateStack(5000);

	
	printf("수식을 입력하세요 : \n");
	gets_s(Math, sizeof(Math));
	FirstToken = strtok(Math, diameter);
	strcat(MathString, FirstToken);
	while (FirstToken != NULL) {
		FirstToken = strtok(NULL, diameter);
		if (FirstToken == NULL)
			break;
		strcat(MathString, FirstToken);
	}

	printf("\n계산할 식 : %s\n", MathString);
	

	if (!CheckPar(MathString, pStack) || !CheckOperator(MathString) || !CheckEquationOrder(MathString) || !CheckAll(MathString))
		return 0;
		//식의 오류가 없는지 검사를 마친 뒤 계산에 들어간다.


	DestroyStack(pStack);
	



	int_Stack *DigitStack = CreateIntStack(strlen(MathString)); //계산 결과, 수학식 중에서 숫자가 들어갈 스택
	Stack *OperatorStack = CreateStack(strlen(MathString)); // Operator가 들어갈 스택
	//총 2개의 스택을 이용하여 계산기를 구현.


	FirstToken = MathString;
	
	printf("\n계산결과 : %d\n", Calculations(OperatorStack, DigitStack, FirstToken));

	ClearStack(OperatorStack);
	int_ClearStack(DigitStack);
	DestroyStack(OperatorStack);
	DestroyIntStack(DigitStack);

	return 0;
}