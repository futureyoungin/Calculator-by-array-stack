#pragma once

#include "ArrayStack.h"
#include "CreateStack.h"
#include <stdio.h>

bool IsEmptyStack(Stack *pStack) {
	if (pStack->top == - 1) {
		printf("\tStack is Empty\n");
		return true;
	}
	else {
		return false;
	}
}

bool int_IsEmptyStack(int_Stack *pStack) {
	if (pStack->top == -1) {
		printf("\tint_Stack is Empty\n");
		return true;
	}
	else {
		return false;
	}
}