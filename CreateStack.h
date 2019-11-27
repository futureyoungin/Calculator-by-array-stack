#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h"

Stack *CreateStack(int size) {
	Stack *pStack = (Stack*)malloc(sizeof(Stack));
	if (pStack == NULL)
		return NULL;

	pStack->stack = (char*)malloc(sizeof(char)*size);
	if (pStack->stack == NULL) {
		free(pStack);
		return NULL;
	}

	pStack->max_size = size;
	pStack->top = -1;

	return pStack;
}

int_Stack *CreateIntStack(int size) {
	int_Stack *pStack = (int_Stack*)malloc(sizeof(int_Stack));
	if (pStack == NULL)
		return NULL;

	pStack->stack = (int*)malloc(sizeof(int)*size);
	if (pStack->stack == NULL) {
		free(pStack);
		return NULL;
	}

	pStack->max_size = size;
	pStack->top = -1;

	return pStack;
}