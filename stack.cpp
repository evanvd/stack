#include "stack.h"

void StackInit(stack_t* stk,size_t size)
{
    stk->capacity = size;
    printf("%d %d\n", stk->capacity, stk->size);
    stk->data = (char*)calloc(stk->capacity, sizeof(char));
    size_t index = 0;
    for (; index < stk->capacity; index++)
    {
        scanf("%c", &stk->data[index]);
    }

    stk->size = index;
}


void StackDump(stack_t* stk)
{
    printf("capacity - %lu\n", stk->capacity);
    printf("capacity - %lu\n", stk->capacity);

    for (size_t index = 0; index < stk->size; index++)
    {
        printf("data[%lu] = %c\n", index, stk->data[index]);
    }
}
void StackPush(stack_t* stk, int element)
{
    if (stk->capacity <= stk->size)
    {
        stk->data = (int*)realloc(stk->data,stk->size);
    }
    
    stk->data[stk->size] = element;
}
int StackPop(stack_t* stk)
{
    return stk->data[size];
}

//TODO Push pop dump verify ctr dtr canary realloc