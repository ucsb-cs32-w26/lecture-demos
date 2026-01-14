#include "aimove2.h"
#include <iostream>

namespace aimove {
    void move(int* coordinates) {
        std::cout << "in move-ai move()" << std::endl;
    }

    void compute() {
        // code for compute
        std::cout << "compute() in aimove2.cpp\n";
    }

    void awesomeNewMove1() {
        // code
    }
    void awesomeNewMove2() {
        // code
    }
    void awesomeNewMove3() {
        // code
    }
}

// note this can also be used instead of enclosing everything in the namespace block:
/*
void aimove::move(int* coordinates) {
    std::cout << "in move-ai move()" << std::endl;
}

void aimove::compute() {
    // code for compute
    std::cout << "compute() in aimove2.cpp\n";
}

void aimove::awesomeNewMove1() {
    // code
}
void aimove::awesomeNewMove2() {
    // code
}
void aimove::awesomeNewMove3() {
    // code
}
*/

