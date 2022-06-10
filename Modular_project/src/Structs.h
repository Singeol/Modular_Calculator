#ifndef STRUCTS_H_
#define STRUCTS_H_

typedef struct data {
	char mode, operation;
	int size;
	double *x, *y;
	double *result;
} data;


typedef struct node {
	char mode, operation;
	int size;
	double *x, *y;
	double *result;
	struct node *next;
} node;

typedef struct list{
	node *head;
	node *current;
} list;

typedef struct queue{
	node *head;
	node *tail;
} queue;

typedef struct nodeS {
	double x;
	struct nodeS *next;
} nodeS;

typedef struct stack {
	nodeS *head;
} stack;

#endif /* STRUCTS_H_ */
