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
	char *FirstToken; // ' '���ֱ�.
	char diameter[] = " ";
	
	
	Stack *pStack = CreateStack(5000);

	
	printf("������ �Է��ϼ��� : \n");
	gets_s(Math, sizeof(Math));
	FirstToken = strtok(Math, diameter);
	strcat(MathString, FirstToken);
	while (FirstToken != NULL) {
		FirstToken = strtok(NULL, diameter);
		if (FirstToken == NULL)
			break;
		strcat(MathString, FirstToken);
	}

	printf("\n����� �� : %s\n", MathString);
	

	if (!CheckPar(MathString, pStack) || !CheckOperator(MathString) || !CheckEquationOrder(MathString) || !CheckAll(MathString))
		return 0;
		//���� ������ ������ �˻縦 ��ģ �� ��꿡 ����.


	DestroyStack(pStack);
	



	int_Stack *DigitStack = CreateIntStack(strlen(MathString)); //��� ���, ���н� �߿��� ���ڰ� �� ����
	Stack *OperatorStack = CreateStack(strlen(MathString)); // Operator�� �� ����
	//�� 2���� ������ �̿��Ͽ� ���⸦ ����.


	FirstToken = MathString;
	
	printf("\n����� : %d\n", Calculations(OperatorStack, DigitStack, FirstToken));

	ClearStack(OperatorStack);
	int_ClearStack(DigitStack);
	DestroyStack(OperatorStack);
	DestroyIntStack(DigitStack);

	return 0;
}