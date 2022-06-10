#include "Structs.h"
#include "Lists.h"
#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

// Функция для чтения данных записанных в нормальной польской нотации из входного файла
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

