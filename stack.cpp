#include "stack.h"

void StackInit(stack_t* stk,size_t size)
{
    stk->capacity = size;
    stk->data = (int*)calloc(stk->capacity, sizeof(int));
    size_t index = 0;
    for (; index < stk->capacity; index++)
    {
        scanf("%d", &stk->data[index]);
    }
    stk->size = index;
}

void StackDump(stack_t* stk)
{
    StackVerify(stk);    
    printf("capacity - %lu\n", stk->capacity);
    printf("capacity - %lu\n", stk->capacity);

    for (size_t index = 0; index < stk->size; index++)
    {
        printf("data[%lu] = %c\n", index, stk->data[index]);
    }
    StackVerify(stk);    
}

void StackDestroy(stack_t* stk)
{
    free(stk->data);
    stk->size = 0;
    stk->capacity = 0;
}

void StackPush(stack_t* stk, int element)
{
    StackVerify(stk);    
    if (stk->capacity <= stk->size)
    {
        stk->data = (int*)realloc(stk->data,stk->size);
    }
    stk->data[stk->size] = element;
    StackVerify(stk);    
}

int StackPop(stack_t* stk)
{
    StackVerify(stk);    
    return stk->data[stk->size-1];
    stk->data[stk->size-1] = 0;
    stk->size--;
    StackVerify(stk);
}

stackError StackVerify(stack_t* stk)
{
    return NoErr;
}

//TODO Push 
//TODO pop dump 
//TODO verify ctr dtr canary realloc