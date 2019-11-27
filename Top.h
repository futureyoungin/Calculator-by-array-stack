#pragma once

#include "ArrayStack.h"
#include "Push.h"
#include "CreateStack.h"
#include "Pop.h"

#include <stdio.h>

char Top(Stack *pStack) {
	if (pStack->top == -1) {
		return 0;
	}
	return pStack->stack[pStack->top];
}
