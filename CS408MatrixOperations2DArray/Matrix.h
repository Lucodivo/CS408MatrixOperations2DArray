// acts as #ifndef
#pragma once

// these macros are monstrosities, are only for fun, and are very fragile
// they allow for the matrices to not be defined by constants, though
// the dimensions of the arrays X, Y, Z must follow traditional matrix math rules
#define addMatMac(X,Y,Z)    for(int i = 0; i < (sizeof(X)/sizeof(*X)); i++) { \
                                for (int j = 0; j < (sizeof(X[0])/sizeof(*X[0])); j++) { \
                                    Z[i][j] = X[i][j] + Y[i][j]; }}
#define subMatMac(X,Y,Z)    for(int i = 0; i < (sizeof(X)/sizeof(*X)); i++) { \
                                for (int j = 0; j < (sizeof(X[0])/sizeof(*X[0])); j++) { \
                                    Z[i][j] = X[i][j] - Y[i][j]; }}
#define multMatMac(X,Y,Z)   for(int i = 0; i < (sizeof(X)/sizeof(*X)); i++) { \
                                for (int j = 0; j < (sizeof(Y[0])/sizeof(*Y[0])); j++) { \
                                    Z[i][j] = 0; \
                                    for(int k = 0; k < (sizeof(X)[0]/sizeof(*X[0])); k++) { \
                                        Z[i][j] += X[i][k] * Y[k][j];}}}
#define printMatMac(X)  for(int i = 0; i < (sizeof(X)/sizeof(*X)); i++) { \
                            for (int j = 0; j < (sizeof(X[0])/sizeof(*X[0])); j++) { \
                                std::cout << X[i][j] << "\t"; } \
                            std::cout << "\n"; }

// constants, since our 2D array functions cannot handle dynamic dimensions
#define NUM_ROWS 5
#define NUM_COLS 5

// matrix operation functions
void addMat(double X[NUM_ROWS][NUM_COLS], double Y[NUM_ROWS][NUM_COLS], double Z[NUM_ROWS][NUM_COLS]);
void subMat(double X[NUM_ROWS][NUM_COLS], double Y[NUM_ROWS][NUM_COLS], double Z[NUM_ROWS][NUM_COLS]);
void multMat(double X[NUM_ROWS][NUM_COLS], double Y[NUM_ROWS][NUM_COLS], double Z[NUM_ROWS][NUM_COLS]);

void printMat(double X[NUM_ROWS][NUM_COLS]);