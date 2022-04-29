#include "queue.h"
#include "stdio.h"

int main (void)
{
    queue_t my_queue;
    // initialize
    que_init(&my_queue);

    // Enqueue
    for (int i = 0; i < 8; i++) {
        printf("%d. Enqueue %d\n", i + 1, i);
        enque_element(&my_queue, i);
        printf("\tlen = %d\n", my_queue.curr_len);
        printf("\tsum = %d\n", my_queue.sum);
    }
    printf("===========================\n");
    // Dequeue
    for (int i = 0; i < 8; i++) {
        printf("%d. Dequeue %d\n", i + 1, i);
        printf("\tdequeue val = %d\n", deque_element(&my_queue));
        printf("\tlen = %d\n", my_queue.curr_len);
        printf("\tsum = %d\n", my_queue.sum);
    }
}