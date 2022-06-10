/*
 ============================================================================
 Name        : Modular_project.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include "Arithmetic.h"
#include "Structs.h"
#include "Lists.h"
#include "Queue.h"
#include "Stack.h"
#include "Input.h"
#include <stdio.h>
#include <stdlib.h>

FILE *fin, *fout; //Declare variables for work with files


/* Основная функция, точка входа
 * Main function, entry point*/
int main(int argc, char* argv[]){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	double nm;
	char input[259], output[259], in[256], operation, b, notation, structure; // Переменные для хранения имени файлов
	data *var;
	stack s1;
	list l1, l2;
	queue q1, q2;
	do {
		printf("С каким режимом вы хотите работать? p - нормальная польска нотация(список, очередь), n - обратная польская нотация(стек)\n");
		scanf(" %c", &notation);
		switch (notation) {
			case 'n':
				printf("Выбран стек для работы\n");
				structure = 's';
				init_stack(&s1);
				puts("Enter filename to input");
				scanf("%s", input);
				puts("Enter filename to output");
				scanf("%s", output);
				fin = fopen(input, "r");
				if ((fout = fopen(output, "a")) == NULL) {
					fout = fopen(output, "w");
				}
				while (feof(fin) == 0) {
					fscanf(fin, "%s", in);
						if (atof(in) == 0) {
							operation = in[0];
							switch (operation) {
								case '+':
									push(&s1, *doSum(pop(&s1), pop(&s1)));
									break;
								case '-':
									push(&s1, *doSubstraction(pop(&s1), pop(&s1)));
									break;
								case '*':
									push(&s1, *doMultiply(pop(&s1), pop(&s1)));
									break;
								case '/':
									push(&s1, *doDivision(pop(&s1), pop(&s1)));
									break;
								case '!':
									push(&s1, *doFactorial(pop(&s1)));
									break;
								case '^':
									push(&s1, *doPow(pop(&s1), pop(&s1)));
									break;
								case '=':
									fprintf(fout, "%lf\n", pop(&s1));
									break;
							}
						}
						else {
							nm = atof(in);
							push(&s1, nm);
						}
					}
				fclose(fin);
				fclose(fout);
				break;
			case 'p':
				printf("С какой структурой вы хотите работать? l - список, q - очередь\n");
				scanf(" %c", &structure);
				switch (structure) {
					case 'l':
						init_list(&l1);
						init_list(&l2);
						puts("Enter filename to input");
						scanf("%s", input);
						puts("Enter filename to output");
						scanf("%s", output);
						fin = fopen(input, "r");
						var = malloc(sizeof(data));
						while (feof(fin) == 0) {
							var = inputPN(fin);
							pushElement(&l1, var);
						}
						fclose(fin);
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
						l1.current = l1.head;
						l2.current = l2.head;
						if ((fout = fopen(output, "a")) == NULL){
							fout = fopen(output, "w");
						}
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
									if (l2.current->operation != '!') {
										fprintf(fout, "%lf + %lf = %lf\n", *l2.current->x, *l2.current->y, *l2.current->result);
									}
									else fprintf(fout, "%lf! = %lf\n", *l2.current->x, *l2.current->result);
							}
							nextElement(&l2);
						}
						fclose(fout);
						while (l1.head != NULL){
							deleteElement(&l1);
						}
						while (l2.head != NULL){
							deleteElement(&l2);
						}
						break;
					case 'q':
						init_queue(&q1);
						init_queue(&q2);
						puts("Enter filename to input");
						scanf("%s", input);
						puts("Enter filename to output");
						scanf("%s", output);
						fin = fopen(input, "r");
						var = malloc(sizeof(data));
						while (feof(fin) == 0) {
							var = inputPN(fin);
							enqueue(&q1, var);
						}
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
						if ((fout = fopen(output, "a")) == NULL) {
							fout = fopen(output, "w");
						}
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
									if (var->operation != '!') {
										fprintf(fout, "%lf + %lf = %lf\n", *var->x, *var->y, *var->result);
									}
									else fprintf(fout, "%lf! = %lf\n", *var->x, *var->result);
									}
									break;
							}
						fclose(fout);
						break;
				}
				break;
			default:
				printf("Введены неверные параметры");
				return 0;
				break;
		}
		puts("Continue working? y - yes, n - no");
		scanf(" %c", &b);
	} while(b!='n');
	return 0;
}
