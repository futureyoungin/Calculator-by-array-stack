#pragma once
#include "ArrayStack.h"
#include "Top.h"
#include <stdio.h>
#include <stdlib.h>


int CountStackItem(Stack *pStack) {
	
	if (pStack->top == -1)
		return 0;
		
	int CountItem = pStack->top + 1;

	return CountItem;
}

//어떤 기능이야?