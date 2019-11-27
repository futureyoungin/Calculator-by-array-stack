#pragma once
#include "ArrayStack.h"
#include "CreateStack.h"
#include "Pop.h"
#include <stdio.h>

void ClearStack(Stack *pStack) {
	if (pStack == NULL) {
		printf("ERROR : There isn't a Stack\n");
		return;
	}
	else {
		while (pStack->top != -1) {
			Pop(pStack);
		}
	}
}

void int_ClearStack(int_Stack *pStack) {
	if (pStack == NULL) {
		printf("ERROR : There isn't a Stack\n");
		return;
	}
	else {
		while (pStack->top != -1) {
			int_Pop(pStack);
		}
	}
}