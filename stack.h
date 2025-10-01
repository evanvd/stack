#include <stdio.h> 
#include <stdlib.h>

typedef struct stack_t
{
    int* data = {};
    size_t size = 0;
    size_t capacity = 0;
} stack_t;

enum stackError 
{
    NoErr = -1,
    CanaryErr = 1,

};

void StackInit(stack_t* stk, size_t size);
void StackDump(stack_t* stk);
void StackPush(stack_t* data, int element);
int StackPop(stack_t* data);
void StackDestroy(stack_t* stk);
stackError StackVerify(stack_t* stk);