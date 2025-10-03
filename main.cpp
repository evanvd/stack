#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <string.h>

int main()
{
    // TODO do infinite cycle with scanf
    stack_t stk1 = {};
    StackInit(&stk1, (size_t)5);

    StackDump(&stk1);
    char* console_input = "";
    while(strcmp(console_input,"exit") != 0)
    {
        scanf("%s", console_input);
        CallFromConsole(&stk1,console_input);
    }
    StackDestroy(&stk1);

    return 0;
}
