#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    // TODO do infinite cycle with scanf
    stack_t stk1 = {};
    StackInit(&stk1,5);

    StackPush(&stk1, 69);

    StackDump(&stk1);

    //stk1.data[0] = 0;
    
    printf("%d", StackPop(&stk1));

    StackDump(&stk1);


    StackPush(&stk1,3);
    StackDestroy(&stk1);

    return 0;
}
