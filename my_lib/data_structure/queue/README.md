### *Queue*

> *Implement the queue in C.*

> *Motivation: Requirement of the running average for button's denoise strategy.*

| File | Description |
|:---------|:-----------|
|queue.h|Contain the parameters and intro of queue.c|
|queue.c|Implement the queue|
|test.c|Program to test the queue function|
|test|Binary file of test.c. <br /> usage: `./test`|
|makefile|Build the binary file test. <br /> usage: `make`|

See the ***queue.h***

| Parameter | Description |
|:---------|:-----------|
|SUM_QUEUE|If this macro is defined, the program calculates the sum of elements in the queue. <br />**Note. This macro should not be defined if the element isn't number.** <br /> **`SUM_QUEUE`** can be used in the running average.|
|QType|Datatype of elements in queue|
|SType|Datatype of sum|
|MAX_QUEUE_LEN|Available size of queue|

**Please make sure the parameters are set appropriately before used the function.**
