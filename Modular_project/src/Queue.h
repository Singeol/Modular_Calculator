#include "Structs.h"
#include <stdio.h>
#include <stdlib.h>
#ifndef QUEUE_H_
#define QUEUE_H_

void init_queue(queue *q);

void enqueue(queue *q, data *value);

data* dequeue(queue *q);

#endif /* QUEUE_H_ */
