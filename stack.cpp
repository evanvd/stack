#include "stack.h"

void StackInit(stack_t* stk,size_t size)
{
    stk->capacity = size;
    //printf("%lu %lu\n", stk->capacity, stk->size);
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
    printf("capacity - %lu\n", stk->capacity);
    printf("capacity - %lu\n", stk->capacity);

    for (size_t index = 0; index < stk->size; index++)
    {
        printf("data[%lu] = %c\n", index, stk->data[index]);
    }
    
}