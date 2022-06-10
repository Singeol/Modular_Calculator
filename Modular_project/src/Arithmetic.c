#include <stdio.h>
#include <stdlib.h>



/* Функция для сложения векторов
 *
 * Function for adding vectors*/
double* doSumVector(double *x, double *y, int size){
	double *result;
	result = malloc(size*sizeof(double));
	for (int i = 0; i < size; i++) result[i] =  x[i] + y[i];
	return result;
}

/* Функция для разности векторов
 * Function for the difference of vectors*/
double* doSubstractionVector(double *x, double *y, int size){
	double *result;
	result = malloc(size*sizeof(double));
	for (int i = 0; i < size; i++) result[i] =  x[i] - y[i];
	return result;
}

/* Функция для умножения векторов
 * Function for multiplying vectors*/
double* doMultiplyVector(double *x, double *y, int size){
	double *result;
	result = malloc(sizeof(double));
	*result = 0;
	for (int i = 0; i < size; i++) *result +=  x[i] * y[i];
	return result;
}

/* Функция для нахождения модуля числа
 * Function for finding the modulus of a number*/
double doAbs(double x){
	if (x < 0){
		return x*(-1);
	}
	else return x;
}

/* Функция для нахождения суммы чисел
 * Function for finding the sum of numbers*/
double* doSum(double x, double y){
	double *result;
	result = malloc(1*sizeof(double));
	*result = x + y;
	return result;
}

/* Функция для нахождения разности чисел
 * Function for finding the difference of numbers*/
double* doSubstraction(double x, double y){
	double *result;
	result = malloc(1*sizeof(double));
	*result = x - y;
	return result;
}

/* Функция для нахождения произведения чисел
 * Function for finding the product of numbers*/
double* doMultiply(double x, double y){
	double *result;
	result = malloc(1*sizeof(double));
	*result = x * y;
	return result;
}

/* Функция для нахождения частного чисел
 * Function for finding the quotient of numbers*/
double* doDivision(double x, double y){
	double *result;
	result = malloc(1*sizeof(double));
	*result = x / y;
	return result;
}

/* Функция для нахождения факториала числа с помощью рекурсии
 * A function for finding the factorial of a number using recursion*/
double* doFactorial(int x){
	double *result;
	result = malloc(1*sizeof(double));
	*result = 1;
	for (int i = 2; i <= x; i++){
		*result *= i;
	}
	return result;
}

/* Функция для возведения числа в степень, работает с натуральными числами
 * При попытке использовать формулу для вычисления x^y=exp(y*ln(x))
 * Точность не очень хорошая, поэтому было решено сделать возведение
 * В степень только для натуральных чисел
 * A function for exponentiating a number, works with natural numbers
 * When trying to use the formula to calculate x^y=exp(y*ln(x))
 * The accuracy is not very good, so it was decided to do the construction
 * To the power only for natural numbers*/
double* doPow(int x, int y){
	/* Объявляем переменную для хранения результата
	 * We declare variable for storing the result*/
	double *result;
	result = malloc(1*sizeof(double));
	*result = 1;
	if (y < 0){
		y = doAbs(y);
		for (int i=1; i<=y; i++){
			*result *= x;
		}
		*result = (1/(*result));
	}
	else{
		for (int i=1; i<=y; i++){
			*result *= x;
		}
	}
	return result;
}
