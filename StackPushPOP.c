#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isfull(struct stack *ptr )
{
    if (ptr->top==ptr->size-1)
    {
        return 1;
    }

    else
    {
    return 0;

    }
    
}

int isempty(struct stack *ptr )
{
    if (ptr->top== -1)
    {
        return 1;
    }

    else
    {
    return 0;

    }
    
}

void push(struct stack *ptr,int value)
{
    if (ptr->top==ptr->size-1)
    {
        printf("Stack Overflow");
    }

    else
    {
        ptr->top++;
        ptr->arr[ptr->top]=value;
        printf("%d\n", ptr->arr[ptr->top]);
    }

}

int pop(struct stack *ptr)
{
    if (ptr->top==-1)
    {
        printf("stack overflow\n");
        return -1;
    }

    else
    {
        int val=ptr->arr[ptr->top];
        ptr->top--;

        return val;
       
        
    }

}

int peek(struct stack *ptr,int i)
{
    if (ptr->top - i+1<0)
    {
        printf("not a valid possition\n");
        return -1;
    }
    else
    {
        return ptr->arr[ptr->top - i+1];
    }
    
}


int main(int argc, char const *argv[])
{
    struct stack *sp =(int *)malloc(sizeof(struct stack)); 
    sp->size=10;
    sp->top=-1;
    sp->arr=(int *)malloc(sp->size*sizeof(int));

    // sp->top++;
    // sp->arr[sp->top]=12;
    
    
    push(sp,40);
    push(sp,50);
    push(sp,60);
    push(sp,70);
    push(sp,80);
    push(sp,90);
    push(sp,100);

    printf("%d\n",isfull(sp));
    printf("%d\n",isempty(sp));

    // printf("%d\n", pop(sp));

    for (int j = 1; j <=sp->top +1; j++)
    {
        printf("element:%d = %d\n",j,peek(sp,j));
    }
      

    return 0;
}
