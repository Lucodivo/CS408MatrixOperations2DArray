#include <iostream>

// these macros are monstrosities, are only for fun, and are very fragile
// they allow for the matrices to not be defined by constants, though
// the dimensions of the arrays X, Y, Z must follow traditional matrix math rules
#define addMatMac(X,Y,Z) for(int i = 0; i < (sizeof(X)/sizeof(*X)); i++) { \
                            for (int j = 0; j < (sizeof(X[0])/sizeof(*X[0])); j++) { \
                                Z[i][j] = X[i][j] + Y[i][j]; }}
#define subMatMac(X,Y,Z) for(int i = 0; i < (sizeof(X)/sizeof(*X)); i++) { \
                            for (int j = 0; j < (sizeof(X[0])/sizeof(*X[0])); j++) { \
                                Z[i][j] = X[i][j] - Y[i][j]; }}
#define multMatMac(X,Y,Z) for(int i = 0; i < (sizeof(X)/sizeof(*X)); i++) { \
                            for (int j = 0; j < (sizeof(Y[0])/sizeof(*Y[0])); j++) { \
                                Z[i][j] = 0; \
                                for(int k = 0; k < (sizeof(X)[0]/sizeof(*X[0])); k++) { \
                                    Z[i][j] += X[i][k] * Y[k][j];}}}
#define printMatMac(X) for(int i = 0; i < (sizeof(X)/sizeof(*X)); i++) { \
                        for (int j = 0; j < (sizeof(X[0])/sizeof(*X[0])); j++) { \
                            std::cout << X[i][j] << "\t"; } \
                        std::cout << "\n"; }

#define NUM_ROWS 5
#define NUM_COLS 5

void addMat(double X[NUM_ROWS][NUM_COLS], double Y[NUM_ROWS][NUM_COLS], double Z[NUM_ROWS][NUM_COLS]);
void subMat(double X[NUM_ROWS][NUM_COLS], double Y[NUM_ROWS][NUM_COLS], double Z[NUM_ROWS][NUM_COLS]);
void multMat(double X[NUM_ROWS][NUM_COLS], double Y[NUM_ROWS][NUM_COLS], double Z[NUM_ROWS][NUM_COLS]);
void printMat(double X[NUM_ROWS][NUM_COLS]);

/**
 * @brief	Performs 2D array matrix operations and displays their results (commented
 *          (commented out macros can be substituted for the function calls)
 * @author	Connor A. Haskins
 * @date	11/11/2016
 */

int main() {
    double m1[NUM_ROWS][NUM_COLS] = { {1.0, 2.0, 3.0, 4.0, 5.0}, {2.0, 2.0, 2.0, 2.0, 2.0}, {3.0, 1.0, 1.0, 1.0, 3.0}, {0.0, 0.0, 2.0, 3.0, 2.0}, {4.0, 4.0, 4.0, 0.0, 0.0} };
    double m2[NUM_ROWS][NUM_COLS] = { {1.0, 0.0, 0.0, 0.0, 0.0}, {1.0, 2.0, 1.0, 2.0, 1.0}, {0.0, 0.0, 1.0, 0.0, 0.0}, {1.0, 1.0, 1.0, 1.0, 1.0}, {2.0, 2.0, 2.0, 2.0, 2.0} };
    double m3[NUM_ROWS][NUM_COLS];

    std::cout << "(1) M3 = M1 + M2 \n";
    std::cout << "(2) M4 = M1 - M2 \n";
    std::cout << "(3) M5 = M1 * M2 \n";
    std::cout << "\n";

    //addMatMac(m1, m2, m3);
    addMat(m1, m2, m3);

    std::cout << "(1) M3 = M1 + M2 \n";
    std::cout << "====================================\n";
    printMat(m1);
    std::cout << "====================================\n";
    printMat(m2);
    std::cout << "====================================\n";
    printMat(m3);
    std::cout << "\n";

    //subMatMac(m1, m2, m3);
    subMat(m1, m2, m3);

    std::cout << "(2) M4 = M1 - M2 \n";
    std::cout << "====================================\n";
    printMat(m1);
    std::cout << "====================================\n";
    printMat(m2);
    std::cout << "====================================\n";
    printMat(m3);
    std::cout << "\n";

    //multMatMac(m1, m2, m3);
    multMat(m1, m2, m3);

    std::cout << "(3) M5 = M1 * M2 \n";
    std::cout << "====================================\n";
    printMat(m1);
    std::cout << "====================================\n";
    printMat(m2);
    std::cout << "====================================\n";
    printMat(m3);

    return 0;
}

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