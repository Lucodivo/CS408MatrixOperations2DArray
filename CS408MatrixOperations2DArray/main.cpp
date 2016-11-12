#include <iostream>
#include "Matrix.h"

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

    // this is a commented out macro that performs the same functionality as addMat
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

    // this is a commented out macro that performs the same functionality as subMat
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

    // this is a commented out macro that performs the same functionality as multMat
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