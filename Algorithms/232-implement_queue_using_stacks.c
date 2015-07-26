/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Description:

Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
*/

typedef struct {
    int *data;
    int  pos;
} Stack;

typedef struct {
    Stack *stk;
    Stack *aux_stk; /* auxiliary stack */
} Queue;

/* A simple stack implementation */
Stack *stackCreate(int maxSize) {
    Stack *stk;

    stk = (Stack *) malloc(sizeof(Stack));
    stk->data = (int *) malloc(maxSize * sizeof(int));
    stk->pos = 0;

    return stk;
}

void stackDestroy(Stack *s) {
    free(s->data);
    free(s);
}
bool stackEmpty(Stack *s) {
    return s->pos == 0 ? true : false;
}

void stackPush(Stack *s, int e) {
    s->data[s->pos++] = e;
}

int stackPop(Stack *s) {
    return s->data[--s->pos];
}

int stackTop(Stack *s) {
    return s->data[s->pos - 1];
}

/* Create a queue */
void queueCreate(Queue *queue, int maxSize) {
    queue->stk = stackCreate(maxSize);
    queue->aux_stk = stackCreate(maxSize);
}

/* Push element x to the back of queue */
void queuePush(Queue *queue, int element) {
    int tmp;

    while (!stackEmpty(queue->stk)) {
        tmp = stackPop(queue->stk);
        stackPush(queue->aux_stk, tmp);
    }

    stackPush(queue->stk, element);

    while (!stackEmpty(queue->aux_stk)) {
        tmp = stackPop(queue->aux_stk);
        stackPush(queue->stk, tmp);
    }
}

/* Removes the element from front of queue */
void queuePop(Queue *queue) {
    stackPop(queue->stk);
}

/* Get the front element */
int queuePeek(Queue *queue) {
    return stackTop(queue->stk);
}

/* Return whether the queue is empty */
bool queueEmpty(Queue *queue) {
    return stackEmpty(queue->stk);
}

/* Destroy the queue */
void queueDestroy(Queue *queue) {
    stackDestroy(queue->stk);
    stackDestroy(queue->aux_stk);
}
