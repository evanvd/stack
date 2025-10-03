#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <string.h>

int main()
{
    stack_t stk1 = {};
    StackInit(&stk1, (size_t)5);

    StackDump(&stk1);
    char console_input[12];
    while(true)
    {
        scanf("%s", console_input);
        if(strcmp(console_input,"EXIT") == 0)
        {
            break;
        }
        CallFromConsole(&stk1,console_input);
    }
    StackDestroy(&stk1);

    return 0;
}