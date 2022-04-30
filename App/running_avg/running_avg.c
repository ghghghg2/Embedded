
#include "stdlib.h"
#include "../../my_lib/common/public.h"
#include "../../my_lib/data_structure/queue/queue.h"


uint16_t adc_val_generator(void) {
    uint16_t val = rand() % 1024;
    // printf("Value = %d\n", val);
}

void print_queue(const queue_t* que)
{
    printf("Len = %d\n", que->curr_len);
    printf("Running average = %d\n", que->sum / que->curr_len);
    printf("Elements = [");
    for (int i = 0; i < MAX_QUEUE_LEN; i++) {
        printf("%u  ", que->data[i]);
    }
    printf("]\n");
}

int main()
{
    queue_t que_adc_vals;
    que_init(&que_adc_vals);
    // Enqueue
    for (int i = 0; i < 20; i++) {
        uint16_t val = adc_val_generator();
        enque_element(&que_adc_vals, val);
        printf("%d. Enqueue %u.\n", i+1, val);
        print_queue(&que_adc_vals);
    }
    printf("\n============================================================\n");
    // Dequeue
    for (int i = 0; i < MAX_QUEUE_LEN - 1; i++) {
        uint16_t val = deque_element(&que_adc_vals);
        printf("%d. Dequeue %u.\n", i+1, val);
        print_queue(&que_adc_vals);
    }
    return 0;
}
