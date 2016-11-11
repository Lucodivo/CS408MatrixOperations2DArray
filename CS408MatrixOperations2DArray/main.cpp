#include <iostream>

// these macros are monstrosities, are only for fun, and are very fragile
// the dimensions of the arrays X, Y, Z must follow traditional matrix math rules
#define addition(X,Y,Z) for(int i = 0; i < (sizeof(X)/sizeof(*X)); i++){for (int j = 0; j < (sizeof(X[0])/sizeof(*X[0])); j++){Z[i][j] = X[i][j] + Y[i][j];}}
#define subtraction(X,Y,Z) for(int i = 0; i < (sizeof(X)/sizeof(*X)); i++){for (int j = 0; j < (sizeof(X[0])/sizeof(*X[0])); j++){Z[i][j] = X[i][j] - Y[i][j];}}
#define multiplication(X,Y,Z) for(int i = 0; i < (sizeof(X)/sizeof(*X)); i++){for (int j = 0; j < (sizeof(Y[0])/sizeof(*Y[0])); j++){Z[i][j] = 0;for(int k = 0; k < (sizeof(X)[0]/sizeof(*X[0])); k++){Z[i][j] += X[i][k] * Y[k][j];}}}
#define printArr(X) for(int i = 0; i < (sizeof(X)/sizeof(*X)); i++){for (int j = 0; j < (sizeof(X[0])/sizeof(*X[0])); j++){std::cout << X[i][j] << "\t";} std::cout << "\n";}

#define NUM_ROWS 5
#define NUM_COLS 5

int main() {
	double m1[NUM_ROWS][NUM_COLS] = { {1.0, 2.0, 3.0, 4.0, 5.0}, {2.0, 2.0, 2.0, 2.0, 2.0}, {3.0, 1.0, 1.0, 1.0, 3.0}, {0.0, 0.0, 2.0, 3.0, 2.0}, {4.0, 4.0, 4.0, 0.0, 0.0} };
	double m2[NUM_ROWS][NUM_COLS] = { {1.0, 0.0, 0.0, 0.0, 0.0}, {1.0, 2.0, 1.0, 2.0, 1.0}, {0.0, 0.0, 1.0, 0.0, 0.0}, {1.0, 1.0, 1.0, 1.0, 1.0}, {2.0, 2.0, 2.0, 2.0, 2.0} };
	double m3[NUM_ROWS][NUM_COLS];

	std::cout << "(1) M3 = M1 + M2 \n";
	std::cout << "(2) M4 = M1 - M2 \n";
	std::cout << "(3) M5 = M1 * M2 \n";

	std::cout << "\n";

	addition(m1, m2, m3);

	std::cout << "(1) M3 = M1 + M2 \n";
	std::cout << "====================================\n";
	printArr(m1);
	std::cout << "====================================\n";
	printArr(m2);
	std::cout << "====================================\n";
	printArr(m3);

	std::cout << "\n";

	subtraction(m1, m2, m3);
	std::cout << "(2) M4 = M1 - M2 \n";
	std::cout << "====================================\n";
	printArr(m1);
	std::cout << "====================================\n";
	printArr(m2);
	std::cout << "====================================\n";
	printArr(m3);
	
	std::cout << "\n";

	multiplication(m1, m2, m3);
	std::cout << "(3) M5 = M1 * M2 \n";
	std::cout << "====================================\n";
	printArr(m1);
	std::cout << "====================================\n";
	printArr(m2);
	std::cout << "====================================\n";
	printArr(m3);

	return 0;
}