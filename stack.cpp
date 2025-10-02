#include "stack.h"
#include <assert.h>

int canary_value = 0xC0FFEE;
const int POISON_VALUE = 0xDEAD;

void StackInit(stack_t* stk,size_t size)
{
    stk->capacity = size;
    stk->data = (int*)calloc(stk->capacity + 2, sizeof(int));
    stk->data[stk->capacity + 1] = canary_value;
    size_t index = 1;
    for (; index < stk->capacity + 1; index++)
    {
        //scanf("%d", &stk->data[index]);
        stk->data[index] = index;
    }
    stk->size = index;
    stk->data[stk->size + 1] = canary_value;
}

void StackDump(stack_t* stk)
{
    StackVerify(stk);
    printf("\ncapacity - %lu\n", stk->capacity);
    printf("size - %lu\n", stk->size - 1);

    for (size_t index = 0; index < stk->size; index++)
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
    int temp = stk->data[--stk->size];
    stk->data[stk->size] = canary_value;
    StackVerify(stk);
    return temp;
}

stackError StackVerify(stack_t* stk) // do verify in main
{
    //printf("%d\n", stk->data[stk->size+1]);
    //assert(stk->data[stk->size+1] != canary_value);
    if (stk->data[stk->size] != canary_value)
    {
        printf("лох");        
        return CanaryErr;
    }
    return NoErr;
}

//TODO pop dump 
//TODO verify ctr dtr canary realloc