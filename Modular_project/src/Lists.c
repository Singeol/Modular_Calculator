#include "Structs.h"
#include <stdio.h>
#include <stdlib.h>

/* Функция для инициализации списка
 * Function to initialize the list
 */
void init_list(list *l) {
	l->head = NULL;
	l->current = NULL;
}

/* Функция для добавления входных данных в конец списка
 * Function for add input data to end of list
 */
void pushElement(list *l, data *value) {

	node* tmp = malloc(sizeof(node));
	node *last = l->head;
	tmp->operation = value->operation;
	tmp->mode = value->mode;
	tmp->result = value->result;
	tmp->x = value->x;
	tmp->y = value->y;
	tmp->size = value->size;
	tmp->next = NULL;
	if(l->head == NULL){
		l->head = tmp;
		return;
	}

	while (last->next != NULL){
		last = last->next;
	}
	last->next = tmp;
	return;
}

// Удаляет первый элемент исходного списка
void deleteElement(list *l) {
  node *tmp;

  if(&l->head == NULL) return;

  tmp = l->head;

  l->head = l->head->next;

  free(tmp);
}

/* Функция для перемещения вперёд по списку
 * Function for move forward through list
 */
node* nextElement(list *l){
	l->current = l->current->next;
	return l->current;
}
