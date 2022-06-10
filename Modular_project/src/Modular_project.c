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
#include "Output.h"
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
				printf("С какой структурой вы хотите работать? l - список, q - очередь");
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
						calcList(l1 ,l2);
						l1.current = l1.head;
						l2.current = l2.head;
						if ((fout = fopen(output, "a")) == NULL){
							fout = fopen(output, "w");
						}
						writeList(fout, l2);
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
						calcQueue(q1, q2);
						if ((fout = fopen(output, "a")) == NULL){
							fout = fopen(output, "w");
						}
						writeQueue(fout, q2);
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
