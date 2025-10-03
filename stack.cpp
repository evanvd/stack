#include "stack.h"
#include <assert.h>
#include <string.h>

int CANARY_VALUE = 0xC0FFEE;
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

    stk->data[0] = CANARY_VALUE;

    for (size_t index = 1; index <= stk->capacity; index++) 
    {
        stk->data[index] = POISON_VALUE;
    }

    stk->data[stk->capacity + 1] = CANARY_VALUE;
}

void StackDump(stack_t* stk)
{
    StackVerify(stk);
    printf("\ncapacity - %lu\n", stk->capacity);
    printf("size - %lu\n", stk->size);

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
    if (stk->capacity == stk->size)//TODO fix сравнение с size
    {
        stk->data = (int*)realloc(stk->data,stk->size);
        stk->capacity++;
        stk->data[stk->capacity] = CANARY_VALUE;
    }
    stk->size++;
    stk->data[stk->size] = element;
    StackVerify(stk);    
}

int StackPop(stack_t* stk)
{
    StackVerify(stk);
    if (stk->size == 0)
    {
        printf("Stack empty");
        return 0;
    }
    
    int temp = stk->data[--stk->size];
    StackVerify(stk);
    return temp;
}

stackError StackVerify(stack_t* stk) // TODO verify in main
{
    if (stk == NULL) return NullData;
    if (stk->data == NULL) return NullData;
    
    if (stk->data[stk->capacity + 1] != CANARY_VALUE)
    {
        printf("Right canary value has been changed");
        stk->stack_error = RightCanaryErr;  
        return RightCanaryErr;      
    }

    else if (stk->data[0] != CANARY_VALUE)
    {
        printf("Left canary value has been changed\n");
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
    
    else if(strcmp(console_input,"POP") == 0)
    {
        printf("%d\n", StackPop(stk));
    }
    
    else if(strcmp(console_input, "DUMP") == 0)
    {
        StackDump(stk);
    }
    else
    {
        printf("unknown command\n");
    }
}

//TODO verify