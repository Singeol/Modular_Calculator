#include "Structs.h"
#include <stdio.h>
#include <stdlib.h>

/* Функция для инициализирования стека
 * Function to initialize the stack
 */
void init_stack(stack *s) {
	s->head = NULL;
}

/* Функция для добавления элемента в стек
 * Fucntion for add element of stack
 */
void push(stack *s, double number) {

	nodeS * tmp = malloc(sizeof(nodeS));

	tmp->x = number;

	tmp->next = s->head;

	s->head = tmp;

}

/* Функция для изъятия данных из стека
 * Function to pop element from stack
 */
double pop(stack *s) {
	nodeS *tmp;
	tmp = malloc(sizeof(nodeS));
	tmp = s->head;

	s->head = s->head->next;

	return tmp->x;
}

