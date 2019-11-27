#pragma once
#include <stdio.h>
#include "Push.h"
#include "CreateStack.h"
#include "ArrayStack.h"

char Pop(Stack *pStack) {
	if (pStack->top == -1) {
		printf("ERROR : Stack is empty\n");
		return 0;
	}
	else {
		printf("Pop completed\n");
		return pStack->stack[pStack->top--];
	}
}


int int_Pop(int_Stack *pStack) {
	if (pStack->top == -1) {
		printf("ERROR : Stack is empty\n");
		return 0;
	}
	else {
		printf("Pop completed\n");
		return pStack->stack[pStack->top--];
	}
}