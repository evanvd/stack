#include <stdio.h> 
#include <stdlib.h>
typedef struct stack_t
{
    int* data = {};
    size_t size = 0;
    size_t capacity = 0;
} stack_t;

void StackInit(stack_t* stk, size_t size);
void PutStack(stack_t* stk);
void StackPush(stack_t* data, int element);
int StackPop(stack_t* data);
void StackDestroy(stack_t* stk);
