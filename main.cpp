#include <stdio.h>
#include <stdlib.h>
#include "stack.h"



int main()
{
    stack_t stk1 = {};
    StackInit(&stk1,5);

    StackDump(&stk1);
    
    printf("%d", StackPop(&stk1));
    StackDestroy(&stk1);
}