#include "Arithmetic.h"
#include "Structs.h"
#include "Lists.h"
#include "Queue.h"
#include "Input.h"
#include <stdio.h>
#include <stdlib.h>

void writeList(FILE *fout, list l2) {
	while (l2.current != NULL){
		switch (l2.current->mode){
			case 'v':
				fprintf(fout, "( ");
				for (int i = 0; i < l2.current->size; i++){
					if (i == l2.current->size - 1){
						fprintf(fout, "%lf", l2.current->x[i]);
					}
					else fprintf(fout, "%lf ", l2.current->x[i]);
				}
				fprintf(fout, " ) %c ( ", l2.current->operation);
				for (int i = 0; i < l2.current->size; i++){
					if (i == l2.current->size - 1){
						fprintf(fout, "%lf", l2.current->y[i]);
					}
					else fprintf(fout, "%lf ", l2.current->y[i]);
				}
				if (l2.current->operation == '+' || l2.current->operation == '-'){
					fprintf(fout, " ) = ( ");
					for (int i = 0; i < l2.current->size; i++){
						if (i == l2.current->size - 1){
							fprintf(fout, "%lf", l2.current->result[i]);
						}
						else fprintf(fout, "%lf ", l2.current->result[i]);
						}
						fprintf(fout, " )\n");
					}
				else{
					fprintf(fout, " ) = %lf\n", *l2.current->result);
				}
				break;
			case 'n':
				switch (l2.current->operation){
					case '+':
						fprintf(fout, "%lf + %lf = %lf\n", *l2.current->x, *l2.current->y, *l2.current->result);
						break;
					case '-':
						fprintf(fout, "%lf - %lf = %lf\n", *l2.current->x, *l2.current->y, *l2.current->result);
						break;
					case '*':
						fprintf(fout, "%lf * %lf = %lf\n", *l2.current->x, *l2.current->y, *l2.current->result);
						break;
					case '/':
						fprintf(fout, "%lf / %lf = %lf\n", *l2.current->x, *l2.current->y, *l2.current->result);
						break;
					case '!':
						fprintf(fout, "%lf! = %lf\n", *l2.current->x, *l2.current->result);
						break;
					case '^':
						fprintf(fout, "%lf^%lf = %lf\n", *l2.current->x, *l2.current->y, *l2.current->result);
						break;
				}
		}
		nextElement(&l2);
	}
}

void writeQueue(FILE *fout, queue q2) {
	data *var;
	var = malloc(sizeof(data));
	while ((var = dequeue(&q2)) != NULL) {
		switch (var->mode) {
			case 'v':
				fprintf(fout, "( ");
				for (int i = 0; i < var->size; i++) {
					if (i == var->size - 1){
						fprintf(fout, "%lf", var->x[i]);
					}
					else fprintf(fout, "%lf ", var->x[i]);
				}
				fprintf(fout, " ) %c ( ", var->operation);
				for (int i = 0; i < var->size; i++){
					if (i == var->size - 1){
						fprintf(fout, "%lf", var->y[i]);
					}
					else fprintf(fout, "%lf ", var->y[i]);
				}
				if (var->operation == '+' || var->operation == '-') {
					fprintf(fout, " ) = ( ");
					for (int i = 0; i < var->size; i++) {
						if (i == var->size - 1){
							fprintf(fout, "%lf", var->result[i]);
						}
						else fprintf(fout, "%lf ", var->result[i]);
					}
					fprintf(fout, " )\n");
				}
				else{
					fprintf(fout, " ) = %lf\n", *var->result);
				}
				break;
			case 'n':
				switch (var->operation) {
					case '+':
						fprintf(fout, "%lf + %lf = %lf\n", *var->x, *var->y, *var->result);
						break;
					case '-':
						fprintf(fout, "%lf - %lf = %lf\n", *var->x, *var->y, *var->result);
						break;
					case '*':
						fprintf(fout, "%lf * %lf = %lf\n", *var->x, *var->y, *var->result);
						break;
					case '/':
						fprintf(fout, "%lf / %lf = %lf\n", *var->x, *var->y, *var->result);
						break;
					case '!':
						fprintf(fout, "%lf! = %lf\n", *var->x, *var->result);
						break;
					case '^':
						fprintf(fout, "%lf^%lf = %lf\n", *var->x, *var->y, *var->result);
						break;
				}
		}
	}
	free(var);
}
