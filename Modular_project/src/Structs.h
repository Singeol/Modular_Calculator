#ifndef STRUCTS_H_
#define STRUCTS_H_

// Структура для промежуточного хранения данных
typedef struct data {
	char mode, operation;
	int size;
	double *x, *y;
	double *result;
} data;

// Структура элемента очереди или списка
typedef struct node {
	char mode, operation;
	int size;
	double *x, *y;
	double *result;
	struct node *next;
} node;

// Структура для описания списка
typedef struct list{
	node *head;
	node *current;
} list;

// Структура для описания очереди
typedef struct queue{
	node *head;
	node *tail;
} queue;

// Структура элемента стека
typedef struct nodeS {
	double x;
	struct nodeS *next;
} nodeS;

// Структура для описания стека
typedef struct stack {
	nodeS *head;
} stack;

#endif /* STRUCTS_H_ */
