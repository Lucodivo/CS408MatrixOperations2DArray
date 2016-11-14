#include <iostream>
#include "Matrix.h"

void printCommands();
void printTwoMatrices(double m1[NUM_ROWS][NUM_COLS], double m2[NUM_ROWS][NUM_COLS]);
void printResults(double m1[NUM_ROWS][NUM_COLS], double m2[NUM_ROWS][NUM_COLS], double m3[NUM_ROWS][NUM_COLS]);

/**
 * @brief   Performs 2D array matrix operations and displays their results
 *          (commented out macros can be substituted for the function calls)
 * @author	Connor A. Haskins
 * @date	11/11/2016
 */
int main() {
    // dimension constants defined in Matrix.h
    double m1[NUM_ROWS][NUM_COLS] = { {1.0, 2.0, 3.0, 4.0, 5.0}, {2.0, 2.0, 2.0, 2.0, 2.0}, {3.0, 1.0, 1.0, 1.0, 3.0}, {0.0, 0.0, 2.0, 3.0, 2.0}, {4.0, 4.0, 4.0, 0.0, 0.0} };
    double m2[NUM_ROWS][NUM_COLS] = { {1.0, 0.0, 0.0, 0.0, 0.0}, {1.0, 2.0, 1.0, 2.0, 1.0}, {0.0, 0.0, 1.0, 0.0, 0.0}, {1.0, 1.0, 1.0, 1.0, 1.0}, {2.0, 2.0, 2.0, 2.0, 2.0} };
    double m3[NUM_ROWS][NUM_COLS];

    printTwoMatrices(m1, m2);
    printCommands();

    char choice;
    std::cin >> choice;

    // while the user enters a given command, continue the program
    while (choice > '0' && choice < '4') {
        switch (choice)
        {
        case '1':
            // this is a commented out macro that performs the same functionality as addMat
            //addMatMac(m1, m2, m3);
            addMat(m1, m2, m3);

            std::cout << "(1) M4 = M1 + M2 \n";
            printResults(m1, m2, m3);
            break;
        case '2':
            // this is a commented out macro that performs the same functionality as subMat
            //subMatMac(m1, m2, m3);
            subMat(m1, m2, m3);
            std::cout << "(2) M4 = M1 - M2 \n";
            printResults(m1, m2, m3);
            break;
        case '3':
            // this is a commented out macro that performs the same functionality as multMat
            //multMatMac(m1, m2, m3);
            multMat(m1, m2, m3);

            std::cout << "(3) M5 = M1 * M2 \n";
            printResults(m1, m2, m3);
            break;
        default:
            break;
        }
        printCommands();
        std::cin >> choice;
    }

    return 0;
}

/**
 * @brief   Display the user's options
 */
void printCommands() {
    std::cout << "(1) M3 = M1 + M2 \n";
    std::cout << "(2) M4 = M1 - M2 \n";
    std::cout << "(3) M5 = M1 * M2 \n";
    std::cout << "Enter the one of the following commands. \n";
    std::cout << "Or any other key to terminate. \n";
    std::cout << "\n";
}

/**
 * @brief   Print two matrices.
 * @param   m1[NUM_ROWS][NUM_COLS]
 * @param   m2[NUM_ROWS][NUM_COLS]
 */
void printTwoMatrices(double m1[NUM_ROWS][NUM_COLS], double m2[NUM_ROWS][NUM_COLS]) {
    std::cout << "===============Matrix 1===============\n";
    printMat(m1);
    std::cout << "===============Matrix 2===============\n";
    printMat(m2);
    std::cout << "\n";
}


/**
* @brief   Print two matrices and their result matrix.
* @param   m1[NUM_ROWS][NUM_COLS]
* @param   m2[NUM_ROWS][NUM_COLS]
* @param   m3[NUM_ROWS][NUM_COLS]
*/
void printResults(double m1[NUM_ROWS][NUM_COLS], double m2[NUM_ROWS][NUM_COLS], double m3[NUM_ROWS][NUM_COLS]) {
    printTwoMatrices(m1, m2);
    std::cout << "================Result================\n";
    printMat(m3);
    std::cout << "\n\n";
}