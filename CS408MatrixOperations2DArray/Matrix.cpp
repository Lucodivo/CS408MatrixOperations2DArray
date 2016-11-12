#include <iostream>
#include "Matrix.h"

/**
* @brief	Adds the first two matrices and stores the values in the third matrix
* @param	X[NUM_ROWS][NUM_COLS]	Matrix #1 (addend)
* @param	Y[NUM_ROWS][NUM_COLS]	Matrix #2 (addend)
* @param	Z[NUM_ROWS][NUM_COLS]	The location of the summation of the two matrices
*/
void addMat(double X[NUM_ROWS][NUM_COLS], double Y[NUM_ROWS][NUM_COLS], double Z[NUM_ROWS][NUM_COLS]) {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            Z[i][j] = X[i][j] + Y[i][j];
        }
    }
}

/**
* @brief	Subtracts the second matrix from the first matrix and stores the values in the third matrix.
* @param	X[NUM_ROWS][NUM_COLS]	Matrix #1 (minuend)
* @param	Y[NUM_ROWS][NUM_COLS]	Matrix #2 (subtrahend)
* @param	Z[NUM_ROWS][NUM_COLS]	The location of the difference of the two matrices
*/
void subMat(double X[NUM_ROWS][NUM_COLS], double Y[NUM_ROWS][NUM_COLS], double Z[NUM_ROWS][NUM_COLS]) {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            Z[i][j] = X[i][j] - Y[i][j];
        }
    }
}

/**
* @brief	Performs matrix multiplication on the two matrices and stores the values in the third matrix
*           (DOES NOT SIMPLY MULTIPLY CORRESPONDING INDEXES)
* @param	X[NUM_ROWS][NUM_COLS]	Matrix #1 (multiplicand)
* @param	Y[NUM_ROWS][NUM_COLS]	Matrix #2 (multiplier)
* @param	Z[NUM_ROWS][NUM_COLS]	The location of the product of the two matrices
*/
void multMat(double X[NUM_ROWS][NUM_COLS], double Y[NUM_ROWS][NUM_COLS], double Z[NUM_ROWS][NUM_COLS]) {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            Z[i][j] = 0;
            for (int k = 0; k < NUM_COLS; k++) {
                Z[i][j] += X[i][k] * Y[k][j];
            }
        }
    }
}

/**
* @brief	Prints a matrix to console
* @param	X[NUM_ROWS][NUM_COLS]
*/
void printMat(double X[NUM_ROWS][NUM_COLS]) {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            std::cout << X[i][j] << "\t";
        }
        std::cout << "\n";
    }
}