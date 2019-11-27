#pragma once

#include <stdio.h>

typedef struct {
	char *stack;
	int max_size;
	int top;

}Stack;

typedef struct {
	int *stack;
	int max_size;
	int top;

}int_Stack;

typedef enum { false = 0, true = 1 } bool;