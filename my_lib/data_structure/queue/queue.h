#ifndef QUEUE_H
#define QUEUE_H

#include "../../common/public.h"

/* Turn on the calculation of sum of elements in queue. This should not be defined if the elements aren't number */
#define SUM_QUEUE
/* Datatype in queue */
#define QType int16_t
/* Datatype of sum of elements in the queue */
#define SType int16_t

/* Max size of Queue */
#define MAX_QUEUE_LEN 8
/* Datatype of index */
#if MAX_QUEUE_LEN > 255
    #define LType uint16_t
#else
    #define LType uint8_t
#endif


typedef struct {
    LType head_index;    // index to store data
    LType tail_index;    // index to read data
    LType curr_len;   // number of valid element in the queue
    SType sum; // sum of elements in queue. Calculated if SUM_QUEUE is defined
    QType data[MAX_QUEUE_LEN];
}queue_t;


/*
    @brief Initialize a queue object as zero 
*/
void que_init(queue_t *que);

/*
    @brief Enqueue the val into *que. Update the que->sum if SUM_QUEUE is defined.
*/
void enque_element(queue_t *que, QType val);
/*
    @brief Dequeue the val from *que. Update the que->sum if SUM_QUEUE is defined.
*/
QType deque_element(queue_t *que);

#endif
