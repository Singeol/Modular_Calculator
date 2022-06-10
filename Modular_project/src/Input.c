#include "Structs.h"
#include "Lists.h"
#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

data* inputPN(FILE *fin) {
	data *var;
	var = malloc(sizeof(data));
	fscanf(fin," %c %c", &var->operation, &var->mode);
	switch (var->mode){
		case 'n':
			var->size = 1;
			if (var->operation == '!'){
				var->x = malloc(1 * sizeof(double));
				for (int i = 0; i < var->size; i++) fscanf(fin, "%lf", &var->x[i]);
				var->y = NULL;
			}
			else{
				var->x = malloc(1 * sizeof(double));
				var->y = malloc(1 * sizeof(double));
				for (int i = 0; i < var->size; i++) fscanf(fin, "%lf", &var->x[i]);
				for (int i = 0; i < var->size; i++) fscanf(fin, "%lf", &var->y[i]);
			}
			break;
		case 'v':
			fscanf(fin, "%i", &var->size);
			var->x = malloc(var->size*sizeof(double));
			var->y = malloc(var->size*sizeof(double));
			for (int i = 0; i < var->size; i++) fscanf(fin, "%lf", &var->x[i]);
			for (int i = 0; i < var->size; i++) fscanf(fin, "%lf", &var->y[i]);
			break;
		}
	return var;
}

void calcList(list l1, list l2){
	data *var;
	var = malloc(sizeof(data));
	l1.current = l1.head;
	while (l1.current != NULL){
		var->mode = l1.current->mode;
		var->operation = l1.current->operation;
		var->size = l1.current->size;
		var->x = l1.current->x;
		var->y = l1.current->y;
		switch (var->mode){
			case 'v':
				switch (var->operation){
					case '+':
						var->result = doSumVector(var->x, var->y, var->size);
						break;
					case '-':
						var->result = doSubstractionVector(var->x, var->y, var->size);
						break;
					case '*':
						var->result = doMultiplyVector(var->x, var->y, var->size);
						break;
				}
				break;
			case 'n':
				switch (l1.current->operation){
					case '+':
						var->result = doSum(*var->x, *var->y);
						break;
					case '-':
						var->result = doSubstraction(*var->x, *var->y);
						break;
					case '*':
						var->result = doMultiply(*var->x, *var->y);
						break;
					case '/':
						var->result = doDivision(*var->x, *var->y);
						break;
					case '!':
						var->result = doFactorial(*var->x);
						break;
					case '^':
						var->result = doPow(*var->x, *var->y);
						break;
				}
				break;
		}
		pushElement(&l2, var);
		nextElement(&l1);
	}
	free(var);
}

void calcQueue(queue q1, queue q2) {
	data *var;
	var = malloc(sizeof(data));
	while ((var = dequeue(&q1)) != NULL) {
		switch (var->mode) {
			case 'v':
				switch (var->operation) {
					case '+':
						var->result = doSumVector(var->x, var->y, var->size);
						break;
					case '-':
						var->result = doSubstractionVector(var->x, var->y, var->size);
						break;
					case '*':
						var->result = doMultiplyVector(var->x, var->y, var->size);
						break;
				}
				break;
			case 'n':
				switch (var->operation) {
					case '+':
						var->result = doSum(*var->x, *var->y);
						break;
					case '-':
						var->result = doSubstraction(*var->x, *var->y);
						break;
					case '*':
						var->result = doMultiply(*var->x, *var->y);
						break;
					case '/':
						var->result = doDivision(*var->x, *var->y);
						break;
					case '!':
						var->result = doFactorial(*var->x);
						break;
					case '^':
						var->result = doPow(*var->x, *var->y);
						break;
				}
				break;
		}
		enqueue(&q2, var);
	}
}
