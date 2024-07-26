#include <stdio.h>
#include <stdlib.h>

struct queue 
{
    int size;
    int f;
    int r;
    int *arr;
};

int isfull(struct queue *q)
{
    if (q->r==q->size-1)
    {
        return 1;
    }
    return 0;
}

int isempty(struct queue *q)
{
    if (q->r==q->f)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q,int val)
{
    if(isfull(q))
    {
        printf("This queue is full\n");
    }
    else
    {
        q->r++;
        q->arr[q->r]=val;

    }
}

int dequeue(struct queue *q)
{
    int a=-1;
    if(isempty(q))
    {
        printf("This queue is empty\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];

    }
    return a;
}

int main(int argc, char const *argv[])
{
    struct queue q;
    q.size=100;
    q.f=-1;
    q.r=-1;
    q.arr=(int *)malloc(q.size*sizeof(int));

    enqueue(&q,12);
    enqueue(&q,15);

    printf("decueing element %d\n",dequeue(&q));
    printf("decueing element %d\n",dequeue(&q));


    if(isempty(&q))
    {
        printf("queue is empty\n");
    } 
    if(isfull(&q))
    {
        printf("queue is full\n");
    }



    return 0;
}
