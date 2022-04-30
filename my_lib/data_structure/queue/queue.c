#include "queue.h"


/*
    @brief Increment the head_index (Roll back to zero if head_index > MAX_QUEUE_LEN - 1)
*/
static void incr_head_index(queue_t *que);

/*
    @brief Increment the tail_index (Roll back to zero if tail_index > MAX_QUEUE_LEN - 1)
*/  
static void incr_tail_index(queue_t *que);


void que_init(queue_t *que)
{
    que->curr_len = 0;
    que->head_index = 0;
    que->tail_index = 0;
    que->sum = 0;
    for (int i = 0; i < MAX_QUEUE_LEN; i++) {
        que->data[i] = 0;
    }
}

void enque_element(queue_t *que, QType val) 
{
    if (que->curr_len < MAX_QUEUE_LEN) { 
        que->curr_len++;
        #ifdef SUM_QUEUE
        que->sum += val;
        #endif
    } else {
        #ifdef SUM_QUEUE
        que->sum -= que->data[que->tail_index];
        que->sum += val;
        #endif
        incr_tail_index(que);
    }
    que->data[que->head_index] = val;
    incr_head_index(que);
}

QType deque_element(queue_t *que) 
{
    QType elem = 0;
    if (que->curr_len > 0) {
        elem = que->data[que->tail_index];
        incr_tail_index(que);
        que->curr_len--;
        #ifdef SUM_QUEUE
        que->sum -= elem;
        #endif
    } else {}

    return elem;
}

uint16_t que_get_len(queue_t *que)
{
    return que->curr_len;
}



static void incr_head_index(queue_t *que)
{
    que->head_index = (que->head_index >= (MAX_QUEUE_LEN - 1))? 0 : que->head_index + 1;
}

static void incr_tail_index(queue_t *que)
{
    que->tail_index = (que->tail_index >= (MAX_QUEUE_LEN - 1))? 0 : que->tail_index + 1;
}
