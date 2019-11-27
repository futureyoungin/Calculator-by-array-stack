#pragma once
#include "ArrayStack.h"
#include "CreateStack.h"

#include <stdio.h>

void DestroyStack(Stack *pStack) {
	if (pStack->max_size > 0)
		free(pStack->stack);
	
	free(pStack);
	printf("DestroyStack is completed\n");
}

void DestroyIntStack(int_Stack *pStack) {
	if (pStack->max_size > 0)
		free(pStack->stack);

	free(pStack);
	printf("DestroyStack is completed\n");
}