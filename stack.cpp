#include "stack.h"
#include <assert.h>
#include <string.h>

int canary_value = 0xC0FFEE;
const int POISON_VALUE = 0xDEAD;

void StackInit(stack_t* stk,size_t capacity)
{
    stk->capacity = capacity;
    stk->data = (int*)calloc(stk->capacity + 2, sizeof(int));

    if(stk->data == NULL)
    {
        stk->stack_error = NullData;
        return;
    }

    stk->data[0] = canary_value;

    size_t index = 1;
    for (; index < stk->capacity + 1; index++)
    {
        //scanf("%d", &stk->data[index]);
        stk->data[index] = (int)index;
    }

    stk->size = index;
    stk->data[stk->size + 1] = canary_value;
}

void StackDump(stack_t* stk)
{
    StackVerify(stk);
    printf("\ncapacity - %lu\n", stk->capacity);
    printf("size - %lu\n", stk->size - 1);

    for (size_t index = 1; index < stk->size; index++)
    {
        printf("data[%lu] = %d\n", index, stk->data[index]);
    }
    StackVerify(stk);    
}

void StackDestroy(stack_t* stk)
{
    free(stk->data);
    stk->size = POISON_VALUE;
    stk->capacity = POISON_VALUE;
}

void StackPush(stack_t* stk, int element)
{
    if (stk->capacity <= stk->size)
    {
        stk->data = (int*)realloc(stk->data,stk->size);
        stk->capacity++;
    }
    stk->data[stk->size] = element;
    stk->size++;
    stk->data[stk->size] = canary_value;
    StackVerify(stk);    
}

int StackPop(stack_t* stk)
{
    StackVerify(stk);
    int temp = stk->data[--stk->size];
    stk->data[stk->size] = canary_value;
    StackVerify(stk);
    return temp;
}

stackError StackVerify(stack_t* stk) // TODO verify in main
{
    if (stk->data[stk->size + 1] != canary_value)
    {
        printf("Right canary value has been changed");
        stk->stack_error = RightCanaryErr;  
        return RightCanaryErr;      
    }

    else if (stk->data[0] != canary_value)
    {
        printf("Left canary value has been changed");
        stk->stack_error = LeftCanaryErr;
        return LeftCanaryErr;
    }
    return NoErr;
}

void CallFromConsole(stack_t* stk, char* console_input)
{
    if(strcmp(console_input, "PUSH") == 0)
    {
        int push_data;
        scanf("%d",&push_data);
        StackPush(stk, push_data);
    }
    
    if(strcmp(console_input,"POP") == 0)
    {
        StackPop(stk);
    }
    
    if(strcmp(console_input, "DUMP") == 0)
    {
        StackDump(stk);
    }
    else
    {
        printf("unknown command");
    }
}

//TODO verify