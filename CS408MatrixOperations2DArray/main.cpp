#include <iostream>

#define addition(X,Y,Z) for(int i = 0; i < (sizeof(X)/sizeof(*X)); i++){for (int j = 0; j < (sizeof(X[0])/sizeof(*X[0])); j++){Z[i][j] = X[i][j] + Y[i][j];}}
#define WIDTH 3
#define HEIGHT 5

int main() {
	//double m1[5][MAX] = { {1.0, 2.0, 3.0, 4.0, 5.0}, {2.0, 2.0, 2.0, 2.0, 2.0}, {3.0, 1.0, 1.0, 1.0, 3.0}, {0.0, 0.0, 2.0, 3.0, 2.0}, {4.0, 4.0, 4.0, 0.0, 0.0} };
	//double m2[MAX][MAX] = { {1.0, 0.0, 0.0, 0.0, 0.0}, {1.0, 2.0, 1.0, 2.0, 1.0}, {0.0, 0.0, 1.0, 0.0, 0.0}, {1.0, 1.0, 1.0, 1.0, 1.0}, {2.0, 2.0, 2.0, 2.0, 2.0} };
	double m1[WIDTH][HEIGHT] = { {1.0, 2.0, 3.0, 4.0, 5.0}, {2.0, 2.0, 2.0, 2.0, 2.0}, {3.0, 1.0, 1.0, 1.0, 3.0}};
	double m2[WIDTH][HEIGHT] = { {1.0, 0.0, 0.0, 0.0, 0.0}, {1.0, 2.0, 1.0, 2.0, 1.0}, {0.0, 0.0, 1.0, 0.0, 0.0}};

	std::cout << "(1) M3 = M1 + M2 \n";
	std::cout << "(2) M4 = M1 - M2 \n";
	std::cout << "(3) M5 = M1 * M2 \n";

	double m3[WIDTH][HEIGHT];;

	addition(m1, m2, m3);

	return 0;
}