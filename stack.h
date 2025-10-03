#include <stdio.h> 
#include <stdlib.h>

enum stackError 
{
    NoErr = -1,
    LeftCanaryErr = 1,
    RightCanaryErr = 2,
    NullData = 3
};

typedef struct stack_t
{
    int* data = {};
    size_t size = 0;
    size_t capacity = 0;
    stackError stack_error = NoErr;
} stack_t;

void StackInit(stack_t* stk, size_t capacity);
void StackDump(stack_t* stk);
void StackPush(stack_t* data, int element);
int StackPop(stack_t* data);
void StackDestroy(stack_t* stk);
stackError StackVerify(stack_t* stk);

void CallFromConsole(stack_t* stk, char* console_input);