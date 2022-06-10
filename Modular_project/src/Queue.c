#include "Structs.h"
#include <stdio.h>
#include <stdlib.h>


/* Функция для инициализации очереди
 * Function for initialize the queue
 */
void init_queue(queue *q) {
	q->head = NULL;
	q->tail = NULL;
}

/* Функция для добавления элемента в очередь
 * Fucntion for add element of queue
 */
void enqueue(queue *q, data *value) {

	node * tmp = malloc(sizeof(node));
	tmp->operation = value->operation;
	tmp->mode = value->mode;
	tmp->result = value->result;
	tmp->x = value->x;
	tmp->y = value->y;
	tmp->size = value->size;

	if (q->tail != NULL) {
		q->tail->next = tmp;
	}

	q->tail = tmp;

	if(q->head == NULL) {
		q->head = tmp;
	}
}

/* Функция для изъятия данных из очереди
 * Function to dequeue data
 */
data* dequeue(queue *q) {
	data *result;
	result = malloc(sizeof(data));

	if (q->head == NULL){
		result = NULL;
		return result;
	}

	node *tmp = q->head;

	result->mode = tmp->mode;
	result->operation = tmp->operation;
	result->size = tmp->size;
	result->x = tmp->x;
	result->y = tmp->y;
	result->result = tmp->result;

	//take it off.
	q->head = q->head->next;
	if (q->head == NULL) {
		q->tail = NULL;
	}
	free(tmp);

	return result;
}

