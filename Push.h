#pragma once
#include <stdio.h>
#include "CreateStack.h"
#include "ArrayStack.h"


void Push(Stack *pStack,  char item) {
	if (pStack->top == pStack->max_size - 1) {
		printf("ERROR : Stack is Full\n");
		return;
	}
	else {
		pStack->stack[++pStack->top] = item;
		printf("Push Complete\n");
	}
}

void int_Push(int_Stack *pStack, int item) {
	if (pStack->top == pStack->max_size - 1) {
		printf("ERROR : Stack is Full\n");
		return;
	}
	else {
		pStack->stack[++pStack->top] = item;
		printf("Push Complete\n");
	}
}
