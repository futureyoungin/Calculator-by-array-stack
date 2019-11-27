#pragma once
#include "ArrayStack.h"
#include "CreateStack.h"
#include <stdio.h>
#include <stdlib.h>


bool IsFullStack(Stack *pStack) {
	if (pStack->top == pStack->max_size - 1) {
		printf("Stack is Full\n");
		return true;
	}
	else {
		printf("Stack isn't full\n");
		return false;
	}
}